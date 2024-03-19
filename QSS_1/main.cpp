#include "widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //设置全局样式
    a.setStyleSheet("QPushButton{color:red;}");
    Widget w;
    w.show();
    return a.exec();
}
