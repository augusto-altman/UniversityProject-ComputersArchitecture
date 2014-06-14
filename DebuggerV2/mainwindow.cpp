#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include "QextSerialPort.h"
#include "signalmanagement.h"
#include "continueexethread.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    disableInputs();
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
        ui->connectButton->setDisabled(true);
        send(1); // Instructions
        send(34); // Iadd
        enableInputs();
    }
    else {
        qDebug() << "device failed to open:" << port->errorString();
        ui->conectionState->setText("<FONT COLOR='#ff0000' > state: Error");
    }
}

void MainWindow::on_sendClockButton_clicked()
{
    clocking();
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

void MainWindow::displayReceived(QByteArray bytes, int size, int code){
    QString instructionTemp = "";
    qDebug() << "displayReceived()" ;
    if(code != 1 && code != 34 && code != 0){
        ui->receiveBrowser->append(QString("<B>").append(QString(ui->signalSelector->currentText())).
                                   append(":").append("</B>"));
    }
    else if(code == 0){
        if(contador == 0 && !continueExecution){
            ui->receiveBrowser->append("------------------------------------------");
            ui->receiveBrowser->append("Clock:");
            contador++;
        }
    }

    int i;
    if(code == 1){
        ui->InstructionLabel->setText("");
    }else if(code == 34){
        ui->IaddLabel->setText("");
    }else if(code == 0){
        ui->InstructionLabel->text().append('\n');
    }

    for(i=0;i<size;i++){
        int j=0;
        QString output = QString::number(((unsigned char)bytes.at(i)),2);
        for(j = output.length() ; j < 8 ; j++ ){
            output.prepend('0');
        }
        if(code == 1){
            ui->InstructionLabel->setText(ui->InstructionLabel->text().append('\n').append(output));
            instructionTemp.append(output);

        }else if(code == 34){
            ui->IaddLabel->setText(ui->IaddLabel->text().append('\n').append(output));
        }
        else if(code == 0){
            if(!continueExecution)
                 ui->receiveBrowser->append(QString("").append(output));
        }
        else{
            ui->receiveBrowser->append(QString("").append(output));
        }
        qDebug() << QString("received:").append(output);

    }
    if(instructionTemp == instrCero)
        breakConditionCE = true;
}

void MainWindow::send(){
    unsigned int codeInt = signalManagement::getCodeBasedIndex(ui->signalSelector->currentIndex());
//    unsigned char tam = signalManagement::getBytesQuantityFromCode(codeInt);
    unsigned char code = codeInt;
//    code = ((tam << 6) & 0xC0)|(code & 0x3F);
    qDebug() << code;

    port->write(QString(QChar(code)).toLatin1());
    receive(codeInt);
}

void MainWindow::send(int codeReceived){
    unsigned int codeInt = codeReceived;
//    unsigned char tam = signalManagement::getBytesQuantityFromCode(codeInt);
    unsigned char code = codeInt;
//    code = ((tam << 6) & 0xC0)|(code & 0x3F);
    qDebug() << code;
    port->write(QString(QChar(code)).toLatin1());
    receive(codeReceived);
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

void MainWindow::clocking(){
     if(!continueExecution){
         disableInputs();
     }

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

    if(!continueExecution){
        MainWindow::on_refreshButton_clicked();
        enableInputs();
    }

}

void MainWindow::disableInputs(){
    ui->sendClockButton->setDisabled(true);
    ui->sendClockButton->update();
    ui->sendClockButton->repaint();

    ui->requestButton->setDisabled(true);
    ui->requestButton->update();
    ui->requestButton->repaint();

    ui->contExe->setDisabled(true);
    ui->contExe->update();
    ui->contExe->repaint();

    ui->signalSelector->setDisabled(true);
    ui->signalSelector->update();
    ui->signalSelector->repaint();
}

void MainWindow::enableInputs(){
    ui->sendClockButton->setEnabled(true);
    ui->sendClockButton->update();
    ui->sendClockButton->repaint();

    ui->requestButton->setEnabled(true);
    ui->requestButton->update();
    ui->requestButton->repaint();

    ui->contExe->setEnabled(true);
    ui->contExe->update();
    ui->contExe->repaint();

    ui->signalSelector->setEnabled(true);
    ui->signalSelector->update();
    ui->signalSelector->repaint();
}

void MainWindow::on_contExe_clicked()
{
    breakConditionCE = false;
    continueExecution=true;

   disableInputs();

    while(! breakConditionCE){
        MainWindow::clocking();
    }
    MainWindow::clocking();
    MainWindow::clocking();
    MainWindow::clocking();
    continueExecution=false;

    enableInputs();
    MainWindow::on_refreshButton_clicked();
}

void MainWindow::on_refreshButton_clicked()
{
    ui->RegisterViewer->setText("");
    int count = 64;
    for(count = 64; count < 96  ; count++){
        unsigned int codeInt = count;
        unsigned char code = codeInt;
        qDebug() << code;
        port->write(QString(QChar(code)).toLatin1());
        receiveRegister(count);
    }
}

void MainWindow::receiveRegister(int code){
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
    displayReceivedRegister(buff, bytesQuantity,code);
    if(port->bytesAvailable()){
        ui->conectionState->setText("<FONT COLOR='#ff0000' > state: bytes in Queue not received");
    }
}

void MainWindow::displayReceivedRegister(QByteArray bytes, int size, int code){
    qDebug() << "displayReceived()" ;
     QString salida = "";
     QString salidaInt = "";
     salida.append(QString("Registro ").append(QString::number(code-64)).append(": "));
//    ui->RegisterViewer->append(QString::number(code-64));
    qDebug() << size;
    int i;

    for(i=0;i<size;i++){
        int j=0;
        QString output = QString::number(((unsigned char)bytes.at(i)),2);
        for(j = output.length() ; j < 8 ; j++ ){
            output.prepend('0');
        }
        salidaInt.append(output);
//        ui->RegisterViewer->append(QString("").append(output));
        qDebug() << QString("received:").append(output);
    }
//    salida.toInt(0,2);
    salida.append(QString::number(salidaInt.toInt(0,2)));
    ui->RegisterViewer->append(salida);
//    ui->RegisterViewer->append(QString::number(salida.toInt(0,2)));

//    ui->RegisterViewer->append(salida);
}
