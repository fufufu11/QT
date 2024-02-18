#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    connect(ui->pushButton,&QPushButton::clicked,this,&Widget::handClick);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::handClick()
{
    if(ui->pushButton->text() == QString("Hello World!"))
    {
        ui->pushButton->setText("Hello Qt!");
    }
    else
    {
        ui->pushButton->setText("Hello World!");
    }
}
