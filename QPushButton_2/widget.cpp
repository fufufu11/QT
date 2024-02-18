#include "widget.h"
#include "ui_widget.h"
#include <QIcon>
#include <QPushButton>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //设置图标
    ui->pushButton_target->setIcon(QIcon(":/image/pushbutton.png"));
    ui->pushButton_target->setIconSize(QSize(50,50));
    ui->pushButton_up->setIcon(QIcon(":/image/up.png"));
    ui->pushButton_down->setIcon(QIcon(":/image/down.png"));
    ui->pushButton_left->setIcon(QIcon(":/image/left.png"));
    ui->pushButton_right->setIcon(QIcon(":/image/right.png"));

    //设置快捷键
    ui->pushButton_up->setShortcut(QKeySequence(Qt::Key_W));
    ui->pushButton_down->setShortcut(QKeySequence(Qt::Key_S));
    ui->pushButton_left->setShortcut(QKeySequence(Qt::Key_A));
    ui->pushButton_right->setShortcut(QKeySequence(Qt::Key_D));

    //按键快捷键默认可以重复触发，鼠标不行，以下代码设置鼠标重复触发
    ui->pushButton_up->setAutoRepeat(true);
    ui->pushButton_down->setAutoRepeat(true);
    ui->pushButton_left->setAutoRepeat(true);
    ui->pushButton_right->setAutoRepeat(true);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_up_clicked()
{
    QRect rect = ui->pushButton_target->geometry();
    ui->pushButton_target->setGeometry(rect.x(),rect.y() - 5,rect.width(),rect.height());
}


void Widget::on_pushButton_down_clicked()
{
    QRect rect = ui->pushButton_target->geometry();
    ui->pushButton_target->setGeometry(rect.x(),rect.y() + 5,rect.width(),rect.height());
}


void Widget::on_pushButton_left_clicked()
{
    QRect rect = ui->pushButton_target->geometry();
    ui->pushButton_target->setGeometry(rect.x() - 5,rect.y(),rect.width(),rect.height());
}


void Widget::on_pushButton_right_clicked()
{
    QRect rect = ui->pushButton_target->geometry();
    ui->pushButton_target->setGeometry(rect.x() + 5,rect.y(),rect.width(),rect.height());
}

