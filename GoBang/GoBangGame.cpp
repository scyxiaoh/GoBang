//
//  GoBangGame.cpp
//  GoBang
//
//  Created by Kevin Sun on 2018/9/20.
//

#include "GoBangGame.hpp"
#include <iostream>


GoBangGame::GoBangGame() {
    state = new GoBangState(15);
}


GoBangGame::~GoBangGame() {
    delete state;
}

bool GoBangGame::isValidMove(int x, int y) {
    return state->isValidMove(x, y);
}

void GoBangGame::processMove(GoBangMove m) {
    state->processMove(m);
    if (guiHandler != nullptr)  guiHandler->guiAddPiece(m);
}

GoBangMove* GoBangGame::parseMove(QString s) {
    QStringList components = s.split(' ');
    if (components.size() < 3 || components.at(0).toInt() >= state->size || components.at(1).toInt() >= state->size) {
        perror("ERROR: invalid move parsed from client.\n");
        return nullptr;
    }
    return new GoBangMove(state->get(components.at(0).toInt(), components.at(1).toInt()), components.at(2).toInt());
}



