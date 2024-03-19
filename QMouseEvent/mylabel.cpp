#include "mylabel.h"
#include <QDebug>
MyLabel::MyLabel(QWidget *parent)
    : QLabel(parent)
{}

void MyLabel::enterEvent(QEnterEvent *event)
{
    qDebug() << "鼠标进入";
}
