//
//  GoBangGame.cpp
//  GoBang
//
//  Created by Kevin Sun on 2018/9/20.
//

#include "GoBangGame.hpp"


GoBangGame::GoBangGame(GoBangPlayer *p1, GoBangPlayer *p2) {
    this->p1 = p1;
    this->p2 = p2;
    state = new GoBangState(15);
}


GoBangGame::~GoBangGame() { 
    delete p1;
    delete p2;
    delete state;
}
