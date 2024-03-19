#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 1.设置窗口标题
    this->setWindowTitle("客户端");
    //2.实例化 socket 对象
    socket = new QTcpSocket(this);
    //3.和服务器建立连接
    socket->connectToHost("127.0.0.1",9090);
    //4.等待并确认连接是否出错
    if(!socket->waitForConnected())
    {
        QMessageBox::critical(nullptr,"连接服务器出错",socket->errorString());
        exit(1);
    }
    connect(socket,&QTcpSocket::readyRead,this,[=](){
        QString response = socket->readAll();
        ui->listWidget->addItem(QString("服务器说： ") + response);
    });
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    //获取输入框内容
    const QString& text = ui->lineEdit->text();
    //清空输入框内容
    ui->lineEdit->setText("");
    //把消息显示到界面上
    ui->listWidget->addItem(QString("客户端说： ") + text);
    //发送消息给服务器
    socket->write(text.toUtf8());
}

