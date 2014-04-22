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
    QLabel *label;
    QTextBrowser *receiveBrowser;
    QPushButton *connectButton;
    QLabel *label_2;
    QPushButton *requestButton;
    QPushButton *sendClockButton;
    QLabel *conectionState;
    QComboBox *signalSelector;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(727, 453);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(300, 10, 101, 31));
        label->setStyleSheet(QLatin1String("font: 75 8pt \"MS Shell Dlg 2\";\n"
"font: 14pt \"MS Shell Dlg 2\";"));
        receiveBrowser = new QTextBrowser(centralWidget);
        receiveBrowser->setObjectName(QStringLiteral("receiveBrowser"));
        receiveBrowser->setGeometry(QRect(10, 40, 511, 351));
        connectButton = new QPushButton(centralWidget);
        connectButton->setObjectName(QStringLiteral("connectButton"));
        connectButton->setGeometry(QRect(570, 50, 75, 23));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(530, 100, 161, 16));
        requestButton = new QPushButton(centralWidget);
        requestButton->setObjectName(QStringLiteral("requestButton"));
        requestButton->setGeometry(QRect(570, 160, 75, 23));
        sendClockButton = new QPushButton(centralWidget);
        sendClockButton->setObjectName(QStringLiteral("sendClockButton"));
        sendClockButton->setGeometry(QRect(570, 250, 75, 23));
        conectionState = new QLabel(centralWidget);
        conectionState->setObjectName(QStringLiteral("conectionState"));
        conectionState->setGeometry(QRect(530, 75, 151, 21));
        signalSelector = new QComboBox(centralWidget);
        signalSelector->setObjectName(QStringLiteral("signalSelector"));
        signalSelector->setGeometry(QRect(540, 130, 161, 22));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 727, 21));
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
        label->setText(QApplication::translate("MainWindow", "Debugger", 0));
        connectButton->setText(QApplication::translate("MainWindow", "Connect", 0));
        label_2->setText(QApplication::translate("MainWindow", "Code to request", 0));
        requestButton->setText(QApplication::translate("MainWindow", "Request", 0));
        sendClockButton->setText(QApplication::translate("MainWindow", "send Clock ", 0));
        conectionState->setText(QApplication::translate("MainWindow", "state: ", 0));
        signalSelector->clear();
        signalSelector->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Clocking", 0)
         << QApplication::translate("MainWindow", "IF: Instruction (32 bits)", 0)
         << QApplication::translate("MainWindow", "ID: aluOp ", 0)
         << QApplication::translate("MainWindow", "ID: isJump", 0)
         << QApplication::translate("MainWindow", "ID: isNotConditional", 0)
         << QApplication::translate("MainWindow", "ID: isEqual (for branch)", 0)
         << QApplication::translate("MainWindow", "ID: memWrite", 0)
         << QApplication::translate("MainWindow", "ID: wbi", 0)
         << QApplication::translate("MainWindow", "ID: memRead", 0)
         << QApplication::translate("MainWindow", "ID: aluSrc", 0)
         << QApplication::translate("MainWindow", "ID: reg1", 0)
         << QApplication::translate("MainWindow", "ID: reg2", 0)
         << QApplication::translate("MainWindow", "ID: extededInstr", 0)
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
         << QApplication::translate("MainWindow", "EXE: regaddr_o", 0)
         << QApplication::translate("MainWindow", "EXE: data_b_o", 0)
         << QApplication::translate("MainWindow", "EXE: out", 0)
         << QApplication::translate("MainWindow", "MEM: dataFromMem", 0)
         << QApplication::translate("MainWindow", "MEM: dataFromImm", 0)
         << QApplication::translate("MainWindow", "MEM: regaddrout", 0)
         << QApplication::translate("MainWindow", "WB: dataToRegFile", 0)
         << QApplication::translate("MainWindow", "WB: weRegFile", 0)
         << QApplication::translate("MainWindow", "IF: IAdd", 0)
        );
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
