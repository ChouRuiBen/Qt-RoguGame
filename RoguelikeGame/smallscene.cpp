#include "smallscene.h"

pausescene::pausescene():scene()
{
    this->setFixedSize(800, 500);
    this->setStyleSheet("background-color: rgb(255, 178, 102)");
    //对返回键的修改
    backSet();
    back.move(500, 300);
    //文本框
    txt = new QTextEdit(this);
    txt->setStyleSheet("background: transparent; color: black; border-style: inset; font: bold 40px; font-family: 微软雅黑;");
    txt->setText("游戏已经暂停");
    txt->setReadOnly(true);
    txt->setFixedSize(400, 100);
    txt->move(270, 150);
    //继续游玩按钮
    btn = new Mypushbutton;
    btn->setParent(this);
    btn->setFixedSize(200, 80);
    btn->setText("继续游玩");
    btn->move(100, 300);
    btn->setStyleSheet("background-color: rgb(102, 255, 102); color: black; border-style: inset; font: bold 25px; font-family: 微软雅黑");
}

void pausescene::closeEvent(QCloseEvent *e)
{
    emit(btn->QPushButton::clicked());
}

failscene::failscene()
{
    this->setFixedSize(800, 500);
    this->setStyleSheet("background-color: rgb(255, 178, 102)");
    //对返回键的修改
    backSet();
    back.move(500, 300);
    //文本框
    txt = new QTextEdit(this);
    txt->setStyleSheet("background: transparent; color: black; border-style: inset; font: bold 40px; font-family: 微软雅黑;");
    txt->setText("游戏结束了呜呜呜");
    txt->setReadOnly(true);
    txt->setFixedSize(400, 100);
    txt->move(230, 150);
    //继续游玩按钮
    btn = new Mypushbutton;
    btn->setParent(this);
    btn->setFixedSize(200, 80);
    btn->setText("复活");
    btn->move(100, 300);
    btn->setStyleSheet("background-color: rgb(102, 255, 102); color: black; border-style: inset; font: bold 25px; font-family: 微软雅黑");
}

levelupscene::levelupscene() : scene()
{
    this->setFixedSize(900, 500);
    this->setStyleSheet("background-color: rgb(255, 178, 102)");
    backSet();
    back.setText("返回主菜单");

    for(int i = 0; i < 6; i++){
        txt[i].setReadOnly(true);
        txt[i].setStyleSheet("background: transparent; color: black; border-style: inset; font: bold 25px; font-family: 微软雅黑;");
        txt[i].setFixedSize(300, 100);
        switch (i) {
        case 0:{
            txt[0].setText("角色生命值翻倍\n");
        }
            break;
        case 1:{
            txt[1].setText("角色攻击力翻倍\n");
        }
            break;
        case 2:{
            txt[2].setText("角色移动速度+2\n");
        }
            break;
        case 3:{
            txt[3].setText("子弹发射间隔缩短\n");
        }
            break;
        case 4:{
            txt[4].setText("子弹攻击范围扩大\n");
        }
            break;
        case 5:{
            txt[5].setText("子弹作用延迟缩短\n");
        }
            break;
        default:
            break;
        }
    }
    for(int i = 0; i < 6; i++){
        btn[i].setFixedSize(200, 80);
        btn[i].setStyleSheet("QPushButton{border-image: url(:/buttons/choose.jpg)}");
    }
    int i1 = rand() % 6, i2 = rand() % 6, i3 = rand() % 6;
    while(i2 == i1){
        i2 = rand() % 6;
    }
    while(i3 == i2 || i3 == i1){
        i3 = rand() % 6;
    }
    Load(i1, i2, i3);
}

void levelupscene::Load(int i1, int i2, int i3)
{
    txt[i1].setParent(this);
    btn[i1].setParent(this);
    txt[i1].move(10, 150);
    txt[i1].show();
    btn[i1].move(10, 250);

    txt[i2].setParent(this);
    btn[i2].setParent(this);
    txt[i2].move(340, 150);
    txt[i2].show();
    btn[i2].move(340, 250);

    txt[i3].setParent(this);
    btn[i3].setParent(this);
    txt[i3].move(680, 150);
    txt[i3].show();
    btn[i3].move(680, 250);
}

winscene::winscene() : scene()
{
    this->setFixedSize(800, 500);
    this->setStyleSheet("background-color: rgb(255, 178, 102)");
    backSet();
    back.move(550, 350);
    image.load(":/scenes/smile.png");
}

void winscene::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawPixmap(10, 10, image);
    painter.setPen(QColor(Qt::white));
    painter.setFont(QFont("微软雅黑", 50, QFont::Bold));
    painter.drawText(QRectF(500, 100, 300, 200), "Win!");
}
