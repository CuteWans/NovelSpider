#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QNetworkAccessManager>
#include <QNetworkAddressEntry>
#include <QNetworkReply>
#include <QByteArray>
#include "filedownloader.h"
#include <QTextCodec>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    QString url_str;
    QString page;
    QString name;
    int tag = 0;
public:
    MainWindow(QWidget *parent = nullptr);
    QString Translation_text(QString str);
    QString Translation_book(QString str);
    QString Translation_chapter(QString str);
    QString number_Transfer_BigChinese(double Fnumber);
    void find_essay_page();
    void Getpreurl(QString &str);
    void Getlasurl(QString &str);
    bool dcheck(int it, QString &str);
    bool xcheck(int it, QString &str);
    bool bcheck(QCharRef a);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    FileDownloader* fd;
    FileDownloader* fd_booklist;
    FileDownloader* fd_bookmenu;

public slots:
    void Getessay();
    void Getessay_pre();
    void Getessay_las();
    void loadText();
    void loadText_booklist();
    void loadText_bookmenu();
};
#endif // MAINWINDOW_H
