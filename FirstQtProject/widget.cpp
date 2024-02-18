#include "widget.h"
#include "ui_widget.h" //form file 被qmake生成的头文件

Widget::Widget(QWidget *parent)  //构造函数
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);  //把form file 生成的界面和当前 widget 关联起来
}

Widget::~Widget()  //析构函数
{
    delete ui;
}
