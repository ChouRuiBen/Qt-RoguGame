#include "widget.h"
#include <QApplication>
#include <qDebug>
#include <QMediaPlayer>



int main(int argc, char *argv[])
{

    QApplication app(argc, argv);

    srand( (unsigned int) time(NULL));

    mainWidget window_game;

    return app.exec();
}
