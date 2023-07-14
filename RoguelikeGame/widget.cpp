#include "widget.h"
#include "ui_widget.h"

mainWidget::mainWidget(QWidget *parent) :
    QWidget(parent)
{
    recorder = 0;
    isalive = true;
    ishp = true;
    isep = true;
    ispower = true;
    islog = 1;

    //页面构建
    game = new playscene;
    start = new startscene;
    choose = new choosescene;
    store = new storescene;
    cheat = new cheatscene;
    help = new helpscene;
    pause = new pausescene;
    fail = new failscene;
    win = new winscene;
    level = new levelupscene;

    //启动信号
    start->show();
    loadsave();
    store->pass_on(money, goods1, goods2, goods3, goods4);
    loadintogame();

    //构造按钮信号与槽的联系
    connections();
}

mainWidget::~mainWidget()
{
    delete game;
    delete start;
    delete choose;
    delete help;
    delete cheat;
    delete pause;
    delete store;
    delete fail;
    delete win;
    delete level;
}

void mainWidget::do_save()
{
    QSettings setting("Parameter.ini", QSettings::IniFormat);

    setting.beginGroup("moneynum");
    setting.setValue("money", money);
    setting.endGroup();

    setting.beginGroup("goodsnum");
    setting.setValue("goods1", QString::number(goods1));
    setting.setValue("goods2", QString::number(goods2));
    setting.setValue("goods3", QString::number(goods3));
    setting.setValue("goods4", QString::number(goods4));
    setting.endGroup();
    setting.sync();
}

void mainWidget::loadsave()
{
    QSettings setting("Parameter.ini", QSettings::IniFormat);

    setting.beginGroup("moneynum");
    money = setting.value("money",0).toInt();
    setting.endGroup();

    setting.beginGroup("goodsnum");
    goods1 = setting.value("goods1",0).toInt();
    goods2 = setting.value("goods2",0).toInt();
    goods3 = setting.value("goods3",0).toInt();
    goods4 = setting.value("goods4",0).toInt();
    setting.endGroup();
}

void mainWidget::loadintogame()
{
    game->hero.bfmaxhp += goods2;
    game->hero.Maxhp = game->hero.bfmaxhp;
    game->hero.hp = game->hero.Maxhp;

    game->hero.bfatk += goods2;
    game->hero.atk = game->hero.bfatk;

    game->hero.bfspeed += goods2 / 2;
    game->hero.speed = game->hero.bfspeed;

    int ff = goods3;
    while(ff > 1){
        game->hero.bfcd *= 0.8;
        game->hero.bfkeeptime *= 1.1;
        game->hero.bfarea *= 1.1;
        ff-=2;
    }

    game->hero.cd = game->hero.bfcd;
    game->hero.keeptime = game->hero.bfkeeptime;
    game->hero.area = game->hero.bfarea;

    game->hero.bfget_money += goods4;
    game->hero.get_money = game->hero.bfget_money;

}

