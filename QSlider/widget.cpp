#include "widget.h"
#include "ui_widget.h"
#include <QShortcut>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->horizontalSlider->setMinimum(500);
    ui->horizontalSlider->setMaximum(2000);
    ui->horizontalSlider->setSingleStep(100);
    ui->horizontalSlider->setValue(800);

    ui->verticalSlider->setMinimum(500);
    ui->verticalSlider->setMaximum(1500);
    ui->verticalSlider->setSingleStep(100);
    ui->verticalSlider->setValue(600);

    //翻转朝向，默认滑块从下往上增长，改成从上往下增长
    ui->verticalSlider->setInvertedAppearance(true);

    //设置快捷键
    QShortcut* shortCut1 = new QShortcut(this);
    shortCut1->setKey(QKeySequence("-"));
    connect(shortCut1,&QShortcut::activated,this,&Widget::sub);

    QShortcut* shortCut2 = new QShortcut(this);
    shortCut2->setKey(QKeySequence("="));
    connect(shortCut2,&QShortcut::activated,this,&Widget::add);

}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_horizontalSlider_valueChanged(int value)
{
    QRect rect = this->geometry();
    this->setGeometry(rect.x(),rect.y(),value,rect.height());
}



void Widget::on_verticalSlider_valueChanged(int value)
{
    QRect rect = this->geometry();
    this->setGeometry(rect.x(),rect.y(),rect.width(),value);
}

void Widget::sub()
{
    int value = ui->horizontalSlider->value();
    ui->horizontalSlider->setValue(value - 20);
}

void Widget::add()
{
    int value = ui->horizontalSlider->value();
    ui->horizontalSlider->setValue(value + 20);
}

