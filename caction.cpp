#include "caction.h"

CAction::CAction(int __page, const QString & text, QObject* parent) : QAction(text, parent), page(__page) {
    connect(this, &QAction::triggered, this, &CAction::onActionTrig);
}

void CAction::onActionTrig() {
    emit clicked(page);
}
