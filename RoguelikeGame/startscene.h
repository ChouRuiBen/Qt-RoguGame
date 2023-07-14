#ifndef STARTSCENE_H
#define STARTSCENE_H

#include "scene.h"

class startscene: public scene
{
public:
    startscene();
    //实现标题
    void setTitle();
    //实现开始按钮
    void setStartButton();
    //实现商店按钮
    void setStoreButton();
    //实现帮助按钮
    void setHelpButton();
    //实现作弊按钮
    void setCheatButton();
    //绘图事件重构
    void paintEvent(QPaintEvent *);

    Mypushbutton *start, *store, *help, *cheat;
};

#endif // STARTSCENE_H
