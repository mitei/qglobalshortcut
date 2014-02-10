qglobalshortcut
===============

Qt global-shortcut class

* supports Qt5.0 later.
* supports Windows and X11. (I don't have Mac.)
* not a library. (copy src/ to your project directly.)
* You can use this without any restriction.

### Usage

add to your .pro like this

```plain
QT = core gui widgets

unix:QT = x11extras
unix:LIBS += -lX11 -lxcb
unix:QMAKE_CXXFLAGS += "-std=c++11"

HEADERS += \
    src/qglobalshortcut.h

SOURCES += \
    src/qglobalshortcut.cc

win32:SOURCES += src/qglobalshortcut_win.cc
unix:SOURCES  += src/qglobalshortcut_x11.cc
#macx:SOURCES  += src/qglobalshortcut_macx.cc
```

`QGlobalShortcut` class has some method like `QShortcut` class.

```cpp
class QGlobalShortcut : public QObject {

public:
    explicit       QGlobalShortcut(QObject* parent = nullptr);
    explicit       QGlobalShortcut(const QKeySequence& keyseq, QObject* parent = nullptr);
    QKeySequence   key() const;
    void           setKey(const QKeySequence& keyseq);

signals:
    void           activated();

};
```

use this as follows:

```cpp
QGlobalShortcut gs;
gs.setKey(QKeySequence("Alt+Ctrl+Space"));

connect(&gs, SIGNAL(activated()), ...);
```
