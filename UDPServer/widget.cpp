#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>
#include <QNetworkDatagram>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //1.设置窗口标题
    this->setWindowTitle("服务器");
    //2.实例化 socket
    socket = new QUdpSocket(this);
    //3.连接信号槽，处理收到的请求
    connect(socket,&QUdpSocket::readyRead,this,&Widget::processRequest);
    //4.绑定端口
    bool ret = socket->bind(QHostAddress::Any,9090);
    if(!ret)
    {
        QMessageBox::critical(nullptr,"服务器启动出错",socket->errorString());
        return;
    }
}

Widget::~Widget()
{
    delete ui;
}

void Widget::processRequest()
{
    //1.读取请求
    const QNetworkDatagram& requestDatagram = socket->receiveDatagram();
    QString request = requestDatagram.data();
    //2.根据请求计算响应
    const QString& response = process(request);
    //3.把响应写到客户端
    QNetworkDatagram responseDatagram(response.toUtf8(),
                                      requestDatagram.senderAddress(),requestDatagram.senderPort());
    socket->writeDatagram(responseDatagram);

    // 显示打印日志
    QString log = "[" + requestDatagram.senderAddress().toString() + ":" +
                  QString::number(requestDatagram.senderPort()) + "] req:"+
                  request + ",resp: " + response;
    ui->listWidget->addItem(log);
}

QString Widget::process(const QString& request)
{
    return request;
}
