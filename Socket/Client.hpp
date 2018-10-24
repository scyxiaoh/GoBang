//
//  Client.hpp
//  GoBang
//
//  Created by Kevin Sun on 2018/9/21.
//

#ifndef Client_hpp
#define Client_hpp

#include <string>
#include <thread>
#include <iostream>
#include "Socket.hpp"
#include "GoBang/GoBangPlayer.hpp"
#include "GoBang/GoBangGame.hpp"

class Client : public Socket{

public:
    Client(GoBangPlayer *p, GoBangGame *g);
    ~Client();
    void run();
    bool userMoveNeeded;
    int getlocalPlayerId();
    GoBangGame *game;
    GoBangPlayer *player;
    void playMove(GoBangMove *decision);
    std::thread thread();
private:
    bool connected();
    void clientLoop();
    void processMessage(QString message);
};

#endif /* Client_hpp */
