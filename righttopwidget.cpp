#include "righttopwidget.h"

rightTopWidget::rightTopWidget(QWidget *parent) : QWidget(parent) {
    stackedWidget = new QStackedWidget(this);
    parameterswidget = new parametersWidget;
    conditionwidget = new conditionWidget;
    measuresetwidget = new measuresetWidget;
    pickwidget = new pickWidget;
    updatewidget = new updateWidget;

    stackedWidget->addWidget(parameterswidget);
    stackedWidget->addWidget(conditionwidget);
    stackedWidget->addWidget(measuresetwidget);
    stackedWidget->addWidget(pickwidget);
    stackedWidget->addWidget(updatewidget);
    stackedWidget->setCurrentIndex(0);
}
