#include "playscene.h"

playscene::playscene(): scene()
{
    backSet();
    timer.setInterval(GAME_HZ);
    totaltimer.setInterval(100 * GAME_HZ);
    sum = 0;
    start = 1;
    flash = 1;
    recorderbullet = 0;
    recorderGhost = 0;
    recorderGiant = 0;

    currentmoney = 0;

    totaltime = HOLD_TIME;

    stopplaymusic.setFixedSize(80, 80);
    stopplaymusic.setStyleSheet("QPushButton{border-image: url(:/buttons/music.png)}");
    stopplaymusic.setParent(this);
    stopplaymusic.move(1470, 20);
    stopplaymusic.show();
}

Barrio::Barrio()
{
    image.load(LOCATION_BARRIO);
    bx = rand()%(GAME_WIDTH - 600) + 110;
    by = rand()%(GAME_HEIGHT - 400) + 95;
    rect.setRect(bx, by, BARRIO_WIDTH, BARRIO_HEIGHT);
}

void Barrio::reload()
{
    bx = rand()%(GAME_WIDTH - 600) + 110;
    by = rand()%(GAME_HEIGHT - 400) + 95;
    rect.setRect(bx, by, BARRIO_WIDTH, BARRIO_HEIGHT);
}

void playscene::pass_in(int outside_character)
{
    whichCharacter = outside_character;
}

void playscene::initialdetect()
{
    if(start == 0){
        sum = 0;
        recorderbullet = 0;
        start = 1;
    }

    while (hero.rect.intersects(barrio.rect)) {
        hero.cx = rand()%(GAME_WIDTH - 500);
        hero.cy = rand()%(GAME_HEIGHT - 300);
        hero.rect.moveTo(hero.cx, hero.cy);
    }

    if(flash){
        while(boss.rect.intersects(barrio.rect)){
            boss.cx = rand() % (GAME_WIDTH - 500);
            boss.cy = rand()%(GAME_HEIGHT - 200);
            boss.rect.moveTo(boss.cx, boss.cy);
        }

        while(boss.rect.intersects(hero.rect)){
            boss.cx = rand() % (GAME_WIDTH - 500);
            boss.cy = rand()%(GAME_HEIGHT - 200);
            boss.rect.moveTo(boss.cx, boss.cy);
        }

        flash = 0;
    }

}

