//
//  GoBangGame.hpp
//  GoBang
//
//  Created by Kevin Sun on 2018/9/20.
//

#ifndef GoBangGame_hpp
#define GoBangGame_hpp

#include <stdio.h>
#include "GoBangPlayer.hpp"
#include "GoBangState.hpp"
#include "Scene/GameScene.hpp"

class GoBangGame {
public:
    GoBangGame(GoBangPlayer *p1, GoBangPlayer *p2);
    ~GoBangGame();
    bool isValidMove(int x, int y);
    GameScene *guiHandler;
    void processMove(GoBangMove m);
private:
    GoBangPlayer *p1;
    GoBangPlayer *p2;
    GoBangState *state;
};

#endif /* GoBangGame_hpp */
