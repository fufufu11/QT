#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDockWidget>
#include <QLabel>
#include <QVBoxLayout>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //创建浮动窗口
    QDockWidget* dockwidget = new QDockWidget("浮动窗口",this);
    //将浮动窗口置于当前窗口中,同时设置停靠在左侧
    addDockWidget(Qt::LeftDockWidgetArea,dockwidget);

    //创建一个 QWidget ，并加入到 dockWidget 中
    QWidget* container = new QWidget();
    dockwidget->setWidget(container);
    //创建一个标签和一个垂直的布局管理器，把布局管理器加入到 Qwidget 中
    //再把控件加入到布局管理器中
    QLabel* label = new QLabel("这是一个标签",this);
    QVBoxLayout* vlayout = new QVBoxLayout();
    container->setLayout(vlayout);
    vlayout->addWidget(label);
}

MainWindow::~MainWindow()
{
    delete ui;
}
