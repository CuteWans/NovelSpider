#include "fail_to_getpage.h"
#include "ui_fail_to_getpage.h"
#include "find_page.h"

void Fail_to_getpage::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Return || event->key() == Qt::Key_Enter) {
        Return_2();
    }
}

Fail_to_getpage::Fail_to_getpage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Fail_to_getpage)
{
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::clicked, this, &Fail_to_getpage::Return_2);
}

void Fail_to_getpage::Return_2() {
    this->close();
}

Fail_to_getpage::~Fail_to_getpage()
{
    delete ui;
}
