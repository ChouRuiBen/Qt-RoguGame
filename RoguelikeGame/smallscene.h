#ifndef PAUSESCENE_H
#define PAUSESCENE_H

#include <scene.h>
#include <QTextEdit>
#include <QCloseEvent>
#include <QPaintEvent>

class pausescene: public scene
{
public:
    pausescene();
    QTextEdit * txt;
    Mypushbutton * btn;
    void closeEvent(QCloseEvent *e);

};

class failscene: public scene
{
public:
    failscene();
    QTextEdit * txt;
    Mypushbutton *btn;
};

class levelupscene: public scene
{
public:
    levelupscene();
    QTextEdit txt[6];
    Mypushbutton btn[6];
    void Load(int , int , int );
};

class winscene: public scene
{
public:
    winscene();
    //绘图事件重构
    void paintEvent(QPaintEvent *);
    QPixmap image;
};

#endif // PAUSESCENE_H
