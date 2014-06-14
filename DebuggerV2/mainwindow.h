#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "qextserialport.h"
#include "continueexethread.h"

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

    void on_contExe_clicked();

    void on_refreshButton_clicked();

private:
    Ui::MainWindow *ui;
    QextSerialPort *port;
    void disableInputs();
    void enableInputs();
//    void displayReceived(QByteArray bytes, int size);
//    char getBytesQuantityFromCode(int code);
//    int getCodeBasedIndex(int index);
//    void receive();
    void receive(int signal);
    void clocking();
    void send();
    void send(int code);
    void displayReceived(QByteArray bytes, int size, int code);
    int contador;
    bool continueExecution = false;
    bool breakConditionCE = false;
    void continueClocks();
    void receiveRegister(int codeReceived);
    void displayReceivedRegister(QByteArray bytes, int size, int code);
    const QString instrCero = "00000000000000000000000000000000";
    ContinueExeThread thread;
};

#endif // MAINWINDOW_H
