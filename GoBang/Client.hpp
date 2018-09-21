//
//  Client.hpp
//  GoBang
//
//  Created by Kevin Sun on 2018/9/21.
//

#ifndef Client_hpp
#define Client_hpp

#include <stdio.h>
#include "GoBangPlayer.hpp"
#include "GoBangGame.hpp"

class Client {
public:
    Client(GoBangPlayer *p, GoBangGame *g);
    ~Client();
    bool userMoveNeeded;
    int getlocalPlayerId();
private:
    GoBangPlayer *player;
    GoBangGame *game;
};

#endif /* Client_hpp */
