#pragma once

#include <QObject>
class QKeySequence;

class QGlobalShortcut : public QObject {
    Q_OBJECT
    Q_PROPERTY(QKeySequence key READ key WRITE setKey)
    //Q_PROPERTY(bool enabled READ isEnabled WRITE setEnabled)

public:
    explicit QGlobalShortcut(QObject* parent = nullptr);
    explicit QGlobalShortcut(const QKeySequence& keyseq, QObject* parent = nullptr);

    QKeySequence key() const;
    void setKey(const QKeySequence& keyseq);
    //bool isEnabled() const;    void setEnabled(bool on);
 
signals:
    void activated();

private:
    static quint32 toNativeKeycode(Qt::Key k);
    static quint32 toNativeModifiers(Qt::KeyboardModifiers m);
    static void registerKey(quint32 k, quint32 m);
    static void unregisterKey(quint32 k, quint32 m);
};
