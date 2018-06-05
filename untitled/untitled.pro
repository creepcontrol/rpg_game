#-------------------------------------------------
#
# Project created by QtCreator 2018-05-12T17:13:13
#
#-------------------------------------------------

QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = untitled
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
    screensstack.cpp \
    screencontroller.cpp \
    frame.cpp \
    form.cpp \
    graphview.cpp \
    animationpool.cpp \
    animatedgraphicsitem.cpp \
    graphicsactor.cpp \
    towers.cpp \
    menu.cpp \
    aboutactor.cpp \
    line.cpp \
    hpitem.cpp \
    panelitem.cpp \
    enemyactor.cpp





HEADERS += \
    screensstack.h \
    screencontroller.h \
    frame.h \
    form.h \
    graphview.h \
    animationpool.h \
    singleton.h \
    animatedgraphicsitem.h \
    graphicsactor.h \
    menu.h \
    aboutactor.h \
    line.h \
    Towers.h \
    HpItem.h \
    panelitem.h \
    resize_image.h \
    enemyactor.h






FORMS += \
    frame.ui \
    form.ui \
    menu.ui

RESOURCES += \
    resources/game.qrc

DISTFILES += \
    ../rrrfer-admin-hedgehog-5262450efc6a/resources/game/pics/hedgehog_down.png
