#ifndef CHEATSCENE_H
#define CHEATSCENE_H

#include "scene.h"
#include <Mypushbutton.h>
#include <QTextEdit>
class cheatscene : public scene
{
public:
    int isCheat;
    cheatscene();
    //绘图事件重构
    void paintEvent(QPaintEvent *);
    QPushButton btn_cheat;
    QTextEdit txt_cheat, gift;
};

#endif // CHEATSCENE_H
