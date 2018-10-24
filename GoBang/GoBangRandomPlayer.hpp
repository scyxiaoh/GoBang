//
//  GoBangRandomPlayer.hpp
//  GoBang
//
//  Created by Kevin Sun on 2018/10/16.
//

#ifndef GoBangRandomPlayer_hpp
#define GoBangRandomPlayer_hpp

#include <stdio.h>
#include <stdlib.h>
#include "GoBangPlayer.hpp"

class GoBangRandomPlayer : public GoBangPlayer {
public:
    GoBangRandomPlayer(std::string pName, int id) : GoBangPlayer(pName, id) {};
    GoBangRandomPlayer(int id) : GoBangPlayer(id) {};
    GoBangMove* chooseMove(GoBangState *state);
};
#endif /* GoBangRandomPlayer_hpp */
