//
//  Client.hpp
//  GoBang
//
//  Created by Kevin Sun on 2018/9/21.
//

#ifndef Client_hpp
#define Client_hpp

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <string>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <thread>
#include <iostream>
#include "GoBangPlayer.hpp"
#include "GoBangGame.hpp"

class Client {
public:
    Client(GoBangPlayer *p, GoBangGame *g);
    ~Client();
    bool userMoveNeeded;
    int getlocalPlayerId();
    GoBangGame *game;
    char* readMsg();
    void run();
    std::thread thread();
private:
    GoBangPlayer *player;
    char *inputLine;
    int clnt_sockfd;
    struct sockaddr_in remote_addr;
    bool connected();
    void clientLoop();
};

#endif /* Client_hpp */