void playscene::paintEvent(QPaintEvent *)
{
    QBrush red_brush( QColor("#F20900"));
    QPainter painter(this);
    //背景
    painter.drawPixmap(0, 0, background);
    //障碍
    painter.drawPixmap(barrio.bx, barrio.by, barrio.image);
    //角色
    painter.drawPixmap(hero.cx, hero.cy, hero.image);
    //角色血条
    painter.setBrush(QColor("#33FF33"));
    hero.rate = 1.0 * hero.hp / hero.Maxhp;
    painter.drawRect(hero.cx, hero.cy - 5, hero.rate * 100, hero.image.height()*0.15);
    painter.setBrush(red_brush);


  //子弹
    //hero
    hero.loadBullet(whichCharacter);
    QPainter bulletpainter(this);
    for(int i = 0; i < BULLET_NUM; i++){
        if(hero.bullets[i].is_free){
            continue;
        }
        QMatrix matrix;
        matrix.rotate(45 *  (8 - hero.bullets[i].num));
        hero.bullets[i].t_image = hero.bullets[i].t_image.transformed(matrix, Qt::SmoothTransformation);
        bulletpainter.drawPixmap(hero.bullets[i].t_x, hero.bullets[i].t_y, hero.bullets[i].t_image);
 //       bulletpainter.rotate(hero.bullets[i].num * 45);
    }

    //giantw
    for(int k = 0; k < ELITENEMY_NUM; k ++){
        if(giantw[k].isfree){
            continue;
        }
        for(int i = 0; i < BULLET_NUM; i++){
            if(giantw[k].bullets[i].is_free){
                continue;
            }
            bulletpainter.drawPixmap(giantw[k].bullets[i].t_x, giantw[k].bullets[i].t_y, giantw[k].bullets[i].t_image);
        }
    }

    //boss
    if(!boss.isfree){
        for(int i = 0; i < BULLET_NUM; i++){
            if(boss.bullets[i].is_free){
                continue;
            }
            bulletpainter.drawPixmap(boss.bullets[i].t_x, boss.bullets[i].t_y, boss.bullets[i].t_image);
        }
    }

  //enemy
    QPainter enemypainter(this);
    //ghost
    for(int i = 0; i < NORMALENEMY_NUM; i++){
        if(ghost[i].isfree){
            continue;
        }
        enemypainter.drawPixmap(ghost[i].cx, ghost[i].cy, ghost[i].image);
        enemypainter.setBrush(red_brush);
        ghost[i].rate = 1.0 * ghost[i].hp / ghost[i].Maxhp;
        enemypainter.drawRect(ghost[i].cx, ghost[i].cy - 8, ghost[i].rate*ghost[i].image.width(), ghost[i].image.height()*0.15);

    }

    //giantf
    for(int i = 0; i < ELITENEMY_NUM; i++){
        if(giantf[i].isfree){
            continue;
        }
        enemypainter.drawPixmap(giantf[i].cx, giantf[i].cy, giantf[i].image);
        enemypainter.setBrush(red_brush);
        giantf[i].rate = 1.0 * giantf[i].hp / giantf[i].Maxhp;
        enemypainter.drawRect(giantf[i].cx - 10, giantf[i].cy - 5, giantf[i].rate*giantf[i].image.width(), giantf[i].image.height()*0.15);
    }

    //giantw
    for(int i = 0; i < ELITENEMY_NUM; i++){
        if(giantw[i].isfree){
            continue;
        }
        enemypainter.drawPixmap(giantw[i].cx, giantw[i].cy, giantw[i].image);
        enemypainter.setBrush(red_brush);
        giantw[i].rate = 1.0 * giantw[i].hp / giantw[i].Maxhp;
        enemypainter.drawRect(giantw[i].cx - 10, giantw[i].cy - 5, giantw[i].rate*giantw[i].image.width(), giantw[i].image.height()*0.15);
    }

    // boss
    if(!boss.isfree){
        enemypainter.drawPixmap(boss.cx, boss.cy, boss.image);
        enemypainter.setBrush(red_brush);
        boss.rate = 1.0 * boss.hp / boss.Maxhp;
        enemypainter.drawRect(boss.cx, boss.cy - 5, boss.rate * 150, boss.image.height()*0.1);
    }
    //掉落物
    for(int i = 0; i < DROP_NUM; i++){
        if(drops[i].isfree){
            continue;
        }
        enemypainter.drawPixmap(drops[i].x, drops[i].y, drops[i].image);
    }

    //左上角: 倒计时 + 角色属性 + BOSS血量
    QString bottomleft, time;
    time = "倒计时: " + QString::number(totaltime);
    bottomleft = "\nLevel: " + QString::number(hero.level) + "\nEP: " + QString::number(hero.ep) + "/" + QString::number(200 * hero.level - 100) + "\nHP: " + QString::number(hero.hp) + "/" + QString::number(hero.Maxhp) + "\nRank:" + QString::number(currentmoney) +  "\nBOSS's HP: " + QString::number(boss.hp);
    // bottomleft += "\nSpeed: " + QString::number(hero.speed) + "\nATK: " + QString::number(hero.atk)
    QPainter datapainter(this);
    datapainter.setPen(QColor(Qt::white));
    datapainter.setFont(QFont("楷体", 25, QFont::Bold));
    datapainter.drawText(QRectF(35, 10, 600, 80), time);
    datapainter.setFont(QFont("楷体", 15, QFont::Bold));
    datapainter.drawText(QRectF(40, 30, 300, 400), bottomleft);
}