//按键--信号和槽的使用
void mainWidget::connections()
{
    //开始界面的link start按键
    connect(start->start, &QPushButton::clicked, this, [=](){
        game->timer.stop();
        game->totaltimer.stop();
        choose->show();
        start->close();
    });

    //开始界面的store按键
    connect(start->store, &QPushButton::clicked,this, [=](){
        store->show();
        start->close();
    });

    //开始界面的cheat按键
    connect(start->cheat, &QPushButton::clicked,this, [=](){
        cheat->show();
        start->close();
    });

    //开始界面的help按键
    connect(start->help, &QPushButton::clicked, this, [=](){
        help->show();
        start->close();
    });

    //choose界面的back按键
    connect(&(choose->back), &QPushButton::clicked, this, [=](){
        choose->close();
        start->show();        
    });

    //choose界面的choose1(巫师)按键
    connect(&choose->choose1, &QPushButton::clicked, this, [=](){
        game->pass_in(1);
        game->hero.LoadI(1);
        game->show();
        game->timer.start();
        game->totaltimer.start();
        this->choose->close();
        update();
        game->music();
    });

    //choose界面的choose2(骑士)按键
    connect(&choose->choose2, &QPushButton::clicked, this, [=](){
        game->pass_in(2);
        game->hero.LoadI(2);
        game->show();
        game->timer.start();
        game->totaltimer.start();
        this->choose->close();
        update();
        game->music();

    });

    //choose界面的choose3(屠夫)按键
    connect(&choose->choose3, &QPushButton::clicked, this, [=](){
        game->pass_in(3);
        game->hero.LoadI(3);
        game->show();
        game->timer.start();
        game->totaltimer.start();
        this->choose->close();
        update();
        game->music();

    });

    //play界面的计时器1
    connect(&game->timer, &QTimer::timeout, [=](){
        levelup();
        game->initialdetect();
        game->showupEnemy();
        game->collisiondetect();
        game->updateallposition();
        this->shoot();
        ggwhynot();
    });

    //play界面的计时器2
    connect(&game->totaltimer, &QTimer::timeout, [=](){
        if(game->hero.bullets[0].isthrough && game->hero.hp < game->hero.Maxhp){
            game->hero.hp += game->hero.level;
        }
      game->totaltime --;
      game->currentmoney += game->hero.get_money;
      if(game->totaltime == 120)  game->boss.isfree = false;
      if(game->totaltime <= 0 || game->boss.hp <= 0){
        F5();
        game->timer.stop();
        game->totaltimer.stop();
        game->close();
        win->show();
        store->pass_on(money, goods1, goods2, goods3, goods4);
      }
    });

    //play界面的back按键
    connect(&(game->back), &QPushButton::clicked, this, [=](){
        game->timer.stop();
        game->totaltimer.stop();
        pause->show();
        if(game->isplay){
            game->isplay = 0;
            game->player->stop();
        }
    });

    //play界面的音乐暂停按键
    connect(&(game->stopplaymusic), &QPushButton::clicked, this, [=](){
        if(game->isplay){
            game->isplay = 0;
            game->player->pause();
        }
        else {
            game->isplay = 1;
            game->player->play();
        }
    });

    //pause界面的back按键
    connect(&(pause->back), &QPushButton::clicked, this, [=](){
        game->close();
        pause->close();
        game->timer.stop();
        game->totaltimer.stop();
        start->show();
        if(game->isplay){
            game->isplay = 0;
            game->player->stop();
        }
    });

    //pause界面的继续按键
    connect(pause->btn, &QPushButton::clicked, this, [=](){
        game->timer.start();
        game->totaltimer.start();
        pause->close();
    });

    //fail界面的back按键
    connect(&(fail->back), &QPushButton::clicked, this, [=](){
        F5();
        isalive = true;
        game->close();
        fail->close();
        start->show();
        if(game->isplay){
            game->isplay = 0;
            game->player->stop();
        }
    });

    //fail界面的复活按键
    connect(fail->btn, &QPushButton::clicked, this, [=](){
        if(isalive && goods1 > 0){
            isalive = false;
            goods1 --;
            game->hero.reload();
            fail->close();
            game->timer.start();
            game->totaltimer.start();
            game->show();
        }
    });

    //store界面的back按键
    connect(&(store->back), &QPushButton::clicked, this, [=](){
        store->close();
        start->show();
    });

    //store界面的heart购买按键
    connect(&(store->buy_heart), &QPushButton::clicked, this, [=](){
        if(money >= PRICE){
            money -= PRICE;
            goods1 ++;
            store->pass_on(money, goods1, goods2, goods3, goods4);
            update();
            islog = 1;
        }
    });

    //store界面的hpadd购买按键
    connect(&(store->buy_hpadd), &QPushButton::clicked, this, [=](){
        if(money >= PRICE){
            money -= PRICE;
            goods2 ++;
            store->pass_on(money, goods1, goods2, goods3, goods4);
            update();
            islog = 1;
        }
    });

    //store界面的power购买按键
    connect(&(store->buy_power), &QPushButton::clicked, this, [=](){
        if(money >= PRICE){
            money -= PRICE;
            goods3 ++;
            store->pass_on(money, goods1, goods2, goods3, goods4);
            update();
            islog = 1;
        }
    });

    //store界面的epadd购买按键
    connect(&(store->buy_epadd), &QPushButton::clicked, this, [=](){
        if(money >= PRICE){
            money -= PRICE;
            goods4 ++;
            store->pass_on(money, goods1, goods2, goods3, goods4);
            update();
            islog = 1;
        }
    });

    //cheat界面的选择按键
    connect(&(cheat->btn_cheat), &QPushButton::clicked, this, [=](){
        isCheat = 1;
        cheat->gift.show();
        Cheat();
//        isCheat = 0;
        islog = 1;
    });

    //cheat界面的back按键
    connect(&(cheat->back), &QPushButton::clicked, this, [=](){
        cheat->close();
        start->show();
    });

    //help界面的back按键
    connect(&(help->back), &QPushButton::clicked, this, [=](){
        help->close();
        start->show();
    });

    //win界面的返回至主菜单
    connect(&(win->back), &QPushButton::clicked, this, [=](){
        win->close();
        start->show();
        if(game->isplay){
            game->isplay = 0;
            game->player->stop();
        }
    });
}

