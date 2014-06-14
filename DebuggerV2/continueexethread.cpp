#include "continueexethread.h"
#include <QDebug>

void ContinueExeThread::run()
{
    while(true)
        qDebug() << "hello from worker thread " << thread()->currentThreadId();

}