void playscene::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_A)
        {
            this->hero.Myvector.StateofMoveKeys[0] = QString("pressed");
        }
        if(event->key() == Qt::Key_W)
        {
            this->hero.Myvector.StateofMoveKeys[1] = QString("pressed");
        }
        if(event->key()==Qt::Key_S)
        {
            this->hero.Myvector.StateofMoveKeys[2] = QString("pressed");
        }
        if(event->key()==Qt::Key_D)
        {
            this->hero.Myvector.StateofMoveKeys[3] = QString("pressed");
        }
}

void playscene::keyReleaseEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_A)
    {
        this->hero.Myvector.StateofMoveKeys[0]=QString("unpressed");
    }
    if(event->key()==Qt::Key_W)
    {
        this->hero.Myvector.StateofMoveKeys[1]=QString("unpressed");
    }
    if(event->key()==Qt::Key_S)
    {
        this->hero.Myvector.StateofMoveKeys[2]=QString("unpressed");
    }
    if(event->key()==Qt::Key_D)
    {
        this->hero.Myvector.StateofMoveKeys[3]=QString("unpressed");
    }
}

void playscene::judge_movement()
{
    //角色
    hero.rect.setRect(hero.cx, hero.cy, hero.image.width() - 5, hero.image.height() - 5);
    if(hero.rect.intersects(barrio.rect)){
        hero.cx = hero.bfx;
        hero.cy = hero.bfy;
        hero.rect.setRect(hero.bfx, hero.bfy, hero.image.width() - 5, hero.image.height() - 5);
    }
    else
    if(hero.cx <= 0 || hero.cx > GAME_WIDTH - hero.image.width())   hero.cx = hero.bfx;
    if(hero.cy <= 0 || hero.cy > GAME_HEIGHT - hero.image.height())   hero.cy = hero.bfy;

    //角色子弹
    for(int i = 0; i < BULLET_NUM; i++){
        if(hero.bullets[i].is_free){
            continue;
        }
        if(hero.bullets[i].t_rect.intersects(barrio.rect)){
            hero.bullets[i].is_free = true;
        }
        if(hero.bullets[i].t_y < 0 || hero.bullets[i].t_y > GAME_HEIGHT || hero.bullets[i].t_x <  0 || hero.bullets[i].t_x > GAME_WIDTH ){
            hero.bullets[i].is_free = true;
         }
    }

    //giantw子弹
    for(int k = 0; k < ELITENEMY_NUM; k ++){
        if(giantw[k].isfree){
            continue;
        }
        for(int i = 0; i < BULLET_NUM; i++){
            if(giantw[k].bullets[i].is_free){
                continue;
            }
            if(giantw[k].bullets[i].t_rect.intersects(barrio.rect)){
                giantw[k].bullets[i].is_free = true;
            }
            if(giantw[k].bullets[i].t_y < 0 || giantw[k].bullets[i].t_y > GAME_HEIGHT || giantw[k].bullets[i].t_x < 0 || giantw[k].bullets[i].t_x > GAME_WIDTH){
                giantw[k].bullets[i].is_free = true;
            }
        }
    }

    //ghost
    for(int i = 0; i < NORMALENEMY_NUM; i++){
        if(ghost[i].isfree){
            continue;
        }
        if(ghost[i].cx <= 0 || ghost[i].cx >= GAME_WIDTH - 100){
            ghost[i].cx = ghost[i].bfx;
            ghost[i].wayx *= -1;
        }
        if(ghost[i].cy <= 0 || ghost[i].cy >= GAME_HEIGHT - 50){
            ghost[i].cy = ghost[i].bfy;
            ghost[i].wayy *= -1;
        }
        if(ghost[i].rect.intersects(barrio.rect)){
            ghost[i].cx = ghost[i].bfx;
            ghost[i].wayx *= -1;
            ghost[i].cy = ghost[i].bfy;
            ghost[i].wayy *= -1;
        }
    }

    //giantw
    for(int i = 0; i < ELITENEMY_NUM; i++){
        if(giantw[i].isfree){
            continue;
        }
        if(giantw[i].cx <= 0 || giantw[i].cx >= GAME_WIDTH - 100){
            giantw[i].cx = giantw[i].bfx;
        }
        if(giantw[i].cy <= 0 || giantw[i].cy >= GAME_HEIGHT - 50){
            giantw[i].cy = giantw[i].bfy;
        }
        if(giantw[i].rect.intersects(barrio.rect)){
            giantw[i].cx = giantw[i].bfx;
            giantw[i].cy = giantw[i].bfy;
        }
        if(giantf[i].rect.intersects(hero.rect)){
            giantf[i].cx = giantf[i].bfx;
            giantf[i].cy = giantf[i].bfy;
        }
    }

    //giantw的子弹
    for(int i = 0; i < BULLET_NUM; i++){
        if(giantw[i].bullets[i].t_rect.intersects(barrio.rect))
            giantw[i].bullets[i].is_free = true;
        if(giantw[i].bullets[i].t_y < 0 || giantw[i].bullets[i].t_y > GAME_HEIGHT || giantw[i].bullets[i].t_x <  0 || giantw[i].bullets[i].t_x > GAME_WIDTH )
            giantw[i].bullets[i].is_free = true;
    }

    //giantf
    for(int i = 0; i < ELITENEMY_NUM; i++){
        if(giantf[i].isfree){
            continue;
        }
        if(giantf[i].cx < 0 || giantf[i].cx > GAME_WIDTH){
            giantf[i].cx = giantf[i].bfx;
        }
        if(giantf[i].cy < 0 || giantf[i].cy > GAME_HEIGHT){
            giantf[i].cy = giantf[i].bfy;
        }
        if(giantf[i].rect.intersects(barrio.rect)){
            giantf[i].cx = giantf[i].bfx;
            giantf[i].cy = giantf[i].bfy;
        }
        if(giantf[i].rect.intersects(hero.rect)){
            giantf[i].cx = giantf[i].bfx;
            giantf[i].cy = giantf[i].bfy;
        }
    }

    //boss
    if(boss.cx < 0 || boss.cx > GAME_WIDTH){
         boss.cx = boss.bfx;
    }
    if(boss.cy < 0 || boss.cy > GAME_HEIGHT){
         boss.cy = boss.bfy;
    }
    if(boss.rect.intersects(barrio.rect)){
         boss.cx = boss.bfx;
         boss.cy = boss.bfy;
    }

    //boss的子弹
    for(int i = 0; i < BULLET_NUM; i++){
        if(boss.bullets[i].t_rect.intersects(barrio.rect))
            boss.bullets[i].is_free = true;
        if(boss.bullets[i].t_y < 0 ||boss.bullets[i].t_y > GAME_HEIGHT || boss.bullets[i].t_x <  0 || boss.bullets[i].t_x > GAME_WIDTH )
            boss.bullets[i].is_free = true;
    }
    return ;
}

