#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

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
    this->port = new QextSerialPort("COM1", QextSerialPort::EventDriven);
    port->setBaudRate(BAUD19200);
    port->setFlowControl(FLOW_OFF);
    port->setParity(PAR_NONE);
    port->setDataBits(DATA_8);
    port->setStopBits(STOP_2);

    if (port->open(QIODevice::ReadWrite) == true) {
        connect(port, SIGNAL(readyRead()), this, SLOT(onReadyRead()));
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

void MainWindow::on_requestButton_clicked()
{
    port->write(QString(QChar(ui->signalSelector->currentIndex())).toLatin1());
}
void MainWindow::onReadyRead()
{
    qDebug() << "onReadyRead()" ;
    QByteArray bytes;
    int a = port->bytesAvailable();
    bytes.resize(a);
    port->read(bytes.data(), bytes.size());
    displayReceived(bytes, a);
}

void MainWindow::displayReceived(QByteArray bytes, int size){
    qDebug() << "displayReceived()" ;
    ui->receiveBrowser->append(QString(ui->signalSelector->currentText()).
                               append(" (").
                               append(QString::number(ui->signalSelector->currentIndex())).
                               append(") :"));

    ui->receiveBrowser->append(QString("bytes read:").append(QString::number(bytes.size())));
    int i;
    for(i=0;i<size;i++){
        int j=0;
        QString output = QString::number(((unsigned char)bytes.at(i)),2);
        for(j = output.length() ; j < 8 ; j++ ){
            output.prepend('0');
        }
        ui->receiveBrowser->append(QString("Bits:").append(output));
        qDebug() << QString("Just bits:").append(output);
    }
}

void MainWindow::on_sendClockButton_clicked()
{
    port->write(QString(QChar(0)).toLatin1());
}
//if(bytes.at(i) < 0){
//    int j=0;
//    QString output = QString::number(bytes.at(i)+256,2);
//    for(j = output.length() ; j < 8 ; j++ ){
//        output.prepend('0');
//    }
//     ui->receiveBrowser->append(QString("Bits:").append(output));
//     qDebug() << QString("Just bits:").append(QString::number(bytes.at(i)+256,2));
//}
//else{
