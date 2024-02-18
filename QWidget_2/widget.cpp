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

void Widget::on_pushButton_up_clicked()
{
    QRect rect = ui->pushButton_target->geometry();
    //rect.setY(rect.y() - 10);
    //ui->pushButton_target->setGeometry(rect);
    ui->pushButton_target->setGeometry(rect.x(),rect.y() - 10,rect.width(),rect.height());
}


void Widget::on_pushButton_down_clicked()
{
    QRect rect = ui->pushButton_target->geometry();
   // rect.setY(rect.y() + 10);
    //ui->pushButton_target->setGeometry(rect);
    ui->pushButton_target->setGeometry(rect.x(),rect.y() + 10,rect.width(),rect.height());
}



void Widget::on_pushButton_left_clicked()
{
    QRect rect = ui->pushButton_target->geometry();
    //rect.setX(rect.x() - 10);
    //ui->pushButton_target->setGeometry(rect);
    ui->pushButton_target->setGeometry(rect.x() - 10,rect.y(),rect.width(),rect.height());
}


void Widget::on_pushButton_right_clicked()
{
    QRect rect = ui->pushButton_target->geometry();
    //rect.setX(rect.x() + 10);
    //ui->pushButton_target->setGeometry(rect);
    ui->pushButton_target->setGeometry(rect.x() + 10,rect.y(),rect.width(),rect.height());
}

