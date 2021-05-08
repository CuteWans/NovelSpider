#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QNetworkAccessManager>
#include <QNetworkAddressEntry>
#include <QNetworkReply>
#include <QByteArray>
#include <QTextCodec>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    QString name;
public:
    MainWindow(QWidget *parent = nullptr);
    void keyPressEvent(QKeyEvent* event);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

public slots:
    void Getessay();
};
#endif // MAINWINDOW_H
