#include "widget.h"
#include "ui_widget.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //创建顶层 layout
    QVBoxLayout* vLayout = new QVBoxLayout(this);
    //添加两个按钮进去
    QPushButton* btn1 = new QPushButton("按钮1");
    QPushButton* btn2 = new QPushButton("按钮2");
    vLayout->addWidget(btn1);
    vLayout->addWidget(btn2);

    //创建要嵌套进去的 layout
    QHBoxLayout* hLayout = new QHBoxLayout(this);
    //添加两个按钮进去
    QPushButton* btn3 = new QPushButton("按钮3");
    QPushButton* btn4 = new QPushButton("按钮4");
    hLayout->addWidget(btn3);
    hLayout->addWidget(btn4);
    //嵌套
    vLayout->addLayout(hLayout);
}

Widget::~Widget()
{
    delete ui;
}
