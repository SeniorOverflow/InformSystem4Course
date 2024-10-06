#include "../include/Lab3Core.h"
#include <math.h>


Lab3Core::Lab3Core(Parameters *parameters)
{
    goals = parameters->goals;
    measurements = parameters->measurements;
    trackedParameters = parameters->trackedParameters;
    outputParameters = parameters->outputParameters;
    initialRating = parameters->initialRating;
    levelLang = parameters->levelLang;
    numberOfPrograms = parameters->numberOfPrograms;
    volumsOfWriienPr = parameters->volumsOfWriienPr;
    numOfErrors = parameters->numOfErrors;
    necessaryVolume = parameters->necessaryVolume;
    minNumberOperands = goals*measurements*trackedParameters+goals*outputParameters;
    if (minNumberOperands/8 > 8)
    {
        numberOfSoftModules = minNumberOperands/8+minNumberOperands/64;
    } else numberOfSoftModules = minNumberOperands/8;
    debuggetFunPerDay = 10;
    numberProgrammersInTeam = 5;
    
}

Lab3Core::~Lab3Core()
{

}

double Lab3Core::PotentialVolumeProgram() {
    return (Lab3Core::minNumberOperands+2)*log2(Lab3Core::minNumberOperands+2);
}

int Lab3Core::PotentialNumberErrors() {
    return pow(PotentialVolumeProgram(), 2)/(3000*levelLang);
}

int Lab3Core::NumberOfLevels() {
    if (numberOfSoftModules > 8)
    {
        return (int) log2(minNumberOperands)/3+1;
    } else return 1;
    
}

double Lab3Core::ProgramLengths() {
    return 220*numberOfSoftModules+numberOfSoftModules*log2(numberOfSoftModules);
}

double Lab3Core::SoftwareVolume() {
    return 220*numberOfSoftModules*log2(48);
}

int Lab3Core::NumberOfAssemblerFunc() {
    return 3*ProgramLengths()/8;
}

double Lab3Core::CalendarProgrammingTime() {
    return 3*ProgramLengths()/(8*numberProgrammersInTeam*debuggetFunPerDay);
}

int Lab3Core::PotentialNumberErrorsTwo() {
    return SoftwareVolume()/3000;
}

double Lab3Core::TimeToRefuse() {
    return CalendarProgrammingTime()/(2*log(PotentialNumberErrorsTwo()))*7;
}

double Lab3Core::Coefficient(double rating, int i) {
    switch (i)
    {
    case 1:
        return 1/(levelLang+rating);
    case 2:
        return 1/(levelLang*rating);
    case 3:
        return (1/levelLang+1/rating);
    default:
        return 1/(levelLang+rating);
    }
}

double Lab3Core::CurrentRating(int numberOfPrograms, int i) {
    double sumVl = 0, sumErToCof = 0, r = initialRating;

    for (int j = 0; j < numberOfPrograms; j++)
        {
            sumVl += volumsOfWriienPr[j];
            if (numOfErrors[j] != 0)
            {
                sumErToCof += numOfErrors[j]/Coefficient(r, i);
            }
            r = r*abs(1+0.001*(sumVl - sumErToCof));
        }
        return r;
}

double Lab3Core::PotentialNumberErrorsThree(double coeff) {
    return coeff*necessaryVolume;
}

int Lab3Core::GetSoftModules() {
    return numberOfSoftModules;
}

void Lab3Core::GetDataResult(ResultData *result) {
    result->countPotencialErrors_task1 = PotentialNumberErrors();
    result->countProgramModules = GetSoftModules();
    if (NumberOfLevels() > 1)
    {
        result->programLevel = ProgmamLevel::MultiLevel;
    } else result->programLevel = ProgmamLevel::Simple;
    
    result->lengthProgram = ProgramLengths();
    result->voulmeProgram = SoftwareVolume();
    result->countAssemblerCommand = NumberOfAssemblerFunc();
    result->calendarTimeProgramming = CalendarProgrammingTime();
    result->countPotencialErrors_task2 = PotentialNumberErrorsTwo();
    result->startStabilityProgram = TimeToRefuse();
    double dd, r, z;
    std::array<double, 3> ratings, countErrors;
    for (size_t i = 1; i < 4; i++)
    {
        dd = CurrentRating(numberOfPrograms, i);
        ratings.at(i-1) = dd;
        r = Coefficient(dd, i);
        z =PotentialNumberErrorsThree(r);
        countErrors.at(i-1) = z;
    }
    result->currentRaitingProgrammer = ratings;
    result->countPotencialErrors = countErrors;
}