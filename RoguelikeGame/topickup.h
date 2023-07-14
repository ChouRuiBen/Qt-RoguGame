#ifndef TOPICKUP_H
#define TOPICKUP_H

#include <basee.h>

class topickup
{
public:
    topickup();
    void Load(int, int, int); //随机加载掉落物(0---金币, 1---血瓶, 2---经验瓶, 3, 4--nothing)
    int x, y;
    int kind;
    bool isfree;
    QRect rect;
    QPixmap image;
};

#endif // TOPICKUP_H
