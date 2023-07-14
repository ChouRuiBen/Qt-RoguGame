#include "normalenemy.h"

Normalenemy::Normalenemy()
{
    image.load(":/characters/ghost.png");

    rect.setWidth(image.width());
    rect.setHeight(image.height());

    atk = GHOST_ATK;

    Maxhp = GHOST_HP;
    hp = Maxhp;
    rate = 1;
    ep = GHOST_EP;

    speed = GHOST_SPEED;

    isfree = true;

    wayx = 1;
    wayy = 1;
}

void Normalenemy::reload()
{
    atk = 5;

    hp = Maxhp;
    rate = 1;

    speed = 4;

    isfree = true;

    wayx = 1;
    wayy = 1;
}