void mainWidget::connectioninlevel()
{
    //level界面升级确定按键
    connect(&level->btn[0], &QPushButton::clicked, this, [=](){
        game->hero.Maxhp *= 2;
        game->hero.hp = game->hero.Maxhp;
        game->hero.ep -= 100 + 200 * (game->hero.level - 1);
        game->hero.level ++;
        level->close();
        game->timer.start();
        game->totaltimer.start();
        for(int i=0;i<4;i++){
            game->hero.Myvector.StateofMoveKeys[i]=QString("unpressed");
        }
        game->hero.Myvector.toZeroVector();
    });

    connect(&level->btn[1], &QPushButton::clicked, this, [=](){
        game->hero.atk *= 2;
        game->hero.hp = game->hero.Maxhp;
        game->hero.ep -= 100 + 200 * (game->hero.level - 1);
        game->hero.level ++;
        level->close();
        game->timer.start();
        game->totaltimer.start();
        for(int i=0;i<4;i++){
            game->hero.Myvector.StateofMoveKeys[i]=QString("unpressed");
        }
        game->hero.Myvector.toZeroVector();
    });

    connect(&level->btn[2], &QPushButton::clicked, this, [=](){
        game->hero.speed += 2;
        game->hero.ep -= 100 + 200 * (game->hero.level - 1);
        game->hero.level ++;
        game->hero.hp = game->hero.Maxhp;
        level->close();
        game->timer.start();
        game->totaltimer.start();
        for(int i=0;i<4;i++){
            game->hero.Myvector.StateofMoveKeys[i]=QString("unpressed");
        }
        game->hero.Myvector.toZeroVector();
    });

    connect(&level->btn[3], &QPushButton::clicked, this, [=](){
        game->hero.cd *= 0.8;
        game->hero.ep -= 100 + 200 * (game->hero.level - 1);
        game->hero.level ++;
        game->hero.hp = game->hero.Maxhp;
        level->close();
        game->timer.start();
        game->totaltimer.start();
        for(int i=0;i<4;i++){
            game->hero.Myvector.StateofMoveKeys[i]=QString("unpressed");
        }
        game->hero.Myvector.toZeroVector();
    });

    connect(&level->btn[4], &QPushButton::clicked, this, [=](){
        game->hero.area *= 1.2;
        game->hero.ep -= 100 + 200 * (game->hero.level - 1);
        game->hero.level ++;
        game->hero.hp = game->hero.Maxhp;
        level->close();
        game->timer.start();
        game->totaltimer.start();
        for(int i=0;i<4;i++){
            game->hero.Myvector.StateofMoveKeys[i]=QString("unpressed");
        }
        game->hero.Myvector.toZeroVector();
    });

    connect(&level->btn[5], &QPushButton::clicked, this, [=](){
        game->hero.keeptime *= 1.2;
        game->hero.ep -= 100 + 200 * (game->hero.level - 1);
        game->hero.level ++;
        game->hero.hp = game->hero.Maxhp;
        level->close();
        game->timer.start();
        game->totaltimer.start();
        for(int i=0;i<4;i++){
            game->hero.Myvector.StateofMoveKeys[i]=QString("unpressed");
        }
        game->hero.Myvector.toZeroVector();
    });
}

void mainWidget::Cheat()
{
    if(isCheat){
    money += 9999;
    goods1 += 99;
    goods2 += 99;
    goods3 += 99;
    goods4 += 99;
    store->pass_on(money, goods1, goods2, goods3, goods4);
    do_save();
    update();
    }
    isCheat = 0;
}

void mainWidget::shoot()
{
    recorder ++;
    if(recorder){
      game->hero.shoot();
    }
    if(recorder % 4 == 0){
        for(int i = 0; i < ELITENEMY_NUM; i++){
            if(game->giantw[i].isfree){
                continue;
            }
            game->giantw[i].shoot();
        }
    }

    if(recorder % 2 == 0 && game->boss.isfree == false){
        game->boss.shoot();
    }

}

int mainWidget::levelup()
{
     if(game->hero.ep >= 100 + 200 * (game->hero.level - 1)){
        level = new levelupscene;
        connectioninlevel();
        game->hero.get_money = game->hero.level;
        game->timer.stop();
        game->totaltimer.stop();
        level->show();
     }
     return 0;
}

void mainWidget::ggwhynot()
{
    if(game->hero.hp <= 0 ){
        fail->show();
        game->timer.stop();
        game->totaltimer.stop();
        game->close();
        store->pass_on(money, goods1, goods2, goods3, goods4);
        do_save();

    }
}

void mainWidget::F5()
{
    game->sum = 0;
    game->start = 0;
    game->flash = 1;
    game->totaltime = HOLD_TIME;
    game->currentmoney = 0;
    game->barrio.reload();
    game->hero.reload();
    game->boss.reload();

    for(int i = 0; i < DROP_NUM; i++){
        game->drops[i].isfree = true;
    }

    for(int i = 0; i < NORMALENEMY_NUM; i++){
        game->ghost[i].reload();
    }
    for(int i = 0; i < ELITENEMY_NUM; i++){
        game->giantw[i].reload();
        game->giantf[i].reload();
    }
    game->boss.reload();
    game->recorderGhost = 0;
    game->recorderGiant = 0;
    update();
}

void mainWidget::closeEvent(QCloseEvent *)
{
    do_save();
}

