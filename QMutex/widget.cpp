#include "widget.h"
#include "ui_widget.h"
#include <mythread.h>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    myThread *t1 = new myThread(this);
    myThread *t2 = new myThread(this);
    t1->start();
    t2->start();
}

Widget::~Widget()
{
    delete ui;
}
