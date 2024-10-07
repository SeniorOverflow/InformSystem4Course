#pragma once
#include <vector>
#include <array>


struct Lab2ResultData
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
    // Вспомогательные функции для расчетов
    double VXi(const std::vector<double>& X);      // Сумма Xi
    double VIXi(const std::vector<double>& X);     // Сумма i * Xi
    double VLP(double B, int n);                   // Левая часть уравнения для B
    double VRP(double B, const std::vector<double>& X); // Правая часть уравнения для B
    double f(double B, const std::vector<double>& X);   // Функция для метода Ньютона
    double df(double B, const std::vector<double>& X);  // Производная для метода Ньютона
    double newtonMethod(double initialGuess, const std::vector<double>& X, double tolerance, int maxIterations);
    double calculateK(double B, const std::vector<double>& X); // Вычисление коэффициента K
    double calculateXn1(double B, double K, int n);            // Вычисление Xn+1
    double calculateTk(double B, double K, const std::vector<double>& X); // Вычисление времени до окончания тестирования


public:
    Lab2Core(std::vector<std::array<int, 2>> errorsData);
    Lab2ResultData result();
    ~Lab2Core();


private:

    double coefficientB_ {0.00};
    double coefficientK_ {0.00};
    double timeToEndTesting_ {0.00}; 
    double midValueTime_ {0.00}; 
    
    std::vector<std::array<int, 2>> errorsData_;
};
