//
//  Coord.hpp
//  GoBang
//
//  Created by Kevin Sun on 2018/8/12.
//

#ifndef Coord_hpp
#define Coord_hpp

#include <stdio.h>
#include <string>

class Coord{
public:
    enum Piece{
        BLACK,
        WHITE,
        EMPTY
    };
    
    int x, y;
    Piece piece;
    Coord(){};
    Coord(int pX, int pY);
    void setCoord(int pX, int pY);
    
private:
    std::string toString();
};
#endif /* Coord_hpp */
