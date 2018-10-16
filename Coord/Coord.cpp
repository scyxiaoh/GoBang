//
//  Coord.cpp
//  GoBang
//
//  Created by Kevin Sun on 2018/8/12.
//

#include "Coord.hpp"

Coord::Coord(){
    piece = Piece::EMPTY;
}

Coord::Coord(int pX, int pY){
    this->x = pX;
    this->y = pY;
    piece = Piece::EMPTY;
}

Coord::Coord(Coord *toClone) {
    this->x = toClone->x;
    this->y = toClone->y;
    this->piece = toClone->piece;
}

void Coord::setCoord(int pX, int pY){
    this->x = pX;
    this->y = pY;
}

std::string Coord::toString(){
    return "(" + std::to_string(this->x) + ", " + std::to_string(this->y) +")";
}

void Coord::setOccupancy(int playerId) { 
    if (playerId == 0) {
        piece = Piece::BLACK;
    }
    else {
        piece = Piece::WHITE;
    }
}


