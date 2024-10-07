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
    // ��������������� ������� ��� ��������
    double VXi(const std::vector<double>& X);      // ����� Xi
    double VIXi(const std::vector<double>& X);     // ����� i * Xi
    double VLP(double B, int n);                   // ����� ����� ��������� ��� B
    double VRP(double B, const std::vector<double>& X); // ������ ����� ��������� ��� B
    double f(double B, const std::vector<double>& X);   // ������� ��� ������ �������
    double df(double B, const std::vector<double>& X);  // ����������� ��� ������ �������
    double newtonMethod(double initialGuess, const std::vector<double>& X, double tolerance, int maxIterations);
    double calculateK(double B, const std::vector<double>& X); // ���������� ������������ K
    double calculateXn1(double B, double K, int n);            // ���������� Xn+1
    double calculateTk(double B, double K, const std::vector<double>& X); // ���������� ������� �� ��������� ������������


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
