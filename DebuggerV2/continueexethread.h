#ifndef CONTINUEEXETHREAD_H
#define CONTINUEEXETHREAD_H

#include <QThread>

class ContinueExeThread : public QThread
{
    Q_OBJECT
private:
    void run();
};

#endif // CONTINUEEXETHREAD_H
