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

class GoBangBoard{
public:
    GoBangBoard(const int pSize);
    ~GoBangBoard();
    inline Coord get(int x, int y);
    
private:
    static int size;
    Coord *coords;
};
#endif /* GoBangBoard_hpp */
