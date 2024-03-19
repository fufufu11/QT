#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

   // ui->pushButton->setStyleSheet("QPushButton {color: red;}");

    //给 widget 本身设置样式
    //this->setStyleSheet("QPushButton{color:red;}");

    //设置指定控件样式
    //ui->pushButton->setStyleSheet("QPushButton{font-size:50px;}");

    //设置第一个按钮为绿色
    ui->pushButton->setStyleSheet("QPushButton{color:green;}");
}

Widget::~Widget()
{
    delete ui;
}
