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
    int x, y;
    Coord();
    Coord(int pX, int pY){
        this->x = pX;
        this->y = pY;
    };
    ~Coord();
    void setCoord(int pX, int pY);
    
private:
    std::string toString();
};
#endif /* Coord_hpp */