void playscene::updateBullets()
{
    //角色
    for(int i = 0; i < BULLET_NUM; i++){
        if(hero.bullets[i].is_free){
            continue;
        }
        switch (hero.bullets[i].num) {
        case 0:{
            hero.bullets[i].t_y += hero.bullets[i].t_speed;
        }
            break;
        case 1:{
            hero.bullets[i].t_x += hero.bullets[i].t_speed;
            hero.bullets[i].t_y += hero.bullets[i].t_speed;
        }
            break;
        case 2:{
            hero.bullets[i].t_x += hero.bullets[i].t_speed;
        }
            break;
        case 3:{
            hero.bullets[i].t_x += hero.bullets[i].t_speed;
            hero.bullets[i].t_y -= hero.bullets[i].t_speed;
        }
            break;
        case 4:{
            hero.bullets[i].t_y -= hero.bullets[i].t_speed;
        }
            break;
        case 5:{
            hero.bullets[i].t_x -= hero.bullets[i].t_speed;
            hero.bullets[i].t_y -= hero.bullets[i].t_speed;
        }
            break;
        case 6:{
            hero.bullets[i].t_x -= hero.bullets[i].t_speed;
        }
            break;
        case 7:{
            hero.bullets[i].t_x -= hero.bullets[i].t_speed;
            hero.bullets[i].t_y += hero.bullets[i].t_speed;
        }
            break;
        default:
            break;
        }
        hero.bullets[i].t_rect.setRect(hero.bullets[i].t_x, hero.bullets[i].t_y, hero.bullets[i].t_image.width(), hero.bullets[i].t_image.height());
    }

    //giantw
    for(int i = 0; i < ELITENEMY_NUM; i++){
        if(giantw[i].isfree){
            continue;
        }
        for(int j = 0; j < BULLET_NUM; j++){
            if(giantw[i].bullets[j].is_free){
                continue;
            }
            switch (giantw[i].bullets[j].num) {
            case 0:
                giantw[i].bullets[j].t_x += giantw[i].bullets[j].t_speed;
                break;
            case 1:
                giantw[i].bullets[j].t_y += giantw[i].bullets[j].t_speed;
                break;
            case 2:
                giantw[i].bullets[j].t_x -= giantw[i].bullets[j].t_speed;
                break;
            case 3:
                giantw[i].bullets[j].t_y -= giantw[i].bullets[j].t_speed;
                break;
            default:
                break;
            }
            giantw[i].bullets[j].t_rect.setRect(giantw[i].bullets[j].t_x, giantw[i].bullets[j].t_y, giantw[i].bullets[j].t_image.width(), giantw[i].bullets[j].t_image.height());

        }
    }

    //boss
    for(int i = 0; i < BULLET_NUM; i++){
        if(boss.bullets[i].is_free){
            continue;
        }
        switch (boss.bullets[i].num) {
        case 0: case 8:
            boss.bullets[i].t_y += boss.bullets[i].t_speed;
            break;
        case 1: case 9:{
            boss.bullets[i].t_x += boss.bullets[i].t_speed;
            boss.bullets[i].t_y += boss.bullets[i].t_speed;
        }
            break;
        case 2: case 10:{
            boss.bullets[i].t_x += boss.bullets[i].t_speed;
        }
            break;
        case 3: case 11:{
            boss.bullets[i].t_x += boss.bullets[i].t_speed;
            boss.bullets[i].t_y -= boss.bullets[i].t_speed;
        }
            break;
        case 4: case 12:{
            boss.bullets[i].t_y -= boss.bullets[i].t_speed;
        }
            break;
        case 5: case 13:{
            boss.bullets[i].t_x -= boss.bullets[i].t_speed;
            boss.bullets[i].t_y -= boss.bullets[i].t_speed;
        }
            break;
        case 6: case 14:{
            boss.bullets[i].t_x -= boss.bullets[i].t_speed;
        }
            break;
        case 7: case 15:{
            boss.bullets[i].t_x -= boss.bullets[i].t_speed;
            boss.bullets[i].t_y += boss.bullets[i].t_speed;
        }
            break;
        default:
            break;
        }
        boss.bullets[i].t_rect.setRect(boss.bullets[i].t_x, boss.bullets[i].t_y, boss.bullets[i].t_image.width(), boss.bullets[i].t_image.height());
    }
}

