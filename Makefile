#############################################################################
# Makefile for building: SFGL
# Generated by qmake (3.0) (Qt 5.5.1)
# Project:  SFGL.pro
# Template: app
# Command: /home/rootming/Qt5.5.1/5.5/gcc_64/bin/qmake -spec linux-g++ CONFIG+=debug -o Makefile SFGL.pro
#############################################################################

MAKEFILE      = Makefile

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = 
CFLAGS        = -pipe -g -Wall -W -fPIC $(DEFINES)
CXXFLAGS      = -pipe -g -std=c++0x -Wall -W -fPIC $(DEFINES)
INCPATH       = -I. -I../../../Qt5.5.1/5.5/gcc_64/mkspecs/linux-g++
QMAKE         = /home/rootming/Qt5.5.1/5.5/gcc_64/bin/qmake
DEL_FILE      = rm -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p
COPY          = cp -f
COPY_FILE     = cp -f
COPY_DIR      = cp -f -R
INSTALL_FILE  = install -m 644 -p
INSTALL_PROGRAM = install -m 755 -p
INSTALL_DIR   = cp -f -R
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
TAR           = tar -cf
COMPRESS      = gzip -9f
DISTNAME      = SFGL1.0.0
DISTDIR = /home/rootming/SFGL/new/SFGL/.tmp/SFGL1.0.0
LINK          = g++
LFLAGS        = -Wl,-rpath,/home/rootming/Qt5.5.1/5.5/gcc_64
LIBS          = $(SUBLIBS) -static -lpthread 
AR            = ar cqs
RANLIB        = 
SED           = sed
STRIP         = strip

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = main.cpp \
		fbdev.cpp \
		basedraw.cpp \
		surface.cpp 
OBJECTS       = main.o \
		fbdev.o \
		basedraw.o \
		surface.o
DIST          = ../../../Qt5.5.1/5.5/gcc_64/mkspecs/features/spec_pre.prf \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/common/unix.conf \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/common/linux.conf \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/common/sanitize.conf \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/common/gcc-base.conf \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/common/gcc-base-unix.conf \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/common/g++-base.conf \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/common/g++-unix.conf \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/qconfig.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_3dcollision.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_3dcollision_private.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_3dcore.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_3dcore_private.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_3dinput.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_3dinput_private.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_3dlogic.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_3dlogic_private.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_3dquick.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_3dquick_private.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_3dquickrenderer.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_3dquickrenderer_private.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_3drenderer.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_3drenderer_private.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_bluetooth.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_bluetooth_private.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_bootstrap_private.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_clucene_private.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_concurrent.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_concurrent_private.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_core.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_core_private.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_dbus.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_dbus_private.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_declarative.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_declarative_private.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_designer.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_designer_private.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_designercomponents_private.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_enginio.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_enginio_private.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_gui.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_gui_private.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_help.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_help_private.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_location.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_location_private.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_multimedia.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_multimedia_private.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_multimediawidgets.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_multimediawidgets_private.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_network.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_network_private.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_nfc.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_nfc_private.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_opengl.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_opengl_private.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_openglextensions.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_openglextensions_private.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_platformsupport_private.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_positioning.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_positioning_private.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_printsupport.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_printsupport_private.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_qml.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_qml_private.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_qmldevtools_private.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_qmltest.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_qmltest_private.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_qtmultimediaquicktools_private.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_quick.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_quick_private.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_quickparticles_private.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_quickwidgets.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_quickwidgets_private.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_script.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_script_private.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_scripttools.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_scripttools_private.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_sensors.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_sensors_private.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_serialport.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_serialport_private.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_sql.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_sql_private.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_svg.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_svg_private.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_testlib.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_testlib_private.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_uiplugin.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_uitools.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_uitools_private.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_webchannel.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_webchannel_private.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_webengine.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_webengine_private.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_webenginecore.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_webenginecore_private.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_webenginewidgets.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_webenginewidgets_private.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_webkit.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_webkit_private.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_webkitwidgets.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_webkitwidgets_private.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_websockets.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_websockets_private.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_webview_private.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_widgets.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_widgets_private.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_x11extras.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_x11extras_private.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_xcb_qpa_lib_private.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_xml.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_xml_private.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_xmlpatterns.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_xmlpatterns_private.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/features/qt_functions.prf \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/features/qt_config.prf \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/linux-g++/qmake.conf \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/features/spec_post.prf \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/features/exclusive_builds.prf \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/features/default_pre.prf \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/features/resolve_config.prf \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/features/default_post.prf \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/features/c++11.prf \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/features/warn_on.prf \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/features/testcase_targets.prf \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/features/exceptions.prf \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/features/yacc.prf \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/features/lex.prf \
		SFGL.pro fbdev.h \
		debug.h \
		basedraw.h \
		surface.h \
		deffont.h \
		drawdef.h main.cpp \
		fbdev.cpp \
		basedraw.cpp \
		surface.cpp
