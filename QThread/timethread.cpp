#include "timethread.h"
#include <QTime>
TimeThread::TimeThread(QObject *parent)
    : QThread{parent}
{}

void TimeThread::run()
{
    while(1)
    {
        QString time = QTime::currentTime().toString("hh:mm:ss");
        emit sendTime(time);//发送信号
        sleep(1);//1秒 这个函数是 QThread 里的函数
    }
}
