//
//  Server.cpp
//  GoBang
//
//  Created by Kevin Sun on 2018/9/23.
//

#include "Server.hpp"
#include <QString>


Server::Server() {
    opt = 1;
    max_clients = 2;
    count_clients = 0;
    turnPlayer = 0;
    
    memset(&my_addr, 0, sizeof(my_addr));
    my_addr.sin_family = AF_INET;
    my_addr.sin_addr.s_addr = INADDR_ANY;
    my_addr.sin_port = htons(8000);
    
    clnt_addr_size = sizeof(struct sockaddr_in);
    
    //initialise all client socketfd to 0 so not checked
    for (int i = 0; i < max_clients; i++) {
        clnt_sockfd[i] = 0;
    }
    //create a master server socket
    if ((socketfd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket error\n");
        exit(EXIT_FAILURE);
    }
    
    //set master socket to allow multiple connections
    if (setsockopt(socketfd, SOL_SOCKET, SO_REUSEADDR, (char *) &opt, sizeof(opt)) < 0) {
        perror("setsockopt error\n");
        exit(EXIT_FAILURE);
    }
    
    //bind the socket to localhost port 8000
    if (bind(socketfd, (struct sockaddr*)&my_addr, sizeof(struct sockaddr)) < 0){
        perror("bind error\n");
        exit(EXIT_FAILURE);
    }
}

bool Server::listenAndAccept() {
    //try to specify maximum of 2 pending connections for the master socket
    if (listen(socketfd, 2) < 0){
        perror("listen error\n");
        return false;
    }
    
    printf("Waiting for connections ...\n");
    
    while(true) {
        //clear the socket set
        __DARWIN_FD_ZERO(&readfds);
        
        //add master socket to set
        __DARWIN_FD_SET(socketfd, &readfds);
        max_sd = socketfd;
        
        //add child socket to set
        for (int i = 0; i < max_clients; i++) {
            //socket descriptor
            sd = clnt_sockfd[i];
            
            // if valid socket descriptor then add to read list
            if(sd > 0){
                __DARWIN_FD_SET(sd, &readfds);
            }
            
            //highest file descriptor number, need it for the select function
            if (sd > max_sd){
                max_sd = sd;
            }
        }
        
        //wait for an activity on one of the sockets, timeout is NULL
        activity = select( max_sd + 1, &readfds, NULL, NULL, NULL);
        
        if ((activity < 0) && (errno != EINTR)) {
            printf("select error\n");
        }
        
        //if something happened on the master socket
        //then it's an incoming connection
        if (__DARWIN_FD_ISSET(socketfd, &readfds)){
            int new_socket;
            if ((new_socket = accept(socketfd, (struct sockaddr *)&my_addr, (socklen_t *)&clnt_addr_size)) < 0){
                perror("accept error\n");
                return false;
            }
            
            printf("New connection, socket fd is %d, ip is: %s, port: %d\n", new_socket, inet_ntoa(my_addr.sin_addr), ntohs(my_addr.sin_port));
            
            //send welcome message
            
            //add new socket to array of sockets
            for (int i = 0; i < max_clients; i++){
                //if position is empty
                if (clnt_sockfd[i] == 0) {
                    clnt_sockfd[i] = new_socket;
                    printf("Added to list of sockets ad %d\n", i);
                    count_clients ++;
                    
                    break;
                }
            }
        }
        
        //else its some IO operation on some other socket
        for (int i = 0; i < max_clients; i++){
            sd = clnt_sockfd[i];
            
            if (__DARWIN_FD_ISSET(sd, &readfds)){
                //check if it was for closing
                if ((len = read(sd, buffer, 1024)) == 0) {
                    //the client disconnected, get his details and print
                    getpeername(sd, (struct sockaddr *)&my_addr, (socklen_t *)&clnt_addr_size);
                    printf("Host disconnected, ip %s, port %d \n", inet_ntoa(my_addr.sin_addr), ntohs(my_addr.sin_port));
                    
                    //close the socket and mark as 0 in the list for reuse
                    close(sd);
                    clnt_sockfd[i] = 0;
                    count_clients --;
                    
                    return false;
                }
            }
        }
        
        if (count_clients == max_clients) {
            return true;
        }
    }
}

std::thread Server::thread() { 
    return std::thread(&Server::run, this);
}

void Server::run() { 
    if (listenAndAccept()){
        serverLoop();
    }
}

void Server::serverLoop() {
    
    //release the first turn
    char *message = "PLAY 0|";
    for (int i = 0; i < max_clients; i++){
        if((len = send(clnt_sockfd[i], message, strlen(message),0)) < 0){
            perror("write error\n");
        }
    }
    
    while(true) {
        //clear the socket set
        __DARWIN_FD_ZERO(&readfds);
        
        //add master socket to set
        __DARWIN_FD_SET(socketfd, &readfds);
        max_sd = socketfd;
        
        //add child socket to set
        for (int i = 0; i < max_clients; i++) {
            //socket descriptor
            sd = clnt_sockfd[i];
            
            // if valid socket descriptor then add to read list
            if(sd > 0){
                __DARWIN_FD_SET(sd, &readfds);
            }
            
            //highest file descriptor number, need it for the select function
            if (sd > max_sd){
                max_sd = sd;
            }
        }
        
        //wait for an activity on one of the sockets, timeout is NULL
        activity = select( max_sd + 1, &readfds, NULL, NULL, NULL);
        
        if ((activity < 0) && (errno != EINTR)) {
            printf("select error\n");
        }
        
        //some IO operation on client sockets
        for (int i = 0; i < max_clients; i++) {
            sd = clnt_sockfd[i];
            
            if (__DARWIN_FD_ISSET(sd, &readfds)){
                //check if it was for closing
                if ((len = read(sd, buffer, 1024)) == 0) {
                    //the client disconnected, get his details and print
                    getpeername(sd, (struct sockaddr *)&my_addr, (socklen_t *)&clnt_addr_size);
                    printf("Host disconnected, ip %s, port %d \n", inet_ntoa(my_addr.sin_addr), ntohs(my_addr.sin_port));
                    
                    //close the socket and mark as 0 in the list for reuse
                    close(sd);
                    clnt_sockfd[i] = 0;
                    count_clients --;
                }
                //process the incoming message
                else {
                    buffer[len] = '\0';
                    processMessage(buffer);
                }
            }
        }
    }
    
    close(clnt_sockfd[0]);
    close(clnt_sockfd[1]);
    close(socketfd);
}

void Server::processMessage(char *msg) {
    //currently just echo back the message
    for (int i = 0; i < max_clients; i++){
        if((len = send(clnt_sockfd[i], msg, strlen(msg),0)) < 0){
            perror("write error\n");
        }
    }
    
    nextTurn();
    
    /**
    QString message(msg);
    if (message.startsWith("")){
        
    }
     **/
}

void Server::nextTurn() { 
    turnPlayer = 1 - turnPlayer;
    std::string str = "PLAY " + std::to_string(turnPlayer) + "|";
    char *cstr = new char [str.size() + 1];
    strcpy(cstr, str.c_str());
    for (int i = 0; i < max_clients; i++){
        if((len = send(clnt_sockfd[i], cstr, strlen(cstr),0)) < 0){
            perror("write error\n");
        }
    }
    delete[] cstr;
}








