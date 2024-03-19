#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->treeWidget->setHeaderLabel("动物");

    QTreeWidgetItem* item1 = new QTreeWidgetItem();
    item1->setText(0,"猫");
    ui->treeWidget->addTopLevelItem(item1);

    QTreeWidgetItem* item2 = new QTreeWidgetItem();
    item2->setText(0,"狗");
    ui->treeWidget->addTopLevelItem(item2);

    QTreeWidgetItem* item3 = new QTreeWidgetItem();
    item3->setText(0,"鸟");
    ui->treeWidget->addTopLevelItem(item3);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    //获取输入框的内容
    const QString& text = ui->lineEdit->text();
    if(text.isEmpty())
    {
        return;
    }
    //添加到顶层节点中
    QTreeWidgetItem* item = new QTreeWidgetItem();
    item->setText(0,text);
    ui->treeWidget->addTopLevelItem(item);
}


void Widget::on_pushButton_2_clicked()
{
    //获取输入框的内容
    const QString& text = ui->lineEdit->text();
    if(text.isEmpty())
    {
        return;
    }
    //获取到当前选中的节点
    QTreeWidgetItem* currentItem = ui->treeWidget->currentItem();
    if(currentItem == nullptr)
    {
        return;
    }
    //构造新的 Item
    QTreeWidgetItem* newItem = new QTreeWidgetItem();
    newItem->setText(0,text);
    //添加 item 到选中节点
    currentItem->addChild(newItem);
    //展开父节点
    currentItem->setExpanded(true);
}


void Widget::on_pushButton_3_clicked()
{
    //获取到当前选中的节点
    QTreeWidgetItem* currentItem = ui->treeWidget->currentItem();
    if(currentItem == nullptr)
    {
        return;
    }
    //获取当前节点的父节点
    QTreeWidgetItem* parent = currentItem->parent();
    if(parent == nullptr)
    {
        //顶层节点
        int index = ui->treeWidget->indexOfTopLevelItem(currentItem);
        ui->treeWidget->takeTopLevelItem(index);
    }
    else
    {
        //非顶层节点
        parent->removeChild(currentItem);
    }
}

