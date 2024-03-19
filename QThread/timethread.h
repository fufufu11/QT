#ifndef TIMETHREAD_H
#define TIMETHREAD_H

#include <QThread>
#include <QWidget>

class TimeThread : public QThread
{
    Q_OBJECT
public:
    explicit TimeThread(QObject *parent = nullptr);

    void run();//重写线程任务函数
signals:
    void sendTime(QString Time);//声明信号函数
};

#endif // TIMETHREAD_H
