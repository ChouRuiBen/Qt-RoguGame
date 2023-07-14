#include "topickup.h"

topickup::topickup()
{
    x = 0;
    y = 0;
    isfree = true;
}

void topickup::Load(int m, int n, int a)
{
    x = m;
    y = n;
    kind = a;
    rect.moveTo(x, y);
    isfree = false;
    switch (a) {
    case 0:
        image.load(":/weapons/coin.png");
        break;
    case 1:
        image.load(":/weapons/HP.png");
        break;
    case 2:
        image.load(":/weapons/EP.png");
        break;
    default:
        break;
    }
    rect.setWidth(image.width());
    rect.setHeight(image.height());
}
