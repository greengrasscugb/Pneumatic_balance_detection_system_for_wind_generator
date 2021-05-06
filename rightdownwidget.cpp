#include <QStandardItemModel>

#include "rightdownwidget.h"
rightDownWidget::rightDownWidget(QWidget *parent) : QWidget(parent) {
    tablewidget = new tableWidget;
    tablewidget->setParent(this);
    tablewidget->show();
}
