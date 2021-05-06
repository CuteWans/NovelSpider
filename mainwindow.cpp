#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

QString xend = "<br />";
QString dend = "</div>";
QString xl = "，。“”？：！…‘’~—*（）《》【】·；、_";
QString pre = "上一章";
QString las = "下一章";

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), fd(nullptr), fd_booklist(nullptr), fd_bookmenu(nullptr), menu(new QString [10005][2]) {
    ui->setupUi(this);
    tot = 0;    page = 1;
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::Getessay);
    connect(ui->pushButton_4, &QPushButton::clicked, this, &MainWindow::Getessay_page);
    connect(ui->pushButton_3, &QPushButton::clicked, this, &MainWindow::Getessay_las);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &MainWindow::Getessay_pre);
}

void MainWindow::Getessay_page() {
    QString page_str = ui->textEdit_2->toPlainText();
    page = page_str.toInt();
    QUrl url(menu[page][0]);
    if(fd != nullptr)   delete fd;
    fd = new FileDownloader(url, this);
    connect(fd, SIGNAL (downloaded()), this, SLOT (loadText()));
}

void MainWindow::Getessay_pre() {
    QTextCodec *tc = QTextCodec::codecForName("GBK");
    QString str = tc->toUnicode(fd->downloadedData());
    Getpreurl(str);
    str = "https://www.hongyeshuzhai.com/" + str;
    QUrl url(str);
    if(fd != nullptr)   delete fd;
    fd = new FileDownloader(url, this);
    connect(fd, SIGNAL (downloaded()), this, SLOT (loadText()));
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
    QUrl url(str);
    if(fd != nullptr)   delete fd;
    fd = new FileDownloader(url, this);
    connect(fd, SIGNAL (downloaded()), this, SLOT (loadText()));
}

void MainWindow::Getlasurl(QString &str) {
    int pos = str.indexOf(las);
    str.truncate(pos);
    str = str.right(35);
    int start = str.indexOf("/");
    int end = str.length() - 2;
    str = str.mid(start, end - start);
}

void MainWindow::Getessay() {
    name = ui->textEdit->toPlainText();
    find_essay_page();
}

void MainWindow::find_essay_page() {
    QUrl url("https://www.hongyeshuzhai.com/xiaoshuodaquan/");
    if(fd_booklist != nullptr)   delete fd_booklist;
    fd_booklist = new FileDownloader(url, this);
    connect(fd_booklist, &FileDownloader::downloaded, this, &MainWindow::loadText_booklist);
}

//小说大全页面查找指定书目
void MainWindow::loadText_booklist() {
    QTextCodec *tc = QTextCodec::codecForName("GBK");
    QString str = tc->toUnicode(fd_booklist->downloadedData());
    QString str_bookmenu = Translation_book(str);
    QUrl url(str_bookmenu);
    if(fd_bookmenu != nullptr)   delete fd_bookmenu;
    fd_bookmenu = new FileDownloader(url, this);
    connect(fd_bookmenu, &FileDownloader::downloaded, this, &MainWindow::loadText_bookmenu);
}

QString MainWindow::Translation_book(QString str) {
    QString s;
    int index2 = str.indexOf(name) - 2;
    int index1 = index2 - 44;//////网址位数不确定
    s = str.mid(index1, 44);
    return s;
}

//指定小说页面查找指定章节
void MainWindow::loadText_bookmenu() {
    QTextCodec *tc = QTextCodec::codecForName("GBK");
    QString str = tc->toUnicode(fd_bookmenu->downloadedData());
    Translation_chapter(str);
    QString str_chapter = menu[page][0];
    QUrl url(str_chapter);
    if(fd != nullptr)   delete fd;
    fd = new FileDownloader(url, this);
    connect(fd, SIGNAL (downloaded()), this, SLOT (loadText()));
}

void MainWindow::Translation_chapter(QString str) {
    QString s;
    int index1 = str.indexOf("<dt>");
    int index2 = str.indexOf("<dt>",index1 + 4);
    while((index2 = str.indexOf("<dd>", index2 + 4)) > 0) {
        int index3 = str.indexOf("/", index2);
        menu[++tot][0] = "https://www.hongyeshuzhai.com" + str.mid(index3, 28);
        int index4 = str.indexOf(">", index3) + 1;
        int index5 = str.indexOf("<", index4);
        menu[tot][1] = str.mid(index4, index5 - index4);
    }
}

MainWindow::~MainWindow() {
    delete ui;
}

//分析文章正文
void MainWindow::loadText() {
    QTextCodec *tc = QTextCodec::codecForName("GBK");
    QString str = tc->toUnicode(fd->downloadedData());
    QString str_change = Translation_text(str);
    ui->textBrowser->setPlainText(str_change);
}

QString MainWindow::Translation_text(QString str) {
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
