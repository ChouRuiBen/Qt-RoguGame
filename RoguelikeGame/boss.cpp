#include "boss.h"

BOSS::BOSS()
{
    image.load(":/characters/bad_wizard_wool.png");

    rect.setWidth(image.width());
    rect.setHeight(image.height());

    atk = BOSS_ATK;

    Maxhp = BOSS_HP;
    hp = Maxhp;
    rate = 1;

    speed = BOSS_SPEED;

    isfree = true;

    bx = 0;
    by = 0;

    cx = rand() % (GAME_WIDTH - 500);
    cy = rand() % (GAME_HEIGHT - 200);

    for(int i = 0; i < BULLET_NUM; i++){
        bullets[i].t_image.load(":/weapons/bad_wizard_ball.png");
    }
}

void BOSS::shoot()
{
    recorder ++;
    if(recorder < BULLET_INTERVAL - 5){
        return ;
    }
    recorder = 0;
    for(int i = 0; i < BULLET_NUM * 2; i += 8){
       if(bullets[i].is_free){
           for(int j = 0; j < 8; j++){
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

void BOSS::reload()
{

    cx = rand() % (GAME_WIDTH - 500);
    cy = rand() % (GAME_HEIGHT - 200);

    atk = BOSS_ATK;

    hp = Maxhp;
    rate = 1;

    isfree = true;

    speed = BOSS_SPEED;

    for(int i = 0; i < BULLET_NUM; i++){
        bullets[i].is_free = true;
    }

    recorder = 0;
}
