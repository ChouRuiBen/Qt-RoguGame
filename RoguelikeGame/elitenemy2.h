#ifndef ELITENEMY2_H
#define ELITENEMY2_H

#include <basee.h>
#include <topickup.h>
#include <movevector.h>
#include <bullet.h>

class elitenemy2 //近战
{
public:
    elitenemy2();
    void reload();

    QRect rect;

    QPixmap image;

    double cx, cy; // 现在位置
    double bfx, bfy; // 之前位置

    MoveVector Myvector; // 与移动相关的向量

    int atk, hp, ep, Maxhp;// 攻击力, 血量, 血量上限, 击杀后获得经验
    double rate; // 血量 / 血量上限(供画血条用)

    double  speed; // 速度

    bool isfree;

};

#endif // ELITENEMY2_H
