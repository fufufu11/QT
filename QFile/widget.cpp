#include "widget.h"
#include "ui_widget.h"
#include <QFileDialog>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    //通过文件对话框获取到打开的文件路径
    QString path = QFileDialog::getOpenFileName(this);
    //设置该文件路径到 lineEdit
    ui->lineEdit->setText(path);
    //创建一个文件对象
    QFile file(path);
    //以追加的方式写文件
    file.open(QIODevice::Append);
    file.write("这是示例");
    file.close();
    //只读方式打开文件
    file.open(QIODevice::ReadOnly);
    //读取文件的内容保存到 str
    QString str = file.readAll();
    //将文件内容设置到 textEdit
    ui->textEdit->setText(str);
    //关闭文件
    file.close();
}

