#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "basee.h"
#include "character.h"
#include <QKeyEvent>
#include <QMouseEvent>
#include <QCloseEvent>
#include <QTimer>
#include <QSettings>
#include "bullet.h"
#include "startscene.h"
#include "playscene.h"
#include "storescene.h"
#include "cheatscene.h"
#include "helpscene.h"
#include "choosescene.h"
#include "smallscene.h"

namespace Ui {
class mainWidget;
}

class mainWidget : public QWidget{
    Q_OBJECT

public:

    mainWidget(QWidget *parent = 0);
    ~mainWidget();

    void loadintogame();

    //按钮之间的联系
    void connections();
    void connectioninlevel();

    //作弊
    void Cheat();

    //射击
    void shoot();

    // 升级
    int levelup();

    int recorder;

    //判断死亡
    void ggwhynot();

    // 存档
    void do_save();
    void loadsave();

    //刷新
    void F5();

    //关闭
    void closeEvent(QCloseEvent *);

public:
    //界面
    startscene *start;
    choosescene *choose;
    playscene *game;
    storescene *store;
    cheatscene *cheat;
    helpscene * help;
    pausescene * pause;
    failscene * fail;
    levelupscene * level;
    winscene * win;

    //道具 + 金钱
    int goods1, goods2, goods3, goods4;
    int money;

    //标志
    int isCheat, islog;
    bool isalive, ishp, isep, ispower;

private:
    Ui::mainWidget *ui;
};

#endif // WIDGET_H
