#pragma once
#include <vector>
#include <array>
#include "Parameters.h"
#include "ResultData.h"




class Lab3Core final
{

private:
    //число одновременно сопровождаемых целей
    int goals;
    //количество измерений каждого отслеживаемого параметра
    int measurements;
    //Количество отслеживаемых параметров
    int trackedParameters;
    //Количество расчитываемых параметров по каждой цели
    int outputParameters;
    //Начальный рейтинг
    double initialRating;
    //Уровень языка программирования
    double levelLang;
    //Количество написанных программ
    int numberOfPrograms;
    //Объём написанных программ
    std::vector<int> volumsOfWriienPr;
    //Количество совершённых впрограммах ошибок
    std::vector<int> numOfErrors;
    //Объём программы, которую предполагается написать
    int necessaryVolume;

    //Минимальное число операндов
    int minNumberOperands;
    //Количество модулей программы
    int numberOfSoftModules;

public:
    //Число отлаженных команд в день
    int debuggetFunPerDay;
    //Число программистов в команде
    int numberProgrammersInTeam;
    Lab3Core(Parameters *);
    ~Lab3Core();
    //Потенциальный объём программы
    double PotentialVolumeProgram();
    //Потенциальное количество ошибок (задание 1)
    int PotentialNumberErrors();
    //Количество модулей программы
    int GetSoftModules();
    //Число уровней программы
    int NumberOfLevels();
    //Длина программы
    double ProgramLengths();
    //Объём программы
    double SoftwareVolume();
    //Количество команд ассемблера
    int NumberOfAssemblerFunc();
    //Календарное время программирования
    double CalendarProgrammingTime();
    //Потенциальное количество ошибок (задание 2)
    int PotentialNumberErrorsTwo();
    //время наработки на отказ в часах
    double TimeToRefuse();
    //Коэффициент
    double Coefficient(double, int);
    //Текущий рейтинг программиста
    double CurrentRating(int, int);
    //Потенциальное число ошибок с учётом коэффициента текущего рейтинга и объёма программы
    double PotentialNumberErrorsThree(double);
    //Сбор данных результата выполнения лабораторной
    void GetDataResult(ResultData *);

private:

};
