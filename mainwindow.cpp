#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "find_page.h"
#include <QDebug>
#include <QDesktopWidget>

void MainWindow::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Return || event->key() == Qt::Key_Enter) {
        Getessay();
    }
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::Getessay);
}

void MainWindow::Getessay() {
    name = ui->textEdit->text();
    find_page* hd = new find_page(this, name);
    hd->setAttribute(Qt::WA_DeleteOnClose);
    hd->move(this->geometry().center() - hd->rect().center());
    hd->show();
    hide();
}

MainWindow::~MainWindow() {
    delete ui;
}
