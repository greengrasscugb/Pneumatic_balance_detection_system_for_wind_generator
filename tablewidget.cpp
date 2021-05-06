#include <QDebug>
#include <QStandardItemModel>
#include <QString>
#include <qmath.h>
#include "global.h"
#include "tablewidget.h"
tableWidget::tableWidget(QWidget* parent) : QTableView(parent) {
    _model = new QStandardItemModel(this);
    for (int i = 0; i < dataBucket.size(); i++) {
        _model->setItem(i, 0, new QStandardItem(QString::number(dataBucket[i])));
    }
    this->setFixedSize(400, 750);
    this->setModel(_model);
    //connect(_model, SIGNAL(dataChanged(QModelIndex,QModelIndex,QVector<int>)), this, SLOT(dataChangedSlot(QModelIndex,QModelIndex,QVector<int>)));
}
tableWidget::~tableWidget() {
}
//void tableWidget::dataChangedSlot(const QModelIndex &topLeft, const QModelIndex &bottomRight, const QVector<int> &roles){
//    qDebug() << _model->data(topLeft).toString() << endl;
//}
tableWidget:: update1(){
    QStandardItemModel* model = new QStandardItemModel(this);
    for (int i = 0; i < dataBucket.size(); i++) {
        model->setItem(i, 0, new QStandardItem(QString::number(dataBucket[i])));
    }
    this->setModel(model);
    this->setFixedSize(400, 750);
}
void tableWidget:: slotitemChanged(QTableWidgetItem * item){
//    qDebug() << "运行到这里了";
         QString s=_model->item(item->row(),item->column())->text();
        dataBucket[item->row()]=s.toDouble();
//        qDebug() << dataBucket[item->row()];
}

