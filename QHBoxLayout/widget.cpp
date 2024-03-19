#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>
#include <QHBoxLayout>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QPushButton* btn1 = new QPushButton("按钮1");
    QPushButton* btn2 = new QPushButton("按钮2");
    QPushButton* btn3 = new QPushButton("按钮3");

    QHBoxLayout* layout = new QHBoxLayout(this);

    layout->addWidget(btn1);
    layout->addWidget(btn2);
    layout->addWidget(btn3);
}


Widget::~Widget()
{
    delete ui;
}
