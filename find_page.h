#ifndef FIND_PAGE_H
#define FIND_PAGE_H

#include <QMainWindow>
#include <QNetworkAccessManager>
#include <QNetworkAddressEntry>
#include <QNetworkReply>
#include <QByteArray>
#include "filedownloader.h"
#include <QTextCodec>

#include <QDialog>
#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QKeyEvent>

namespace Ui {
class find_page;
}

class find_page : public QMainWindow
{
    Q_OBJECT
    QString url_str;
    int page;
    QString name;
    QString (*menu)[2];
    int tot;
    bool flag;
public:
    find_page(QWidget *parent = nullptr, QString name_tmp = "");
    QString Translation_text(QString str);
    QString Translation_book(QString str);
    void Translation_chapter(QString str);
    void find_essay_page();
    void Getpreurl(QString &str);
    void Getlasurl(QString &str);
    bool dcheck(int it, QString &str);
    bool xcheck(int it, QString &str);
    bool bcheck(QCharRef a);
    void keyPressEvent(QKeyEvent* event);
    ~find_page();

private:
    Ui::find_page *ui;
    FileDownloader* fd;
    FileDownloader* fd_booklist;
    FileDownloader* fd_bookmenu;

public slots:
    void on_pushButton_clicked_();
    void Getessay();
    void Getessay_pre();
    void Getessay_las();
    void Getessay_page();
    void loadText();
    void loadText_booklist();
    void loadText_bookmenu();
};

#endif // FIND_PAGE_H
