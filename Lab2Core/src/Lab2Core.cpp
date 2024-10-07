#include "Lab2Core.h"
#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>


Lab2Core::Lab2Core(std::vector<std::array<int, 2> > errorsData)
{
    errorsData_ = std::move(errorsData);
    findCoefficientB();
    findCoefficientK();
    findMidValueTime();
    findTimeToEndTesting();
}

double Lab2Core::Sum_Xi(const std::vector<double>& X) {
    double sum = 0;
    for (double x : X) {
        sum += x;
    }
    return sum;
}


double Lab2Core::Sum_i_Xi(const std::vector<double>& X) {
    double sum = 0;
    for (size_t i = 0; i < X.size(); ++i) {
        sum += (i + 1) * X[i];  
    }
    return sum;
}


double Lab2Core::leftPartFindB(double B, int n) {
    double sum = 0;
    for (int i = 1; i <= n; ++i) {
        sum += 1.0 / (B - i + 1);
    }
    return sum;
}


double Lab2Core::rightPartFindB(double B, const std::vector<double>& X) {
    double Sum_XiVal = Sum_Xi(X);
    double Sum_i_XiVal = Sum_i_Xi(X);
    return Sum_XiVal / ((B + 1) * Sum_XiVal - Sum_i_XiVal);
}


double Lab2Core::function_f_B(double B, const std::vector<double>& X) {
    int n = X.size();
    return leftPartFindB(B, n) - rightPartFindB(B, X);
}


double Lab2Core::derivative_f_B(double B, const std::vector<double>& X) {
    double h = 1e-6;  
    return (function_f_B(B + h, X) - function_f_B(B, X)) / h;
}


double Lab2Core::newtonMethod(double initialGuess, const std::vector<double>& X, double tolerance, int maxIterations) {
    double B = initialGuess;
    for (int i = 0; i < maxIterations; ++i) {
        double fB = function_f_B(B, X);
        double dfB = derivative_f_B(B, X);

        if (std::abs(dfB) < 1e-10) {
            std::cerr << "Proizvodnaya slishkom mala, vozmozhno delenie na nol." << std::endl;
            return B;
        }

        double nextB = B - fB / dfB;

        if (std::abs(nextB - B) < tolerance) {
            return nextB;
        }

        B = nextB;
    }

    std::cerr << "Ne udalos naiti resenie za ukazannoe chislo iteracii. " << std::endl;
    return B;
}


void Lab2Core::findCoefficientB()
{
    std::vector<double> X;
    for (const auto& pair : errorsData_) {
        X.push_back(pair[1]);
    }

    double initialGuess = 100.0;  
    double tolerance = 1e-6;      
    int maxIterations = 100;      

    coefficientB_ = newtonMethod(initialGuess, X, tolerance, maxIterations);
}


void Lab2Core::findCoefficientK()
{
    std::vector<double> X;
    for (const auto& pair : errorsData_) {
        X.push_back(pair[1]);
    }

    coefficientK_ = calculateK(coefficientB_, X);
}

double Lab2Core::calculateK(double B, const std::vector<double>& X) {
    int n = X.size();
    double sum = 0;
    for (int i = 1; i <= n; ++i) {
        sum += (B - i + 1) * X[i - 1];
    }
    return static_cast<double>(n) / sum;
}

void Lab2Core::findTimeToEndTesting()
{
    std::vector<double> X;
    for (const auto& pair : errorsData_) {
        X.push_back(pair[1]);
    }

    midValueTime_ = calculateXn1(coefficientB_, coefficientK_, X.size());
}

double Lab2Core::calculateXn1(double B, double K, int n) {
    return 1.0 / (K * (B - n));
}

void Lab2Core::findMidValueTime()
{
    std::vector<double> X;
    for (const auto& pair : errorsData_) {
        X.push_back(pair[1]);
    }

    timeToEndTesting_ = calculateTk(coefficientB_, coefficientK_, X);
}

double Lab2Core::calculateTk(double B, double K, const std::vector<double>& X) {
    double sum = 0;
    int n = X.size();
    for (int i = n + 1; i <= B; ++i) {
        sum += 1.0 / (B - i + 1);
    }
    return Sum_Xi(X) + (1.0 / K) * sum;
}

Lab2ResultData Lab2Core::result()
{
    Lab2ResultData result;
    result.coefficientB  = coefficientB_;
    result.coefficientK  = coefficientK_;
    result.timeToEndTesting  = timeToEndTesting_;
    result.midValueTime  = midValueTime_;

    return result;
}

Lab2Core::~Lab2Core()
{

}
