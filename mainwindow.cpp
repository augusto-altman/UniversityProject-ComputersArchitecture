#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QTextStream>

int cantidadEnsamblajesHechos = 0;

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

void MainWindow::on_botonBrowse_clicked()
{
    QFileDialog dialog;
    dialog.setFileMode(QFileDialog::AnyFile);
    dialog.setFileMode(QFileDialog::FileMode());
    dialog.setViewMode(QFileDialog::Detail);
    dialog.setFilter(QDir::Files);
    dialog.setWindowTitle("Open File");
    dialog.setDirectory(QDir::currentPath());
    dialog.exec();
    QString directory = dialog.selectedFiles().first();


    if(!directory.isNull() && !directory.isEmpty()){
        ui->DireccionArchivoLineEdit->setText(directory);
        if(directory.contains("."))
            ui->nombreArchivoSalidaLineEdit->setText(directory.replace(directory.size()-4,4,".coe"));
        else
            ui->nombreArchivoSalidaLineEdit->setText(directory.append(".coe"));
    }

     QWidget::raise();
}

void MainWindow::on_botonEnsamblar_clicked()
{
    QString instruccionAProcesar;
    QString instruccionProcesada;
    QString coeCode;
    QString directory = ui->DireccionArchivoLineEdit->displayText();
    QString exitFileName = ui->nombreArchivoSalidaLineEdit->displayText();


    coeCode.append(QString("memory_initialization_radix=2")\
                        .append(";\n"));
    coeCode.append("memory_initialization_vector=\n");

    QFile sourceFile(directory);
    QFile exitFile(exitFileName);

    sourceFile.open(QIODevice::ReadOnly | QIODevice::Text);
    exitFile.open(QIODevice::WriteOnly | QIODevice::Text);

    QTextStream in(&sourceFile);
    QTextStream out(&exitFile);
    QString line = in.readLine();
    while (!line.isNull()) {
        // process here
        //La instruccion a procesar seria todo lo que esta antes de los comentarios.
        instruccionAProcesar = line.split(";", QString::SkipEmptyParts).at(0);
        //Procesamos la instrucción.
        instruccionProcesada = procesarInstruccion(instruccionAProcesar);
        if(!instruccionProcesada.isEmpty()){
            coeCode.append(instruccionProcesada.append(",\n"));
        }
        line = in.readLine();
    }
    out << coeCode;
    exitFile.close();
    sourceFile.close();

    cantidadEnsamblajesHechos = cantidadEnsamblajesHechos + 1;
    ui->labelCantidadEnsanblada->setText(QString("terminado conversion ").append(QString("%1").arg(cantidadEnsamblajesHechos)).append(" "));



}


/**
  * @brief Evalua una expresion y devuelve el resultado.
  * @param expression Expresion que se desea evaluar.
  * @return Resultado de la expresion.
  */
QString MainWindow::evaluate(QString expression){
    QScriptEngine engine;
    return engine.evaluate(expression).toString();
}

//***********************************************************************************************************
//***Los siguientes m�todos procesan las instrucciones pedidas. Todos reciben 3 par�metros, aunque no     ***
//***todas los usen, de manera tal que todos los metodos puedan ser llamados con la misma instrucci�n.    ***
//***En la signatura, los par�metros se reciben en el �rden en que se escriben en la instrucci�n.         ***
//***Cuando se convierten a binarios, los operandos de la instrucci�n generalmente se ponen en otro orden.***
//***********************************************************************************************************

//*********************************************************************************
//************************** INSTRUCCIONES TIPO-R *********************************
//*********************************************************************************

/**
  * @brief Procesa la instruccion SLL
  * @param rd Operando rd de la instrucci�n SLL.
  * @param rt Operando rt de la instrucci�n SLL.
  * @param sa Operando sa de la instrucci�n SLL.
  * @return Instrucci�n en formato binario.
  */
QString MainWindow::sllOp(QString rd, QString rt, QString sa){
    QString instruccionBinaria("00000000000");
    instruccionBinaria.append(decToBinary(evaluate(rt)).rightJustified(5,'0'));
    instruccionBinaria.append(decToBinary(evaluate(rd)).rightJustified(5,'0'));
    instruccionBinaria.append(decToBinary(evaluate(sa)).rightJustified(5,'0'));
    instruccionBinaria.append("000000");
    return instruccionBinaria;
}

/**
  * @brief Procesa la instruccion SRL
  * @param rd Operando rd de la instrucci�n SRL.
  * @param rt Operando rt de la instrucci�n SRL.
  * @param sa Operando sa de la instrucci�n SRL.
  * @return Instrucci�n en formato binario.
  */
