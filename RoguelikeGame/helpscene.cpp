#include "helpscene.h"

helpscene::helpscene(): scene()
{
    setTxt();
    backSet();
}

void helpscene::setTxt()
{
    QTextEdit *text = new QTextEdit(this);
    text->setPlainText("                     关于本作   \n"
                       "欢迎游玩周锐奔自主开发的Roguelike(肉鸽类)游戏\n"
                       "基本操作: 使用键盘ＷＡＳＤ进行上下左右移动躲避子弹和攻击敌人\n"
                       "获胜条件: 坚持180s或者打败BOSS\n"
                       "如果出现BOSS和障碍物重叠建议重开(概率很小就是了)\n"
                       "实现了: \n"
                       "三个可游玩角色, 4种怪物(BOSS, 近战+远程精英怪, 普通敌人),\n"
                       "局内和全局强化, 自动存档, 掉落物\n"
                       "Extension: "
                       "受伤效果(血条 + 左上角数值显示), 远程攻击显示\n"
                       "又加上最近在听Queen所以就把'败者食尘'做成了背景音乐(如侵删)\n"
                       "\n联系作者: QQ:1270075908(验证问题为本名, 不备注姓名不会加 -_- )\n"
                       "制作不易, 感谢游玩");
    text->setReadOnly(true);
    text->setFixedSize(1400, 1000);
    text->setStyleSheet("background: transparent; color: white; border-style: outset; font: bold 36px; font-family: 楷体;");
    text->move(300, 100);
    text->show();
}

void helpscene::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawPixmap(0, 0, background);
}
