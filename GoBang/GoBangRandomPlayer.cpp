//
//  GoBangRandomPlayer.cpp
//  GoBang
//
//  Created by Kevin Sun on 2018/10/16.
//

#include "GoBangRandomPlayer.hpp"


GoBangMove* GoBangRandomPlayer::chooseMove(GoBangState *state) {
    return state->randomMove(playerId);
}
