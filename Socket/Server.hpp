//
//  Server.hpp
//  GoBang
//
//  Created by Kevin Sun on 2018/9/23.
//

#ifndef Server_hpp
#define Server_hpp

#include <stdlib.h>
#include <sys/select.h> //FD_SET, FD_ISSET, FD_ZERO macros
#include <netinet/in.h>
#include <iostream>
#include <thread>
#include "Socket.hpp"

class Server : public Socket{

public:
    Server();
    void run();
    std::thread thread();
private:
    int clnt_sockfd[2], count_clients, max_clients, activity, max_sd, sd, opt, turnPlayer;
    socklen_t clnt_addr_size;
    struct sockaddr_in my_addr;
    fd_set readfds;
    
    void serverLoop();
    bool listenAndAccept();
    void processMessage(char *msg);
    void nextTurn();
};

#endif /* Server_hpp */
