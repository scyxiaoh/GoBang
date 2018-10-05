//
//  Client.cpp
//  GoBang
//
//  Created by Kevin Sun on 2018/9/21.
//

#include "Client.hpp"


Client::Client(GoBangPlayer *p, GoBangGame *g) {
    player = p;
    game = g;
    userMoveNeeded = false;
    inputLine = new char[40];
    
    clnt_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    memset(&remote_addr, 0, sizeof(remote_addr));
    remote_addr.sin_family = AF_INET;
    remote_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    remote_addr.sin_port = htons(8000);
}

Client::~Client() { 
    delete player;
    delete game;
    delete[] inputLine;
}

int Client::getlocalPlayerId() { 
    return player->playerId;
}

char* Client::readMsg() {
    std::cout << "start to read" << std::endl;
    char buffer[40];
    ssize_t len = recv(clnt_sockfd, buffer, 40, 0);
    inputLine[len] = '\0';
    std::cout << "readed: " << buffer << std::endl;
    return buffer;
}

bool Client::connected() {
    if ((clnt_sockfd = socket(PF_INET, SOCK_STREAM, 0)) < 0){
        perror("socket error");
        return false;
    }
    
    if (connect(clnt_sockfd, (struct sockaddr*)&remote_addr, sizeof(struct sockaddr)) < 0) {
        perror("connect error");
        return false;
    }
    printf("connected to server\n");
    
    return true;
}

void Client::run() { 
    if (connected()){
        clientLoop();
    }
}

void Client::clientLoop() {
    printf("client loop starts.\n");
    ssize_t len = recv(clnt_sockfd, inputLine, 40, 0);
    printf("digit: %d\n", len);
    inputLine[len] = '\0';
    std::cout << "readed: " << inputLine << std::endl;
    
    close(clnt_sockfd);
}

std::thread Client::thread() { 
    return std::thread(&Client::run, this);
}







