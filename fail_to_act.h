#ifndef FAIL_TO_ACT_H
#define FAIL_TO_ACT_H

#include <QMainWindow>

namespace Ui {
class Fail_to_act;
}

class Fail_to_act : public QMainWindow
{
    Q_OBJECT

public:
    explicit Fail_to_act(QWidget *parent = nullptr);
    ~Fail_to_act();

private:
    Ui::Fail_to_act *ui;

public slots:
    void Return_1();
};

#endif // FAIL_TO_ACT_H
