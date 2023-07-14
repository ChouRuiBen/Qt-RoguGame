#ifndef HELPSCENE_H
#define HELPSCENE_H

#include "scene.h"
#include <QTextEdit>
#include <QFile>
#include <QTextStream>
class helpscene: public scene
{
public:
    helpscene();
    //设置只读文本框
    void setTxt();
    //绘图事件重构
    void paintEvent(QPaintEvent *);
};

#endif // HELPSCENE_H
