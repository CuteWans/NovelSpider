#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

QString xend = "<br />";
QString dend = "</div>";
QString xl = "，。“”？：！…‘’~—*（）《》【】·；、_";
QString pre = "上一章";
QString las = "下一章";

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), fd(nullptr) {
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::Getessay);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &MainWindow::Getessay_pre);
    connect(ui->pushButton_3, &QPushButton::clicked, this, &MainWindow::Getessay_las);
}

void MainWindow::Getessay_pre() {
    QTextCodec *tc = QTextCodec::codecForName("GBK");
    QString str = tc->toUnicode(fd->downloadedData());
    Getpreurl(str);
    str = "https://www.hongyeshuzhai.com/" + str;
    ui->textEdit->setText(str);
    Getessay();
}

void MainWindow::Getpreurl(QString &str) {
    int pos = str.indexOf(pre);
    str.truncate(pos);
    str = str.right(35);
    int start = str.indexOf("/");
    int end = str.length() - 2;
    str = str.mid(start, end - start);
}

void MainWindow::Getessay_las() {
    QTextCodec *tc = QTextCodec::codecForName("GBK");
    QString str = tc->toUnicode(fd->downloadedData());
    Getlasurl(str);
    str = "https://www.hongyeshuzhai.com/" + str;
    ui->textEdit->setText(str);
    Getessay();
}

void MainWindow::Getlasurl(QString &str) {
    int pos = str.indexOf(las);
    str.truncate(pos);
    str = str.right(35);
    int start = str.indexOf("/");
    int end = str.length() - 2;
    str = str.mid(start, end - start);
}

/*void MainWindow::url_change() {
    url_str = ui->textEdit->toPlainText();
    QString str_page = url_str.right(13);
    str_page.chop(5);
    int page = str_page.toInt() + tag;
    QString str_tmp = QString::number(page) + ".html";
    ui->textEdit->setText(url_str.replace(44, 13, str_tmp));
    Getessay();
}*/

void MainWindow::Getessay() {
    url_str = ui->textEdit->toPlainText();
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
    QString str = tc->toUnicode(fd->downloadedData());
    QString str_change = Translation(str);
    ui->textBrowser->setPlainText(str_change);
}

QString MainWindow::Translation(QString str) {
    QString s;
    int index1 = str.indexOf("<h1>") + 4;
    int index2 = str.indexOf("</h1>");
    s += str.mid(index1, index2 - index1);
    s += '\n';  s += '\n';
    int it = str.indexOf("<div id=\"content\">") + 18;
    while(!dcheck(it, str)) {
        if((str[it] >= 0x4E00 && str[it] <= 0x9FA5) || bcheck(str[it]))
            s += str[it];
        if(xcheck(it, str)) s += '\n';
        it ++;
    }
    return s;
}

bool MainWindow::bcheck(QCharRef a) {
    for(int i = 0; i < 23; i ++)
        if(a == xl[i])  return 1;
    return 0;
}

bool MainWindow::xcheck(int i, QString &str) {
    for(int it = 0; it < 6; it ++)
        if(str[i + it] != xend[it])   return 0;
    return 1;
}

bool MainWindow::dcheck(int i, QString &str) {
    for(int it = 0; it < 6; it ++)
        if(str[i + it] != dend[it])   return 0;
    return 1;
}
