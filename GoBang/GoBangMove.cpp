//
//  GoBangMove.cpp
//  GoBang
//
//  Created by Kevin Sun on 2018/9/13.
//

#include "GoBangMove.hpp"


GoBangMove::GoBangMove(Coord *place, int player) {
    end = place;
    playerId = player;
}

GoBangMove::~GoBangMove() { 
    delete end;
}

