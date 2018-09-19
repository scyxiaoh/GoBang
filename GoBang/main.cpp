//
//  main.cpp
//  GoBang
//
//  Created by Kevin Sun on 2018/8/11.
//  Copyright © 2018年 Kevin Sun. All rights reserved.
//

#include <iostream>
#include <QApplication>
#include "MainWindow.hpp"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    std::unique_ptr<int> a;
    a.reset(new int(5));
    std::cout << *a.get() << std::endl;
    a.reset(new int(6));
    std::cout << *a.get() << std::endl;
    
    MainWindow window;
    window.show();

    return app.exec();
}