QMAKE_TARGET  = SFGL
DESTDIR       = #avoid trailing-slash linebreak
TARGET        = SFGL


first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

$(TARGET):  $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: SFGL.pro ../../../Qt5.5.1/5.5/gcc_64/mkspecs/linux-g++/qmake.conf ../../../Qt5.5.1/5.5/gcc_64/mkspecs/features/spec_pre.prf \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/common/unix.conf \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/common/linux.conf \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/common/sanitize.conf \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/common/gcc-base.conf \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/common/gcc-base-unix.conf \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/common/g++-base.conf \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/common/g++-unix.conf \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/qconfig.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_3dcollision.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_3dcollision_private.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_3dcore.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_3dcore_private.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_3dinput.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_3dinput_private.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_3dlogic.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_3dlogic_private.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_3dquick.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_3dquick_private.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_3dquickrenderer.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_3dquickrenderer_private.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_3drenderer.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_3drenderer_private.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_bluetooth.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_bluetooth_private.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_bootstrap_private.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_clucene_private.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_concurrent.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_concurrent_private.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_core.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_core_private.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_dbus.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_dbus_private.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_declarative.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_declarative_private.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_designer.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_designer_private.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_designercomponents_private.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_enginio.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_enginio_private.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_gui.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_gui_private.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_help.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_help_private.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_location.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_location_private.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_multimedia.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_multimedia_private.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_multimediawidgets.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_multimediawidgets_private.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_network.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_network_private.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_nfc.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_nfc_private.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_opengl.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_opengl_private.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_openglextensions.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_openglextensions_private.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_platformsupport_private.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_positioning.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_positioning_private.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_printsupport.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_printsupport_private.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_qml.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_qml_private.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_qmldevtools_private.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_qmltest.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_qmltest_private.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_qtmultimediaquicktools_private.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_quick.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_quick_private.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_quickparticles_private.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_quickwidgets.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_quickwidgets_private.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_script.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_script_private.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_scripttools.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_scripttools_private.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_sensors.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_sensors_private.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_serialport.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_serialport_private.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_sql.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_sql_private.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_svg.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_svg_private.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_testlib.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_testlib_private.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_uiplugin.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_uitools.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_uitools_private.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_webchannel.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_webchannel_private.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_webengine.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_webengine_private.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_webenginecore.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_webenginecore_private.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_webenginewidgets.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_webenginewidgets_private.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_webkit.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_webkit_private.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_webkitwidgets.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_webkitwidgets_private.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_websockets.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_websockets_private.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_webview_private.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_widgets.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_widgets_private.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_x11extras.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_x11extras_private.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_xcb_qpa_lib_private.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_xml.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_xml_private.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_xmlpatterns.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_xmlpatterns_private.pri \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/features/qt_functions.prf \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/features/qt_config.prf \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/linux-g++/qmake.conf \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/features/spec_post.prf \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/features/exclusive_builds.prf \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/features/default_pre.prf \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/features/resolve_config.prf \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/features/default_post.prf \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/features/c++11.prf \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/features/warn_on.prf \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/features/testcase_targets.prf \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/features/exceptions.prf \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/features/yacc.prf \
		../../../Qt5.5.1/5.5/gcc_64/mkspecs/features/lex.prf \
		SFGL.pro
	$(QMAKE) -spec linux-g++ CONFIG+=debug -o Makefile SFGL.pro
