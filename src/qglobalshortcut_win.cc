#include "qglobalshortcut.h"
#include <QKeySequence>
#include <Windows.h>

bool QGlobalShortcut::QGlobalShortcutEventFilter::nativeEventFilter(const QByteArray &event_type,
                                        void *message, long *result)
{
    MSG* msg = static_cast<MSG*>(message);
    if (msg->message == WM_HOTKEY) {
        quint32 id = static_cast<quint32>(msg->wParam);
        activate(id);
        return true;
    }
    return false;
}

quint32 QGlobalShortcut::toNativeKeycode(Qt::Key k) {
    // F1 ~ F24
    if (k >= Qt::Key_F1 && k <= Qt::Key_F24)
        return VK_F1 + (k - Qt::Key_F1);
    // 0 ~ 9
    if (k >= Qt::Key_0 && k <= Qt::Key_9)
        return k;
    // A ~ Z
    if (k >= Qt::Key_A && k <= Qt::Key_Z)
        return k;

    switch (k) {
    case Qt::Key_Escape:
        return VK_ESCAPE;
    case Qt::Key_Tab:
    case Qt::Key_Backtab:
        return VK_TAB;
    case Qt::Key_Backspace:
        return VK_BACK;
    case Qt::Key_Return:
    case Qt::Key_Enter:
        return VK_RETURN;
    case Qt::Key_Insert:
        return VK_INSERT;
    case Qt::Key_Delete:
        return VK_DELETE;
    case Qt::Key_Pause:
        return VK_PAUSE;
    case Qt::Key_Print:
        return VK_PRINT;
    case Qt::Key_Clear:
        return VK_CLEAR;
    case Qt::Key_Home:
        return VK_HOME;
    case Qt::Key_End:
        return VK_END;
    case Qt::Key_Left:
        return VK_LEFT;
    case Qt::Key_Up:
        return VK_UP;
    case Qt::Key_Right:
        return VK_RIGHT;
    case Qt::Key_Down:
        return VK_DOWN;
    case Qt::Key_PageUp:
        return VK_PRIOR;
    case Qt::Key_PageDown:
        return VK_NEXT;
    case Qt::Key_Space:
        return VK_SPACE;
    case Qt::Key_Asterisk:
        return VK_MULTIPLY;
    case Qt::Key_Plus:
        return VK_ADD;
    case Qt::Key_Comma:
        return VK_SEPARATOR;
    case Qt::Key_Minus:
        return VK_SUBTRACT;
    case Qt::Key_Slash:
        return VK_DIVIDE;
    case Qt::Key_Backslash:
        return VK_OEM_102;        // ?
    case Qt::Key_MediaNext:
        return VK_MEDIA_NEXT_TRACK;
    case Qt::Key_MediaPrevious:
        return VK_MEDIA_PREV_TRACK;
    case Qt::Key_MediaPlay:
        return VK_MEDIA_PLAY_PAUSE;
    case Qt::Key_MediaStop:
        return VK_MEDIA_STOP;
    //case Qt::Key_MediaLast:     // ??
    //case Qt::Key_MediaRecord:   // ??
    case Qt::Key_VolumeDown:
        return VK_VOLUME_DOWN;
    case Qt::Key_VolumeUp:
        return VK_VOLUME_UP;
    case Qt::Key_VolumeMute:
        return VK_VOLUME_MUTE;
    default:
        return 0;
    }
}

quint32 QGlobalShortcut::toNativeModifiers(Qt::KeyboardModifiers m) {
    quint32 mods = 0;
    if (m & Qt::AltModifier)      mods |= MOD_ALT;
    if (m & Qt::ControlModifier)  mods |= MOD_CONTROL;
    if (m & Qt::ShiftModifier)    mods |= MOD_SHIFT;
    if (m & Qt::MetaModifier)     mods |= MOD_WIN;
    return mods;
}

void QGlobalShortcut::registerKey(quint32 k, quint32 m, quint32 id) {
    RegisterHotKey(NULL, id, m, k);
}

void QGlobalShortcut::unregisterKey(quint32 k, quint32 m, quint32 id) {
    UnregisterHotKey(NULL, id);
}
