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
    int tag = 0;
public:
    MainWindow(QWidget *parent = nullptr);
    QString Translation(QString str);
    bool dcheck(int it, QString &str);
    bool xcheck(int it, QString &str);
    bool bcheck(QCharRef a);
    void url_change();
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    FileDownloader* fd;

public slots:
    void Getessay();
    void Getessay_pre();
    void Getessay_las();
    void loadText();
};
#endif // MAINWINDOW_H
