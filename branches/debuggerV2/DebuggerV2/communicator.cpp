#include "communicator.h"
#include <QDebug>
#include "QextSerialPort.h"
#include "signalmanagement.h"


void Communicator::send(QextSerialPort *port){
    unsigned int codeInt = signalManagement::getCodeBasedIndex(ui->signalSelector->currentIndex());
    unsigned char tam = signalManagement::getBytesQuantityFromCode(codeInt);
    unsigned char code = codeInt;
    code = ((tam << 6) & 0xC0)|(code & 0x3F);
    qDebug() << code;
    qDebug() << tam;
    port->write(QString(QChar(code)).toLatin1());
    Communicator::receive(codeInt,port);
}

void Communicator::send(int codeReceived,QextSerialPort *port){
    unsigned int codeInt = codeReceived;
    unsigned char tam = signalManagement::getBytesQuantityFromCode(codeInt);
    unsigned char code = codeInt;
    code = ((tam << 6) & 0xC0)|(code & 0x3F);
    qDebug() << code;
    port->write(QString(QChar(code)).toLatin1());
    Communicator::receive(codeReceived,port);
}

void Communicator::receive(int code,QextSerialPort *port){
    qDebug() << "receive(int)";
    int i =0;
    QByteArray buff;
    int bytesQuantity = signalManagement::getBytesQuantityFromCode(code) + 1;
    //    char buff[1024];
    for(i = 0 ; i < 1024 ; i++){
        buff[i] = 0;
    }
    while( port->bytesAvailable() != bytesQuantity);
    buff = port->readAll();
    mainWindow::displayReceived(buff, bytesQuantity,code);
    if(port->bytesAvailable()){
        ui->conectionState->setText("<FONT COLOR='#ff0000' > state: bytes in Queue not received");
    }
}

void Communicator::clocking(QextSerialPort *port){
    qDebug() << "clocking()";
    contador =0;
    // send ascendent and descendent clocks;
    qDebug() << 63;
    port->write(QString(QChar(63)).toLatin1());
    receive(0);

    qDebug() << 56;
    port->write(QString(QChar(56)).toLatin1());
    receive(0);

    send(1); // Instructions
    send(34); // Iadd
}

