#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>
#include <QGridLayout>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //创建四个按钮
    QPushButton* btn1 = new QPushButton("按钮1");
    QPushButton* btn2 = new QPushButton("按钮2");
    QPushButton* btn3 = new QPushButton("按钮3");
    QPushButton* btn4 = new QPushButton("按钮4");

    //创建网格布局管理器，并且添加元素
    QGridLayout* layout = new QGridLayout();
    layout->addWidget(btn1,0,0);
    layout->addWidget(btn2,1,1);
    layout->addWidget(btn3,2,2);
    layout->addWidget(btn4,10,10);

    //设置 layout 到窗口中
    this->setLayout(layout);
}

Widget::~Widget()
{
    delete ui;
}
