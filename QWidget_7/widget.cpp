#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QCursor cursor(Qt::WaitCursor);//创建一个“等待”光标的对象
    ui->pushButton->setCursor(cursor);//设置光标
}

Widget::~Widget()
{
    delete ui;
}
