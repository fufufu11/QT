#include "widget.h"
#include "ui_widget.h"
#include <QKeyEvent>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_A && event->modifiers() == Qt::ControlModifier)
    {
        qDebug() << "ctrl + A键被按下";
    }
}
