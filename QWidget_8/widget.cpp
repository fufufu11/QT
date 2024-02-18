#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //创建一个位图对象，加载自定义光标图片
    QPixmap pixmap(":/cursor.png");
    //scaled 函数可以设置图片尺寸
    pixmap = pixmap.scaled(64,64);
    //创建 QCursor对象，并指定“热点”为（2，2）坐标位置
    //所谓“热点” 就是鼠标点击时生效的位置
    QCursor cursor(pixmap,2,2);
    //设置光标
    this->setCursor(cursor);
}

Widget::~Widget()
{
    delete ui;
}
