#include "character.h"

Character::Character()
{
    cx = rand()%(GAME_WIDTH - 500);
    cy = rand()%(GAME_HEIGHT - 300);
    rect.setRect(cx, cy, 10, 10);
    rect.moveTo(cx, cy);

    dfc = 5;
    bfmaxhp = 100;
    Maxhp = 100;

    bfspeed = 15;
    speed = bfspeed;

    recorder = 0;

    level = 1;
    rate = 1;
    ep = 0;

    bfcd = 1;
    cd = bfcd;

    bfarea = 1;
    area = bfarea;

    bfkeeptime = 1;
    keeptime = bfkeeptime;

    bfatk = 0;
    atk = bfatk;

    bfget_money = 0;
    get_money += level;
    get_money = bfget_money;

    pick.setRect(cx, cy, 10, 10);

    up.load(":/weapons/pawn_up.png");

//    qDebug () << rect.width();
//    qDebug() <<  rect.height();
//    qDebug () << rect.left();
//    qDebug () << rect.right();

}

void Character::reload()
{
    cx = rand()%(GAME_WIDTH - 500);
    cy = rand()%(GAME_HEIGHT - 300);
    rect.setRect(cx, cy, 10, 10);
    rect.moveTo(cx, cy);

    Maxhp  = bfmaxhp;
    hp = Maxhp;

    speed = bfspeed;

    atk = bfatk;

    cd = bfcd;

    keeptime = bfkeeptime;

    get_money = bfget_money;

    area = bfarea;

    recorder = 0;

    level = 1;
    rate = 1;
    ep = 0;

    for(int i = 0; i < BULLET_NUM; i++){
        bullets[i].is_free = true;
    }

    for(int i=0;i<4;i++){
        Myvector.StateofMoveKeys[i]=QString("unpressed");
    }
    Myvector.toZeroVector();
}

void Character::LoadI(int num)
{
    switch (num) {
    case 1:{ //巫师
        image.load(":/characters/wizard_wool2.png");
        atk += 10;
        isknight = 0;        
    }
        break;
    case 2:{ //骑士
        atk += 8;
        isknight = 1;
        image.load(":/characters/knight_sword2.png");
        isknight = 1;
    }
        break;
    case 3:{ //屠夫
        Maxhp += 20;
        //hp += 10;
        atk += 12;
        image.load(":/characters/berserker_axe2.png");
        isknight = 0;
     }
        break;
    default:
        break;
    }
}

void Character::setPosition()
{
    Myvector.GenerateVector();
    double deltax = Myvector.Vx * speed * 10000.00 / 50000.00;
    double deltay = Myvector.Vy * speed * 10000.00 / 50000.00;
    bfx = cx;
    bfy = cy;
    cx += deltax;
    cy += deltay;
}

void Character::loadBullet(int a)
{
    switch (a) {
    case 1:{ //巫师的子弹加载
        for(int i = 0; i < BULLET_NUM; i++){
            if(i % 2 == 0){
                bullets[i].load(":/weapons/good_wizard_ball_1.png"); //暴击子弹
                bullets[i].isextra = 1;
            }
            else{
                bullets[i].load(":/weapons/good_wizard_ball_2.png");  //减速子弹
                bullets[i].islow = 1;
            }
        }
    }
        break;
    case 2:{ //骑士的子弹加载
        for(int i = 0; i < BULLET_NUM; i++){
           bullets[i].load(":/weapons/sword_2.png");  //剑
        }
    }
        break;
    case 3:{//屠夫的子弹加载
        for(int i = 0; i < BULLET_NUM; i++){
           bullets[i].load(":/weapons/axe_2.png");  //斧头
           bullets[i].isthrough = 1; // 设置为穿透子弹
        }
    }
        break;
    default:
        break;
    }
}

void Character::shoot()
{
    recorder ++;
    if(recorder < BULLET_INTERVAL * cd ){ // bullets[0].cd
         return ;
     }
    else {
         recorder = 0;
         for(int i = 0; i < BULLET_NUM; i += 8){
            if(bullets[i].is_free){
                for(int j = 0; j < 8; j++){
                    bullets[i + j].num = j;
                    bullets[i + j].is_free = false;
                    bullets[i + j].t_x = cx;
                    bullets[i + j].t_y = cy;
                    bullets[i + j].t_rect.setRect(bullets[i + j].t_x, bullets[i + j].t_y, bullets[i + j].t_image.width() * area, bullets[i + j].t_image.height() * area);
                    }
                break;
                }

            }
    }
}

void Character::pickup()
{

}
