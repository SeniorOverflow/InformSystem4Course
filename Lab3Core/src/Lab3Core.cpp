#include "Lab3Core.h"
#include <cmath>
#include <iostream>

namespace lab3_core {

//Lab3Core::Lab3Core(const Params &params)
//{
//    params_ = params;

Lab3Core::Lab3Core()
{
}

void Lab3Core::initData(const Params &params)
{
    parameters_ = params;
    minNumberOperands_ = parameters_.goals * parameters_.measurements *
    parameters_.trackedParameters + parameters_.goals * parameters_.outputParameters;

    if (minNumberOperands_ / optimalNumberOfVariables_ > optimalNumberOfVariables_)
    {
        numberOfSoftModules_ = minNumberOperands_/ optimalNumberOfVariables_ +
        minNumberOperands_ / pow(optimalNumberOfVariables_, 2);
    } else numberOfSoftModules_ = minNumberOperands_ / optimalNumberOfVariables_;

    debuggetFunPerDay_ = 10;
    numberProgrammersInTeam_ = 5;
    lenghtDictionary_ = optimalNumberOfVariables_ * log2(optimalNumberOfVariables_);
    lengthModule_ = 2* lenghtDictionary_ * log2(lenghtDictionary_);

}

Lab3Core::~Lab3Core()
{

}




double Lab3Core::PotentialVolumeProgram() {
    return (Lab3Core::minNumberOperands_+2) * log2(Lab3Core::minNumberOperands_+2);
}

double Lab3Core::PotentialNumberErrors() {
    return pow(PotentialVolumeProgram(), 2) / (numberElementaryDifferences_ * parameters_.levelLang);
}

int Lab3Core::NumberOfLevels() {
    if (numberOfSoftModules_ > optimalNumberOfVariables_)
    {
        return static_cast<int> (log2(minNumberOperands_)/3)+1;
    } else return 1;
    
}

double Lab3Core::ProgramLengths() {
    return  lengthModule_ * numberOfSoftModules_ + numberOfSoftModules_ * log2(numberOfSoftModules_);
}

double Lab3Core::SoftwareVolume() {
    return lengthModule_ * numberOfSoftModules_ * log2(2*lenghtDictionary_);
}

double Lab3Core::NumberOfAssemblerFunc() {
    return coeffAssembler_ * ProgramLengths();
}

double Lab3Core::CalendarProgrammingTime() {
    return coeffAssembler_ * ProgramLengths() / (numberProgrammersInTeam_ * debuggetFunPerDay_);
}

double Lab3Core::PotentialNumberErrorsTwo() {
    return SoftwareVolume() / numberElementaryDifferences_;
}

double Lab3Core::TimeToRefuse() {
    return CalendarProgrammingTime() / (2*log(PotentialNumberErrorsTwo())) * workingHours_;
}

double Lab3Core::Coefficient(double rating, int option) {
    switch (option)
    {
    case 0:
        return 1/(parameters_.levelLang + rating);
    case 1:
        return 1/(parameters_.levelLang * rating);
    case 2:
        return (1/parameters_.levelLang + 1/rating);
    default:
        return 1/(parameters_.levelLang + rating);
    }
}

double Lab3Core::CurrentRating(int option) {
    double sumVl = 0;
    double sumErToCof = 0;
    double rating = parameters_.initialRating;

    for (int i = 0; i < parameters_.numberOfPrograms; i++)
        {
            sumVl += parameters_.volumsOfWriienPr[i];
            if (parameters_.numOfErrors[i] != 0)
            {
                sumErToCof += parameters_.numOfErrors[i] / Coefficient(rating, option);
            }
            rating = rating * fabs(1+0.001 * (sumVl - sumErToCof));
        }
        return rating;
}

double Lab3Core::PotentialNumberErrorsThree(double coeff) {
    return coeff * parameters_.necessaryVolume;
}

void Lab3Core::SetdebuggetFunPerDay(int numDebug) {
    debuggetFunPerDay_ = numDebug;
}

void Lab3Core::SetnumberProgrammersInTeam(int numberProgrammers) {
    numberProgrammersInTeam_ = numberProgrammers;
}

int Lab3Core::GetdebuggetFunPerDay() {
    return debuggetFunPerDay_;
}

int Lab3Core::GetnumberProgrammersInTeam() {
    return numberProgrammersInTeam_;
}

int Lab3Core::GetSoftModules() {
    return numberOfSoftModules_;
}

ResultData Lab3Core::GetDataResult() {
    ResultData result;
    result.countPotencialErrors_task1 = PotentialNumberErrors();
    result.countProgramModules = GetSoftModules();
    if (NumberOfLevels() > 1)
    {
        result.programLevel = ProgmamLevel::MultiLevel;
    } else result.programLevel = ProgmamLevel::Simple;
    
    result.lengthProgram = ProgramLengths();
    result.voulmeProgram = SoftwareVolume();
    result.countAssemblerCommand = NumberOfAssemblerFunc();
    result.calendarTimeProgramming = CalendarProgrammingTime();
    result.countPotencialErrors_task2 = PotentialNumberErrorsTwo();
    result.startStabilityProgram = TimeToRefuse();
    double curRating;
    std::array<double, 3> ratings, countErrors;

    for (size_t i = 0; i < 3; i++)
    {
        curRating = CurrentRating(i);
        ratings.at(i) = curRating;
        countErrors.at(i) = PotentialNumberErrorsThree(Coefficient(curRating, i));
    }
    result.currentRaitingProgrammer = ratings;
    result.countPotencialErrors = countErrors;
    return result;
}
}