../../../Qt5.5.1/5.5/gcc_64/mkspecs/features/spec_pre.prf:
../../../Qt5.5.1/5.5/gcc_64/mkspecs/common/unix.conf:
../../../Qt5.5.1/5.5/gcc_64/mkspecs/common/linux.conf:
../../../Qt5.5.1/5.5/gcc_64/mkspecs/common/sanitize.conf:
../../../Qt5.5.1/5.5/gcc_64/mkspecs/common/gcc-base.conf:
../../../Qt5.5.1/5.5/gcc_64/mkspecs/common/gcc-base-unix.conf:
../../../Qt5.5.1/5.5/gcc_64/mkspecs/common/g++-base.conf:
../../../Qt5.5.1/5.5/gcc_64/mkspecs/common/g++-unix.conf:
../../../Qt5.5.1/5.5/gcc_64/mkspecs/qconfig.pri:
../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_3dcollision.pri:
../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_3dcollision_private.pri:
../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_3dcore.pri:
../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_3dcore_private.pri:
../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_3dinput.pri:
../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_3dinput_private.pri:
../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_3dlogic.pri:
../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_3dlogic_private.pri:
../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_3dquick.pri:
../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_3dquick_private.pri:
../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_3dquickrenderer.pri:
../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_3dquickrenderer_private.pri:
../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_3drenderer.pri:
../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_3drenderer_private.pri:
../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_bluetooth.pri:
../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_bluetooth_private.pri:
../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_bootstrap_private.pri:
../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_clucene_private.pri:
../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_concurrent.pri:
../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_concurrent_private.pri:
../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_core.pri:
../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_core_private.pri:
../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_dbus.pri:
../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_dbus_private.pri:
../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_declarative.pri:
../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_declarative_private.pri:
../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_designer.pri:
../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_designer_private.pri:
../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_designercomponents_private.pri:
../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_enginio.pri:
../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_enginio_private.pri:
../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_gui.pri:
../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_gui_private.pri:
../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_help.pri:
../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_help_private.pri:
../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_location.pri:
../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_location_private.pri:
../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_multimedia.pri:
../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_multimedia_private.pri:
../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_multimediawidgets.pri:
../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_multimediawidgets_private.pri:
../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_network.pri:
../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_network_private.pri:
../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_nfc.pri:
../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_nfc_private.pri:
../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_opengl.pri:
../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_opengl_private.pri:
../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_openglextensions.pri:
../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_openglextensions_private.pri:
../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_platformsupport_private.pri:
../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_positioning.pri:
../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_positioning_private.pri:
../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_printsupport.pri:
../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_printsupport_private.pri:
../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_qml.pri:
../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_qml_private.pri:
../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_qmldevtools_private.pri:
../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_qmltest.pri:
../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_qmltest_private.pri:
../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_qtmultimediaquicktools_private.pri:
../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_quick.pri:
../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_quick_private.pri:
../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_quickparticles_private.pri:
../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_quickwidgets.pri:
../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_quickwidgets_private.pri:
../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_script.pri:
../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_script_private.pri:
../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_scripttools.pri:
../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_scripttools_private.pri:
../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_sensors.pri:
../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_sensors_private.pri:
../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_serialport.pri:
../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_serialport_private.pri:
../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_sql.pri:
../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_sql_private.pri:
../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_svg.pri:
../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_svg_private.pri:
../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_testlib.pri:
../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_testlib_private.pri:
../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_uiplugin.pri:
../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_uitools.pri:
../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_uitools_private.pri:
../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_webchannel.pri:
../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_webchannel_private.pri:
../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_webengine.pri:
../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_webengine_private.pri:
../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_webenginecore.pri:
../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_webenginecore_private.pri:
../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_webenginewidgets.pri:
../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_webenginewidgets_private.pri:
../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_webkit.pri:
../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_webkit_private.pri:
../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_webkitwidgets.pri:
../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_webkitwidgets_private.pri:
../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_websockets.pri:
../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_websockets_private.pri:
../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_webview_private.pri:
../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_widgets.pri:
../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_widgets_private.pri:
../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_x11extras.pri:
../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_x11extras_private.pri:
../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_xcb_qpa_lib_private.pri:
../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_xml.pri:
../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_xml_private.pri:
../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_xmlpatterns.pri:
../../../Qt5.5.1/5.5/gcc_64/mkspecs/modules/qt_lib_xmlpatterns_private.pri:
../../../Qt5.5.1/5.5/gcc_64/mkspecs/features/qt_functions.prf:
../../../Qt5.5.1/5.5/gcc_64/mkspecs/features/qt_config.prf:
../../../Qt5.5.1/5.5/gcc_64/mkspecs/linux-g++/qmake.conf:
../../../Qt5.5.1/5.5/gcc_64/mkspecs/features/spec_post.prf:
../../../Qt5.5.1/5.5/gcc_64/mkspecs/features/exclusive_builds.prf:
../../../Qt5.5.1/5.5/gcc_64/mkspecs/features/default_pre.prf:
../../../Qt5.5.1/5.5/gcc_64/mkspecs/features/resolve_config.prf:
../../../Qt5.5.1/5.5/gcc_64/mkspecs/features/default_post.prf:
../../../Qt5.5.1/5.5/gcc_64/mkspecs/features/c++11.prf:
../../../Qt5.5.1/5.5/gcc_64/mkspecs/features/warn_on.prf:
../../../Qt5.5.1/5.5/gcc_64/mkspecs/features/testcase_targets.prf:
../../../Qt5.5.1/5.5/gcc_64/mkspecs/features/exceptions.prf:
../../../Qt5.5.1/5.5/gcc_64/mkspecs/features/yacc.prf:
../../../Qt5.5.1/5.5/gcc_64/mkspecs/features/lex.prf:
SFGL.pro:
qmake: FORCE
	@$(QMAKE) -spec linux-g++ CONFIG+=debug -o Makefile SFGL.pro

