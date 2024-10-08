#include "Lab5Core.h"

namespace lab5_core {

Lab5Core::Lab5Core()
{

}

void Lab5Core::initData(const Params &params)
{
    params_ = params;

    //enter
//    int countFailures {7};
//    int countExperiments {1300};
//    std::array<double, 2> midWakeUpTimeInterval {0.60,1.00};
//    double permissWakeUpTime{0.65};
//    std::array<double, 2> transformTimeInterval {10.00,16.00};
//    double permissTransformTime{10.0};
//    double baseCriterionSafe {0.9};
    //for exit
    std::array<std::vector<double>,5>estimateValues;
    std::array<double,5> metrics{};
    std::array<double,2> absoluteCriterions{};
    std::array<double,2> relativeCriterions{};
    double phactorStability = {0};

    //оценки первой метрики Н0101-H0110
    for (int i{0}; i < 10; i++){
        estimateValues[0].push_back(0.75);
    }

    //оценки второй метрики Н0201-H0205
    for (int i{0}; i < 5; i++){
        estimateValues[1].push_back(0.8);
    }

    //оценки третьей метрики Н0301-H0305
    for (int i{0}; i < 5; i++){
        estimateValues[2].push_back(0.85);
    }

    //Н0401
    double H0401=1-static_cast<double>(params_.countFailures)/static_cast<double>(params_.countExperiments);
    estimateValues[3].push_back(H0401);

    //H0501
    estimateValues[4].push_back(0.0);
    double midT = params_.midWakeUpTimeInterval[0];
    double step = params_.midWakeUpTimeInterval[0];
    for (int i {0}; i < 100; i++){
        step = step + (params_.midWakeUpTimeInterval[1]-params_.midWakeUpTimeInterval[0])/100;
        midT+=step;
    }
    midT=midT/100;
    if (midT<=params_.permissWakeUpTime){
        estimateValues[4].at(0)=1;}
    else{
        estimateValues[4].at(0)=params_.permissWakeUpTime/midT;
    }

    //H0502
    estimateValues[4].push_back(0.0);
    midT = params_.transformTimeInterval[0];
    step = params_.transformTimeInterval[0];
    for (int i {0}; i < 200; i++){
        step = step + (params_.transformTimeInterval[1]-params_.transformTimeInterval[0])/200;
        midT+=step;
    }
    midT=midT/200;
    if (midT<=params_.permissTransformTime){
        estimateValues[4].at(1)=1;}
    else{
        estimateValues[4].at(1)=params_.permissTransformTime/midT;
    }

    //оценки метрик
    for (int j{0}; j<5; j++) {
        for (int i{0}; i < estimateValues[j].size(); i++) {
            metrics[j] += estimateValues[j][i];
        }
        metrics[j] /= static_cast<double>(estimateValues[j].size());
    }

    //абсолютные оценки критериев (равные веса по 0.3 и по 0.5)
    absoluteCriterions[0] = metrics[0]*0.334 + metrics[1]*0.333 + metrics[2]*0.333;
    absoluteCriterions[1] = metrics[3]*0.5 + metrics[4]*0.5;

    //относительные оценки критериев (равне веса по 0.3 и по 0.5)
    relativeCriterions[0] = absoluteCriterions[0]/params_.baseCriterionSafe;
    relativeCriterions[1] = absoluteCriterions[1]/params_.baseCriterionSafe;

    //фактор надёжности (веса по 0.5)
    phactorStability = relativeCriterions[0]*0.5 + relativeCriterions[1]*0.5;

//    //вывод в консоль всего
//    std::cout.setf(std::ios::fixed);
//    std::cout.precision(2);
//    for (int j{0}; j<5; j++) {
//        for (int i{0}; i < estimateValues[j].size(); i++) {
//            std::cout << estimateValues[j][i] << " ";
//        }
//        std::cout << "\n";
//    }
//    for (int i{0}; i < 5; i++) {
//        std::cout << metrics[i] << " ";
//    }
//    for (int i{0}; i < 2; i++) {
//        std::cout << absoluteCriterions[i] << " ";
//    }
//    std::cout << "\n";
//    for (int i{0}; i < 2; i++) {
//        std::cout << relativeCriterions[i] << " ";
//    }
//    std::cout << "\n" <<phactorStability;

}

ResultData Lab5Core::result()
{
    return result_;
}

Lab5Core::~Lab5Core()
{

}
}
