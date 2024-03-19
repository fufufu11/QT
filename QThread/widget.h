#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <timethread.h>
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
    void showTime(QString time);

private slots:
    void on_pushButton_clicked();

private:
    Ui::Widget *ui;
    TimeThread t;//定义线程对象
};
#endif // WIDGET_H
