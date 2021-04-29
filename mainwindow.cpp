#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::Getessay);
}

void MainWindow::Getessay() {
    const QString url_str = ui->textEdit->toPlainText();
    QUrl url(url_str);
    fd = new FileDownloader(url, this);

    connect(fd, SIGNAL (downloaded()), this, SLOT (loadText()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loadText() {
    QTextCodec *tc = QTextCodec::codecForName("GBK");
    QString str = tc -> toUnicode(fd->downloadedData());
    ui->textBrowser->setPlainText(str);
    fd->deleteLater();
}
