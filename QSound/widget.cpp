#include "widget.h"
#include "ui_widget.h"
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    sound = new QSoundEffect(this);
    sound->setSource(QUrl::fromLocalFile(":/music2.wav"));
    sound->setVolume(0.5);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    sound->play();
}

