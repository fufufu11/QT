#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    // 创建 QMessageBox
    QMessageBox* messageBox = new QMessageBox(this);
    messageBox->setWindowTitle("对话框窗口标题");
    messageBox->setText("这是对话框文本");
    //设置对话框类型
    messageBox->setIcon(QMessageBox::Warning);
    //在消息对话框上设置按钮
    messageBox->setStandardButtons(QMessageBox::Ok | QMessageBox::Save | QMessageBox::Cancel);
    int result = messageBox->exec();//获取到返回值
    if(result == QMessageBox::Ok)
    {
        qDebug() <<"QMessageBox::Ok";
    }
    else if(result == QMessageBox::Save)
    {
        qDebug() << "QMessageBox::Save";
    }
    else if(result == QMessageBox::Cancel)
    {
        qDebug() << "result == QMessageBox::Cancel";
    }
    messageBox->setAttribute(Qt::WA_DeleteOnClose);
}

