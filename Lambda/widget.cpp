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
    connect(button,&QPushButton::clicked,this,[=](){
        qDebug() << "Lambda 被执行了";
        button->move(300,300);
    });
}

Widget::~Widget()
{
    delete ui;
}
