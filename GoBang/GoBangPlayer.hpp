//
//  GoBangPlayer.hpp
//  GoBang
//
//  Created by Kevin Sun on 2018/9/13.
//

#ifndef GoBangPlayer_hpp
#define GoBangPlayer_hpp

#include <stdio.h>
#include <string>
#include "GoBangMove.hpp"
#include "GoBangState.hpp"

class GoBangPlayer {
public:
    std::string name;
    GoBangPlayer(std::string pName, int id);
    GoBangPlayer(int id);
    virtual GoBangMove chooseMove(GoBangState state);
    
protected:
    int playerId;
    
private:
};

#endif /* GoBangPlayer_hpp */
