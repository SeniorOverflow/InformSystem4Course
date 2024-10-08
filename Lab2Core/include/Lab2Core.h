#pragma once
#include <vector>
#include <array>

namespace lab2_core {

struct ResultData
{
    double coefficientB {0.00};
    double coefficientK {0.00};
    double timeToEndTesting {0.00};
    double midValueTime {0.00};
};


class Lab2Core final
{

private:
    void findCoefficientB();
    void findCoefficientK();
    void findTimeToEndTesting();
    void findMidValueTime();
    double Sum_Xi(const std::vector<double>& X);      
    double Sum_i_Xi(const std::vector<double>& X); 
    double leftPartFindB(double B, int n);                   
    double rightPartFindB(double B, const std::vector<double>& X); 
    double function_f_B(double B, const std::vector<double>& X);  
    double derivative_f_B(double B, const std::vector<double>& X);  
    double newtonMethod(double initialGuess, const std::vector<double>& X, double tolerance, int maxIterations);
    double calculateK(double B, const std::vector<double>& X); 
    double calculateXn1(double B, double K, int n);           
    double calculateTk(double B, double K, const std::vector<double>& X); 


public:
    Lab2Core();

    void initData(const std::vector<std::array<int, 2>>& errorsData);



    ResultData result();
    ~Lab2Core();


private:

    double coefficientB_ {0.00};
    double coefficientK_ {0.00};
    double timeToEndTesting_ {0.00}; 
    double midValueTime_ {0.00}; 
    
    std::vector<std::array<int, 2>> errorsData_;
};
}
