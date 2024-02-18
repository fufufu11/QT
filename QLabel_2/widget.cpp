#include "widget.h"
#include "ui_widget.h"
#include <QPixMap>
#include <QDebug>
#include <QResizeEvent>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 设置 label 大小和窗口一样大
    QRect windowRect = this->geometry();
    ui->label->setGeometry(0,0,windowRect.width(),windowRect.height());

    QPixmap pixmap(":/loong.png");
    ui->label->setPixmap(pixmap);
    // 设置内容伸缩
    ui->label->setScaledContents(true);

}

Widget::~Widget()
{
    delete ui;
}

void Widget::resizeEvent(QResizeEvent *event)//这个函数会在窗口大小改变时被自动调用
{
    ui->label->setGeometry(0,0,event->size().width(),event->size().height());
    qDebug() << event->size();
}
