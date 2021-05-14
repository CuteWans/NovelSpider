#ifndef CACTION_H
#define CACTION_H

#include <QAction>
#include <QMainWindow>
#include <QObject>
#include <QWidget>

class CAction : public QAction {
    Q_OBJECT
private :
    int page;
public :
    CAction(int page, const QString & text, QObject* parent = nullptr);
public slots :
    void onActionTrig();
signals :
    void clicked(int page);
};

#endif // CACTION_H
