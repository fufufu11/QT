#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //设置文字居中对齐
    ui->label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);//ctrl + 鼠标左键可查看其他的选项
    ui->label->setText("设置垂直且居中的文本");

    //设置自动换行
    ui->label_2->setAlignment(Qt::AlignTop | Qt::AlignLeft);//设置文字左上对齐
    ui->label_2->setWordWrap(true);
    ui->label_2->setText("这是一段长文本这是一段长文本这是一段长文本这是一段长文本这是一段长文本这是一段长文本");

    //设置首行缩进
    ui->label_3->setAlignment(Qt::AlignTop | Qt::AlignLeft);//设置文字左上对齐
    ui->label_3->setIndent(20);
    ui->label_3->setText("这是一段长文本这是一段长文本这是一段长文本这是一段长文本这是一段长文本这是一段长文本");

    //设置边距
    ui->label_4->setAlignment(Qt::AlignTop | Qt::AlignLeft);
    ui->label_4->setMargin(10);
    ui->label_4->setText("这是一段长文本这是一段长文本这是一段长文本这是一段长文本这是一段长文本这是一段长文本");



}

Widget::~Widget()
{
    delete ui;
}
