#ifndef BULLET_H
#define BULLET_H

#include <basee.h>

class Bullet
{
public:
    Bullet();
    void load(QString );

    int t_x, t_y;

    int t_speed;

    int is_free;

    QRect t_rect;

    QPixmap t_image;

    int isthrough; // 是否为屠夫的穿透子弹

    int islow, isextra; // 是否为法师的减速或者暴击子弹

    int num; // 序号

};

#endif // BULLET_H
