#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), fd(nullptr) {
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::Getessay);
}

void MainWindow::Getessay() {
    const QString url_str = ui->textEdit->toPlainText();
    QUrl url(url_str);
    if(fd != nullptr)   delete fd;
    fd = new FileDownloader(url, this);
    connect(fd, SIGNAL (downloaded()), this, SLOT (loadText()));
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::loadText() {
    QTextCodec *tc = QTextCodec::codecForName("GBK");
    QString str = tc -> toUnicode(fd->downloadedData());
    ui->textBrowser->setPlainText(str);
}
