#pragma once
#include <vector>
#include <array>
#include "Parameters.h"
#include "ResultData.h"




class Lab3Core final
{

private:
    int goals;
    int measurements;
    int trackedParameters;
    int outputParameters;
    double initialRating;
    double levelLang;
    int numberOfPrograms;
    std::vector<int> volumsOfWriienPr;
    std::vector<int> numOfErrors;
    int necessaryVolume;

    int minNumberOperands;
    int numberOfSoftModules;

public:
    int debuggetFunPerDay;
    int numberProgrammersInTeam;
    Lab3Core(Parameters *);
    ~Lab3Core();
    double PotentialVolumeProgram();
    int PotentialNumberErrors();
    int GetSoftModules();
    int NumberOfLevels();
    double ProgramLengths();
    double SoftwareVolume();
    int NumberOfAssemblerFunc();
    double CalendarProgrammingTime();
    int PotentialNumberErrorsTwo();
    double TimeToRefuse();
    double Coefficient(double, int);
    double CurrentRating(int, int);
    double PotentialNumberErrorsThree(double);
    void GetDataResult(ResultData *);

private:

};
