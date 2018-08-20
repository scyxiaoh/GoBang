//
//  Coord.cpp
//  GoBang
//
//  Created by Kevin Sun on 2018/8/12.
//

#include "Coord.hpp"

void Coord::setCoord(int pX, int pY){
    this->x = pX;
    this->y = pY;
}

std::string Coord::toString(){
    return "(" + std::to_string(this->x) + ", " + std::to_string(this->y) +")";
}
