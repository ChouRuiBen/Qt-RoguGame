#include "choosescene.h"

choosescene::choosescene() : scene()
{
    //法师, 骑士, 屠夫图片
    hero1.load(":/characters/wizard_wool2.png");
    hero2.load(":/characters/knight_sword2.png");
    hero3.load(":/characters/berserker_axe2.png");
    //选择按钮
    setChooseButton(&choose1);
    setChooseButton(&choose2);
    setChooseButton(&choose3);
    //法师, 骑士, 屠夫文字
    setText(&text1);
    text1.setText("法师\n可以发射两种法术球(减速/1.5倍伤害)\nHP: 100\natk: 10\n");
    setText(&text2);
    text2.setText("骑士\n可以投掷自己的大剑, 同时拥有一块盾牌能免疫伤害\nHP: 100\natk: 8\ndfc: 5");
    setText(&text3);
    text3.setText("屠夫\n可以投掷自己的斧头, 并且每秒钟回复少量生命值\nHP: 120\natk: 12\n");
    backSet();
}

void choosescene::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    //绘制角色图标
    painter.drawPixmap(0, 0, background);
    painter.drawPixmap(GAME_WIDTH / 4 - 100, GAME_HEIGHT / 4, hero1);
    painter.drawPixmap(GAME_WIDTH / 4 * 2 - 100, GAME_HEIGHT / 4, hero2);
    painter.drawPixmap(GAME_WIDTH / 4 * 3 - 100, GAME_HEIGHT / 4, hero3);

    //绘制文本框
    text1.move(GAME_WIDTH / 4 - 100, GAME_HEIGHT / 4 + 100);
    text1.show();
    text2.move(GAME_WIDTH / 4 * 2 - 100, GAME_HEIGHT / 4 + 100);
    text2.show();
    text3.move(GAME_WIDTH / 4 * 3 - 100, GAME_HEIGHT / 4 + 100);
    text3.show();

    //绘制按钮
    choose1.move(GAME_WIDTH / 4 - 100, GAME_HEIGHT / 4 + 410);
    choose1.show();
    choose2.move(GAME_WIDTH / 4 * 2 - 100, GAME_HEIGHT / 4 + 410);
    choose2.show();
    choose3.move(GAME_WIDTH / 4 * 3- 100, GAME_HEIGHT / 4 + 410);
    choose3.show();
}

void choosescene::setChooseButton(QPushButton *button)
{
    button->setParent(this);
    button->setFixedSize(200, 100);
    button->setStyleSheet("QPushButton{border-image: url(:/buttons/choose.jpg)}");
}

void choosescene::setText(QTextEdit * txt)
{
    txt->setReadOnly(true);
    txt->setParent(this);
    txt->setFixedSize(300, 300);
    txt->setStyleSheet("background: transparent; color: black; border-style: outset; font: bold 30px; font-family: 微软雅黑;");
}