QString MainWindow::srlOp(QString rd, QString rt, QString sa){
    QString instruccionBinaria("00000000000");
    instruccionBinaria.append(decToBinary(evaluate(rt)).rightJustified(5,'0'));
    instruccionBinaria.append(decToBinary(evaluate(rd)).rightJustified(5,'0'));
    instruccionBinaria.append(decToBinary(evaluate(sa)).rightJustified(5,'0'));
    instruccionBinaria.append("000010");
    return instruccionBinaria;
}

/**
  * @brief Procesa la instruccion SRA
  * @param rd Operando rd de la instrucci�n SRA.
  * @param rt Operando rt de la instrucci�n SRA.
  * @param sa Operando sa de la instrucci�n SRA.
  * @return Instrucci�n en formato binario.
  */
QString MainWindow::sraOp(QString rd, QString rt, QString sa){
    QString instruccionBinaria("00000000000");
    instruccionBinaria.append(decToBinary(evaluate(rt)).rightJustified(5,'0'));
    instruccionBinaria.append(decToBinary(evaluate(rd)).rightJustified(5,'0'));
    instruccionBinaria.append(decToBinary(evaluate(sa)).rightJustified(5,'0'));
    instruccionBinaria.append("000011");
    return instruccionBinaria;
}

/**
  * @brief Procesa la instruccion SRLV
  * @param rd Operando rd de la instrucci�n SRLV.
  * @param rt Operando rt de la instrucci�n SRLV.
  * @param rs Operando rs de la instrucci�n SRLV.
  * @return Instrucci�n en formato binario.
  */
QString MainWindow::srlvOp(QString rd, QString rt, QString rs){
    QString instruccionBinaria("000000");
    instruccionBinaria.append(decToBinary(evaluate(rs)).rightJustified(5,'0'));
    instruccionBinaria.append(decToBinary(evaluate(rt)).rightJustified(5,'0'));
    instruccionBinaria.append(decToBinary(evaluate(rd)).rightJustified(5,'0'));
    instruccionBinaria.append("00000000110");
    return instruccionBinaria;
}

/**
  * @brief Procesa la instruccion SRAV
  * @param rd Operando rd de la instrucci�n SRAV.
  * @param rt Operando rt de la instrucci�n SRAV.
  * @param rs Operando rs de la instrucci�n SRAV.
  * @return Instrucci�n en formato binario.
  */
QString MainWindow::sravOp(QString rd, QString rt, QString rs){
    QString instruccionBinaria("000000");
    instruccionBinaria.append(decToBinary(evaluate(rs)).rightJustified(5,'0'));
    instruccionBinaria.append(decToBinary(evaluate(rt)).rightJustified(5,'0'));
    instruccionBinaria.append(decToBinary(evaluate(rd)).rightJustified(5,'0'));
    instruccionBinaria.append("00000000111");
    return instruccionBinaria;
}

/**
  * @brief Procesa la instruccion ADD
  * @param rd Operando rd de la instrucci�n ADD.
  * @param rs Operando rs de la instrucci�n ADD.
  * @param rt Operando rt de la instrucci�n ADD.
  * @return Instrucci�n en formato binario.
  */
QString MainWindow::addOp(QString rd, QString rs, QString rt){
    QString instruccionBinaria("000000");
    instruccionBinaria.append(decToBinary(evaluate(rs)).rightJustified(5,'0'));
    instruccionBinaria.append(decToBinary(evaluate(rt)).rightJustified(5,'0'));
    instruccionBinaria.append(decToBinary(evaluate(rd)).rightJustified(5,'0'));
    instruccionBinaria.append("00000100000");
    return instruccionBinaria;
}

/**
  * @brief Procesa la instruccion SLLV
  * @param rd Operando rd de la instrucci�n SLLV.
  * @param rt Operando rt de la instrucci�n SLLV.
  * @param rs Operando rs de la instrucci�n SLLV.
  * @return Instrucci�n en formato binario.
  */
QString MainWindow::sllvOp(QString rd, QString rt, QString rs){
    QString instruccionBinaria("000000");
    instruccionBinaria.append(decToBinary(evaluate(rs)).rightJustified(5,'0'));
    instruccionBinaria.append(decToBinary(evaluate(rt)).rightJustified(5,'0'));
    instruccionBinaria.append(decToBinary(evaluate(rd)).rightJustified(5,'0'));
    instruccionBinaria.append("00000000100");
    return instruccionBinaria;
}

