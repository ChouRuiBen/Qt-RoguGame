#include "elitenemy2.h"

elitenemy2::elitenemy2()
{
    image.load(":/characters/gaint_axe.png");

    rect.setWidth(image.width());
    rect.setHeight(image.height());

    atk = GIANT_ATK;

    Maxhp = GIANT_HP;
    hp = Maxhp;
    rate = 1;
    ep = GIANT_EP;

    speed = 2 * GIANT_SPEED;

    isfree = true;
}

void elitenemy2::reload()
{
    atk = GIANT_ATK;

    hp = Maxhp;
    rate = 1;

    speed = 2 * GIANT_SPEED;

    isfree = true;
}
