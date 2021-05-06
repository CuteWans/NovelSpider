#ifndef FAIL_TO_GETPAGE_H
#define FAIL_TO_GETPAGE_H

#include <QMainWindow>

namespace Ui {
class Fail_to_getpage;
}

class Fail_to_getpage : public QMainWindow
{
    Q_OBJECT

public:
    explicit Fail_to_getpage(QWidget *parent = nullptr);
    ~Fail_to_getpage();

private:
    Ui::Fail_to_getpage *ui;

public slots:
    void Return_2();
};

#endif // FAIL_TO_GETPAGE_H
