#include "widget.h"
#include "ui_widget.h"
#include <QRadioButton>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->radioButton_male->setChecked(true);
    ui->label->setText("您选择的性别为：男");

    //禁用 other 选项
    //ui->radioButton_other->setCheckable(false);
    ui->radioButton_other->setEnabled(false);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_radioButton_male_clicked()
{
    ui->label->setText("您选择的性别为：男");
}


void Widget::on_radioButton_female_clicked()
{
    ui->label->setText("您选择的性别为：女");
}


void Widget::on_radioButton_other_clicked()
{
    ui->label->setText("您选择的性别为：其他");
}

