#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>
#include <QTcpSocket>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //1. 设置窗口标题
    this->setWindowTitle("服务器");
    //2. 实例化 Tcp server
    tcpServer = new QTcpServer(this);
    //3. 通过信号槽，处理客户端建立新的连接
    connect(tcpServer,&QTcpServer::newConnection,this,&Widget::processConnect);
    //4.监听端口
    bool ret = tcpServer->listen(QHostAddress::Any,9090);
    if(!ret)
    {
        QMessageBox::critical(nullptr,"服务器启动失败",tcpServer->errorString());
        exit(1);
    }
}

Widget::~Widget()
{
    delete ui;
}

void Widget::processConnect()
{
    //1.获取到新的连接对应的 socket
    QTcpSocket* clientSocket = tcpServer->nextPendingConnection();
    QString log = "[" + clientSocket->peerAddress().toString() +
                  ":" + QString::number(clientSocket->peerPort()) + "] 客户端上线";
    ui->listWidget->addItem(log);
    //2.通过信号槽，处理收到请求的情况
    connect(clientSocket,&QTcpSocket::readyRead,this,[=](){
        //2.1 读取请求
        QString request = clientSocket->readAll();
        //2.2 根据请求处理响应
        const QString& response = process(request);
        //2.3 把响应写回到客户端
        clientSocket->write(response.toUtf8());

        QString log = "[" + clientSocket->peerAddress().toString() +
                      ":" + QString::number(clientSocket->peerPort()) + "] req: " +
            request + ", resp:" + response;
        ui->listWidget->addItem(log);
    });
    //3.通过信号槽处理断开连接的情况
    connect(clientSocket,&QTcpSocket::disconnected,this,[=](){
        QString log = "[" + clientSocket->peerAddress().toString() +
            ":" + QString::number(clientSocket->peerPort()) + "] 客户端下线";
        ui->listWidget->addItem(log);
        // 删除 clientSocket
        clientSocket->deleteLater();
    });
}

QString Widget::process(const QString &request)
{
    return request;
}