/**
  * @brief Procesa la instruccion ADDU
  * @param rd Operando rd de la instrucci�n ADDU.
  * @param rs Operando rs de la instrucci�n ADDU.
  * @param rt Operando rt de la instrucci�n ADDU.
  * @return Instrucci�n en formato binario.
  */
QString MainWindow::adduOp(QString rd, QString rs, QString rt){
    QString instruccionBinaria("000000");
    instruccionBinaria.append(decToBinary(evaluate(rs)).rightJustified(5,'0'));
    instruccionBinaria.append(decToBinary(evaluate(rt)).rightJustified(5,'0'));
    instruccionBinaria.append(decToBinary(evaluate(rd)).rightJustified(5,'0'));
    instruccionBinaria.append("00000100001");
    return instruccionBinaria;
}

/**
  * @brief Procesa la instruccion SUB
  * @param rd Operando rd de la instrucci�n SUB.
  * @param rs Operando rs de la instrucci�n SUB.
  * @param rt Operando rt de la instrucci�n SUB.
  * @return Instrucci�n en formato binario.
  */
QString MainWindow::subOp(QString rd, QString rs, QString rt){
    QString instruccionBinaria("000000");
    instruccionBinaria.append(decToBinary(evaluate(rs)).rightJustified(5,'0'));
    instruccionBinaria.append(decToBinary(evaluate(rt)).rightJustified(5,'0'));
    instruccionBinaria.append(decToBinary(evaluate(rd)).rightJustified(5,'0'));
    instruccionBinaria.append("00000100010");
    return instruccionBinaria;
}

/**
  * @brief Procesa la instruccion SUBU
  * @param rd Operando rd de la instrucci�n SUBU.
  * @param rs Operando rs de la instrucci�n SUBU.
  * @param rt Operando rt de la instrucci�n SUBU.
  * @return Instrucci�n en formato binario.
  */
QString MainWindow::subuOp(QString rd, QString rs, QString rt){
    QString instruccionBinaria("000000");
    instruccionBinaria.append(decToBinary(evaluate(rs)).rightJustified(5,'0'));
    instruccionBinaria.append(decToBinary(evaluate(rt)).rightJustified(5,'0'));
    instruccionBinaria.append(decToBinary(evaluate(rd)).rightJustified(5,'0'));
    instruccionBinaria.append("00000100011");
    return instruccionBinaria;
}

/**
  * @brief Procesa la instruccion AND
  * @param rd Operando rd de la instrucci�n AND.
  * @param rs Operando rs de la instrucci�n AND.
  * @param rt Operando rt de la instrucci�n AND.
  * @return Instrucci�n en formato binario.
  */
QString MainWindow::andOp(QString rd, QString rs, QString rt){
    QString instruccionBinaria("000000");
    instruccionBinaria.append(decToBinary(evaluate(rs)).rightJustified(5,'0'));
    instruccionBinaria.append(decToBinary(evaluate(rt)).rightJustified(5,'0'));
    instruccionBinaria.append(decToBinary(evaluate(rd)).rightJustified(5,'0'));
    instruccionBinaria.append("00000100100");
    return instruccionBinaria;
}

/**
  * @brief Procesa la instruccion OR
  * @param rd Operando rd de la instrucci�n OR.
  * @param rs Operando rs de la instrucci�n OR.
  * @param rt Operando rt de la instrucci�n OR.
  * @return Instrucci�n en formato binario.
  */
QString MainWindow::orOp(QString rd, QString rs, QString rt){
    QString instruccionBinaria("000000");
    instruccionBinaria.append(decToBinary(evaluate(rs)).rightJustified(5,'0'));
    instruccionBinaria.append(decToBinary(evaluate(rt)).rightJustified(5,'0'));
    instruccionBinaria.append(decToBinary(evaluate(rd)).rightJustified(5,'0'));
    instruccionBinaria.append("00000100101");
    return instruccionBinaria;
}

/**
  * @brief Procesa la instruccion XOR
  * @param rd Operando rd de la instrucci�n XOR.
  * @param rs Operando rs de la instrucci�n XOR.
  * @param rt Operando rt de la instrucci�n XOR.
  * @return Instrucci�n en formato binario.
  */
QString MainWindow::xorOp(QString rd, QString rs, QString rt){
    QString instruccionBinaria("000000");
    instruccionBinaria.append(decToBinary(evaluate(rs)).rightJustified(5,'0'));
    instruccionBinaria.append(decToBinary(evaluate(rt)).rightJustified(5,'0'));
    instruccionBinaria.append(decToBinary(evaluate(rd)).rightJustified(5,'0'));
    instruccionBinaria.append("00000100110");
    return instruccionBinaria;
}

