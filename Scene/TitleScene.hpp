//
//  TitleScene.hpp
//  GoBang
//
//  Created by Kevin Sun on 2018/9/8.
//

#ifndef TitleScene_hpp
#define TitleScene_hpp

#include <QGraphicsScene>
#include <stdio.h>
#include <QPushButton>
#include "GoBang/MainWindow.hpp"

class TitleScene : public QGraphicsScene {
    
public:
    QPushButton *exitButton;
    QPushButton *playPVEButton;
    TitleScene(MainWindow *mW);
    ~TitleScene();

private:

    QPushButton *playPVPButton;
    QPushButton *settingButton;
};
#endif /* TitleScene_hpp */
