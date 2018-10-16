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
    longestRowBlack = 0;
    longestRowWhite = 0;
}

GoBangState::GoBangState(GoBangState *toClone) {
    this->size = toClone->size;
    this->coords = (Coord*) malloc(sizeof(Coord)*size*size);
    //create coord for each x, y
    for (int i = 0; i < size; i++){
        for (int j=0; j < size; j++){
            coords[i*size + j] = *(new Coord(toClone->get(i, j)));
        }
    }
}

GoBangState::~GoBangState(){
    free (this->coords);
}

bool GoBangState::isValidMove(int x, int y) {
    //std::cout << x << "," << y << std::endl;
    if (get(x, y)->piece == Coord::Piece::EMPTY) {
        //std::cout << "true" << std::endl;
        return true;
    }
    else {
        //std::cout << "false" << std::endl;
        return false;
    }
}

void GoBangState::processMove(GoBangMove m) {
    m.process();
    int currentDirectionLongest = 1;
    int currentLongest = 1;
    Coord::Piece colorWanted = m.end->piece;
    //horizontal direction
        //to left
    for (int i = m.end->x - 1; i >= 0; i--){
        if (get(i, m.end->y)->piece == colorWanted) {
            currentDirectionLongest ++;
        }
        else break;
    }
        //to right
    for (int i = m.end->x + 1; i < size; i++) {
        if (get(i, m.end->y)->piece == colorWanted) {
            currentDirectionLongest ++;
        }
        else break;
    }
    if (currentDirectionLongest > currentLongest) currentLongest = currentDirectionLongest;
    currentDirectionLongest = 1;
    
    //vertical direction
        //to up
    for (int i = m.end->y - 1; i >= 0; i--){
        if (get(m.end->x, i)->piece == colorWanted) {
            currentDirectionLongest ++;
        }
        else break;
    }
        //to down
    for (int i = m.end->y + 1; i < size; i++) {
        if (get(m.end->x, i)->piece == colorWanted) {
            currentDirectionLongest ++;
        }
        else break;
    }
    if (currentDirectionLongest > currentLongest) currentLongest = currentDirectionLongest;
    currentDirectionLongest = 1;
    
    //diagonal positive
        // to up-right
    for (int i = m.end->x + 1, j = m.end->y - 1; i < size && j >= 0; i++, j--) {
        if (get(i, j)->piece == colorWanted) {
            currentDirectionLongest ++;
        }
        else break;
    }
        // to down-left
    for (int i = m.end->x - 1, j = m.end->y + 1; i >= 0 && j < size; i--, j++) {
        if (get(i, j)->piece == colorWanted) {
            currentDirectionLongest ++;
        }
        else break;
    }
    if (currentDirectionLongest > currentLongest) currentLongest = currentDirectionLongest;
    currentDirectionLongest = 1;
    
    //diagonal negative
        // to up-left
    for (int i = m.end->x - 1, j = m.end->y - 1; i >= 0 && j >= 0; i--, j--) {
        if (get(i, j)->piece == colorWanted) {
            currentDirectionLongest ++;
        }
        else break;
    }
        // to down-right
    for (int i = m.end->x + 1, j = m.end->y + 1; i < size && j < size; i++, j++) {
        if (get(i, j)->piece == colorWanted) {
            currentDirectionLongest ++;
        }
        else break;
    }
    if (currentDirectionLongest > currentLongest) currentLongest = currentDirectionLongest;
    currentDirectionLongest = 1;
    
    //ultimately update longest row information
    if (colorWanted == Coord::Piece::BLACK && currentLongest >longestRowBlack) {
        longestRowBlack = currentLongest;
    }
    else if (colorWanted == Coord::Piece::WHITE && currentLongest >longestRowWhite) {
        longestRowWhite = currentLongest;
    }
}

std::vector<GoBangMove*> GoBangState::allPossibleMoves(int playerId) {
    std::vector<GoBangMove*> list;
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++) {
            if (isValidMove(i, j)){
                list.push_back(new GoBangMove(get(i, j), playerId));
            }
        }
    }
    return list;
}





