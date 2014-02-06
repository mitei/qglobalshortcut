QT = core

TARGET = test_qglobalshortcut
TEMPLATE = app
unix:QMAKE_CXXFLAGS += "-std=c++11"

DESTDIR = dest

HEADERS += \
	src/qglobalshortcut.h

SOURCES += \
	src/main.cc \
	src/qglobalshortcut.cc

win32:SOURCES += src/qglobalshortcut_win.cc
unix:SOURCES  += src/qglobalshortcut_x11.cc
macx:SOURCES  += src/qglobalshortcut_macx.cc
