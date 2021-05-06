#include <time.h>
#include <QApplication>
#include <QDesktopWidget>
#include <QFile>
#include <QFileDialog>
#include <QMenuBar>
#include <QMessageBox>
#include <QStackedWidget>
#include <QTextStream>
#include <ctime>
#include <QDebug>
#include "global.h"
#include "leftdownwidget.h"
#include "lefttopwidget.h"
#include "mainwindow.h"
#include "rightdownwidget.h"
#include "righttopwidget.h"
#include "tablewidget.h"
#include "subwindow.h"

using namespace std;

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent) {
    setWindowTitle("风力发电机气动平衡检测系统");
    pixmap.load(":/new/prefix1/1.jpg");
    setWindowIcon(pixmap);

    QDesktopWidget* desktop = QApplication::desktop();
    //    resize(desktop->width()/2,desktop->height()/2);
    //    move(desktop->width()/2-this->width()/2,desktop->height()/2-this->height()/2);
    setWindowFlag(Qt::Window);
    setWindowFlags(windowFlags() | Qt::WindowMaximizeButtonHint);
    setWindowFlags(windowFlags() | Qt::WindowMinimizeButtonHint);
    setWindowState(Qt::WindowMaximized);
    //    setFixedSize();
    //    showFullScreen();
    this->setFixedSize(desktop->width(),desktop->height());
    //设置其界面为最大值

    //设置切分
    splitterMain = new QSplitter(Qt::Horizontal, this);  //水平划分
    splitterLeft = new QSplitter(Qt::Vertical, this);
    splitterRight = new QSplitter(Qt::Vertical, this);

    leftDown = new leftDownWidget(this);
    leftTop = new leftTopWidget(this);
    rightTop = new rightTopWidget(this);
    rightDown = new rightDownWidget(this);

    splitterLeft->setOpaqueResize(false);
    splitterRight->setOpaqueResize(false);
    splitterLeft->addWidget(leftTop);
    splitterLeft->addWidget(leftDown);
    splitterRight->addWidget(rightTop);
    splitterRight->addWidget(rightDown);

    splitterRight->setMinimumSize(400, 200);
    splitterRight->setStretchFactor(0,1);
    splitterRight->setStretchFactor(1,4);

    splitterLeft->setStretchFactor(0,-1);
    splitterLeft->setStretchFactor(1,-1);
    //应该会使得控件不可伸缩

    splitterMain->addWidget(splitterLeft);
    splitterMain->addWidget(splitterRight);
    splitterMain->setStyleSheet("QSplitter::handle { background-color: gray }");
    splitterMain->setHandleWidth(10);
    splitterMain->setOpaqueResize(false);
    splitterMain->setStretchFactor(0, 1);

    this->setCentralWidget(splitterMain);
    //切分完毕

    fileMenu = menuBar()->addMenu(tr("项目"));
    setMenu = menuBar()->addMenu(tr("参数信息"));
    measureMessageMenu = menuBar()->addMenu(tr("测量数据"));
    measureFunctionMenu = menuBar()->addMenu(tr("测量功能"));
    viewActionMenu = menuBar()->addMenu(tr("视图"));
    relateActionMenu = menuBar()->addMenu(tr("关于"));
    //添加菜单

//    newBuiltAction = new QAction(tr("新建"), this);
//    fileMenu->addAction(newBuiltAction);
    openAction = new QAction(tr("打开"), this);
    fileMenu->addAction(openAction);
//    addaction = new QAction(tr("添加"), this);
//    fileMenu->addAction(addaction);
    saveAction = new QAction(tr("保存"), this);
    fileMenu->addAction(saveAction);
    repoartAction = new QAction(tr("报告"), this);
    fileMenu->addAction(repoartAction);
    exitAction = new QAction(tr("退出"), this);
    fileMenu->addAction(exitAction);
    //文件操作QAction

    parametersAction = new QAction(tr("传输信息"), this);
    setMenu->addAction(parametersAction);
    conditionAction = new QAction(tr("测量信息"), this);
    setMenu->addAction(conditionAction);
    measuresetAction = new QAction(tr("角度信息"), this);
    setMenu->addAction(measuresetAction);
    //参数设置QAction

    pickAction = new QAction(tr("筛选"), this);
    measureMessageMenu->addAction(pickAction);
    updateAction = new QAction(tr("修改"), this);
    //测量数据QAction

    measureMessageMenu->addAction(updateAction);
    bladeAngleAction = new QAction(tr("叶片偏角"), this);
    measureFunctionMenu->addAction(bladeAngleAction);
    bladeTwistAction = new QAction(tr("叶片扭曲"), this);
    measureFunctionMenu->addAction(bladeTwistAction);
    bladePitchAction = new QAction(tr("叶片齿距"), this);
    measureFunctionMenu->addAction(bladePitchAction);
    towerVibrationAction = new QAction(tr("塔筒震动"), this);
    measureFunctionMenu->addAction(towerVibrationAction);
    fanClearanceAction = new QAction(tr("风机净空"), this);
    measureFunctionMenu->addAction(fanClearanceAction);
    bladeDeflectionAction = new QAction(tr("叶片挠度"), this);
    measureFunctionMenu->addAction(bladeDeflectionAction);
    yawDetectionAction = new QAction(tr("偏航检测"),this);
    measureFunctionMenu->addAction(yawDetectionAction);
    bladetopbeforeAction = new QAction(tr("叶片尖部拟合前"), this);
    measureFunctionMenu->addAction(bladetopbeforeAction);
    bladetopbehindAction = new QAction(tr("叶片尖部拟合后"), this);
    measureFunctionMenu->addAction(bladetopbehindAction);
    bladerootbeforeAction = new QAction(tr("叶片根部拟合前"), this);
    measureFunctionMenu->addAction(bladerootbeforeAction);
    bladerootbehindAction = new QAction(tr("叶片根部拟合后"), this);
    measureFunctionMenu->addAction(bladerootbehindAction);
    //测量功能QAction

    measureFunctionMenu->addAction(yawDetectionAction);
    enlargeAction = new QAction(tr("放大"), this);
    viewActionMenu->addAction(enlargeAction);
    shrinkAction = new QAction(tr("缩小"), this);
    viewActionMenu->addAction(shrinkAction);
    //放大缩小QAction

    softwareVersionAction = new QAction(tr("软件版本"), this);
    relateActionMenu->addAction(softwareVersionAction);
    technicalSupportAction = new QAction(tr("技术支持"), this);
    relateActionMenu->addAction(technicalSupportAction);

    //关联信号槽
    connect(exitAction, SIGNAL(triggered()), this, SLOT(close()));//关闭
    connect(openAction, SIGNAL(triggered()), this, SLOT(open()));//打开
    connect(saveAction, SIGNAL(triggered()), this, SLOT(save()));//保存
    connect(repoartAction, SIGNAL(triggered()), this, SLOT(repoart()));//生成报告
    connect(parametersAction, SIGNAL(triggered()), this, SLOT(parameters()));//测试条件
    connect(conditionAction, SIGNAL(triggered()), this, SLOT(condition()));//风机参数
    connect(measuresetAction, SIGNAL(triggered()), this, SLOT(measureset()));//测量设置
    connect(pickAction, SIGNAL(triggered()), this, SLOT(pick()));//筛选
    connect(updateAction, SIGNAL(triggered()), this, SLOT(update()));//修改
    connect(bladeAngleAction, SIGNAL(triggered()), this, SLOT(bladeAngle()));//叶片偏角
    connect(bladeTwistAction, SIGNAL(triggered()), this, SLOT(bladeTwist()));//叶片扭角
    connect(bladePitchAction, SIGNAL(triggered()), this, SLOT(bladePitch()));//叶片齿距
    connect(towerVibrationAction, SIGNAL(triggered()), this, SLOT(towerVibration()));//塔筒振动
    connect(fanClearanceAction, SIGNAL(triggered()), this, SLOT(fanClearance()));//风机震动
    connect(bladeDeflectionAction, SIGNAL(triggered()), this, SLOT(bladeDeflection()));//叶片挠度
    connect(yawDetectionAction, SIGNAL(triggered()), this, SLOT(yawDetection()));//偏航检测
    connect(bladetopbeforeAction, SIGNAL(triggered()), this, SLOT(bladetopbefore()));//叶片尖部拟合前
    connect(bladetopbehindAction, SIGNAL(triggered()), this, SLOT(bladetopbehind()));//叶片尖部拟合后
    connect(bladerootbeforeAction, SIGNAL(triggered()), this, SLOT(bladerootbefore()));//叶片根部拟合前
    connect(bladerootbehindAction, SIGNAL(triggered()), this, SLOT(bladerootbehind()));//叶片根部拟合后

    connect(enlargeAction, SIGNAL(triggered()), this, SLOT(enlarge()));
    connect(shrinkAction, SIGNAL(triggered()), this, SLOT(shrink()));

    connect(softwareVersionAction, SIGNAL(triggered()), this, SLOT(softwareVersion()));
    connect(technicalSupportAction, SIGNAL(triggered()), this, SLOT(technicalSupport()));
}

