#ifndef LEFTTOPWIDGET_H
#define LEFTTOPWIDGET_H

#include <QWidget>
#include <QtCharts>
using namespace QtCharts;

class leftTopWidget : public QChartView {
    Q_OBJECT
   public:
    explicit leftTopWidget(QWidget *parent = nullptr);
    void paintStaticChart();
   signals:

   public slots:
};

#endif  // LEFTTOPWIDGET_H
