//
//  Resources.cpp
//  GoBang
//
//  Created by Kevin Sun on 2018/10/15.
//

#include "Resources.hpp"


QImage Resources::Image::whitePiece() { 
    return QImage(":images/whitePiece.png");
}

QImage Resources::Image::blackPiece() {
    return QImage(":images/blackPiece.png");
}

QImage Resources::Image::titleBackGround() {
    return QImage(":images/titleBackGround.jpg");
}

QImage Resources::Image::gameBackGround() {
    return QImage(":images/gameBackGround.jpg");
}
