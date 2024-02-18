#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->pushButton_yes->setToolTip("这是一个yes按钮");
    ui->pushButton_yes->setToolTipDuration(3000);//设置为 3 秒

    ui->pushButton_no->setToolTip("这是一个no按钮");
    ui->pushButton_no->setToolTipDuration(3000);

}

Widget::~Widget()
{
    delete ui;
}