void playscene::showupEnemy()
{
    recorderGhost += hero.level;
    recorderGiant += hero.level;

    if(recorderGhost >= ENEMY_INTERVAL){
        recorderGhost = 0;
        for(int i = 0; i < NORMALENEMY_NUM; i++){
              if(ghost[i].isfree){
                  ghost[i].isfree = false;
                  ghost[i].cx = rand()%(GAME_WIDTH_RECT);
                  ghost[i].cy = 0;
                  if(i % 2 == 0)
                    ghost[i].cy += GAME_HEIGHT_RECT;
                  ghost[i].rect.moveTo(ghost[i].cx, ghost[i].cy);
                  break;
              }
        }
    }

    if(recorderGiant >= 5 * ENEMY_INTERVAL){
        recorderGiant = 0;
        for(int i = 0; i < ELITENEMY_NUM; i++){
            if(giantf[i].isfree){
                giantf[i].isfree = false;
                giantf[i].cy = rand()%(GAME_HEIGHT_RECT);
                giantf[i].cx = 0;
                if(i % 2 == 0)
                    giantf[i].cx += GAME_WIDTH_RECT;
                giantf[i].rect.moveTo(ghost[i].cx, ghost[i].cy);
                break;
            }
        }

        for(int i = 0; i < ELITENEMY_NUM; i++){
            if(giantw[i].isfree){
                //qDebug () << "aa";
                giantw[i].isfree = false;
                giantw[i].cy = rand()%(GAME_HEIGHT_RECT);
                giantw[i].cx = 0;
                if(i % 2 == 0)
                    giantw[i].cx += GAME_WIDTH_RECT;
                giantw[i].rect.moveTo(ghost[i].cx, ghost[i].cy);
                break;
            }
        }
    }
}

