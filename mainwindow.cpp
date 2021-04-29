#include "mainwindow.h"
#include "ui_mainwindow.h"

QString xend = "</br>";
QString dend = "</div>";
QString xl = "，。“”？";

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
    QString str = tc->toUnicode(fd->downloadedData());
    QString str_change = Translation(str);
    ui->textBrowser->setPlainText(str_change);
}

QString MainWindow::Translation(QString str) {
    QString s;
    int index1 = str.indexOf("<h1>") + 4;
    int index2 = str.indexOf("</h1>");
    s += str.mid(index1, index2 - index1);
    s += '\n';
    int it = str.indexOf("<div id=\"content\">") + 18;
    while(!dcheck(it, str)) {
        if(str[it] >= 0x4E00 && str[it] <= 0x9FA5)
            s += str[it];
        if(xcheck(it, str)) s += '\n';
        it ++;
    }
    return s;
}

bool MainWindow::xcheck(int i, QString &str) {
    for(int it = 0; it < 5; it ++)
        if(str[i + it] != xend[it])   return 0;
    return 1;
}

bool MainWindow::dcheck(int i, QString &str) {
    for(int it = 0; it < 6; it ++)
        if(str[i + it] != dend[it])   return 0;
    return 1;
}
