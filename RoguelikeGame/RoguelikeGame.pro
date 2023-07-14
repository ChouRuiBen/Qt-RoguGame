#-------------------------------------------------
#
# Project created by QtCreator 2023-05-20T20:25:50
#
#-------------------------------------------------

QT       += core gui
QT       += multimedia multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = RoguelikeGame
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        widget.cpp \
    movevector.cpp \
    character.cpp \
    bullet.cpp \
    scene.cpp \
    startscene.cpp \
    Mypushbutton.cpp \
    helpscene.cpp \
    playscene.cpp \
    storescene.cpp \
    cheatscene.cpp \
    choosescene.cpp \
    boss.cpp \
    topickup.cpp \
    normalenemy.cpp \
    elitenemy1.cpp \
    elitenemy2.cpp \
    smallscene.cpp

HEADERS += \
        widget.h \
    parameter.h \
    basee.h \
    movevector.h \
    character.h \
    bullet.h \
    scene.h \
    startscene.h \
    Mypushbutton.h \
    helpscene.h \
    playscene.h \
    storescene.h \
    cheatscene.h \
    choosescene.h \
    boss.h \
    topickup.h \
    normalenemy.h \
    elitenemy1.h \
    elitenemy2.h \
    smallscene.h

FORMS += \
        widget.ui

RESOURCES += \
    res.qrc \
    res.qrc \
    res.qrc
