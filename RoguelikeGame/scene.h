#ifndef SCENE_H
#define SCENE_H

#include <QWidget>
#include "Mypushbutton.h"
#include "basee.h"

class scene : public QWidget{
    Q_OBJECT
public:
    scene();
    //初始化返回键
    void backSet();
    //背景图片
    QPixmap background;
    //返回键
    QPushButton back;
};

#endif // SCENE_H
