#include "widget.h"
#include "ui_widget.h"
#include <QNetworkDatagram>
//提前定义好服务器的 IP 和 端口
const QString& SERVER_IP = "127.0.0.1";
const quint16 SERVER_PORT = 9090;
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //1.设置窗口名字
    this->setWindowTitle("客户端");
    //2.实例化 socket
    socket = new QUdpSocket(this);

    //通过信号槽，处理服务器返回的数据
    connect(socket,&QUdpSocket::readyRead,this,&Widget::processResponse);

}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    //1.获取到输入框内容
    const QString& text = ui->lineEdit->text();
    //2.构造请求数据
    QNetworkDatagram requestDatagram(text.toUtf8(),QHostAddress(SERVER_IP),SERVER_PORT);
    //3.发送请求
    socket->writeDatagram(requestDatagram);
    //4.消息添加到列表框中
    ui->listWidget->addItem("客户端说: " + text);
    //5.清空输入框
    ui->lineEdit->setText("");
}

void Widget::processResponse()
{
    const QNetworkDatagram responseDatagram = socket->receiveDatagram();
    QString response = responseDatagram.data();
    ui->listWidget->addItem(QString("服务器：") + response);
}

