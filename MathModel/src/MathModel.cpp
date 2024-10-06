#include "MathModel.h"

//MathModel::MathModel() {
//    m_setData.reset(new std::function<void(const Params &)>([&](const Params &params) {
//        setData(params);
//    }));

//    m_getResult.reset(new std::function<std::vector<double>()>([&]() {
//        return getResult();
//    }));

//}

//std::vector<double> MathModel::getResult() {
//    return {m_averageFlowRate, m_reynoldNumber, m_flowPressureLoss};
//}


//std::function<void(const Params &)> *MathModel::setDataFunc() {
//    return m_setData.get();
//}

//std::function<std::vector<double>()> *MathModel::getResultFunc() {
//    return m_getResult.get();
//}


MathModel::MathModel()
{

}
