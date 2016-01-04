TEMPLATE = lib
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES +=  \
    fbdev.cpp \
    basedraw.cpp \
    surface.cpp \
    image.cpp \
    drawdef.cpp \
    matrix4x4.cpp \
    vector3d.cpp \
    vector4d.cpp \
    surface3d.cpp \
    sfgl.cpp \
    sfgllable.cpp \
    font.cpp

HEADERS += \
    fbdev.h \
    debug.h \
    basedraw.h \
    surface.h \
    drawdef.h \
    image.h \
    matrix4x4.h \
    vector3d.h \
    vector4d.h \
    surface3d.h \
    sfgl.h \
    sfgllable.h \
    font.h

LIBS += -lpthread -lpng12 -lz -lfreetype
QMAKE_CXXFLAGS +=
INCLUDEPATH += /usr/include/freetype2
