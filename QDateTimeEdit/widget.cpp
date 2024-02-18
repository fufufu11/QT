#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    // 获取到两个时间框的时间日期
    QDateTime timeOld = ui->dateTimeEdit_old->dateTime();
    QDateTime timeNew = ui->dateTimeEdit_new->dateTime();

    //计算日期差值
    //int days = timeOld.daysTo(timeNew);
    int days = (timeOld.secsTo(timeNew) / 3600) / 24;
    int hours = (timeOld.secsTo(timeNew) / 3600) % 24;

    //设置 label 内容
    ui->label->setText(QString::number(days) + "天" + QString::number(hours) + QString("个小时"));
}

