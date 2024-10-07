#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <MathModel.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:


public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_calculateLab5_clicked();

    void on_pushButton_calulateLab3_clicked();

    void on_pushButton_calculateLab2_clicked();

    void on_pushButton_removeRowForomTable_clicked();

    void on_pushButton_addRowToTable_clicked();

private:
    Ui::MainWindow *ui;
    std::vector<std::array<int, 2>> lab2_Params_;
    lab3_core::Params  lab3_Params_;
    lab5_core::Params lab5_Params_;

    lab2_core::ResultData lab2_ResultData_;
    lab3_core::ResultData lab3_ResultData_;
    lab5_core::ResultData lab5_ResultData_;

    MathModel mathModel_;
};
#endif // MAINWINDOW_H
