//
//  GoBangBoard.cpp
//  GoBang
//
//  Created by Kevin Sun on 2018/8/12.
//

#include "GoBangState.hpp"

int GoBangState::size;

GoBangState::GoBangState(const int pSize){
    this->size = pSize;
    //initialize the coord array
    this->coords = new Coord [size * size];
    //set x, y for each coord
    for (int i = 0; i < pSize; i++){
        for (int j=0; j < pSize; j++){
            this->coords[i*pSize + j].setCoord(i, j);
        }
    }
}

GoBangState::~GoBangState(){
    delete [] this->coords;
}

Coord GoBangState::get(int x, int y){
    return this->coords[x*this->size + y];
}
