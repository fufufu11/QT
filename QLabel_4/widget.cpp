#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->label->setBuddy(ui->radioButton);
    ui->label_2->setBuddy(ui->radioButton_2);
}

Widget::~Widget()
{
    delete ui;
}
