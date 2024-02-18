#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget // 创建项目时，选择的父类
{
    Q_OBJECT //这里本质是一个宏，展开后是一段代码，该宏允许类中使用信号和槽机制

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;//通过该指针可以访问UI界面中的任意控件
};
#endif // WIDGET_H
