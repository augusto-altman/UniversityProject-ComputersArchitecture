/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTextBrowser *receiveBrowser;
    QLabel *label;
    QPushButton *connectButton;
    QLabel *conectionState;
    QLabel *label_3;
    QComboBox *signalSelector;
    QPushButton *requestButton;
    QPushButton *sendClockButton;
    QLineEdit *ComEdit;
    QLabel *IaddLabel;
    QLabel *InstructionLabel;
    QLabel *label_4;
    QLabel *label_5;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(807, 538);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        receiveBrowser = new QTextBrowser(centralWidget);
        receiveBrowser->setObjectName(QStringLiteral("receiveBrowser"));
        receiveBrowser->setGeometry(QRect(10, 70, 421, 371));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(260, 10, 211, 51));
        connectButton = new QPushButton(centralWidget);
        connectButton->setObjectName(QStringLiteral("connectButton"));
        connectButton->setGeometry(QRect(650, 100, 131, 31));
        conectionState = new QLabel(centralWidget);
        conectionState->setObjectName(QStringLiteral("conectionState"));
        conectionState->setGeometry(QRect(650, 130, 151, 21));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(650, 150, 141, 31));
        signalSelector = new QComboBox(centralWidget);
        signalSelector->setObjectName(QStringLiteral("signalSelector"));
        signalSelector->setGeometry(QRect(650, 180, 131, 21));
        requestButton = new QPushButton(centralWidget);
        requestButton->setObjectName(QStringLiteral("requestButton"));
        requestButton->setGeometry(QRect(680, 210, 75, 23));
        sendClockButton = new QPushButton(centralWidget);
        sendClockButton->setObjectName(QStringLiteral("sendClockButton"));
        sendClockButton->setGeometry(QRect(650, 270, 131, 31));
        ComEdit = new QLineEdit(centralWidget);
        ComEdit->setObjectName(QStringLiteral("ComEdit"));
        ComEdit->setGeometry(QRect(650, 70, 131, 20));
        IaddLabel = new QLabel(centralWidget);
        IaddLabel->setObjectName(QStringLiteral("IaddLabel"));
        IaddLabel->setGeometry(QRect(460, 90, 151, 151));
        InstructionLabel = new QLabel(centralWidget);
        InstructionLabel->setObjectName(QStringLiteral("InstructionLabel"));
        InstructionLabel->setGeometry(QRect(460, 270, 161, 151));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(470, 70, 46, 13));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(470, 250, 91, 16));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 807, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        label->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:26pt;\">Debugger V2</span></p></body></html>", 0));
        connectButton->setText(QApplication::translate("MainWindow", "Connect", 0));
        conectionState->setText(QApplication::translate("MainWindow", "<html><head/><body><p>State:</p></body></html>", 0));
        label_3->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt;\">Code to request:</span></p></body></html>", 0));
        signalSelector->clear();
        signalSelector->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Clock()", 0)
         << QApplication::translate("MainWindow", "IF: Instruction", 0)
         << QApplication::translate("MainWindow", "IF: Iadd", 0)
         << QApplication::translate("MainWindow", "ID: aluOp", 0)
         << QApplication::translate("MainWindow", "ID: isJump", 0)
         << QApplication::translate("MainWindow", "ID: isNotConditional", 0)
         << QApplication::translate("MainWindow", "ID: IsEqual", 0)
         << QApplication::translate("MainWindow", "ID: memWrite", 0)
         << QApplication::translate("MainWindow", "ID: wbi", 0)
         << QApplication::translate("MainWindow", "ID: memRead", 0)
         << QApplication::translate("MainWindow", "ID: aluSrc", 0)
         << QApplication::translate("MainWindow", "ID: reg1", 0)
         << QApplication::translate("MainWindow", "ID: reg2", 0)
         << QApplication::translate("MainWindow", "ID: extendedInstr", 0)
         << QApplication::translate("MainWindow", "ID: regAddr1", 0)
         << QApplication::translate("MainWindow", "ID: regAddr2", 0)
         << QApplication::translate("MainWindow", "ID: regDst", 0)
         << QApplication::translate("MainWindow", "EXE: is_jump_o", 0)
         << QApplication::translate("MainWindow", "EXE: branch_eq_o", 0)
         << QApplication::translate("MainWindow", "EXE: branch_inc_o", 0)
         << QApplication::translate("MainWindow", "EXE: zero", 0)
         << QApplication::translate("MainWindow", "EXE: jump_address", 0)
         << QApplication::translate("MainWindow", "EXE: wbi_o", 0)
         << QApplication::translate("MainWindow", "EXE: M_o", 0)
         << QApplication::translate("MainWindow", "EXE: regAddr_o", 0)
         << QApplication::translate("MainWindow", "EXE: data_b_o", 0)
         << QApplication::translate("MainWindow", "EXE: out", 0)
         << QApplication::translate("MainWindow", "MEM: dataFromMem", 0)
         << QApplication::translate("MainWindow", "MEM: dataFromImm", 0)
         << QApplication::translate("MainWindow", "MEM: regAddrOut", 0)
         << QApplication::translate("MainWindow", "MEM: wbi", 0)
         << QApplication::translate("MainWindow", "WB: dataToRegFile", 0)
         << QApplication::translate("MainWindow", "WB: WeRegFile", 0)
        );
        requestButton->setText(QApplication::translate("MainWindow", "Request", 0));
        sendClockButton->setText(QApplication::translate("MainWindow", "Send Clock", 0));
        ComEdit->setText(QApplication::translate("MainWindow", "COM1", 0));
        IaddLabel->setText(QString());
        InstructionLabel->setText(QString());
        label_4->setText(QApplication::translate("MainWindow", "Iadd: ", 0));
        label_5->setText(QApplication::translate("MainWindow", "Instruction:", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