/**
  * @brief Procesa la instruccion NOR
  * @param rd Operando rd de la instrucci�n NOR.
  * @param rs Operando rs de la instrucci�n NOR.
  * @param rt Operando rt de la instrucci�n NOR.
  * @return Instrucci�n en formato binario.
  */
QString MainWindow::norOp(QString rd, QString rs, QString rt){
    QString instruccionBinaria("000000");
    instruccionBinaria.append(decToBinary(evaluate(rs)).rightJustified(5,'0'));
    instruccionBinaria.append(decToBinary(evaluate(rt)).rightJustified(5,'0'));
    instruccionBinaria.append(decToBinary(evaluate(rd)).rightJustified(5,'0'));
    instruccionBinaria.append("00000100111");
    return instruccionBinaria;
}

/**
  * @brief Procesa la instruccion SLT
  * @param rd Operando rd de la instrucci�n SLT.
  * @param rs Operando rs de la instrucci�n SLT.
  * @param rt Operando rt de la instrucci�n SLT.
  * @return Instrucci�n en formato binario.
  */
QString MainWindow::sltOp(QString rd, QString rs, QString rt){
    QString instruccionBinaria("000000");
    instruccionBinaria.append(decToBinary(evaluate(rs)).rightJustified(5,'0'));
    instruccionBinaria.append(decToBinary(evaluate(rt)).rightJustified(5,'0'));
    instruccionBinaria.append(decToBinary(evaluate(rd)).rightJustified(5,'0'));
    instruccionBinaria.append("00000101010");
    return instruccionBinaria;
}

/**
  * @brief Procesa la instruccion SLTU
  * @param rd Operando rd de la instrucci�n SLTU.
  * @param rs Operando rs de la instrucci�n SLTU.
  * @param rt Operando rt de la instrucci�n SLTU.
  * @return Instrucci�n en formato binario.
  */
QString MainWindow::sltuOp(QString rd, QString rs, QString rt){
    QString instruccionBinaria("000000");
    instruccionBinaria.append(decToBinary(evaluate(rs)).rightJustified(5,'0'));
    instruccionBinaria.append(decToBinary(evaluate(rt)).rightJustified(5,'0'));
    instruccionBinaria.append(decToBinary(evaluate(rd)).rightJustified(5,'0'));
    instruccionBinaria.append("00000101011");
    return instruccionBinaria;
}

//*********************************************************************************
//************************** INSTRUCCIONES TIPO-L *********************************
//*********************************************************************************

/**
  * @brief Procesa la instruccion LB
  * @param rt Operando rt de la instrucci�n LB.
  * @param offset Offset de la direcci�n que se desea cargar con la instrucci�n LB.
  * @param base Base de la direcci�n que se desea cargar con la instrucci�n LB.
  * @return Instrucci�n en formato binario.
  */
QString MainWindow::lbOp(QString rt, QString offset, QString base){
    QString instruccionBinaria("100000");
    instruccionBinaria.append(decToBinary(evaluate(base)).rightJustified(5,'0'));
    instruccionBinaria.append(decToBinary(evaluate(rt)).rightJustified(5,'0'));
    instruccionBinaria.append(decToBinary(evaluate(offset)).rightJustified(16,'0'));
    return instruccionBinaria;
}

/**
  * @brief Procesa la instruccion LH
  * @param rt Operando rt de la instrucci�n LH.
  * @param offset Offset de la direcci�n que se desea cargar con la instrucci�n LH.
  * @param base Base de la direcci�n que se desea cargar con la instrucci�n LH.
  * @return Instrucci�n en formato binario.
  */
QString MainWindow::lhOp(QString rt, QString offset, QString base){
    QString instruccionBinaria("100001");
    instruccionBinaria.append(decToBinary(evaluate(base)).rightJustified(5,'0'));
    instruccionBinaria.append(decToBinary(evaluate(rt)).rightJustified(5,'0'));
    instruccionBinaria.append(decToBinary(evaluate(offset)).rightJustified(16,'0'));
    return instruccionBinaria;
}

/**
  * @brief Procesa la instruccion LW
  * @param rt Operando rt de la instrucci�n LW.
  * @param offset Offset de la direcci�n que se desea cargar con la instrucci�n LW.
  * @param base Base de la direcci�n que se desea cargar con la instrucci�n LW.
  * @return Instrucci�n en formato binario.
  */
