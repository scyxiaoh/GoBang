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
    this->coords = (Coord*) malloc(sizeof(Coord)*pSize*pSize);
    //create coord for each x, y
    for (int i = 0; i < pSize; i++){
        for (int j=0; j < pSize; j++){
            coords[i*pSize + j] = *(new Coord(i,j));
        }
    }
}

GoBangState::~GoBangState(){
    free (this->coords);
}

