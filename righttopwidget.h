#ifndef RIGHTTOPWIDGET_H
#define RIGHTTOPWIDGET_H

#include <QListWidget>
#include <QStackedWidget>
#include <QWidget>

#include "conditionwidget.h"
#include "measuresetwidget.h"
#include "parameterswidget.h"
#include "pickwidget.h"
#include "updatewidget.h"

class rightTopWidget : public QWidget {
    Q_OBJECT
   public:
    explicit rightTopWidget(QWidget *parent = nullptr);
    QStackedWidget *stackedWidget;
    parametersWidget *parameterswidget;
    conditionWidget *conditionwidget;
    measuresetWidget *measuresetwidget;
    pickWidget *pickwidget;
    updateWidget *updatewidget;

   signals:

   public slots:
   private:
};

#endif  // RIGHTTOPWIDGET_H
