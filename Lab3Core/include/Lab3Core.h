#pragma once
#include <vector>
#include <array>
#include "Parameters.h"
#include "ResultData.h"


namespace lab3_core {

struct Params
{
    int goals {};
    int measurements {};
    int trackedParameters {};
    int outputParameters {};
    double initialRating {};
    double levelLang {};
    int numberOfPrograms {};
    std::vector<int> volumsOfWritePr;
    std::vector<int> numOfErrors;
    int necessaryVolume {};
};


enum class  ProgmamLevel : uint8_t
{
    MultiLevel = 0x00,
    Simple = 0x01
};


struct ResultData
{
    int countPotencialErrors_task1;
    int countProgramModules;
    ProgmamLevel programLevel;

    double lengthProgram {};
    double voulmeProgram {};

    double countAssemblerCommand {};
    double calendarTimeProgramming {};
    double countPotencialErrors_task2;
    double startStabilityProgram {};

    std::array<double, 3> currentRaitingProgrammer {};
    std::array<double, 3> countPotencialErrors {};
};





class Lab3Core final
{

private:
  
    

public:

//   Lab3Core(const Params & params);

    Lab3Core(const Parameters &);

    ~Lab3Core();
    //Потенциальный объём программы
    double PotentialVolumeProgram();
    //Потенциальное количество ошибок (задание 1)
    double PotentialNumberErrors();
    //Количество модулей программы
    int GetSoftModules();
    //Число уровней программы
    int NumberOfLevels();
    //Длина программы
    double ProgramLengths();
    //Объём программы
    double SoftwareVolume();
    //Количество команд ассемблера
    double NumberOfAssemblerFunc();
    //Календарное время программирования
    double CalendarProgrammingTime();
    //Потенциальное количество ошибок (задание 2)
    double PotentialNumberErrorsTwo();
    //время наработки на отказ в часах
    double TimeToRefuse();
    //Коэффициент
    double Coefficient(double, int);
    //Текущий рейтинг программиста
    double CurrentRating(int);
    //Потенциальное число ошибок с учётом коэффициента текущего рейтинга и объёма программы
    double PotentialNumberErrorsThree(double);
    //Сбор данных результата выполнения лабораторной
    //void GetDataResult(ResultData *);
    ResultData GetDataResult();
    int GetdebuggetFunPerDay();
    void SetdebuggetFunPerDay(int);
    int GetnumberProgrammersInTeam();
    void SetnumberProgrammersInTeam(int);

private:

    Params params_;
    Parameters parameters_;
    //Минимальное число операндов
    int minNumberOperands_;
    //Количество модулей программы
    int numberOfSoftModules_;
    //Число отлаженных команд в день
    int debuggetFunPerDay_;
    //Число программистов в команде
    int numberProgrammersInTeam_;
    //оптимальное число переменных для одного модуля
    const int optimalNumberOfVariables_;
    //коэффициент перерасчёта, для перевода в количество команд ассемблера
    const double coeffAssembler_;
    //число элементарных различений
    const int numberElementaryDifferences_;
    //рабочих часов в день
    const int workingHours_;
    //оптимальная длина одного модуля
    double lengthModule_;
    //длина словаря
    double lenghtDictionary_;
};
}
