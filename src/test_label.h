#ifdef Q_OS_WIN32
#include <QLabel>
#else
#include <QtWidgets/QLabel>
#endif

class TestLabel : public QLabel {
    Q_OBJECT

public:
    TestLabel(QWidget* parent = nullptr)
        : QLabel(parent)
    {
    }

public slots:
    void success();
};
