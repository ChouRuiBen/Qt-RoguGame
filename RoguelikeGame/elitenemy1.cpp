#include "elitenemy1.h"

elitenemy1::elitenemy1()
{
    image.load(":/characters/gaint_wool.png");

    rect.setWidth(image.width());
    rect.setHeight(image.height());

    atk = GIANT_ATK;

    Maxhp = GIANT_HP;
    hp = Maxhp;
    rate = 1;
    ep = GIANT_EP;

    speed = GIANT_SPEED;

    isfree = true;

    for(int i = 0; i < BULLET_NUM; i++){
        bullets[i].t_image.load(":/weapons/giant_ball.png");
    }

    recorder = 0;
}

void elitenemy1::reload()
{
    atk = GIANT_ATK;

    hp = Maxhp;

    rate = 1;

    speed = GIANT_SPEED;

    isfree = true;

    for(int i = 0; i < BULLET_NUM; i++){
        bullets[i].is_free = true;
    }

    recorder = 0;
}

void elitenemy1::shoot()
{
    recorder ++;
    if(recorder < BULLET_INTERVAL){
        return ;
    }
    recorder = 0;
    for(int i = 0; i < BULLET_NUM; i += 4){
       if(bullets[i].is_free){
           for(int j = 0; j < 4; j++){
               bullets[i + j].num = j;
               bullets[i + j].is_free = false;
               bullets[i + j].t_x = cx;
               bullets[i + j].t_y = cy;
               bullets[i + j].t_rect.moveTo(bullets[i + j].t_x, bullets[i + j].t_y);
               }
           break;
           }

       }
}
