#ifndef PICKWIDGET_H
#define PICKWIDGET_H
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QTextCodec>
#include <QTextEdit>
#include <QWidget>
class pickWidget : public QWidget {
    Q_OBJECT
   public:
    explicit pickWidget(QWidget *parent = nullptr);
    void pick();
    void correct();
    void finddifference();
    void dataclass();
   public slots:
    void sendInfo();
    void sendInfo1();
    void sendInfo2();
    void sendInfo3();
   private:
    QPushButton *pickButton;
    QPushButton *correctButton;
    QPushButton *finddifferenceButton;
    QPushButton *dataclassButton;
    QLabel *maxLabel;
    QLabel *minLabel;
    QLineEdit *maxEdit;
    QLineEdit *minEdit;
};

#endif  // PICKWIDGET_H
