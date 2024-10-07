#pragma once
#include <vector>
#include <array>


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
    int countProgramModules;
    ProgmamLevel programLevel;
    int countLevels;

    double lengthProgram {};
    double voulmeProgram {};

    double countAssemblerCommand {};
    double calendarTimeProgramming {};
    double startStabilityProgram {};

    std::array<double, 3> currentRaitingProgrammer {};
    std::array<double, 3> countPotencialErrors {};
};




class Lab3Core final
{

private:


public:
    Lab3Core(const Params & params);
    ~Lab3Core();

private:
   Params params_;
};
}
