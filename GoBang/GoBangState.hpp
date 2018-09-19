//
//  GoBangBoard.hpp
//  GoBang
//
//  Created by Kevin Sun on 2018/8/12.
//

#ifndef GoBangBoard_hpp
#define GoBangBoard_hpp

#include <stdio.h>
#include "Coord/Coord.hpp"

class GoBangState{
public:
    GoBangState(const int pSize);
    ~GoBangState();
    inline Coord get(int x, int y);
    
private:
    static int size;
    Coord *coords;
};
#endif /* GoBangBoard_hpp */
