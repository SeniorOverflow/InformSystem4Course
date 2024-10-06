#pragma once
#include <vector>
#include <array>


namespace lab5_core {

struct Params
{
    int countFailures {0};
    int countExperiments {0};
    std::array<double, 2> midWakeUpTimeInterval {0.00, 0.00};
    double permissWakeUpTime{0.0};
    std::array<double, 2> transformTimeInterval {0.00, 0.00};
    double permissTransformTime{0.0};
    double baseCriterionSafe {0.0};
};

struct ResultData
{
    std::vector<double> estimateValues;
    std::vector<double> metrics;
    std::vector<double> metricsFormula3;
    std::vector<double> absoluteCriterions;
    std::vector<double> relativeCriterions;

    double phactorStability;
};


class Lab5Core final
{

private:


public:
    Lab5Core();
    ~Lab5Core();

private:

};
}
