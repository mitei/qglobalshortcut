#include "qglobalshortcut.h"

QGlobalShortcut::QGlobalShortcut(QObject* parent)
    : QObject(parent)
{
}

QGlobalShortcut::QGlobalShortcut(const QKeySequence& keyseq, QObject* parent)
    : QObject(parent)
{
    setKeysequence(keyseq);
}

QKeySequence QGlobalShortcut::key() const
{
    // TODO
}

void QGlobalShortcut::setKey(const QKeySequence& keyseq)
{
    // TODO
}

