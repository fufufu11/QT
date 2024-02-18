#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
signals:
    void MySignal();//信号声明，不需要定义
public:
    void MySlots();//槽声明，需要定义

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
