#ifndef BOSS_H
#define BOSS_H

#include <basee.h>
#include <topickup.h>
#include <movevector.h>
#include <bullet.h>

class BOSS
{
public:
    BOSS();

    void shoot();
    void reload();

    QRect rect;

    QPixmap image;

    double cx, cy; // 现在位置
    double bfx, bfy; // 之前位置
    int bx, by;// 移动方位

    MoveVector Myvector; // 与移动相关的向量

    int atk, hp, Maxhp; // 攻击力, 血量, 血量上限
    double rate; // 血量 / 血量上限(用于画血条)

    double speed; // 速度

    bool isfree;

    Bullet bullets[BULLET_NUM]; // 子弹

    int recorder; // 子弹计时器
};

#endif // BOSS_H
