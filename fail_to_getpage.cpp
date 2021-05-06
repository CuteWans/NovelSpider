#include "fail_to_getpage.h"
#include "ui_fail_to_getpage.h"
#include "find_page.h"

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
