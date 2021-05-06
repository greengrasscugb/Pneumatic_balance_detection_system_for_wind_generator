#ifndef MEASURESETWIDGET_H
#define MEASURESETWIDGET_H

#include <QLabel>
#include <QLineEdit>
#include <QTextCodec>
#include <QWidget>
#include <QPushButton>

class measuresetWidget : public QWidget {
    Q_OBJECT
   public:
    explicit measuresetWidget(QWidget *parent = nullptr);

   signals:

   public slots:
    void sendInfo();
   private:
    QLabel *aAngleLabel;
    QLineEdit *aAngleEdit;
    QLabel *bAngelLabel;
    QLineEdit *bAngleEdit;
    QPushButton *confirmButton;
};

#endif  // MEASURESETWIDGET_H
