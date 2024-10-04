#include "MathModel.h"

MathModel::MathModel() {
    m_setData.reset(new std::function<void(const Params &)>([&](const Params &params) {
        setData(params);
    }));

    m_getResult.reset(new std::function<std::vector<double>()>([&]() {
        return getResult();
    }));

}

std::vector<double> MathModel::getResult() {
    //std::cout << "GET RESULT INTO MATH MODEL" << std::endl;
    return {m_averageFlowRate, m_reynoldNumber, m_flowPressureLoss};
}

void MathModel::setData(const Params &params) {
    // std::cout << "SET  DATA INTO MATH MODEL" << std::endl;

    m_params = params;

    calculateVolumeFlowPerSecond();
    calculateAverageFlowRate();
    calculateReynoldNumber();
    calculateSumResistanceСoefficientList();
    calculateFlowPressureLoss();

}

std::function<void(const Params &)> *MathModel::setDataFunc() {
    return m_setData.get();
}

std::function<std::vector<double>()> *MathModel::getResultFunc() {
    return m_getResult.get();
}

void MathModel::calculateVolumeFlowPerSecond() {
    m_volumeFlowPerSecond = m_params.consumptionPerHour / (m_params.compressStress * 3600);
}

void MathModel::calculateAverageFlowRate() {
    m_averageFlowRate = 4 * m_volumeFlowPerSecond / (M_PI * std::pow(m_params.crystallizerChannelDiameter, 2));

}

void MathModel::calculateReynoldNumber() {
    m_reynoldNumber =
            (m_averageFlowRate * m_params.crystallizerChannelDiameter * m_params.compressStress) / m_params.viscosity;
    if (m_reynoldNumber < 2320) {
        calculateLambdaForLaminar();
    } else {
        calculateLambdaForTurbulent();
    }

}

void MathModel::calculateLambdaForLaminar() {
    m_lambda = 64 / m_reynoldNumber;
}

void MathModel::calculateLambdaForTurbulent() {
    m_lambda = 0.316 / std::pow(m_reynoldNumber, -0.25);
}

void MathModel::calculateSumResistanceСoefficientList() {

    for (size_t i = 0; i < m_params.resistanceСoefficientList.size() - 1; i++) {
        m_sumResistanceСoefficientList += m_params.resistanceСoefficientList[i];


    }
    m_sumResistanceСoefficientList += m_params.resistanceСoefficientList[4] * m_params.pipeCurve;
}

void MathModel::calculateFlowPressureLoss() {
    m_flowPressureLoss = 0.5 * std::pow(m_averageFlowRate, 2) * m_params.compressStress *
                         (1 + (m_lambda * m_params.crystallizerLength * m_params.viscosity * 2.98 /
                               m_params.crystallizerChannelDiameter) +
                          m_sumResistanceСoefficientList);
}
