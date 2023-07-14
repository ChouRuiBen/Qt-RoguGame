#include "cheatscene.h"

cheatscene::cheatscene(): scene()
{
    backSet();

}

void cheatscene::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawPixmap(0, 0, background);
    //处理文本框
    txt_cheat.setParent(this);
    txt_cheat.setText("是否启动管理员模式?\n这样可能会使得游戏体验变shuang差bao\n");
    txt_cheat.setStyleSheet("background: transparent; color: black; border-style: inset; font: bold 30px; font-family: 微软雅黑; border: 3px black");
    txt_cheat.setFixedSize(600, 200);
    txt_cheat.move(GAME_WIDTH / 3 - 100, GAME_HEIGHT / 2  - 150);
    txt_cheat.show();

    gift.setText("你已经获得额外金币9999, 所有属性额外加成99");
    gift.setFixedSize(600, 200);
    gift.setStyleSheet("color: black; border-style: inset; font: bold 25px; font-family: 微软雅黑; border: 3px black");
    //处理按钮
    btn_cheat.setParent(this);
    btn_cheat.move(GAME_WIDTH / 3, GAME_HEIGHT / 2);
    btn_cheat.setFixedSize(300, 100);
    btn_cheat.setStyleSheet("QPushButton{border-image: url(:/buttons/choose.jpg)}");
    btn_cheat.show();
}
