#include "widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setStyleSheet("QLabel{border:10px solid red;padding-left:10px;}");
    Widget w;
    w.show();
    return a.exec();
}
