//
//  Socket.hpp
//  GoBang
//
//  Created by Kevin Sun on 2018-10-23.
//

#ifndef Socket_hpp
#define Socket_hpp

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

class Socket {
public:
    virtual void run(){};
protected:
    int socketfd;
    ssize_t len;
    char buffer[1024];
    struct sockaddr_in remote_addr;
    virtual void processMessage(char *msg){};

};
#endif /* Socket_hpp */
