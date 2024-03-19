#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //默认情况下运行后单元格是可允许被编辑的，如不想被编辑可以加入这行代码
    //ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

    //创建三行
    ui->tableWidget->insertRow(0);
    ui->tableWidget->insertRow(1);
    ui->tableWidget->insertRow(2);

    //创建三列
    ui->tableWidget->insertColumn(0);
    ui->tableWidget->insertColumn(1);
    ui->tableWidget->insertColumn(2);

    //给三列设定列名
    ui->tableWidget->setHorizontalHeaderItem(0,new QTableWidgetItem("学号"));
    ui->tableWidget->setHorizontalHeaderItem(1,new QTableWidgetItem("姓名"));
    ui->tableWidget->setHorizontalHeaderItem(2,new QTableWidgetItem("年龄"));

    //设置初始数据
    ui->tableWidget->setItem(0,0,new QTableWidgetItem("1001"));
    ui->tableWidget->setItem(0,1,new QTableWidgetItem("张三"));
    ui->tableWidget->setItem(0,2,new QTableWidgetItem("20"));

    ui->tableWidget->setItem(1,0,new QTableWidgetItem("1002"));
    ui->tableWidget->setItem(1,1,new QTableWidgetItem("李四"));
    ui->tableWidget->setItem(1,2,new QTableWidgetItem("19"));

    ui->tableWidget->setItem(2,0,new QTableWidgetItem("1003"));
    ui->tableWidget->setItem(2,1,new QTableWidgetItem("王五"));
    ui->tableWidget->setItem(2,2,new QTableWidgetItem("21"));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_addRow_clicked()
{
    //获取到行数
    int rowCount = ui->tableWidget->rowCount();
    //插入新行
    ui->tableWidget->insertRow(rowCount);
}


void Widget::on_pushButton_add_Col_clicked()
{
    //获取到列数
    int colCount = ui->tableWidget->columnCount();
    //插入新列
    ui->tableWidget->insertColumn(colCount);
    //设置列名
    const QString& name = ui->lineEdit->text();
    ui->tableWidget->setHorizontalHeaderItem(colCount,new QTableWidgetItem(name));
}


void Widget::on_pushButton_delRow_clicked()
{
    //获取到选中的行号
    int curRow = ui->tableWidget->currentRow();
    //删除对应的行
    ui->tableWidget->removeRow(curRow);
}


void Widget::on_pushButton_delCol_clicked()
{
    //获取到选中列号
    int curCol = ui->tableWidget->currentColumn();
    //删除对应的行
    ui->tableWidget->removeColumn(curCol);
}