void playscene::updateMonsters()
{
    //BOSS
        if(boss.cx < hero.cx) boss.bx = 1;
        else if(boss.cx > hero.cx) boss.bx = -1;
        if(boss.cy < hero.cy) boss.by = 1;
        else if(boss.cy > hero.cy) boss.by = -1;
        boss.bfx = boss.cx;
        boss.bfy = boss.cy;
        boss.cx += boss.bx * boss.speed;
        boss.cy += boss.by * boss.speed;
        boss.rect.moveTo(boss.cx, boss.cy);

    //ghosts
    for(int i = 0; i < NORMALENEMY_NUM; i++){
        if(ghost[i].isfree){
            continue;
        }
        ghost[i].bfx = ghost[i].cx;
        ghost[i].bfy = ghost[i].cy;
        ghost[i].cx += ghost[i].speed * ghost[i].wayx;
        ghost[i].cy += ghost[i].speed * ghost[i].wayy;
        ghost[i].rect.moveTo(ghost[i].cx, ghost[i].cy);
    }

    //giantw
    for(int i = 0; i < ELITENEMY_NUM; i++){
        int ix = 0, iy = 0;
        if(giantw[i].isfree){
            continue;
        }
        if(giantw[i].cx < hero.cx) ix = 1;
        else if(giantw[i].cx > hero.cx)  ix = -1;
        if(giantw[i].cy < hero.cy) iy  = 1;
        else if(giantw[i].cy > hero.cy)  iy  = -1;
        giantw[i].bfx = giantw[i].cx;
        giantw[i].bfy = giantw[i].cy;
        giantw[i].cx += giantw[i].speed * ix;
        giantw[i].cy += giantw[i].speed * iy;
        giantw[i].rect.moveTo(giantw[i].cx, giantw[i].cy);
    }

    //giantf
    for(int i = 0; i < ELITENEMY_NUM; i++){
        int ix = 0, iy = 0;
        if(giantf[i].isfree){
            continue;
        }
        if(giantf[i].cx < hero.cx) ix = 1;
        else if(giantf[i].cx > hero.cx)  ix = -1;
        if(giantf[i].cy < hero.cy) iy = 1;
        else if(giantf[i].cy > hero.cy)  iy = -1;
        giantf[i].bfx = giantf[i].cx;
        giantf[i].bfy = giantf[i].cy;
        giantf[i].cx += giantf[i].speed * ix;
        giantf[i].cy += giantf[i].speed * iy;
        giantf[i].rect.moveTo(giantf[i].cx, giantf[i].cy);
    }

}

