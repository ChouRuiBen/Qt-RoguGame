#ifndef CHOOSESCENE_H
#define CHOOSESCENE_H

#include <scene.h>
#include <Mypushbutton.h>
#include <QTextEdit>

class choosescene : public scene
{
public:
    QPixmap hero1, hero2, hero3;
    QPushButton choose1, choose2, choose3;
    QTextEdit text1, text2, text3;

    choosescene();
    //绘图事件重构
    void paintEvent(QPaintEvent *);
    //初始化按钮
    void setChooseButton(QPushButton *);
    //对文本框的初始化
    void setText(QTextEdit *);
};

#endif // CHOOSESCENE_H
