//
//  main.cpp
//  GoBang
//
//  Created by Kevin Sun on 2018/8/11.
//  Copyright © 2018年 Kevin Sun. All rights reserved.
//

#include <iostream>
#include <QApplication>
#include <QPushButton>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    QPushButton button;
    button.setText("My text");
    button.setToolTip("A tooltip");
    button.show();
    return app.exec();
}
