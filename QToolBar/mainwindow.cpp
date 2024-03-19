#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QToolBar>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QToolBar* toolBar1 = new QToolBar(this);
    this->addToolBar(toolBar1);
    //指定工具栏在左侧显示
    this->addToolBar(Qt::LeftToolBarArea,toolBar1);
    //设置只允许在上侧和左侧停靠
    toolBar1->setAllowedAreas(Qt::LeftToolBarArea | Qt::TopToolBarArea);
    //设置工具栏不允许浮动
    toolBar1->setFloatable(false);
    QAction* action1 = new QAction("保存");
    toolBar1->addAction(action1);
}

MainWindow::~MainWindow()
{
    delete ui;
}