MainWindow::~MainWindow() {

}
void MainWindow::newBuilt() {
}

void MainWindow::open() {
    //获取文件路径来打开文件，并检验文件是否打开。否则直接return
    QString fileName = QFileDialog::getOpenFileName(this, tr("打开文件"),
                                                    ".", tr("txt Files (*.txt)"));
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox::warning(NULL, tr("警告！"), tr("未打开任何文件"));
        return;
    }
    //创建一个QtextStream对象来操纵file
    QTextStream fin(&file);
    double tem;
    time_t tv = time(0);
    //当QtextStream对象没有到末尾时，循环
    bool ok = false;
    while (!fin.atEnd()){
        //取得文件中的字符串
        QString s;
        fin >> s;
        tem = s.toDouble(&ok);
        if(!ok){
            //转换失败
            if(s == "D") tem = 0;//标志位的无效数据
            else if(s == "DE02") tem = 1;//错误的无效数据
            else tem = -1;//以-1代表无效数据

        }
        tv = time(0);
        timeStamp.push_back(tv);
        if(tem != 0)
        dataBucket.push_back(tem);
//        qDebug() << temp << " " << tv;
    }
    file.close();
    this->leftTop->paintStaticChart();
    this->leftDown->paintStaticChart();
    rightDown->tablewidget->update1();
}

