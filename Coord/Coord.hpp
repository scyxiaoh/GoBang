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
    Coord();
    Coord(int pX, int pY);
    Coord(Coord * toClone);
    void setCoord(int pX, int pY);
    void setOccupancy(int playerId);
private:
    std::string toString();
};
#endif /* Coord_hpp */