QString MainWindow::lwOp(QString rt, QString offset, QString base){
    QString instruccionBinaria("100011");
    instruccionBinaria.append(decToBinary(evaluate(base)).rightJustified(5,'0'));
    instruccionBinaria.append(decToBinary(evaluate(rt)).rightJustified(5,'0'));
    instruccionBinaria.append(decToBinary(evaluate(offset)).rightJustified(16,'0'));
    return instruccionBinaria;
}

/**
  * @brief Procesa la instruccion LWU
  * @param rt Operando rt de la instrucci�n LWU.
  * @param offset Offset de la direcci�n que se desea cargar con la instrucci�n LWU.
  * @param base Base de la direcci�n que se desea cargar con la instrucci�n LWU.
  * @return Instrucci�n en formato binario.
  */
QString MainWindow::lwuOp(QString rt, QString offset, QString base){
    QString instruccionBinaria("100111");
    instruccionBinaria.append(decToBinary(evaluate(base)).rightJustified(5,'0'));
    instruccionBinaria.append(decToBinary(evaluate(rt)).rightJustified(5,'0'));
    instruccionBinaria.append(decToBinary(evaluate(offset)).rightJustified(16,'0'));
    return instruccionBinaria;
}

/**
  * @brief Procesa la instruccion LBU
  * @param rt Operando rt de la instrucci�n LBU.
  * @param offset Offset de la direcci�n que se desea cargar con la instrucci�n LBU.
  * @param base Base de la direcci�n que se desea cargar con la instrucci�n LBU.
  * @return Instrucci�n en formato binario.
  */
QString MainWindow::lbuOp(QString rt, QString offset, QString base){
    QString instruccionBinaria("100100");
    instruccionBinaria.append(decToBinary(evaluate(base)).rightJustified(5,'0'));
    instruccionBinaria.append(decToBinary(evaluate(rt)).rightJustified(5,'0'));
    instruccionBinaria.append(decToBinary(evaluate(offset)).rightJustified(16,'0'));
    return instruccionBinaria;
}

/**
  * @brief Procesa la instruccion LHU
  * @param rt Operando rt de la instrucci�n LHU.
  * @param offset Offset de la direcci�n que se desea cargar con la instrucci�n LHU.
  * @param base Base de la direcci�n que se desea cargar con la instrucci�n LHU.
  * @return Instrucci�n en formato binario.
  */
QString MainWindow::lhuOp(QString rt, QString offset, QString base){
    QString instruccionBinaria("100101");
    instruccionBinaria.append(decToBinary(evaluate(base)).rightJustified(5,'0'));
    instruccionBinaria.append(decToBinary(evaluate(rt)).rightJustified(5,'0'));
    instruccionBinaria.append(decToBinary(evaluate(offset)).rightJustified(16,'0'));
    return instruccionBinaria;
}

/**
  * @brief Procesa la instruccion SB
  * @param rt Operando rt de la instrucci�n SB.
  * @param offset Offset de la direcci�n que se desea cargar con la instrucci�n SB.
  * @param base Base de la direcci�n que se desea cargar con la instrucci�n SB.
  * @return Instrucci�n en formato binario.
  */
QString MainWindow::sbOp(QString rt, QString offset, QString base){
    QString instruccionBinaria("101000");
    instruccionBinaria.append(decToBinary(evaluate(base)).rightJustified(5,'0'));
    instruccionBinaria.append(decToBinary(evaluate(rt)).rightJustified(5,'0'));
    instruccionBinaria.append(decToBinary(evaluate(offset)).rightJustified(16,'0'));
    return instruccionBinaria;
}

/**
  * @brief Procesa la instruccion SH
  * @param rt Operando rt de la instrucci�n SH.
  * @param offset Offset de la direcci�n que se desea cargar con la instrucci�n SH.
  * @param base Base de la direcci�n que se desea cargar con la instrucci�n SH.
  * @return Instrucci�n en formato binario.
  */
QString MainWindow::shOp(QString rt, QString offset, QString base){
    QString instruccionBinaria("101001");
    instruccionBinaria.append(decToBinary(evaluate(base)).rightJustified(5,'0'));
    instruccionBinaria.append(decToBinary(evaluate(rt)).rightJustified(5,'0'));
    instruccionBinaria.append(decToBinary(evaluate(offset)).rightJustified(16,'0'));
    return instruccionBinaria;
}

