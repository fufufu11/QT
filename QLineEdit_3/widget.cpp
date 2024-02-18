#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->lineEdit->setEchoMode(QLineEdit::Password);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_checkBox_toggled(bool checked)
{
    if(checked)
    {
        ui->lineEdit->setEchoMode(QLineEdit::Normal);
    }
    else
    {
        ui->lineEdit->setEchoMode(QLineEdit::Password);
    }
}

