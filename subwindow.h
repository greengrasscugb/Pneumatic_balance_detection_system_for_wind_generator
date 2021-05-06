#ifndef SUBWINDOW_H
#define SUBWINDOW_H

#include <QWidget>
#include <QtCharts>  //必须这么设置
QT_CHARTS_USE_NAMESPACE     //必须这么设置
#include  <QLabel>

#include  "qwchartview.h"
namespace Ui {
class Subwindow;
}

class Subwindow : public QChartView
{
    Q_OBJECT
private:
    QLabel  *labXYValue; //状态栏显示文字标签
    void    createChart(); //创建图表
    void    prepareData();  //准备数据
public:
    explicit Subwindow(QWidget *parent = 0);
    ~Subwindow();
private slots:
    void on_LegendMarkerClicked(); //图例单击槽函数,自定义槽函数
    void on_mouseMovePoint(QPoint point); //鼠标移动事件，自定义槽函数
    void on_actZoomReset_triggered(); //工具栏按钮，原始大小
    void on_actZoomIn_triggered(); //工具栏按钮，放大
    void on_actZoomOut_triggered(); //工具栏按钮，缩小
private:
    Ui::Subwindow *ui;
};

#endif // SUBWINDOW_H
