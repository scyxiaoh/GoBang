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

class GoBangGame {
public:
    GoBangGame(GoBangPlayer *p1, GoBangPlayer *p2);
    ~GoBangGame();
private:
    GoBangPlayer *p1;
    GoBangPlayer *p2;
    GoBangState *state;
};

#endif /* GoBangGame_hpp */
