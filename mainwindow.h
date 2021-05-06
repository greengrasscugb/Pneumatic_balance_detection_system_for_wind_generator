#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSplitter>
#include <vector>
#include <QPixmap>
#include "leftdownwidget.h"
#include "lefttopwidget.h"
#include "rightdownwidget.h"
#include "righttopwidget.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void parametersConfirm();

private:

    QPixmap pixmap;

    leftTopWidget *leftTop;
    leftDownWidget *leftDown;
    rightTopWidget *rightTop;
    rightDownWidget *rightDown;

    QSplitter *splitterMain;
    QSplitter *splitterRight;
    QSplitter *splitterLeft;

    QMenu *fileMenu;
    QMenu *setMenu;
    QMenu *measureMessageMenu;
    QMenu *measureFunctionMenu;
    QMenu *viewActionMenu;
    QMenu *relateActionMenu;

    QAction *newBuiltAction;
    QAction *openAction;
    QAction *addaction;
    QAction *saveAction;
    QAction *repoartAction;
    QAction *exitAction;

    QAction *parametersAction;
    QAction *conditionAction;
    QAction *measuresetAction;

    //    QAction *recieveAction;
    QAction *pickAction;
    //    QAction *viewAction;
    QAction *updateAction;

    QAction *bladeAngleAction;
    QAction *bladeTwistAction;
    QAction *bladePitchAction;
    QAction *towerVibrationAction;
    QAction *fanClearanceAction;
    QAction *bladeDeflectionAction;
    QAction *yawDetectionAction;
    QAction *bladetopbeforeAction;
    QAction *bladetopbehindAction;
    QAction *bladerootbeforeAction;
    QAction *bladerootbehindAction;
    QAction *enlargeAction;
    QAction *shrinkAction;

    QAction *softwareVersionAction;
    QAction *technicalSupportAction;

private slots:
    void newBuilt();
    void open();
    void add();
    void save();
    void repoart();
    void parameters();  //风机信息
    void condition();   //条件信息
    void measureset();  //数据信息
    //    void recieve();
    void pick();
    //    void view();
    void update();
    void bladeAngle();
    void bladeTwist();
    void bladePitch();
    void towerVibration();
    void fanClearance();
    void bladeDeflection();
    void yawDetection();
    void enlarge();
    void shrink();
    void bladetopbefore();
    void bladetopbehind();
    void bladerootbefore();
    void bladerootbehind();
    void softwareVersion();
    void technicalSupport();
};

#endif  // MAINWINDOW_H
