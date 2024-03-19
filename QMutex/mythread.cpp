#include "mythread.h"
#include <QDebug>
int myThread::num = 0;
QMutex myThread::mutex;
myThread::myThread(QObject *parent)
    : QThread{parent}
{}
void myThread::run()
{
    while(1)
    {
        // 创建的时候加锁，当QMutexLocker 局部销毁的时候解锁
        {
            QMutexLocker lock(&this->mutex);
            qDebug() << "当前线程:" << this << ", Value : " << this->num++;
        }
        sleep(1);
    }
}