/**
  * @brief Procesa la instruccion SW
  * @param rt Operando rt de la instrucci�n SW.
  * @param offset Offset de la direcci�n que se desea cargar con la instrucci�n SW.
  * @param base Base de la direcci�n que se desea cargar con la instrucci�n SW.
  * @return Instrucci�n en formato binario.
  */
QString MainWindow::swOp(QString rt, QString offset, QString base){
    QString instruccionBinaria("101011");
    instruccionBinaria.append(decToBinary(evaluate(base)).rightJustified(5,'0'));
    instruccionBinaria.append(decToBinary(evaluate(rt)).rightJustified(5,'0'));
    instruccionBinaria.append(decToBinary(evaluate(offset)).rightJustified(16,'0'));
    return instruccionBinaria;
}

/**
  * @brief Procesa la instruccion ADDI.
  * @param rt Operando rt de la instrucci�n ADDI.
  * @param rs Operando rs de la instrucci�n ADDI.
  * @param immediate Operando inmediato de la instrucci�n ADDI.
  * @return Instrucci�n en formato binario.
  */
QString MainWindow::addiOp(QString rt, QString rs, QString immediate){
    QString instruccionBinaria("001000");
    instruccionBinaria.append(decToBinary(evaluate(rs)).rightJustified(5,'0'));
    instruccionBinaria.append(decToBinary(evaluate(rt)).rightJustified(5,'0'));
    instruccionBinaria.append(decToBinary(evaluate(immediate)).rightJustified(16,'0'));
    return instruccionBinaria;
}

/**
  * @brief Procesa la instruccion ADDIU.
  * @param rt Operando rt de la instrucci�n ADDIU.
  * @param rs Operando rs de la instrucci�n ADDIU.
  * @param immediate Operando inmediato de la instrucci�n ADDIU.
  * @return Instrucci�n en formato binario.
  */
QString MainWindow::addiuOp(QString rt, QString rs, QString immediate){
    QString instruccionBinaria("001001");
    instruccionBinaria.append(decToBinary(evaluate(rs)).rightJustified(5,'0'));
    instruccionBinaria.append(decToBinary(evaluate(rt)).rightJustified(5,'0'));
    instruccionBinaria.append(decToBinary(evaluate(immediate)).rightJustified(16,'0'));
    return instruccionBinaria;
}

/**
  * @brief Procesa la instruccion ANDI.
  * @param rt Operando rt de la instrucci�n ANDI.
  * @param rs Operando rs de la instrucci�n ANDI.
  * @param immediate Operando inmediato de la instrucci�n ANDI.
  * @return Instrucci�n en formato binario.
  */
QString MainWindow::andiOp(QString rt, QString rs, QString immediate){
    QString instruccionBinaria("001100");
    instruccionBinaria.append(decToBinary(evaluate(rs)).rightJustified(5,'0'));
    instruccionBinaria.append(decToBinary(evaluate(rt)).rightJustified(5,'0'));
    instruccionBinaria.append(decToBinary(evaluate(immediate)).rightJustified(16,'0'));
    return instruccionBinaria;
}

/**
  * @brief Procesa la instruccion ORI.
  * @param rt Operando rt de la instrucci�n ORI.
  * @param rs Operando rs de la instrucci�n ORI.
  * @param immediate Operando inmediato de la instrucci�n ORI.
  * @return Instrucci�n en formato binario.
  */
QString MainWindow::oriOp(QString rt, QString rs, QString immediate){
    QString instruccionBinaria("001101");
    instruccionBinaria.append(decToBinary(evaluate(rs)).rightJustified(5,'0'));
    instruccionBinaria.append(decToBinary(evaluate(rt)).rightJustified(5,'0'));
    instruccionBinaria.append(decToBinary(evaluate(immediate)).rightJustified(16,'0'));
    return instruccionBinaria;
}

/**
  * @brief Procesa la instruccion XORI.
  * @param rt Operando rt de la instrucci�n XORI.
  * @param rs Operando rs de la instrucci�n XORI.
  * @param immediate Operando inmediato de la instrucci�n XORI.
  * @return Instrucci�n en formato binario.
  */
QString MainWindow::xoriOp(QString rt, QString rs, QString immediate){
    QString instruccionBinaria("001110");
    instruccionBinaria.append(decToBinary(evaluate(rs)).rightJustified(5,'0'));
    instruccionBinaria.append(decToBinary(evaluate(rt)).rightJustified(5,'0'));
    instruccionBinaria.append(decToBinary(evaluate(immediate)).rightJustified(16,'0'));
    return instruccionBinaria;
}

