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
    lab2_setData_.reset(new std::function<void (const std::vector<std::array<int, 2>> &)>([&](const std::vector<std::array<int, 2>> & errorsData){
        return lab2Core_->initData(errorsData);
    }));

    lab2_getData_.reset( new  std::function<lab2_core::ResultData()>([&](){

        return lab2Core_->result();
    }));



    lab3_setData.reset( new std::function<void (const lab3_core::Params &)>([&]( const lab3_core::Params &params){
        return lab3Core_->initData(params);
    }));

    lab3_getData.reset(new std::function<lab3_core::ResultData()>([&](){
        return lab3Core_->GetDataResult();
    }));


    lab5_setData.reset(new std::function<void (const lab5_core::Params &)>([&](const lab5_core::Params &params){
        return lab5Core_->initData(params);
    }));

    lab5_getData.reset(new std::function<lab5_core::ResultData()>([&](){
        return lab5Core_->result();
    }));

}
std::function<void (const std::vector<std::array<int, 2> > &)> *MathModel::lab2_InitData()
{
   return lab2_setData_.get();
}

std::function<lab2_core::ResultData ()> *MathModel::lab2_ResultFunc()
{
    return lab2_getData_.get();
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


