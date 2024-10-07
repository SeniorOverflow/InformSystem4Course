#include <array>
#include <stdint.h>

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
