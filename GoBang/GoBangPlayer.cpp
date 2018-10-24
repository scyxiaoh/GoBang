//
//  GoBangPlayer.cpp
//  GoBang
//
//  Created by Kevin Sun on 2018/9/13.
//

#include "GoBangPlayer.hpp"


GoBangPlayer::GoBangPlayer(std::string pName, int id) { 
    name = pName;
    playerId = id;
}

GoBangPlayer::GoBangPlayer(int id) { 
    name = "Player " + std::to_string(id);
    playerId = id;
}

GoBangMove* GoBangPlayer::chooseMove(GoBangState *state) {
    return nullptr;
}


