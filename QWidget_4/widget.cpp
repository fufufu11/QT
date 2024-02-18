#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setWindowTitle("窗口标题");

    QPushButton *button = new QPushButton(this);
    button->setText("按钮");
    button->setWindowTitle("按钮标题");
}

Widget::~Widget()
{
    delete ui;
}
