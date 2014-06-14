#ifndef COMMUNICATOR_H
#define COMMUNICATOR_H

namespace Communicator
{
void send(QextSerialPort *port);
void send(int codeReceived,QextSerialPort *port);
void receive(int code,QextSerialPort *port);
void clocking(QextSerialPort *port);

}

#endif // COMMUNICATOR_H
