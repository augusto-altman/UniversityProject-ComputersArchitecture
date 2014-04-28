#ifndef SIGNALMANAGEMENT_H
#define SIGNALMANAGEMENT_H
#include "QString"

namespace signalManagement
{
    int getCodeBasedIndex(int index);
    char getBytesQuantityFromCode(int code);
    QString getStringFromCode(int code);
}

#endif // SIGNALMANAGEMENT_H
