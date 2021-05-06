#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "find_page.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::Getessay);
}

void MainWindow::Getessay() {
    name = ui->textEdit->toPlainText();
    find_page* hd = new find_page(this, name);
    hd->show();
    hide();
}

MainWindow::~MainWindow() {
    delete ui;
}
