//
//  GoBangMove.hpp
//  GoBang
//
//  Created by Kevin Sun on 2018/9/13.
//

#ifndef GoBangMove_hpp
#define GoBangMove_hpp

#include <stdio.h>
#include "Coord/Coord.hpp"

class GoBangMove {
public:
    GoBangMove(Coord *place, int player);
    ~GoBangMove();
private:
    int playerId;
    Coord *end;
};

#endif /* GoBangMove_hpp */
