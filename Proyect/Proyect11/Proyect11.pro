TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    game.cpp \
    Player.cpp \
    Pekemon.cpp \
    Move.cpp \
    Item.cpp \
    Tienda.cpp

HEADERS += \
    Game.h \
    Player.h \
    Pekemon.h \
    Move.h \
    Item.h \
    Tienda.h
