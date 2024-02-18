#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QValidator>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //设置按钮默认是禁用状态
    ui->pushButton->setEnabled(false);

    //初始化第一个输入框
    ui->lineEdit_name->setPlaceholderText("请输入姓名");
    ui->lineEdit_name->setClearButtonEnabled(true);

    //初始化第二个输入框
    ui->lineEdit_password->setPlaceholderText("请输入密码");
    ui->lineEdit_password->setClearButtonEnabled(true);
    ui->lineEdit_password->setEchoMode(QLineEdit::Password);

    //初始化第三个输入框
    ui->lineEdit_phone->setPlaceholderText("请输入电话号码");
    ui->lineEdit_phone->setClearButtonEnabled(true);
    //验证手机号码必须是 11 位数字，并且按照 “344”的格式输入
    //ui->lineEdit_phone->setInputMask("000-0000-0000");

    //给 lineEdit_phone 注册一个 validator
    ui->lineEdit_phone->setValidator(new QRegularExpressionValidator(QRegularExpression("^1\\d{10}$")));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    QString gender = ui->radioButton_male->isChecked() ? "男" : "女";
    qDebug() << "姓名:" << ui->lineEdit_name->text()
             << "密码:" << ui->lineEdit_password->text()
             << "性别:" << gender
             << "电话:" << ui->lineEdit_phone->text();
}


void Widget::on_lineEdit_phone_textEdited(const QString &arg1)
{
    QString content = arg1;
    int pos = 0;
    if(ui->lineEdit_phone->validator()->validate(content,pos) == QValidator::Acceptable)
    {
        //验证通过，设置按钮为可用状态
        ui->pushButton->setEnabled(true);
    }
    else
    {
        //验证不通过，按钮为禁用状态
        ui->pushButton->setEnabled(false);

    }
}

