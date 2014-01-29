#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QStringList>
#include <QRegExp>
#include <QMetaObject>
#include <QFile>
#include <QFileDialog>
#include <QToolButton>
#include <QIcon>
#include <QtScript/qscriptengine.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
     QString procesarInstruccion(QString instruccionAProcesar);

private slots:
    void on_botonBrowse_clicked();

    void on_botonEnsamblar_clicked();

    //Instrucciones tipo-R
    QString sllOp(QString rd, QString rt, QString sa);
    QString srlOp(QString rd, QString rt, QString sa);
    QString sraOp(QString rd, QString rt, QString sa);
    QString srlvOp(QString rd, QString rt, QString rs);
    QString sravOp(QString rd, QString rt, QString rs);
    QString addOp(QString rd, QString rs, QString rt);
    QString sllvOp(QString rd, QString rt, QString rs);
    QString adduOp(QString rd, QString rs, QString rt);
    QString subOp(QString rd, QString rs, QString rt);
    QString subuOp(QString rd, QString rs, QString rt);
    QString andOp(QString rd, QString rs, QString rt);
    QString orOp(QString rd, QString rs, QString rt);
    QString xorOp(QString rd, QString rs, QString rt);
    QString norOp(QString rd, QString rs, QString rt);
    QString sltOp(QString rd, QString rs, QString rt);
    QString sltuOp(QString rd, QString rs, QString rt);

    //Instrucciones tipo-L
    QString lbOp(QString rt, QString offset, QString base);
    QString lhOp(QString rt, QString offset, QString base);
    QString lwOp(QString rt, QString offset, QString base);
    QString lwuOp(QString rt, QString offset, QString base);
    QString lbuOp(QString rt, QString offset, QString base);
    QString lhuOp(QString rt, QString offset, QString base);
    QString sbOp(QString rt, QString offset, QString base);
    QString shOp(QString rt, QString offset, QString base);
    QString swOp(QString rt, QString offset, QString base);
    QString addiOp(QString rt, QString rs, QString immediate);
    QString addiuOp(QString rt, QString rs, QString immediate);
    QString andiOp(QString rt, QString rs, QString immediate);
    QString oriOp(QString rt, QString rs, QString immediate);
    QString xoriOp(QString rt, QString rs, QString immediate);
    QString luiOp(QString rt, QString immediate, QString _unused);
    QString sltiOp(QString rt, QString rs, QString immediate);
    QString sltiuOp(QString rt, QString rs, QString immediate);
    QString beqOp(QString rs, QString rt, QString offset);
    QString bneOp(QString rs, QString rt, QString offset);
    QString jOp(QString target, QString _unused, QString _unused1);
    QString jalOp(QString target, QString _unused, QString _unused1);

    //instrucciones tipo-J
    QString jrOp(QString rs, QString _unused, QString _unused1);
    QString jalrOp(QString operando1, QString operando2, QString _unused);

private:
    Ui::MainWindow *ui;
    QString decToBinary(QString);
    QString evaluate(QString expression);
};

#endif // MAINWINDOW_H
