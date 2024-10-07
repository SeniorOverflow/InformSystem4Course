#include "Lab2Core.h"
#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

Lab2Core::Lab2Core(std::vector<std::array<int, 2> > errorsData)
{
    errorsData_ = std::move(errorsData);
    findCoefficientB();
    findCoefficientK();
    findMidValueTime();
    findTimeToEndTesting();
}

// Вычисление суммы Xi
double Lab2Core::VXi(const vector<double>& X) {
    double sum = 0;
    for (double x : X) {
        sum += x;
    }
    return sum;
}

// Вычисление суммы i * Xi
double Lab2Core::VIXi(const vector<double>& X) {
    double sum = 0;
    for (size_t i = 0; i < X.size(); ++i) {
        sum += (i + 1) * X[i];  // i+1, так как индексация с 0
    }
    return sum;
}

// Вычисление левой части уравнения для поиска B
double Lab2Core::VLP(double B, int n) {
    double sum = 0;
    for (int i = 1; i <= n; ++i) {
        sum += 1.0 / (B - i + 1);
    }
    return sum;
}

// Вычисление правой части уравнения для поиска B
double Lab2Core::VRP(double B, const vector<double>& X) {
    double VXiVal = VXi(X);
    double VIXiVal = VIXi(X);
    return VXiVal / ((B + 1) * VXiVal - VIXiVal);
}

// Функция f(B) для метода Ньютона
double Lab2Core::f(double B, const vector<double>& X) {
    int n = X.size();
    return VLP(B, n) - VRP(B, X);
}

// Производная f'(B) (численное дифференцирование)
double Lab2Core::df(double B, const vector<double>& X) {
    double h = 1e-6;  // Малое значение для численного дифференцирования
    return (f(B + h, X) - f(B, X)) / h;
}

// Метод Ньютона для нахождения B
double Lab2Core::newtonMethod(double initialGuess, const vector<double>& X, double tolerance, int maxIterations) {
    double B = initialGuess;
    for (int i = 0; i < maxIterations; ++i) {
        double fB = f(B, X);
        double dfB = df(B, X);

        if (abs(dfB) < 1e-10) {
            cerr << "Производная слишком мала, возможно деление на ноль." << endl;
            return B;
        }

        double nextB = B - fB / dfB;

        if (abs(nextB - B) < tolerance) {
            return nextB;
        }

        B = nextB;
    }

    cerr << "Не удалось найти решение за указанное число итераций." << endl;
    return B;
}

// Поиск коэффициента B
void Lab2Core::findCoefficientB()
{
    vector<double> X;
    for (const auto& pair : errorsData_) {
        X.push_back(pair[1]);
    }

    double initialGuess = 100.0;  // начальное приближение
    double tolerance = 1e-6;      // точность
    int maxIterations = 100;      // максимальное число итераций

    coefficientB_ = newtonMethod(initialGuess, X, tolerance, maxIterations);
}

// Вычисление коэффициента пропорциональности K
void Lab2Core::findCoefficientK()
{
    vector<double> X;
    for (const auto& pair : errorsData_) {
        X.push_back(pair[1]);
    }

    coefficientK_ = calculateK(coefficientB_, X);
}

// Вспомогательная функция для вычисления коэффициента K
double Lab2Core::calculateK(double B, const vector<double>& X) {
    int n = X.size();
    double sum = 0;
    for (int i = 1; i <= n; ++i) {
        sum += (B - i + 1) * X[i - 1];
    }
    return static_cast<double>(n) / sum;
}

// Вычисление среднего времени до появления следующей ошибки
void Lab2Core::findTimeToEndTesting()
{
    vector<double> X;
    for (const auto& pair : errorsData_) {
        X.push_back(pair[1]);
    }

    midValueTime_ = calculateXn1(coefficientB_, coefficientK_, X.size());
}

// Вспомогательная функция для вычисления Xn+1
double Lab2Core::calculateXn1(double B, double K, int n) {
    return 1.0 / (K * (B - n));
}

// Вычисление времени до окончания тестирования
void Lab2Core::findMidValueTime()
{
    vector<double> X;
    for (const auto& pair : errorsData_) {
        X.push_back(pair[1]);
    }

    timeToEndTesting_ = calculateTk(coefficientB_, coefficientK_, X);
}

// Вспомогательная функция для вычисления Tk
double Lab2Core::calculateTk(double B, double K, const vector<double>& X) {
    double sum = 0;
    int n = X.size();
    for (int i = n + 1; i <= B; ++i) {
        sum += 1.0 / (B - i + 1);
    }
    return VXi(X) + (1.0 / K) * sum;
}

// Метод для получения результата
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
