#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>
#include <QVBoxLayout>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // //创建三个按钮
    // QPushButton* btn1 = new QPushButton("按钮1");
    // QPushButton* btn2 = new QPushButton("按钮2");
    // QPushButton* btn3 = new QPushButton("按钮3");

    // //创建布局管理器，并且把按钮添加进去。
    // //指定父元素为 this
    // QVBoxLayout* layout = new QVBoxLayout(this);
    // layout->addWidget(btn1);
    // layout->addWidget(btn2);
    // layout->addWidget(btn3);
}

Widget::~Widget()
{
    delete ui;
}
