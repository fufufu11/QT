#include "widget.h"
#include "ui_widget.h"
#include <QLabel>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QLabel *label = new QLabel(this);
    label->setText("这是一段文本");
    QFont font;//创建字体对象
    font.setFamily("仿宋");//设置字体家族
    font.setPointSize(20);//设置字体大小
    font.setBold(true);//设置字体加粗
    font.setItalic(true);//设置字体倾斜
    font.setUnderline(true);//设置字体下划线
    font.setStrikeOut(true);//设置字体删除线
    label->setFont(font);//设置字体对象到 label 上

}

Widget::~Widget()
{
    delete ui;
}
