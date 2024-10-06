#include "Lab2Core.h"

namespace lab2_core {

Lab2Core::Lab2Core(std::vector<std::array<int, 2> > errorsData)
{
    errorsData = std::move(errorsData);
    findCoefficientB();
}

void Lab2Core::findCoefficientK()
{

}

void Lab2Core::findCoefficientB()
{
}

void Lab2Core::findTimeToEndTesting()
{

}

void Lab2Core::findMidValueTime()
{

}

ResultData Lab2Core::result()
{
    ResultData result;
    result.coefficientK  = coefficientK_;
    result.coefficientB  = coefficientB_;
    result.timeToEndTesting  = timeToEndTesting_;
    result.midValueTime  = midValueTime_;

    return result;
}

Lab2Core::~Lab2Core()
{

}
}
