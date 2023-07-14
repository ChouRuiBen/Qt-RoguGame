#include "scene.h"

scene::scene()
{
    //设置窗口尺寸
    this->setFixedSize(GAME_WIDTH, GAME_HEIGHT);

    //设置窗口图标
    this->setWindowIcon(QIcon(":/weapons/eve.png"));

    //设置窗口名字
    this->setWindowTitle(GAME_TiTLE);

    //设置窗口背景
    background.load(GAME_BACKGROUND);
}


//返回键初始化
void scene::backSet()
{
    back.setParent(this);
    back.move(GAME_WIDTH - 250, GAME_HEIGHT - 150);
    back.setFixedSize(200, 80);
    back.setStyleSheet("QPushButton{border-image: url(:/buttons/back.png)}");
}
