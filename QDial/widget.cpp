#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //设置可以循环旋转
    ui->dial->setWrapping(true);
    //设置刻度线可见
    ui->dial->setNotchesVisible(true);
    //设置最大值
    ui->dial->setMaximum(100);
    //设置最小值
    ui->dial->setMinimum(0);
    //设置初始值为
    ui->dial->setValue(100);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_dial_valueChanged(int value)
{
    ui->label->setText(QString("当前不透明度为： ") + QString::number(value));
    this->setWindowOpacity((double)value / 100);
}

