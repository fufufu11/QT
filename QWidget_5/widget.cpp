#include "widget.h"
#include "ui_widget.h"
#include <QIcon>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //创建图标对象
   // QIcon icon("d:/txt.png");
    QIcon icon(":/txt.png");
    //设置图标
    this->setWindowIcon(icon);

}

Widget::~Widget()
{
    delete ui;
}
