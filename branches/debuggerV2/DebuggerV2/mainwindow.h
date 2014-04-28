#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "qextserialport.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_connectButton_clicked();

    void on_requestButton_clicked();

    void on_sendClockButton_clicked();

private:
    Ui::MainWindow *ui;
    QextSerialPort *port;
    void displayReceived(QByteArray bytes, int size);
//    char getBytesQuantityFromCode(int code);
//    int getCodeBasedIndex(int index);
    void receive();
    void receive(int signal);
    void clocking();
    void send();
    void send(int code);
    void displayReceived(QByteArray bytes, int size, int code);
};

#endif // MAINWINDOW_H
