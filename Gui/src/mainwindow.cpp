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
     ui->label_coefficientB->setText(QString::number(lab2_ResultData_.coefficientB, 'f', 6));
     ui->label_coefficientK->setText(QString::number(lab2_ResultData_.coefficientK, 'f', 10) );
     ui->label_timeToEndTesting->setText(QString::number(lab2_ResultData_.timeToEndTesting,'f', 6));
     ui->label_midValueTime->setText(QString::number(lab2_ResultData_.midValueTime,'f', 6 ));
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

    ui->label_lengthProgram->setText(QString::number(lab3_ResultData_.lengthProgram, 'f', 6));
    ui->label_voulmeProgram->setText(QString::number(lab3_ResultData_.voulmeProgram, 'f', 6));

    ui->label_countAssemblerCommand->setText(QString::number(lab3_ResultData_.countAssemblerCommand, 'f', 6));
    ui->label_calendarTimeProgramming->setText(QString::number(lab3_ResultData_.calendarTimeProgramming, 'f', 6));
    ui->label_countPotencialErrors_task2->setText(QString::number(lab3_ResultData_.countPotencialErrors_task2, 'f', 6));
    ui->label_startStabilityProgram->setText(QString::number(lab3_ResultData_.startStabilityProgram, 'f', 6));

    ui->label_currentRaitingProgrammer->setText( "R1:\t" + QString::number(lab3_ResultData_.currentRaitingProgrammer[0], 'f', 6) +"\t"+
            "R2:\t" + QString::number(lab3_ResultData_.currentRaitingProgrammer[1], 'f', 6) +"\t"+
            "R3:\t" + QString::number(lab3_ResultData_.currentRaitingProgrammer[2], 'f', 6));

    ui->label_countPotencialErrors->setText( "PE1:\t" + QString::number(lab3_ResultData_.countPotencialErrors[0], 'f', 6) +"\t"+
            "PE2:\t" + QString::number(lab3_ResultData_.countPotencialErrors[1], 'f', 6) +"\t"+
            "PE3:\t" + QString::number(lab3_ResultData_.countPotencialErrors[2], 'f', 6));
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
    lab5_Params_.countFailures = ui->spinBox_countFailures->value();
    lab5_Params_.countExperiments  = ui->spinBox_countExperiments->value() ;
    lab5_Params_.midWakeUpTimeInterval[0]  = ui->doubleSpinBox_midWakeUpTimeInterval_1->value();
    lab5_Params_.midWakeUpTimeInterval[1]  = ui->doubleSpinBox_midWakeUpTimeInterval_2->value();
    lab5_Params_.permissWakeUpTime = ui->doubleSpinBox_permissWakeUpTime->value();
    lab5_Params_.transformTimeInterval[0]  = ui->doubleSpinBox_transformTimeInterval_1->value();
    lab5_Params_.transformTimeInterval[1]  = ui->doubleSpinBox_transformTimeInterval_2->value();

    lab5_Params_.permissTransformTime  = ui->spinBox_permissTransformTime->value();
    lab5_Params_.baseCriterionSafe   = ui->doubleSpinBox_baseCriterionSafe->value();
}

void MainWindow::drawResultFromLab5()
{

        auto drawVectorDouble = [&](QLabel * label, const std::vector<double> & estimates)
        {
           QString resultString;
           for(int i = 0; i < estimates.size(); ++i)
           {
               resultString += "E"+QString::number(i)+":\t"+ QString::number(estimates[i]) + "\t";
               if(i % 5 == 0 )
                   resultString +="\n";
           }
           label->setText(resultString);
        };

        //lab5_ResultData_
        drawVectorDouble(ui->label_estimateValues_1, lab5_ResultData_.estimateValues[0]);
        drawVectorDouble(ui->label_estimateValues_2, lab5_ResultData_.estimateValues[1]);
        drawVectorDouble(ui->label_estimateValues_3, lab5_ResultData_.estimateValues[2]);
        drawVectorDouble(ui->label_estimateValues_4, lab5_ResultData_.estimateValues[3]);
        drawVectorDouble(ui->label_estimateValues_5, lab5_ResultData_.estimateValues[4]);


        QString metricsStr = "M1:\t" + QString::number(lab5_ResultData_.metrics[0]) + "\t" +
                "M1:\t" + QString::number(lab5_ResultData_.metrics[1]) + "\t" +
                "M1:\t" + QString::number(lab5_ResultData_.metrics[2]) + "\t" +
                "M1:\t" + QString::number(lab5_ResultData_.metrics[3]) + "\t" +
                "M1:\t" + QString::number(lab5_ResultData_.metrics[4]) + "\t" ;

        ui->label_metrics->setText(metricsStr);

        QString aboluteStr =  "A1:\t" + QString::number(lab5_ResultData_.absoluteCriterions[0]) + "\t" +
                "A1:\t" + QString::number(lab5_ResultData_.absoluteCriterions[1]) + "\t";

        ui->label_absoluteCriterions->setText(aboluteStr);


        QString relativeStr =  "R1:\t" + QString::number(lab5_ResultData_.relativeCriterions[0]) + "\t" +
                "R1:\t" + QString::number(lab5_ResultData_.relativeCriterions[1]) + "\t";

        ui->label_relativeCriterions->setText(relativeStr);

        ui->label_phactorStability->setText(QString::number(lab5_ResultData_.phactorStability, 'f', 6));
     //   double phactorStability = {0};
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
    calculateLab5();
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
