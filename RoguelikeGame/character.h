#ifndef HERO_H
#define HERO_H

#include "basee.h"
#include "bullet.h"
#include "movevector.h"

class Character{
public:
    Character(); // 角色初始化

    void reload();

    void LoadI(int ); // 加载角色图片, 数值

    void setPosition(); // 角色位置更新

    void loadBullet(int ); // 加载子弹

    void shoot();//子弹八方向发射

    void pickup(); // 拾取掉落物(金币或者血瓶)

    QPixmap image; // 图像

    QPixmap up;

    QRect rect, pick; // 矩形框

    double cx, cy; // 现在位置
    double bfx, bfy; // 之前位置

    MoveVector Myvector; // 与移动相关的向量

    int atk, dfc, hp, Maxhp;// 攻击力, 防御力(骑士用), 血量, 血量上限
    int bfatk, bfmaxhp;

    double speed; // 速度
    double bfspeed;


    double rate;// 血量 / 血量上限(画血条用)

    int level, ep; // 等级, 经验

    Bullet bullets[BULLET_NUM]; // 子弹

    int recorder; // 子弹计时器

    double area, cd, keeptime; // 子弹: 伤害区域, 冷却时间, 持续时间
    double bfarea, bfcd, bfkeeptime;

    int get_money, bfget_money;

    int isknight; //是否为骑士(盾牌)

};




#endif // HERO_H
