#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //要实现的功能是点击“关闭”按钮，窗口关闭
    QPushButton* button = new QPushButton(this);//创建一个button对象
    button->setText("关闭");//设置button上的文字
    button->move(200,200);//设置button的位置
    connect(button,&QPushButton::clicked,this,&Widget::close);
}

Widget::~Widget()
{
    delete ui;
}
