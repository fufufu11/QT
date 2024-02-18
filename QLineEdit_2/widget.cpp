#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->lineEdit->setEchoMode(QLineEdit::Password);
    ui->lineEdit_2->setEchoMode(QLineEdit::Password);

    ui->label->setText("密码为空");
}

Widget::~Widget()
{
    delete ui;
}

void Widget::compare()
{
    const QString& s1 = ui->lineEdit->text();
    const QString& s2 = ui->lineEdit_2->text();
    if(s1.isEmpty() && s2.isEmpty())
    {
        ui->label->setText("密码为空");
    }
    else if(s1 == s2)
    {
        ui->label->setText("两次输入的密码相同");
    }
    else
    {
        ui->label->setText("两次输入的密码不同");
    }

}

void Widget::on_lineEdit_textEdited(const QString &arg1)
{
    (void) arg1;//因为没有用到这个参数，编译器会报警告，这样写可以骗过编译器。
    compare();
}


void Widget::on_lineEdit_2_textEdited(const QString &arg2)
{
    (void)arg2;
    compare();
}

