//
//  MainWindow.cpp
//  GoBang
//
//  Created by Kevin Sun on 2018/8/12.
//

#include "MainWindow.hpp"
#include "Scene/TitleScene.hpp"

	
MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent)
{
    this->setFixedSize(800,600);
    view = new QGraphicsView(this);
    this->setCentralWidget(view);

    TitleScene *titleScene = new TitleScene();
    QObject::connect(titleScene->exitButton, SIGNAL(clicked()),this,SLOT(close()));
    setScene(titleScene);
}

MainWindow::~MainWindow(){
    delete currentScene;
    delete view;
}

void MainWindow::setScene(QGraphicsScene *scene) {
    if (currentScene != nullptr) delete currentScene;
    currentScene = scene;
    view->setScene(scene);
}

