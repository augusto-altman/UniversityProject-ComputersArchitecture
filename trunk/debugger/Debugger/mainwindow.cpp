#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include "QextSerialPort.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_connectButton_clicked()
{
    this->port = new QextSerialPort("COM6", QextSerialPort::EventDriven);
    port->setBaudRate(BAUD19200);
    port->setFlowControl(FLOW_OFF);
    port->setParity(PAR_NONE);
    port->setDataBits(DATA_8);
    port->setStopBits(STOP_1);

    if (port->open(QIODevice::ReadWrite) == true) {
        if (!(port->lineStatus() & LS_DSR)){
            qDebug() << "warning: device is not turned on";
            ui->conectionState->setText("<FONT COLOR='#ff0000' > state: Error");
        }
        qDebug() << "listening for data on" << port->portName();
        ui->conectionState->setText("<FONT COLOR='#0B610B' > state: Conected");
    }
    else {
        qDebug() << "device failed to open:" << port->errorString();
        ui->conectionState->setText("<FONT COLOR='#ff0000' > state: Error");
    }
}

void MainWindow::receive(){
    int i =0;
    QByteArray buff;
    int bytesQuantity = getBytesQuantityFromCode(ui->signalSelector->currentIndex()) + 1;
//    char buff[1024];
    for(i = 0 ; i < 1024 ; i++){
        buff[i] = 0;
    }

    while( port->bytesAvailable() != bytesQuantity);

    buff = port->readAll();
    displayReceived(buff, bytesQuantity);
    if(port->bytesAvailable()){
        ui->conectionState->setText("<FONT COLOR='#ff0000' > state: bytes in Queue not received");
    }
}

void MainWindow::on_requestButton_clicked()
{
    if(ui->signalSelector->currentIndex() == 0){
        clocking();
    }
    else{
        unsigned char tam = getBytesQuantityFromCode(ui->signalSelector->currentIndex());
        unsigned int codeInt = getCodeBasedIndex(ui->signalSelector->currentIndex());
        unsigned char code = codeInt;
        code = ((tam << 6) & 0xC0)|(code & 0x3F);
        qDebug() << code;
        port->write(QString(QChar(code)).toLatin1());
        receive();
    }
}

void MainWindow::displayReceived(QByteArray bytes, int size){
    qDebug() << "displayReceived()" ;
    ui->receiveBrowser->append(QString(ui->signalSelector->currentText()).
                               append(" (").
                               append(QString::number(ui->signalSelector->currentIndex())).
                               append(") :"));

    ui->receiveBrowser->append(QString("bytes read:").append(QString::number(bytes.length())));
    int i;
    for(i=0;i<size;i++){
        int j=0;
        QString output = QString::number(((unsigned char)bytes.at(i)),2);
        for(j = output.length() ; j < 8 ; j++ ){
            output.prepend('0');
        }
        ui->receiveBrowser->append(QString("").append(output));
        qDebug() << QString("received:").append(output);
    }
}

void MainWindow::on_sendClockButton_clicked()
{
    clocking();
}

char MainWindow::getBytesQuantityFromCode(int code){
    switch (code) {
    case 0:
        return (char)0;
    case 1: // instruction
        return (char)3;
    case 10: // reg1
        return (char)3;
    case 11: //reg2
        return (char)3;
    case 12: //extendedInstr
        return (char) 3;
    case 24: // data_b_o
        return (char) 3;
    case 25: // out (EXE)
        return (char)3;
    case 26: // dataFromMem
        return (char)3;
    case 27: // dataFromImm
        return (char)3;
    case 29: // dataToRegFile
        return (char)3;
    case 31: //IAdd
        return (char)3;
    default:
        return (char) 0;
    }
}

int MainWindow::getCodeBasedIndex(int index){
    switch (index) {
    case 31:
        return 34;
    default:
        return index;
    }
}

void MainWindow::clocking(){
    qDebug() << "clocking()";
    // send ascendent and descendent clocks;
    qDebug() << 63;
    port->write(QString(QChar(63)).toLatin1());
    receive(0);
//    qDebug() << 56;
//    port->write(QString(QChar(56)).toLatin1());
//    receive(0);

//    for(i=0;i<999999999;i++) ;
//    // instruction
//    qDebug() << 1;
//    port->flush();
//    port->write(QString(QChar(1)).toLatin1());
//    receive(1);

}

void MainWindow::receive(int signal){
    qDebug() << "receive(int)";
    int i =0;
    QByteArray buff;
    int bytesQuantity = getBytesQuantityFromCode(signal) + 1;
//    char buff[1024];
    for(i = 0 ; i < 1024 ; i++){
        buff[i] = 0;
    }
    while( port->bytesAvailable() != bytesQuantity);
    buff = port->readAll();
    displayReceived(buff, bytesQuantity);
    if(port->bytesAvailable()){
        ui->conectionState->setText("<FONT COLOR='#ff0000' > state: bytes in Queue not received");
    }
}


