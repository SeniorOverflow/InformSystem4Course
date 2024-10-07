#pragma once
#include <vector>
#include <array>




class Lab5Core final
{

private:



public:
    Lab5Core();
    ~Lab5Core();

private:

};
//#include <iostream>
//#include <vector>
//#include <array>
//int main()
//{
//    //enter
//    int countFailures {7};
//    int countExperiments {1300};
//    std::array<double, 2> midWakeUpTimeInterval {0.60,1.00};
//    double permissWakeUpTime{0.65};
//    std::array<double, 2> transformTimeInterval {10.00,16.00};
//    double permissTransformTime{10.0};
//    double baseCriterionSafe {0.9};
//    //for exit
//    std::array<std::vector<double>,5>estimateValues;
//    std::array<double,5> metrics{};
//    std::array<double,2> absoluteCriterions{};
//    std::array<double,2> relativeCriterions{};
//    double phactorStability = {0};
//
//    //оценки первой метрики Н0101-H0110
//    for (int i{0}; i < 10; i++){
//        estimateValues[0].push_back(0.75);
//    }
//
//    //оценки второй метрики Н0201-H0205
//    for (int i{0}; i < 5; i++){
//        estimateValues[1].push_back(0.8);
//    }
//
//    //оценки третьей метрики Н0301-H0305
//    for (int i{0}; i < 5; i++){
//        estimateValues[2].push_back(0.85);
//    }
//
//    //Н0401
//    double H0401=1-static_cast<double>(countFailures)/static_cast<double>(countExperiments);
//    estimateValues[3].push_back(H0401);
//
//    //H0501
//    estimateValues[4].push_back(0.0);
//    double midT = midWakeUpTimeInterval[0];
//    double step = midWakeUpTimeInterval[0];
//    for (int i {0}; i < 100; i++){
//        step = step + (midWakeUpTimeInterval[1]-midWakeUpTimeInterval[0])/100;
//        midT+=step;
//    }
//    midT=midT/100;
//
//    if (midT<=permissWakeUpTime){
//        estimateValues[4].at(0)=1;}
//    else{
//        estimateValues[4].at(0)=permissWakeUpTime/midT;
//    }
//    //H0502
//    estimateValues[4].push_back(0.0);
//    midT = transformTimeInterval[0];
//    step = transformTimeInterval[0];
//    for (int i {0}; i < 200; i++){
//        step = step + (transformTimeInterval[1]-transformTimeInterval[0])/200;
//        midT+=step;
//    }
//    midT=midT/200;
//    std::cout <<midT<< "\n";
//    if (midT<=permissTransformTime){
//        estimateValues[4].at(1)=1;}
//    else{
//        estimateValues[4].at(1)=permissTransformTime/midT;
//    }
//
//
//
//
//    std::cout.setf(std::ios::fixed);
//    std::cout.precision(2);
//    for (int i{0}; i < 10; i++) {
//        std::cout << estimateValues[0].at(i)<<" ";
//    }
//    std::cout << "\n";
//    for (int i{0}; i < 5; i++) {
//        std::cout << estimateValues[1].at(i)<<" ";
//    }
//    std::cout << "\n";
//    for (int i{0}; i < 5; i++) {
//        std::cout << estimateValues[2].at(i)<<" ";
//    }
//    std::cout << "\n";
//    std::cout << estimateValues[3][0]<<"\n";
//    for (int i{0}; i < 2; i++) {
//        std::cout << estimateValues[4].at(i)<<" ";
//    }
//    return phactorStability;
//}
