#include "widget.h"
#include "ui_widget.h"
#include <QButtonGroup>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //创建三个 QButtonGroup
    QButtonGroup* group1 = new QButtonGroup(this);
    QButtonGroup* group2 = new QButtonGroup(this);
    QButtonGroup* group3 = new QButtonGroup(this);

    //把 QRadioButton 两两一组，放到三个 QButtonGroup 中
    group1->addButton(ui->radioButton);
    group1->addButton(ui->radioButton_2);

    group2->addButton(ui->radioButton_3);
    group2->addButton(ui->radioButton_4);

    group3->addButton(ui->radioButton_5);
    group3->addButton(ui->radioButton_6);

}

Widget::~Widget()
{
    delete ui;
}
