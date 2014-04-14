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
    void onReadyRead();

private:
    Ui::MainWindow *ui;
    QextSerialPort *port;
    void displayReceived(QByteArray bytes, int size);
};

#endif // MAINWINDOW_H
