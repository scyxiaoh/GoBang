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
}

Client::~Client() { 
    delete player;
    delete game;
}

int Client::getlocalPlayerId() { 
    return player->playerId;
}


