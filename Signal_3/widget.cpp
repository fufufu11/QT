#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    connect(this,&Widget::MySignal,this,&Widget::MySlots);
    emit MySignal();//触发信号
}

Widget::~Widget()
{
    delete ui;
}

void Widget::MySlots()
{
    qDebug() << "自定义信号和槽";
}
