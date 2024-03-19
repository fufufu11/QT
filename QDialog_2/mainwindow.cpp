#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDialog>
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
    //创建一个对话框
    QDialog* dialog = new QDialog(this);
    //设置对话框大小
    dialog->resize(400,300);
    //设置对话框标题
    dialog->setWindowTitle("标题");
    dialog->show();

    dialog->setAttribute(Qt::WA_DeleteOnClose);
}

