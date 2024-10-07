#include "mainwindow.h"
#include "../ui/ui_mainwindow.h"

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

void MainWindow::on_pushButton_calulateLab3_clicked()
{

}

void MainWindow::on_pushButton_calculateLab2_clicked()
{


    //getLab2DataFromForm();


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