/**
  * @brief Procesa la instruccion LUI.
  * @param rt Operando rt de la instrucci�n LUI.
  * @param immediate Operando inmediato de la instrucci�n LUI.
  * @param _unused Operando sin uso, ya que la instrucci�n LUI solo tiene 2 operandos.
  *        Esto se hace para lograr compatibilidad entre instrucciones, de manera tal que todas tengan 3
  *        operandos y puedan ser llamadas en la misma instrucci�n.
  * @return Instrucci�n en formato binario.
  */
QString MainWindow::luiOp(QString rt, QString immediate, QString _unused){
    QString instruccionBinaria("00111100000");
    instruccionBinaria.append(decToBinary(evaluate(rt)).rightJustified(5,'0'));
    instruccionBinaria.append(decToBinary(evaluate(immediate)).rightJustified(16,'0'));
    return instruccionBinaria;
}

/**
  * @brief Procesa la instruccion SLTI.
  * @param rt Operando rt de la instrucci�n SLTI.
  * @param rs Operando rs de la instrucci�n SLTI.
  * @param immediate Operando inmediato de la instrucci�n SLTI.
  * @return Instrucci�n en formato binario.
  */
QString MainWindow::sltiOp(QString rt, QString rs, QString immediate){
    QString instruccionBinaria("001010");
    instruccionBinaria.append(decToBinary(evaluate(rs)).rightJustified(5,'0'));
    instruccionBinaria.append(decToBinary(evaluate(rt)).rightJustified(5,'0'));
    instruccionBinaria.append(decToBinary(evaluate(immediate)).rightJustified(16,'0'));
    return instruccionBinaria;
}

/**
  * @brief Procesa la instruccion SLTIU.
  * @param rt Operando rt de la instrucci�n SLTIU.
  * @param rs Operando rs de la instrucci�n SLTIU.
  * @param immediate Operando inmediato de la instrucci�n SLTIU.
  * @return Instrucci�n en formato binario.
  */
QString MainWindow::sltiuOp(QString rt, QString rs, QString immediate){
    QString instruccionBinaria("001011");
    instruccionBinaria.append(decToBinary(evaluate(rs)).rightJustified(5,'0'));
    instruccionBinaria.append(decToBinary(evaluate(rt)).rightJustified(5,'0'));
    instruccionBinaria.append(decToBinary(evaluate(immediate)).rightJustified(16,'0'));
    return instruccionBinaria;
}

/**
  * @brief Procesa la instruccion BEQ.
  * @param rs Operando rs de la instrucci�n BEQ.
  * @param rt Operando rt de la instrucci�n BEQ.
  * @param offset Offset de la direcci�n a la que se saltara si rs = rt.
  * @return Instrucci�n en formato binario.
  */
QString MainWindow::beqOp(QString rs, QString rt, QString offset){
    QString instruccionBinaria("000100");
    instruccionBinaria.append(decToBinary(evaluate(rs)).rightJustified(5,'0'));
    instruccionBinaria.append(decToBinary(evaluate(rt)).rightJustified(5,'0'));
    instruccionBinaria.append(decToBinary(evaluate(offset)).rightJustified(16,'0'));
    return instruccionBinaria;
}

/**
  * @brief Procesa la instruccion BNE.
  * @param rs Operando rs de la instrucci�n BNE.
  * @param rt Operando rt de la instrucci�n BNE.
  * @param offset Offset de la direcci�n a la que se saltara si rs != rt.
  * @return Instrucci�n en formato binario.
  */
QString MainWindow::bneOp(QString rs, QString rt, QString offset){
    QString instruccionBinaria("000101");
    instruccionBinaria.append(decToBinary(evaluate(rs)).rightJustified(5,'0'));
    instruccionBinaria.append(decToBinary(evaluate(rt)).rightJustified(5,'0'));
    instruccionBinaria.append(decToBinary(evaluate(offset)).rightJustified(16,'0'));
    return instruccionBinaria;
}

/**
  * @brief Procesa la instruccion J.
  * @param target Direccion de destino del salto.
  * @param _unused Par�metro no utilizado, solicitado para lograr compatibilidad.
  * @param _unused1 Par�metro no utilizado, solicitado para lograr compatibilidad.
  * @return Instrucci�n en formato binario.
  */
QString MainWindow::jOp(QString target, QString _unused, QString _unused1){
    QString instruccionBinaria("000010");
    instruccionBinaria.append(decToBinary(evaluate(target)).rightJustified(26,'0'));
    return instruccionBinaria;
}

