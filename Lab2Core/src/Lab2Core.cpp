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

// ���������� ����� Xi
double Lab2Core::VXi(const vector<double>& X) {
    double sum = 0;
    for (double x : X) {
        sum += x;
    }
    return sum;
}

// ���������� ����� i * Xi
double Lab2Core::VIXi(const vector<double>& X) {
    double sum = 0;
    for (size_t i = 0; i < X.size(); ++i) {
        sum += (i + 1) * X[i];  // i+1, ��� ��� ���������� � 0
    }
    return sum;
}

// ���������� ����� ����� ��������� ��� ������ B
double Lab2Core::VLP(double B, int n) {
    double sum = 0;
    for (int i = 1; i <= n; ++i) {
        sum += 1.0 / (B - i + 1);
    }
    return sum;
}

// ���������� ������ ����� ��������� ��� ������ B
double Lab2Core::VRP(double B, const vector<double>& X) {
    double VXiVal = VXi(X);
    double VIXiVal = VIXi(X);
    return VXiVal / ((B + 1) * VXiVal - VIXiVal);
}

// ������� f(B) ��� ������ �������
double Lab2Core::f(double B, const vector<double>& X) {
    int n = X.size();
    return VLP(B, n) - VRP(B, X);
}

// ����������� f'(B) (��������� �����������������)
double Lab2Core::df(double B, const vector<double>& X) {
    double h = 1e-6;  // ����� �������� ��� ���������� �����������������
    return (f(B + h, X) - f(B, X)) / h;
}

// ����� ������� ��� ���������� B
double Lab2Core::newtonMethod(double initialGuess, const vector<double>& X, double tolerance, int maxIterations) {
    double B = initialGuess;
    for (int i = 0; i < maxIterations; ++i) {
        double fB = f(B, X);
        double dfB = df(B, X);

        if (abs(dfB) < 1e-10) {
            cerr << "����������� ������� ����, �������� ������� �� ����." << endl;
            return B;
        }

        double nextB = B - fB / dfB;

        if (abs(nextB - B) < tolerance) {
            return nextB;
        }

        B = nextB;
    }

    cerr << "�� ������� ����� ������� �� ��������� ����� ��������." << endl;
    return B;
}

// ����� ������������ B
void Lab2Core::findCoefficientB()
{
    vector<double> X;
    for (const auto& pair : errorsData_) {
        X.push_back(pair[1]);
    }

    double initialGuess = 100.0;  // ��������� �����������
    double tolerance = 1e-6;      // ��������
    int maxIterations = 100;      // ������������ ����� ��������

    coefficientB_ = newtonMethod(initialGuess, X, tolerance, maxIterations);
}

// ���������� ������������ ������������������ K
void Lab2Core::findCoefficientK()
{
    vector<double> X;
    for (const auto& pair : errorsData_) {
        X.push_back(pair[1]);
    }

    coefficientK_ = calculateK(coefficientB_, X);
}

// ��������������� ������� ��� ���������� ������������ K
double Lab2Core::calculateK(double B, const vector<double>& X) {
    int n = X.size();
    double sum = 0;
    for (int i = 1; i <= n; ++i) {
        sum += (B - i + 1) * X[i - 1];
    }
    return static_cast<double>(n) / sum;
}

// ���������� �������� ������� �� ��������� ��������� ������
void Lab2Core::findTimeToEndTesting()
{
    vector<double> X;
    for (const auto& pair : errorsData_) {
        X.push_back(pair[1]);
    }

    midValueTime_ = calculateXn1(coefficientB_, coefficientK_, X.size());
}

// ��������������� ������� ��� ���������� Xn+1
double Lab2Core::calculateXn1(double B, double K, int n) {
    return 1.0 / (K * (B - n));
}

// ���������� ������� �� ��������� ������������
void Lab2Core::findMidValueTime()
{
    vector<double> X;
    for (const auto& pair : errorsData_) {
        X.push_back(pair[1]);
    }

    timeToEndTesting_ = calculateTk(coefficientB_, coefficientK_, X);
}

// ��������������� ������� ��� ���������� Tk
double Lab2Core::calculateTk(double B, double K, const vector<double>& X) {
    double sum = 0;
    int n = X.size();
    for (int i = n + 1; i <= B; ++i) {
        sum += 1.0 / (B - i + 1);
    }
    return VXi(X) + (1.0 / K) * sum;
}

// ����� ��� ��������� ����������
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
