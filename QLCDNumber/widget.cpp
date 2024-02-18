#include "widget.h"
#include "ui_widget.h"
#include <QTimer>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //创建 timer 实例
    timer = new QTimer(this);
    //连接信号槽，QTimer 会每隔一定的时间触发一个 timeout 信号，现在把 timeout 信号和 updateTime 连接起来
    //此时意味着每次触发 timeout 信号都会伴随 updateTimt 函数的执行
    connect(timer,&QTimer::timeout,this,&Widget::updateTime);
    timer->start(1000);//1 秒

}

Widget::~Widget()
{
    delete ui;
}

void Widget::updateTime()
{
    qDebug() << "updateTime";
    int value = ui->lcdNumber->intValue();
    if(value <= 0)
    {
        // 如果时间到，停止定时器
        timer->stop();
        return;
    }
    ui->lcdNumber->display(value - 1);
}


