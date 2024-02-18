#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QPushButton *button = new QPushButton(this);
    button->setText("按钮");
    button->move(200,300);//单位是像素
    this->move(0,0);
}

Widget::~Widget()
{
    delete ui;
}
