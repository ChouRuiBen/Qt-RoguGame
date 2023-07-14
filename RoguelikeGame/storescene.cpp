#include "storescene.h"

storescene::storescene(): scene()
{
    //设置返回键
    backSet();
    //加载图片
    loadPixmap();
    //初始化文本框
    setTxt(&txt_heart);
    setTxt(&txt_hpadd);
    setTxt(&txt_power);
    setTxt(&txt_epadd);
    setTxt(&txt_salary);
    setTxt(&txt_func);
    //初始化按钮
    setButton(&buy_heart);
    setButton(&buy_hpadd);
    setButton(&buy_power);
    setButton(&buy_epadd);

}
//绘图事件重载
void storescene::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawPixmap(0, 0, background);
    //画道具
    painter.drawPixmap(GAME_WIDTH / 5 * 3 - 100, GAME_HEIGHT / 30 + 10, heart2);
    painter.drawPixmap(GAME_WIDTH / 5 * 3 - 20, GAME_HEIGHT / 30 + 10, hp2);
    painter.drawPixmap(GAME_WIDTH / 5 * 3 + 60, GAME_HEIGHT / 30 + 10, power2);
    painter.drawPixmap(GAME_WIDTH / 5 * 3 + 140, GAME_HEIGHT / 30 + 10, ep2);
    painter.drawPixmap(GAME_WIDTH / 5 * 3 - 200, GAME_HEIGHT / 30 + 10, money_);
    //画已有道具和钱
    painter.drawPixmap(GAME_WIDTH / 5 - 100, GAME_HEIGHT / 4 + 10, heart1);
    painter.drawPixmap(GAME_WIDTH / 5 * 2 - 100, GAME_HEIGHT / 4, hp1);
    painter.drawPixmap(GAME_WIDTH / 5 * 3 - 100, GAME_HEIGHT / 4, power1);
    painter.drawPixmap(GAME_WIDTH / 5 * 4 - 100, GAME_HEIGHT / 4, ep1);
    //道具介绍文本
    txt_heart.setText("增加一次复活机会\n价格: 1000\n(一局最多复活一次)\n(下局生效)");
    txt_heart.move(GAME_WIDTH / 5 - 100, GAME_HEIGHT / 4 + 150);
    txt_hpadd.setText("提升角色基础属性\n价格: 1000\n\n(下局生效)");
    txt_hpadd.move(GAME_WIDTH / 5 * 2 - 100, GAME_HEIGHT / 4 + 150);
    txt_power.setText("提升武器属性\n价格: 1000\n\n(下局生效)");
    txt_power.move(GAME_WIDTH / 5 * 3 - 100, GAME_HEIGHT / 4 + 150);
    txt_epadd.setText("提升金币获取系数\n价格: 1000\n\n(下局生效)");
    txt_epadd.move(GAME_WIDTH / 5 * 4 - 100, GAME_HEIGHT / 4 + 150);
    //已有道具和钱文本
    txt_salary.setText(salary);
    txt_salary.move(GAME_WIDTH / 5 * 3 - 180, GAME_HEIGHT / 30 + 60);
    txt_func.setText(func);
    txt_func.move(GAME_WIDTH / 5 * 3 - 100, GAME_HEIGHT / 30 + 60);
    //购买按钮
    buy_heart.move(GAME_WIDTH / 5 - 100, GAME_HEIGHT / 4 + 330);
    buy_heart.show();
    buy_hpadd.move(GAME_WIDTH / 5 * 2 - 100, GAME_HEIGHT / 4 + 330);
    buy_hpadd.show();
    buy_power.move(GAME_WIDTH / 5 * 3 - 100, GAME_HEIGHT / 4 + 330);
    buy_power.show();
    buy_epadd.move(GAME_WIDTH / 5 * 4 - 100, GAME_HEIGHT / 4 + 330);
    buy_epadd.show();
}
//按钮初始化
void storescene::setButton(QPushButton * button)
{
    button->setParent(this);
    button->setFixedSize(200, 100);
    button->setStyleSheet("QPushButton{border-image: url(:/buttons/choose.jpg)}");
}
//文本框初始化
void storescene::setTxt(QTextEdit * txt)
{
    txt->setReadOnly(true);
    txt->setParent(this);
    txt->setFixedSize(400, 300);
    txt->setStyleSheet("background: transparent; color: black; border-style: outset; font: bold 30px; font-family: 微软雅黑;");
}
//图片加载
void storescene::loadPixmap()
{
    heart1.load(":/weapons/heart.png");
    heart2.load(":/weapons/heart_.png");
    hp1.load(":/weapons/HPadd.png");
    hp2.load(":/weapons/HPadd_.png");
    power1.load(":/weapons/power.png");
    power2.load(":/weapons/power_.png");
    ep1.load(":/weapons/EPadd.png");
    ep2.load(":/weapons/EPadd_.png");
    money_.load(":/weapons/money_.png");
}
//全局参数传入
void storescene::pass_on(int a, int b, int c, int d, int e)
{
    money = a;
    heart = b;
    hpadd = c;
    power = d;
    epadd = e;
    salary = QString::number(a);
    func = "      " + QString::number(b) + "    " + QString::number(c) + "    "  + QString::number(d) + "    " + QString::number(e);
}
