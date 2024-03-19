#include "widget.h"
#include "ui_widget.h"
#include <QLabel>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QLabel* label1 = new QLabel(ui->tab);
    label1->setText("标签页1");
    label1->resize(100,50);

    QLabel* label2 = new QLabel(ui->tab_2);
    label2->setText("标签页2");
    label2->resize(100,50);


}


Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    //获取当前有多少个标签页
    int count = ui->tabWidget->count();
    //创建新的 widget
    QWidget* w = new QWidget();
    ui->tabWidget->addTab(w,QString("Tab") + QString::number(count + 1) );
    //给 widget 中添加label
    QLabel* label = new QLabel(w);
    label->setText(QString("标签页") + QString::number(count + 1));
    label->resize(100,50);
    //选中这个标签页
    ui->tabWidget->setCurrentIndex(count);
}


void Widget::on_tabWidget_tabCloseRequested(int index)
{
    ui->tabWidget->removeTab(index);
}

