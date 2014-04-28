#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include "QextSerialPort.h"
#include "signalmanagement.h"

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
    this->port = new QextSerialPort(ui->ComEdit->text(), QextSerialPort::EventDriven);
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
    int bytesQuantity = signalManagement::getBytesQuantityFromCode(ui->signalSelector->currentIndex()) + 1;

    for(i = 0 ; i < 1024 ; i++){
        buff[i] = 0;
    }
    // esperar que los bytes esten disponibles
    while( port->bytesAvailable() != bytesQuantity);

    buff = port->readAll();
    displayReceived(buff, bytesQuantity);
    if(port->bytesAvailable()){
        ui->conectionState->setText("<FONT COLOR='#ff0000' > state: bytes in Queue not received");
    }
}

void MainWindow::receive(int code){
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
    displayReceived(buff, bytesQuantity,code);
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
        send();
    }
}

void MainWindow::send(){
    unsigned int codeInt = signalManagement::getCodeBasedIndex(ui->signalSelector->currentIndex());
    unsigned char tam = signalManagement::getBytesQuantityFromCode(codeInt);
    unsigned char code = codeInt;
    code = ((tam << 6) & 0xC0)|(code & 0x3F);
    qDebug() << code;
    qDebug() << tam;
    port->write(QString(QChar(code)).toLatin1());
    receive(codeInt);
}

void MainWindow::send(int codeReceived){
    unsigned int codeInt = codeReceived;
    unsigned char tam = signalManagement::getBytesQuantityFromCode(codeInt);
    unsigned char code = codeInt;
    code = ((tam << 6) & 0xC0)|(code & 0x3F);
    qDebug() << code;
    port->write(QString(QChar(code)).toLatin1());
    receive(codeReceived);
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

void MainWindow::displayReceived(QByteArray bytes, int size, int code){
    qDebug() << "displayReceived()" ;
    if(code == 1 || code == 34){
        ui->receiveBrowser->append(signalManagement::getStringFromCode(code));
    }\
    else{
        ui->receiveBrowser->append(QString(ui->signalSelector->currentText()).
                                   append(" (").
                                   append(QString::number(ui->signalSelector->currentIndex())).
                                   append(") :"));
    }
    ui->receiveBrowser->append(QString("bytes read:").append(QString::number(bytes.length())));
    int i;
    for(i=0;i<size;i++){
        int j=0;
        QString output = QString::number(((unsigned char)bytes.at(i)),2);
        for(j = output.length() ; j < 8 ; j++ ){
            output.prepend('0');
        }
        if(code == 1){
            ui->InstructionLabel->setText(output);
        }else if(code == 34){
            ui->IaddLabel->setText(output);
        }
        else{
            ui->receiveBrowser->append(QString("").append(output));
        }
        qDebug() << QString("received:").append(output);
    }
}

void MainWindow::on_sendClockButton_clicked()
{
    clocking();
}

void MainWindow::clocking(){
    qDebug() << "clocking()";
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




