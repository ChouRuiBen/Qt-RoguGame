#ifndef STORESCENE_H
#define STORESCENE_H

#include "scene.h"
#include <QTextEdit>
#include "Mypushbutton.h"
#include <QString>
class storescene : public scene
{
public:
    storescene();
    //绘图事件重构
    void paintEvent(QPaintEvent *);
    //按钮的初始化
    void setButton(QPushButton *);
    //文本框的初始化
    void setTxt(QTextEdit *);
    //图片集中加载
    void loadPixmap();
    //把全局参数传入, 方便购买
    void pass_on(int , int , int , int , int);
    //按钮
    QPushButton buy_heart , buy_hpadd, buy_power, buy_epadd;
    //图片
    QPixmap heart1, heart2, hp1, hp2, ep1, ep2, power1, power2, money_;
    //文本框
    QTextEdit txt_heart, txt_hpadd, txt_power, txt_epadd, txt_salary, txt_func;
    //参数
    int money, heart, hpadd, power, epadd;
    //把参数转换成QString类型, 方便输出
    QString salary, func;
};

#endif // STORESCENE_H
