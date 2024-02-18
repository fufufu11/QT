#include "widget.h"
#include "ui_widget.h"
#include <Qicon>
#include <QPushButton>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //创建图标
    QIcon icon(":/image/pushbutton.png");
    //设置图标
    ui->pushButton->setIcon(icon);
    //设置图标大小
    ui->pushButton->setIconSize(QSize(50,50));
}

Widget::~Widget()
{
    delete ui;
}
