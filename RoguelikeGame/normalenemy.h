#ifndef ENEMYNORMAL_H
#define ENEMYNORMAL_H

#include <basee.h>
#include <topickup.h>

class Normalenemy
{
public:
    Normalenemy();
    void reload();

    QRect rect;

    QPixmap image;

    double cx, cy; // 现在位置
    double bfx, bfy; // 之前位置

    int atk, hp, Maxhp, ep;// 攻击力, 血量, 血量上限, 击杀后获得经验
    double rate;// 血量 / 血量上限(供画血条用)

    double speed; // 速度

    int wayx, wayy; // 移动辅助变量

    bool isfree;

};

#endif // ENEMYNORMAL_H
