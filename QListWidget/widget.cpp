#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->listWidget->addItem("C++");
    ui->listWidget->addItem("Java");
    ui->listWidget->addItem("Python");
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    // 获取当前输入框的内容
    const QString& text = ui->lineEdit->text();
    if(text.isEmpty())
    {
        return;
    }
    ui->listWidget->addItem(text);
}


void Widget::on_pushButton_2_clicked()
{
    //获取当前被选中元素的行数
    int row = ui->listWidget->currentRow();
    //如果未选中 row 为 -1
    //删除这一行
    if(row != -1)
    {
        ui->listWidget->takeItem(row);
    }
}

