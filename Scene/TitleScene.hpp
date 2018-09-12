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

class TitleScene : public QGraphicsScene {
    
public:
    QPushButton *exitButton;
    TitleScene();

private:
    QPushButton *playPVEButton;
    QPushButton *playPVPButton;
    QPushButton *settingButton;
};
#endif /* TitleScene_hpp */
