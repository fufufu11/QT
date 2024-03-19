#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>
#include <QWidget>
#include <QMutex>
class myThread : public QThread
{
    Q_OBJECT
public:
    explicit myThread(QObject *parent = nullptr);
    void run();
private:
    static QMutex mutex;//多个线程使用同一把锁
    static int num;//多个线程共同访问一个数据
};

#endif // MYTHREAD_H
