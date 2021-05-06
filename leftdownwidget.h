#ifndef LEFTDOWNWIDGET_H
#define LEFTDOWNWIDGET_H

#include <QWidget>
#include <QtCharts>
using namespace QtCharts;

class leftDownWidget : public QChartView {
    Q_OBJECT
   public:
    explicit leftDownWidget(QWidget *parent = nullptr);
    void paintStaticChart();
   signals:

   public slots:
};

#endif  // LEFTDOWNWIDGET_H
