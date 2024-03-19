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
    QString path = QFileDialog::getOpenFileName(this);

    //文件信息类
    QFileInfo fileinfo(path);
    //打印相关属性
    qDebug() << "文件名字:" << fileinfo.fileName();
    qDebug() << "文件后缀:" << fileinfo.suffix();
    qDebug() << "文件路径:" << fileinfo.path();
    qDebug() << "文件创建时间:" << fileinfo.fileTime(QFileDevice::FileBirthTime);
}

