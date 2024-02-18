#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    myButton = new QPushButton(this);
    myButton->setText("Hello World!");
    connect(myButton,&QPushButton::clicked,this,&Widget::handleClick);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::handleClick()
{
    if(myButton->text() == QString("Hello World!"))
    {
        myButton->setText("Hello Qt!");
    }
    else
    {
        myButton->setText("Hello World!");
    }
}
