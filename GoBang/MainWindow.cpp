//
//  MainWindow.cpp
//  GoBang
//
//  Created by Kevin Sun on 2018/8/12.
//

#include <iostream>
#include "MainWindow.hpp"
#include "Scene/TitleScene.hpp"
#include "Scene/GameScene.hpp"

	
MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent)
{
    this->setFixedSize(800,600);
    view = new QGraphicsView(this);
    this->setCentralWidget(view);

    setScene(new TitleScene(this));
    
}

MainWindow::~MainWindow(){
    currentScene.release();
    delete view;
}

void MainWindow::setScene(QGraphicsScene *scene) {
    currentScene.reset(scene);
    view->setScene(currentScene.get());
}

void MainWindow::startGame() {
    setScene(new GameScene());
}



