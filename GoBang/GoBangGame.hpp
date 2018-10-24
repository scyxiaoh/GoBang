//
//  GoBangGame.hpp
//  GoBang
//
//  Created by Kevin Sun on 2018/9/20.
//

#ifndef GoBangGame_hpp
#define GoBangGame_hpp

#include <stdio.h>
#include <QString>
#include "GoBangPlayer.hpp"
#include "GoBangState.hpp"
#include "Scene/GameScene.hpp"

class GoBangGame {

public:
    GoBangState *state;
    GameScene *guiHandler;
    
    GoBangGame();
    ~GoBangGame();
    bool isValidMove(int x, int y);
    void processMove(GoBangMove m);
    GoBangMove *parseMove(QString s);
    
private:
};

#endif /* GoBangGame_hpp */
