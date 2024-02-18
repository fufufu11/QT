#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    connect(this,&Widget::MySignal,this,&Widget::MySlot);
    EmitSignal();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::MySlot(QString str)
{
    qDebug() << str;
}

void Widget::EmitSignal()
{
    QString str = "Hello";
    emit MySignal(str);//发射信号
}
