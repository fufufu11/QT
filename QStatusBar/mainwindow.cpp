#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //创建状态栏
    QStatusBar* stbar = this->statusBar();
    //将状态栏设置到窗口中
    this->setStatusBar(stbar);
    //状态栏中显示 2 秒的消息
    //stbar->showMessage("这是一个状态消息",2000);

    //QLabel* label = new QLabel("这是一个标签",this);
    //stbar->addWidget(label);

    QLabel* label2 = new QLabel("这是一个标签2",this);
    stbar->addPermanentWidget(label2);
}

MainWindow::~MainWindow()
{
    delete ui;
}
