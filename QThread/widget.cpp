#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(&t,&TimeThread::sendTime,this,&Widget::showTime);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::showTime(QString time)
{
    ui->label->setText(time);
}

void Widget::on_pushButton_clicked()
{
    t.start();
}