/**
  * @brief Procesa la instruccion JAL.
  * @param target Direccion donde se encuentra el procedimiento.
  * @param _unused Par�metro no utilizado, solicitado para lograr compatibilidad.
  * @param _unused1 Par�metro no utilizado, solicitado para lograr compatibilidad.
  * @return Instrucci�n en formato binario.
  */
QString MainWindow::jalOp(QString target, QString _unused, QString _unused1){
    QString instruccionBinaria("000011");
    instruccionBinaria.append(decToBinary(evaluate(target)).rightJustified(26,'0'));
    return instruccionBinaria;
}

//*********************************************************************************
//************************** INSTRUCCIONES TIPO-J *********************************
//*********************************************************************************

/**
  * @brief Procesa la instruccion JR.
  * @param rs Operando rs de la instrucci�n JR.
  * @param _unused Par�metro no utilizado, solicitado para lograr compatibilidad.
  * @param _unused1 Par�metro no utilizado, solicitado para lograr compatibilidad.
  * @return Instrucci�n en formato binario.
  */
QString MainWindow::jrOp(QString rs, QString _unused, QString _unused1){
    QString instruccionBinaria("000000");
    instruccionBinaria.append(decToBinary(evaluate(rs)).rightJustified(5,'0'));
    instruccionBinaria.append("000000000000000001000");
    return instruccionBinaria;
}

/**
  * @brief Procesa la instruccion JALR.
  * @param operando1 Primer operando de la instrucci�n JALR. Puede ser rs (si no est� presente rd) o rd.
  * @param operando2 Segundo operando de la instrucci�n JALR. Puede no estar presente (rd = 31). Si est�
  *                  presente, es rs.
  * @param _unused1 Par�metro no utilizado, solicitado para lograr compatibilidad.
  * @return Instrucci�n en formato binario.
  */
QString MainWindow::jalrOp(QString operando1, QString operando2, QString _unused){
    //Si el segundo operando no est� presente, implica rd = 31, y el primer operando es rs.
    QString rd, rs;
    if(operando2.isEmpty()){
        rs = operando1;
        rd = "31";
    }
    //Si ambos operandos est�n presentes, el primero es rd y el segundo es rs.
    else{
        rd = operando1;
        rs = operando2;
    }

    QString instruccionBinaria("000000");
    instruccionBinaria.append(decToBinary(evaluate(rs)).rightJustified(5,'0'));
    instruccionBinaria.append("00000");
    instruccionBinaria.append(decToBinary(evaluate(rd)).rightJustified(5,'0'));
    instruccionBinaria.append("00000001001");
    return instruccionBinaria;
}

/**
  * @brief Procesa una instrucci�n para convertirla a formato binario
  * @param instruccionAProcesar Instruccion que se desea procesar.
  * @return Instrucci�n en formato binario.
  */
QString MainWindow::procesarInstruccion(QString instruccionAProcesar){
    QString instruccionBinaria = "";
    QString instruccion;
    QString operando1, operando2, operando3;

    //Lo primero que hago es separar el nombre y los operandos de la instruccion por comas.
    instruccionAProcesar.replace(QRegExp("\\s+"), ",");
    instruccionAProcesar.replace("(", ",");
    instruccionAProcesar.remove(")");
    instruccionAProcesar.replace(QRegExp(",+"), ",");

    //Luego asigno cada parte a la variable correspondiente, si corresponde.
    QStringList partes = instruccionAProcesar.split(",");
    instruccion = partes.at(0).toLower().append("Op");
    if(partes.size() > 1)
        operando1 = partes.at(1);
    if(partes.size() > 2)
        operando2 = partes.at(2);
    if(partes.size() > 3)
        operando3 = partes.at(3);

    //Llamo al m�todo que procesa la instrucci�n, pasandole los parametros en operando1, operando2 y operando3
    //y devuelvo la instruccion convertida en instruccionBinaria.
    QMetaObject::invokeMethod(this,
                              instruccion.toLatin1().data(),
                              Qt::DirectConnection,
                              Q_RETURN_ARG(QString, instruccionBinaria),
                              Q_ARG(QString, operando1),
                              Q_ARG(QString, operando2),
                              Q_ARG(QString, operando3)
                              );
    return instruccionBinaria;
}

/*!
  * @brief Convierte un numero decimal a binario,
  * @param numero QString que contiene el numero que desea convertirse en formato texto.
  * @return QString que contiene el numero decimal convertido a binario, listo para ponerse en la salida.
  */
QString MainWindow::decToBinary(QString numero){
    int num = numero.toInt();
    return QString::number(num,2);
}

