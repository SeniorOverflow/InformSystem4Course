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


MathModel::MathModel() : lab2Core_(new lab2_core::Lab2Core()),
    lab3Core_(new lab3_core::Lab3Core()),
    lab5Core_(new lab5_core::Lab5Core())
{

}
std::function<void (std::vector<std::array<int, 2> > &)> *MathModel::lab2_InitData()
{
   return lab2_setData.get();
}

std::function<lab2_core::ResultData ()> *MathModel::lab2_ResultFunc()
{
    return lab2_getData.get();
}


std::function<void (const lab3_core::Params &)> *MathModel::lab3_InitData()
{
    return lab3_setData.get();
}

std::function<lab3_core::ResultData ()> *MathModel::lab3_ResultFunc()
{
    return lab3_getData.get();
}

std::function<void (const lab5_core::Params &)> *MathModel::lab5_InitData()
{
    return lab5_setData.get();
}

std::function<lab5_core::ResultData ()> *MathModel::lab5_ResultFunc()
{
    return lab5_getData.get();
}

MathModel::~MathModel()
{

}


