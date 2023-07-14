#ifndef PLAYSCENE_H
#define PLAYSCENE_H

#include "scene.h"
#include <QTimer>
#include <QBrush>
#include <QTextEdit>
#include <QKeyEvent>
#include <Mypushbutton.h>
#include <character.h>
#include <normalenemy.h>
#include <elitenemy1.h>
#include <elitenemy2.h>
#include <boss.h>
#include <topickup.h>
#include <QMatrix>
#include <QMediaPlayer>

class Barrio{
public:
    Barrio();
    void reload();
    QPixmap image;
    QRect rect;
    int bx, by;
};

class playscene :public scene
{
public:
    playscene();
    void pass_in(int );//外界参数传入
    //初始化检测
    void initialdetect();
    //绘图事件重构
    void paintEvent(QPaintEvent *);

    //键盘事件重构
    void keyPressEvent(QKeyEvent *);
    void keyReleaseEvent(QKeyEvent *event);
    //判断角色和子弹是否正确
    void judge_movement();
    //子弹位置更新
    void updateBullets();
    //怪物刷新
    void showupEnemy();
    //怪物位置更新
    void updateMonsters();
    //碰撞检测
    void collisiondetect();
    //位置更新
    void updateallposition();
    //音乐
    void music();
    //画掉落物
    topickup drops[DROP_NUM];

    Barrio barrio; //障碍物

    Character hero; //角色

    //怪物
    BOSS boss;

    Normalenemy ghost[NORMALENEMY_NUM];

    elitenemy1 giantw[ELITENEMY_NUM];

    elitenemy2 giantf[ELITENEMY_NUM];

    //传入角色构造的参数(选择角色)
    int whichCharacter;

    QTimer timer, totaltimer;//计时器

    int totaltime;

    int recorderGhost, recorderGiant;//记录ghost 和giant 的出现

    int sum, recorderbullet; // 怪物或者怪物子弹的角色接触时长 + 子弹和boss相接触时间

    //int recorderboss; //BOSS移动计时器

    int start;//初始检测中清零sum 和 recorderbullet的标志

    int flash;//初始检测的标志

    int currentmoney;

    Mypushbutton stopplaymusic;
    QMediaPlayer *player;
    int isplay;

};

#endif // PLAYSCENE_H
