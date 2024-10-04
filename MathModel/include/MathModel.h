#pragma once

#include <functional>
#include <ConsoleInterface.h>
#include <memory>


class MathModel final {
private:
    void calculateVolumeFlowPerSecond();

    void calculateAverageFlowRate();

    void calculateReynoldNumber();

    void calculateLambdaForLaminar();

    void calculateLambdaForTurbulent();

    void calculateSumResistanceСoefficientList();

    void calculateFlowPressureLoss();

public:
    explicit MathModel();


    std::vector<double> getResult();

    void setData(const Params &params);

    std::function<void(const Params &)> *setDataFunc();

    std::function<std::vector<double>()> *getResultFunc();


private:
    std::unique_ptr<std::function<void(const Params &)>> m_setData{nullptr};
    std::unique_ptr<std::function<std::vector<double>()>> m_getResult{nullptr};
    Params m_params;

    double m_volumeFlowPerSecond{0.0};
    double m_averageFlowRate{0.0};
    double m_reynoldNumber{0.0};
    // bool m_laminarMode{false};

    double m_lambda{0.0};

    double m_sumResistanceСoefficientList{0.0};

    double m_flowPressureLoss{0.0};
};