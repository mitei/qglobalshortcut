#include <QLabel>

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
