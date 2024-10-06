#pragma once
#include <vector>
#include <array>


struct Lab2ResultData
{
    double coefficientK {0.00};
    double coefficientB {0.00};
    double timeToEndTesting {0.00};
    double midValueTime {0.00};
};


class Lab2Core final
{

private:
    void findCoefficientK();
    void findCoefficientB();
    void findTimeToEndTesting();
    void findMidValueTime();

public:
    Lab2Core(std::vector<std::array<int, 2>> errorsData);
    Lab2ResultData result();
    ~Lab2Core();


private:

    double coefficientK_ {0.00};
    double coefficientB_ {0.00};
    double timeToEndTesting_ {0.00}; 
    double midValueTime_ {0.00}; 
    
    std::vector<std::array<int, 2>> errorsData_;
};
