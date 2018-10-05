//
//  Server.cpp
//  GoBang
//
//  Created by Kevin Sun on 2018/9/23.
//

#include "Server.hpp"


Server::Server() {
    bufferOut = new char[40];
    bufferOut = {0};
    memset(&my_addr, 0, sizeof(my_addr));
    my_addr.sin_family = AF_INET;
    my_addr.sin_addr.s_addr = INADDR_ANY;
    my_addr.sin_port = htons(8000);
}

bool Server::listenAndAccept() {
    if ((serv_sockfd = socket(PF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket error");
        return false;
    }
    
    if (bind(serv_sockfd, (struct sockaddr*)&my_addr, sizeof(struct sockaddr)) < 0){
        perror("bind error");
        return false;
    }
    
    if (listen(serv_sockfd, 20) < 0){
        perror("listen error");
        return false;
    }
    
    socklen_t clnt_addr_size = sizeof(struct sockaddr_in);
    if ((clnt_sockfd = accept(serv_sockfd, (struct sockaddr*)&remote_addr, &clnt_addr_size)) < 0){
        perror("accept error");
        return false;
    }
    printf("accepted client %s\n", inet_ntoa(remote_addr.sin_addr));
    return true;
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
    std::cout << "server loop starts" << std::endl;
    bufferOut = "hello?";
    ssize_t len;
    if((len = send(clnt_sockfd,bufferOut,40,0)) < 0){
        perror("write error");
    }
    printf("sent %d bytes\n", len);
    
    close(clnt_sockfd);
    close(serv_sockfd);
}





