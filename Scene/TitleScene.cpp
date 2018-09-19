//
//  TitleScene.cpp
//  GoBang
//
//  Created by Kevin Sun on 2018/9/8.
//

#include "TitleScene.hpp"
#include <QGraphicsObject>
#include <QPushButton>


TitleScene::TitleScene(MainWindow *mW) {
    setSceneRect(0,0,800,600);
    QImage bgImage(":images/titleBackGround.jpg");
    setBackgroundBrush(QBrush(bgImage.scaled(800,600,Qt::IgnoreAspectRatio)));
    QGraphicsTextItem *titleText = addText("GoBang");
    titleText->setScale(5);
    titleText->setPos(QPointF(60,100));

    playPVEButton = new QPushButton("Start Singleplayer Game");
    playPVPButton = new QPushButton("Start Multiplayer Game");
    settingButton = new QPushButton("Setting");
    exitButton = new QPushButton("Exit");

    playPVEButton->setGeometry(100,250,200,45);
    playPVPButton->setGeometry(100,300,200,45);
    settingButton->setGeometry(100,350,200,45);
    exitButton->setGeometry(100,400,200,45);
    
    QObject::connect(playPVEButton, SIGNAL(clicked()), mW, SLOT(startGame()), Qt::QueuedConnection);
    QObject::connect(playPVPButton, SIGNAL(clicked()), mW, SLOT(startGame()), Qt::QueuedConnection);
    QObject::connect(exitButton, SIGNAL(clicked()), mW, SLOT(close()));
    
    this->addWidget(playPVEButton);
    this->addWidget(playPVPButton);
    this->addWidget(settingButton);
    this->addWidget(exitButton);

}

TitleScene::~TitleScene() { 
    delete playPVEButton;
    delete playPVPButton;
    delete settingButton;
    delete exitButton;
}



