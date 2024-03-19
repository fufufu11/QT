#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    manager = new QNetworkAccessManager(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    //1.获取到输入框中的 URL ，构造 QUrl对象
    QUrl url(ui->lineEdit->text());
    //2.构造 HTTP 请求对象
    QNetworkRequest request(url);
    //3.发送GET请求
    QNetworkReply* response = manager->get(request);
    //4.通过信号槽来处理响应
    connect(response,&QNetworkReply::finished,this,[=](){
        if(response->error() == QNetworkReply::NoError)
        {
            //响应正确
            QString html(response->readAll());
            ui->plainTextEdit->setPlainText(html);
        }
        else
        {
            //响应出错
            ui->plainTextEdit->setPlainText(response->errorString());
        }
        response->deleteLater();
    });
}

