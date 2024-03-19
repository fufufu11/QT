#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    timer_id1 = startTimer(1000);
    timer_id2 = startTimer(2000);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::timerEvent(QTimerEvent *event)
{
    if(event->timerId() == timer_id1)
    {
        static int num1 = 1;
        ui->lcdNumber->display(num1++);
    }
    if(event->timerId() == timer_id2)
    {
        static int num2 = 1;
        ui->lcdNumber_2->display(num2++);
    }
}
