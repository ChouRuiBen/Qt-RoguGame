#include "bullet.h"

Bullet::Bullet(){
    t_speed = BULLET_SPEED;
    is_free = true;
//    t_rect.setRect(0, 0, t_image.width() * area, t_image.height() * area);
}

void Bullet::load(QString str){
    t_image.load(str);
}
