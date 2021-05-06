#include "fail_to_act.h"
#include "ui_fail_to_act.h"
#include "find_page.h"

Fail_to_act::Fail_to_act(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Fail_to_act)
{
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::clicked, this, &Fail_to_act::Return_1);
}

void Fail_to_act::Return_1() {
    this->close();
}

Fail_to_act::~Fail_to_act()
{
    delete ui;
}
