//
//  GameScene.cpp
//  GoBang
//
//  Created by Kevin Sun on 2018/9/12.
//

#include "GameScene.hpp"
#include "Client.hpp"
#include <QColor>
#include <QPainter>
#include <iostream>


GameScene::GameScene(Client *c) {
    setSceneRect(0,0,800,600);
    setBackgroundBrush(QBrush(Resources::Image::gameBackGround().scaled(800,600,Qt::IgnoreAspectRatio)));
    
    //draw board grid
    for (int i = 0; i < 15; i++){
        addLine(76, 76 + i*32, 76 + 32 * 14, 76 + i*32);
        addLine(76 + i*32, 76, 76 + i*32, 76 + 32 * 14);
    }
    
    //draw border
    addLine(68, 68, 76 + 32 * 14 + 8, 68);
    addLine(68, 68, 68, 76 + 32 * 14 + 8);
    addLine(76 + 32 * 14 + 8, 68, 76 + 32 * 14 + 8, 76 + 32 * 14 + 8);
    addLine(68, 76 + 32 * 14 + 8, 76 + 32 * 14 + 8, 76 + 32 * 14 + 8);
    
    //draw special coords (9 even coords)
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            addEllipse(76 + 3 * 32 + i * 32 * 4 - 2, 76 + 3 * 32 + j * 32 * 4 - 2, 4, 4, QPen(Qt::black), QBrush(Qt::black));
        }
    }

    //initiate Client and assign guiHandler
    client = c;
    c->game->guiHandler = this;
    
    this->potentialPiece = new QGraphicsRectItem(0,0,32,32);
    QImage pieceImage;
    if (c->getlocalPlayerId() == 0){
        pieceImage = Resources::Image::blackPiece();
    }
    else {
        pieceImage = Resources::Image::whitePiece();
    }
    this->potentialPiece->setBrush(QBrush(pieceImage.scaled(32, 32,Qt::IgnoreAspectRatio)));
    this->potentialPiece->setPen(QColor(0,0,0,0));
    this->potentialPiece->hide();
    addItem(potentialPiece);

}

GameScene::~GameScene() {
    for (std::vector<QGraphicsRectItem*>::iterator it = guiPieces.begin() ; it != guiPieces.end(); ++it){
        delete (*it);
    }
    guiPieces.clear();
    guiPieces.shrink_to_fit();
    delete potentialPiece;
}

void GameScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event){
    //if (!client->userMoveNeeded) return;
    qreal x = event->scenePos().x();
    qreal y = event->scenePos().y();
    if (x>=64 && x <= 536 && y>= 64 && y <= 536) {
        int xC = ((int)x - 64) / 32;
        int yC = ((int)y - 64) / 32;
        if (client->game->isValidMove(xC, yC)) {
            potentialPiece->setPos((qreal) xC * 32 + 60, (qreal) yC * 32 + 60);
            potentialPiece->show();
        }
        else potentialPiece->hide();

    }
    else {
        potentialPiece->hide();
    }
}

void GameScene::guiAddPiece(GoBangMove m) {
    guiPieces.push_back(m.parseItem());
    addItem(guiPieces.back());
}