qmake_all: FORCE


all: Makefile $(TARGET)

dist: distdir FORCE
	(cd `dirname $(DISTDIR)` && $(TAR) $(DISTNAME).tar $(DISTNAME) && $(COMPRESS) $(DISTNAME).tar) && $(MOVE) `dirname $(DISTDIR)`/$(DISTNAME).tar.gz . && $(DEL_FILE) -r $(DISTDIR)

distdir: FORCE
	@test -d $(DISTDIR) || mkdir -p $(DISTDIR)
	$(COPY_FILE) --parents $(DIST) $(DISTDIR)/


clean: compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


distclean: clean 
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


####### Sub-libraries

check: first

compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: 

####### Compile

main.o: main.cpp fbdev.h \
		basedraw.h \
		surface.h \
		drawdef.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o main.cpp

fbdev.o: fbdev.cpp fbdev.h \
		debug.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o fbdev.o fbdev.cpp

basedraw.o: basedraw.cpp basedraw.h \
		surface.h \
		drawdef.h \
		fbdev.h \
		debug.h \
		deffont.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o basedraw.o basedraw.cpp

surface.o: surface.cpp surface.h \
		drawdef.h \
		fbdev.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o surface.o surface.cpp

####### Install

install:  FORCE

uninstall:  FORCE

FORCE:

