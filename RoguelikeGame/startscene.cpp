#include "startscene.h"
startscene::startscene(): scene()
{
    setTitle();
    setStartButton();
    setStoreButton();
    setCheatButton();
    setHelpButton();
}
//游戏标题
void startscene::setTitle()
{
    Mypushbutton *label = new Mypushbutton;
    label->setText("Roguelike Game");
    label->move(GAME_WIDTH / 4 + 18, GAME_HEIGHT / 7);
    label->setStyleSheet("background: transparent; color: black; border-style: outset; font: bold 48px; font-family: 微软雅黑;");
    label->setFixedSize(700, 150);
    label->setParent(this);
}
//开始游戏->角色选择
void startscene::setStartButton()
{
    start = new Mypushbutton;
    start->move(GAME_WIDTH / 4, GAME_HEIGHT / 3);
    start->setFixedSize(300, 150);
    start->setStyleSheet("QPushButton{border-image: url(:/buttons/start.png)}");
    start->setParent(this);
}
//商店
void startscene::setStoreButton()
{
    store = new Mypushbutton;
    store->move(GAME_WIDTH / 2, GAME_HEIGHT / 3);
    store->setFixedSize(300, 150);
    store->setStyleSheet("QPushButton{border-image: url(:/buttons/shop.png)}");
    store->setParent(this);
}
//帮助
void startscene::setHelpButton()
{
    help = new Mypushbutton;
    help->move(GAME_WIDTH / 2, GAME_HEIGHT / 3 * 1.8);
    help->setFixedSize(300, 150);
    help->setStyleSheet("QPushButton{border-image: url(:/buttons/help.png)}");
    help->setParent(this);
}
//进阶(作弊)
void startscene::setCheatButton()
{
    cheat = new Mypushbutton;
    cheat->move(GAME_WIDTH / 4, GAME_HEIGHT / 3 * 1.8);
    cheat->setFixedSize(300, 150);
    cheat->setStyleSheet("QPushButton{border-image: url(:/buttons/cheat.png)}");
    cheat->setParent(this);
}
//绘图事件重构
void startscene::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawPixmap(0, 0, background);
}
