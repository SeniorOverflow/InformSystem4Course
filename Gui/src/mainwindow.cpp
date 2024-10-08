#include "mainwindow.h"
#include "../ui/ui_mainwindow.h"

void MainWindow::calculateLab2()
{
    getDataFormLab2();

    auto initLab2Fun  = mathModel_.lab2_InitData();
    auto getResultLab2Func = mathModel_.lab2_ResultFunc();
    (*initLab2Fun)(lab2_Params_);
    lab2_ResultData_ = std::move((*getResultLab2Func)());
    drawResultFromLab2();
}

void MainWindow::getDataFormLab2()
{
    lab2_Params_.clear();
    for(int i = 0; i < ui->tableWidget_lab2Errors->rowCount(); ++i)
    {
        int currentNumberError {0};
        int intervalError {0};

        currentNumberError = ui->tableWidget_lab2Errors->item(i, 0)->text().toInt();
        intervalError = ui->tableWidget_lab2Errors->item(i, 1)->text().toInt();
        lab2_Params_.emplace_back(std::array<int, 2>{currentNumberError, intervalError});
    }
}

void MainWindow::drawResultFromLab2()
{
     ui->label_coefficientB->setText(QString::number(lab2_ResultData_.coefficientB, 'f', 4));
     ui->label_coefficientK->setText(QString::number(lab2_ResultData_.coefficientK, 'f', 4) );
     ui->label_timeToEndTesting->setText(QString::number(lab2_ResultData_.timeToEndTesting,'f', 4));
     ui->label_midValueTime->setText(QString::number(lab2_ResultData_.midValueTime,'f', 4 ));
}

void MainWindow::calculateLab3()
{
    getDataFormLab3();
    auto initLab3Fun  = mathModel_.lab3_InitData();
    auto getResultLab3Func = mathModel_.lab3_ResultFunc();
    (*initLab3Fun)(lab3_Params_);
    lab3_ResultData_ = std::move((*getResultLab3Func)());
    drawResultFromLab3();
}

void MainWindow::getDataFormLab3()
{
    lab3_Params_.goals  = ui->spinBox_goals->value();
    lab3_Params_.measurements = ui->spinBox_measurements->value();
    lab3_Params_.trackedParameters = ui->spinBox_trackedParameters->value();
    lab3_Params_.outputParameters = ui->spinBox_outputParameters->value();
    lab3_Params_.initialRating = ui->spinBox_initialRating->value();
    lab3_Params_.levelLang = ui-> doubleSpinBox_levelLang->value();

    lab3_Params_.numberOfPrograms = ui->spinBox_numberOfPrograms->value();
    auto textedVolumsOfWritenPr  = ui->lineEdit_volumsOfWritenPr->text().remove(' ').split(';');

    lab3_Params_.volumsOfWriienPr.clear();
    for(auto & item : textedVolumsOfWritenPr)
    {
        bool isFineConvert;
        int volum = item.toInt(&isFineConvert);
        if(isFineConvert)
            lab3_Params_.volumsOfWriienPr.emplace_back(volum);
    }

    auto textednumOfErrors  = ui->lineEdit_numOfErrors->text().remove(' ').split(';');

    lab3_Params_.numOfErrors.clear();
    for(auto & item : textednumOfErrors)
    {
        bool isFineConvert;
        int error = item.toInt(&isFineConvert);
        if(isFineConvert)
            lab3_Params_.numOfErrors.emplace_back(error);
    }


    lab3_Params_.necessaryVolume  = ui->spinBox_necessaryVolume->value();
}

void MainWindow::drawResultFromLab3()
{

    auto toQString = [&](lab3_core::ProgmamLevel & lvl){

        switch(lvl)
        {
            case lab3_core::ProgmamLevel::MultiLevel :
                return QString("Многоуровневая");
            case lab3_core::ProgmamLevel::Simple:
                return QString("Малоуровневая");
        }
    };

    ui->label_countPotencialErrors_task1->setText(QString::number(lab3_ResultData_.countPotencialErrors_task1));
    ui->label_countProgramModules->setText(QString::number(lab3_ResultData_.countProgramModules));


    ui->label_programLevel->setText(toQString(lab3_ResultData_.programLevel));

    ui->label_lengthProgram->setText(QString::number(lab3_ResultData_.lengthProgram));
    ui->label_voulmeProgram->setText(QString::number(lab3_ResultData_.voulmeProgram));

    ui->label_countAssemblerCommand->setText(QString::number(lab3_ResultData_.countAssemblerCommand));
    ui->label_calendarTimeProgramming->setText(QString::number(lab3_ResultData_.calendarTimeProgramming));
    ui->label_countPotencialErrors_task2->setText(QString::number(lab3_ResultData_.countPotencialErrors_task2));
    ui->label_startStabilityProgram->setText(QString::number(lab3_ResultData_.startStabilityProgram));

    ui->label_currentRaitingProgrammer->setText( "R1:\t" + QString::number(lab3_ResultData_.currentRaitingProgrammer[0]) +"\t"+
            "R2:\t" + QString::number(lab3_ResultData_.currentRaitingProgrammer[1]) +"\t"+
            "R3:\t" + QString::number(lab3_ResultData_.currentRaitingProgrammer[2]));

    ui->label_countPotencialErrors->setText( "PE1:\t" + QString::number(lab3_ResultData_.countPotencialErrors[0]) +"\t"+
            "PE2:\t" + QString::number(lab3_ResultData_.countPotencialErrors[1]) +"\t"+
            "PE3:\t" + QString::number(lab3_ResultData_.countPotencialErrors[2]));
}

void MainWindow::calculateLab5()
{
    getDataFromLab5();
    auto initLab5Fun  = mathModel_.lab5_InitData();
    auto getResultLab5Func = mathModel_.lab5_ResultFunc();
    (*initLab5Fun)(lab5_Params_);
    lab5_ResultData_ = std::move((*getResultLab5Func)());
    drawResultFromLab5();
}

void MainWindow::getDataFromLab5()
{

}

void MainWindow::drawResultFromLab5()
{

}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_calculateLab5_clicked()
{

}

void MainWindow::on_pushButton_calculateLab3_clicked()
{
    calculateLab3();
}

void MainWindow::on_pushButton_calculateLab2_clicked()
{
    calculateLab2();
}

void MainWindow::on_pushButton_removeRowForomTable_clicked()
{
    if(ui->tableWidget_lab2Errors->rowCount() > 0)
        ui->tableWidget_lab2Errors->removeRow(ui->tableWidget_lab2Errors->rowCount() - 1);
}

void MainWindow::on_pushButton_addRowToTable_clicked()
{
    ui->tableWidget_lab2Errors->insertRow(ui->tableWidget_lab2Errors->rowCount());
    ui->tableWidget_lab2Errors->setItem(ui->tableWidget_lab2Errors->rowCount() - 1, 0,
                new QTableWidgetItem(QString::number(ui->tableWidget_lab2Errors->rowCount())));

            ui->tableWidget_lab2Errors->setItem(
                        ui->tableWidget_lab2Errors->rowCount() - 1,
                        1,
                        new QTableWidgetItem(QString::number(1)));

}
