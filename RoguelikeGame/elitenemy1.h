#ifndef ELITENEMY_H
#define ELITENEMY_H

#include <basee.h>
#include <topickup.h>
#include <movevector.h>
#include <bullet.h>

class elitenemy1 //远程
{
public:
    elitenemy1();
    void reload();

    void shoot();

    QRect rect;

    QPixmap image;

    double cx, cy; // 现在位置
    double bfx, bfy; // 之前位置

    MoveVector Myvector; // 与移动相关的向量

    bool isfree;

    int atk, hp, Maxhp, ep; // 攻击力, 血量, 血量上限, 击杀后获得经验
    double rate; // 血量 / 血量上限(供画血条用)

    double  speed; // 速度

    Bullet bullets[BULLET_NUM]; // 子弹

    int recorder; // 子弹计时器
};

#endif // ELITENEMY_H
