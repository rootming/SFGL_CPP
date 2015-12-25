TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    fbdev.cpp \
    basedraw.cpp \
    surface.cpp \
    image.cpp \
    drawdef.cpp

HEADERS += \
    fbdev.h \
    debug.h \
    basedraw.h \
    surface.h \
    deffont.h \
    drawdef.h \
    image.h


LIBS += -static -lpthread -lpng12 -lz
QMAKE_CXXFLAGS +=
