#include "widget.h"
#include "ui_widget.h"
#include <QLabel>
#include <QDebug>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //创建label对象
    QLabel *label = new QLabel(this);//推荐这种写法，后面再讲对象树时会讲到
    //QLabel label(this);//这种写法也可以，但是不推荐

    label->setText("Hello World!");//编辑文本
}

Widget::~Widget()
{
    qDebug() << "析构函数";
    delete ui;
}