void MainWindow::add() {
}

void MainWindow::save() {
    // 获取文件路径来打开文件，并检验文件是否打开。否则直接return
    QString fileName = QFileDialog::getSaveFileName(this, tr("保存文件"),
                                                    ".", tr("txt Files (*.txt)"));
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly)) {
        QMessageBox::warning(NULL, tr("警告！"), tr("未成功保存！"));
        return;
    }

    // 创建一个QtextStream对象来操纵file
    QTextStream fout(&file);

    vector<double>::iterator itData = dataBucket.begin();
    //    vector<int>::iterator itTime = timeStamp.begin();
    //时间函数不知道需不需要保存
    for(;itData != dataBucket.end();++itData){
        fout << *itData << endl;
    }
    file.close();
    QMessageBox::information(NULL,tr("提示！"),tr("成功保存！"));
}

void MainWindow::repoart() {
}

void MainWindow::parameters() {//风机信息
    rightTop->stackedWidget->setCurrentIndex(0);
}

void MainWindow::condition() {//条件信息
    rightTop->stackedWidget->setCurrentIndex(1);
}

void MainWindow::measureset() {//数据信息
    rightTop->stackedWidget->setCurrentIndex(2);
}

//void MainWindow::recieve(){

//}

void MainWindow::pick() {
    //筛选
    rightTop->stackedWidget->setCurrentIndex(3);
}

//void MainWindow:: view(){

//}

void MainWindow::update() {
    rightTop->stackedWidget->setCurrentIndex(4);
}

void MainWindow::bladeAngle() {
    //叶片偏角
}

void MainWindow::bladeTwist() {
    //叶片扭角
}

void MainWindow::bladePitch() {
    //叶片齿距
}

void MainWindow::towerVibration() {
    //塔筒振动
}

void MainWindow::fanClearance() {
    //风机净空
}

void MainWindow::bladeDeflection() {
    //叶尖挠度
}

void MainWindow::yawDetection() {
    //偏航检测
}

void MainWindow::enlarge() {
    //图片的放大功能
}

void MainWindow::shrink() {
    //图片的缩小功能
}

void MainWindow::bladetopbefore(){
    //叶片尖部拟合前成图

    //QDialog * dlog = new QDialog(this); //指定父窗口
    //dlog->show();
    //delete dlog;

    Subwindow s;
    s.show();
}

void MainWindow::bladetopbehind(){
    //叶片尖部拟合后成图
}
void MainWindow::bladerootbefore(){
    //叶片根部拟合前成图

}
void MainWindow::bladerootbehind(){
    //叶片根部拟合后成图
}


void MainWindow::softwareVersion() {
    //软件版本
    QMessageBox::information(NULL,tr("软件版本"),tr("风力发电机气动平衡检测系统 v1.1.0  Alpha"));
}

void MainWindow::technicalSupport() {
    //技术支持
    QMessageBox::information(NULL,tr("技术支持"),tr("本软件由中国地质大学（北京）信息工程学院项目组开发"));
}
