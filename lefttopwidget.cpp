#include "lefttopwidget.h"
#include "global.h"

leftTopWidget::leftTopWidget(QWidget *parent) : QChartView(parent) {
    // setMinimumSize(400,200);
}

void leftTopWidget::paintStaticChart() {
    //创建图表
    QChart * chart = new QChart();
    this->setChart(chart);
    //创建折线
    QLineSeries * series0 = new QLineSeries ();
    chart->addSeries(series0);
    //序列添加数值
    qreal t = 0, intv = 1;
    for (auto it : dataBucket) {
       series0->append(t, it);
       t += intv;
       if (t > 10000)
            break;
    }
    //创建坐标轴
    QValueAxis *axisX = new QValueAxis; //X轴
    axisX->setRange(0,10000);
    axisX->setTitleText("time(secs)");
    QValueAxis *axisY = new QValueAxis; //Y轴
    axisY->setRange(65, 76);
    axisY->setTitleText("value");
    chart->setAxisX(axisX, series0);
    chart->setAxisY(axisY, series0);
}
