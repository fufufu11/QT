#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFontDialog>
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
    bool ok = false;
    QFont font = QFontDialog::getFont(&ok);
    qDebug() << "ok = " << ok;//查看 ok 的值
    qDebug() << font;//返回字体的相关参数
}

