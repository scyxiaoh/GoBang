//
//  Resources.hpp
//  GoBang
//
//  Created by Kevin Sun on 2018/10/15.
//

#ifndef Resources_hpp
#define Resources_hpp

#include <stdio.h>
#include <QGraphicsObject>

class Resources {
public:
    class Image {
    public:
        static QImage whitePiece();
        static QImage blackPiece();
        static QImage titleBackGround();
        static QImage gameBackGround();
    };
};
#endif /* Resources_hpp */
