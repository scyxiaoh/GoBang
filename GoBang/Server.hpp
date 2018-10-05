//
//  Server.hpp
//  GoBang
//
//  Created by Kevin Sun on 2018/9/23.
//

#ifndef Server_hpp
#define Server_hpp

#include <stdio.h>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <iostream>
#include <thread>

class Server {
public:
    Server();
    void run();
    std::thread thread();
private:
    int serv_sockfd;
    int clnt_sockfd;
    char *bufferOut;
    bool listenAndAccept();
    struct sockaddr_in my_addr;
    struct sockaddr_in remote_addr;
    void serverLoop();
};

#endif /* Server_hpp */