void playscene::collisiondetect()
{
    //角色子弹和怪物
    for(int i = 0; i < BULLET_NUM; i++){
        if(hero.bullets[i].is_free){
            continue;
        }

        //角色子弹和近战普通怪
        for(int j = 0; j < NORMALENEMY_NUM; j++){
            if(ghost[j].isfree){
                continue;
            }
            if(hero.bullets[i].t_rect.intersects(ghost[j].rect)){
                ghost[j].hp -= hero.atk;
                if(hero.bullets[i].isextra) ghost[j].hp -= hero.atk / 2;
                if(hero.bullets[i].islow) ghost[j].speed *= 0.8;
                if(!hero.bullets[i].isthrough)  hero.bullets[i].is_free = true;
                if(ghost[j].hp <= 0) {
                    ghost[j].reload();
                    hero.ep += ghost[j].ep;
                    int could = rand() % (2 * hero.level);
                    if(could < 3){
                        for(int i = 0; i < DROP_NUM; i++){
                            if(drops[i].isfree){
                                drops[i].Load(ghost[j].cx, ghost[j].cy, could);
                                break;
                            }
                        }
                    }
                }
                break;
            }
        }
        if(hero.bullets[i].is_free){
            continue;
        }

        //角色子弹和近战精英怪
        for(int j = 0; j < ELITENEMY_NUM; j++){
            if(giantf[j].isfree){
                continue;
            }
            if(hero.bullets[i].t_rect.intersects(giantf[j].rect)){
                //qDebug() << giantf[j].hp;
                if(hero.bullets[i].isextra) giantf[j].hp -= hero.atk / 2;
                if(hero.bullets[i].islow) giantf[j].speed *= 0.8;
                giantf[j].hp -= hero.atk;
                if(!hero.bullets[i].isthrough)  hero.bullets[i].is_free = true;
                if(giantf[j].hp <= 0) {
                    giantf[j].reload();
                    hero.ep += giantf[j].ep;
                    int could = rand() % (2 * hero.level);
                    if(could < 3){
                        for(int i = 0; i < DROP_NUM; i++){
                            if(drops[i].isfree){
                                drops[i].Load(ghost[j].cx, ghost[j].cy, could);
                                break;
                            }
                        }
                    }
                }
                break;
            }
        }

        if(hero.bullets[i].is_free){
            continue;
        }

        //角色子弹和远程精英怪
        for(int j = 0; j < ELITENEMY_NUM; j++){
            if(giantw[j].isfree){
                continue;
            }

            //角色子弹和远程精英怪的子弹
            for(int k = 0; k < BULLET_NUM; k ++){
                if(hero.bullets[i].t_rect.intersects(giantw[j].bullets[k].t_rect)){
                    hero.bullets[i].is_free = true;
                    giantw[j].bullets[k].is_free = true;
                    break;
                }
            }

            if(hero.bullets[i].t_rect.intersects(giantw[j].rect)){
                //qDebug() << giantf[j].hp;
                if(hero.bullets[i].isextra) giantw[j].hp -= hero.atk / 2;
                if(hero.bullets[i].islow) giantw[j].speed *= 0.8;
                giantw[j].hp -= hero.atk;
                if(!hero.bullets[i].isthrough)  hero.bullets[i].is_free = true;
                if(giantw[j].hp <= 0) {
                    giantw[j].reload();
                    hero.ep += giantw[j].ep;
                    int could = rand() % (2 * hero.level);
                    if(could < 3){
                        for(int i = 0; i < DROP_NUM; i++){
                            if(drops[i].isfree){
                                drops[i].Load(ghost[j].cx, ghost[j].cy, could);
                                break;
                            }
                        }
                    }
                }
                break;
            }
        }
        if(hero.bullets[i].is_free){
            continue;
        }

        //角色子弹和BOSS子弹
        for(int k = 0; k < BULLET_NUM; k ++){
            if(hero.bullets[i].t_rect.intersects(boss.bullets[k].t_rect)){
                hero.bullets[i].is_free = true;
                boss.bullets[k].is_free = true;
                break;
            }
        }

        //子弹与BOSS
        if(hero.bullets[i].t_rect.intersects(boss.rect) && boss.isfree == false){

            recorderbullet ++;
            if(recorderbullet == 100){
                recorderbullet = 0;                
                if(hero.bullets[i].isextra) boss.hp -= hero.atk / 2;
                if(hero.bullets[i].islow) boss.speed *= 0.8;
                boss.hp -= hero.atk;
                if(!hero.bullets[i].isthrough)  hero.bullets[i].is_free = true;
                if(boss.hp <= 0) {
                    boss.isfree = true;

                }
                continue;
            }
        }
    }

  //怪物和角色碰撞

    //掉落物
    for(int i = 0; i < DROP_NUM; i++){
        if(drops[i].isfree){
            continue;
        }
        if(drops[i].rect.intersects(hero.rect)){
            drops[i].isfree = true;
            switch (drops[i].kind) {
            case 0:
                hero.get_money += 2;
                break;
            case 1:{
                hero.hp += 5;
                if(hero.hp > hero.Maxhp)
                    hero.hp = hero.Maxhp;
            }
                break;
            case 2:
                hero.ep += 50;
                break;
            default:
                break;
            }
        }
    }

    //ghost
    for(int i = 0; i < NORMALENEMY_NUM; i++){
        if(!ghost[i].isfree && hero.rect.intersects(ghost[i].rect)){
            sum ++;
            if(sum >= 100) {
                sum = 0;
                hero.hp -= ghost[i].atk;
                if(hero.isknight){
                    hero.hp += hero.dfc;
                }
            }
        }
    }

    //giantw
    for(int i = 0; i < ELITENEMY_NUM; i++){
        if(!giantw[i].isfree && hero.rect.intersects(giantw[i].rect)){
            sum ++;
            if(sum >= 100) {
                hero.hp -= giantw[i].atk / 2;
                sum = 0;
                if(hero.isknight){
                    hero.hp += hero.dfc;
                }
            }
        }
    }

    //giantf
    for(int i = 0; i < ELITENEMY_NUM; i++){
        if(!giantf[i].isfree && hero.rect.intersects(giantf[i].rect)){
            sum ++;
            if(sum >= 100) {
                hero.hp -= giantf[i].atk;
                if(hero.isknight){
                    hero.hp += hero.dfc;
                }
                sum = 0;
            }
        }
    }

    //giantw的子弹
    for(int i = 0; i < ELITENEMY_NUM; i++){
        for(int j  = 0; j < BULLET_NUM; j++){
            if(!giantw[i].isfree && hero.rect.intersects(giantw[i].bullets[j].t_rect)){
                sum ++;
                if(sum >= 100) {
                    hero.hp -= giantw[i].atk;
                    if(hero.isknight){
                        hero.hp += hero.dfc;
                    }
                    sum = 0;
                }
            }
        }
    }

    //boss和角色
    if(hero.rect.intersects(boss.rect)){
        sum ++;
        if(sum >= 100) {
            hero.hp -= boss.atk / 2;
            if(hero.isknight){
                hero.hp += hero.dfc;
            }
            sum = 0;
        }
    }
    //boss的子弹
    if(!boss.isfree){
        for(int i = 0; i < BULLET_NUM; i++){
            if(hero.rect.intersects(boss.bullets[i].t_rect)){
                sum ++;
                boss.bullets[i].is_free = true;
                if(sum >= 100){
                    hero.hp -= boss.atk;
                    if(hero.isknight){
                        hero.hp += hero.dfc;
                    }
                    sum = 0;
                }
            }
        }
    }


}

void playscene::updateallposition()
{
    updateBullets();

    hero.setPosition();

    updateMonsters();

    judge_movement();

    update();
}

void playscene::music()
{
    player = new QMediaPlayer(this);//设置背景音乐
    player->setMedia(QUrl::fromEncoded("qrc:/music.mp3"));
    player->setVolume(50);//音量
    isplay = 1;
    player->play();
}
