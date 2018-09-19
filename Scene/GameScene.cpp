//
//  GameScene.cpp
//  GoBang
//
//  Created by Kevin Sun on 2018/9/12.
//

#include "GameScene.hpp"
#include <QColor>
#include <QPainter>


GameScene::GameScene() { 
    setSceneRect(0,0,800,600);
    QImage bgImage(":images/gameBackGround.jpg");
    setBackgroundBrush(QBrush(bgImage.scaled(800,600,Qt::IgnoreAspectRatio)));
    
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
    
    addEllipse(298, 298, 4, 4, QPen(Qt::black), QBrush(Qt::black));
}
