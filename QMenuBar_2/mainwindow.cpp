#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //创建菜单栏
    //QMenuBar* menubar = this->menuBar();
    QMenuBar* menubar = new QMenuBar();
    //把菜单栏放入窗口中
    this->setMenuBar(menubar);
    //创建菜单
    QMenu* menu1 = new QMenu("文件(&F)");
    QMenu* menu2 = new QMenu("编辑(&E)");
    QMenu* menu3 = new QMenu("构建(&C)");
    //添加菜单到菜单栏中
    menubar->addMenu(menu1);
    menubar->addMenu(menu2);
    menubar->addMenu(menu3);
    //创建菜单项
    QAction* action1 = new QAction("open(&O)");
    QAction* action2 = new QAction("close");
    QAction* action3 = new QAction("create");
    //将菜单项添加到菜单上
    menu1->addAction(action1);
    menu1->addSeparator();//在 open 和 close 之间添加分割线
    menu1->addAction(action2);
    menu1->addAction(action3);
    //点击 open 的时候触发槽函数
    connect(action1,&QAction::triggered,this,&MainWindow::handle);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::handle()
{
    qDebug() << "点击了 open 菜单项";
}
