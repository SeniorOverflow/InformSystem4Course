#include <iostream>
#include "ConsoleInterface.h"
#include "MathModel.h"
#include <memory>

int main() {
    setlocale(LC_ALL, "Russian");

//    std::function<void(const Params &)> setDataFun = [](const Params &params) {
//        std::cout << "in Fun" << std::endl;
//    };
//
//    std::function<std::vector<double>()> getResultFun = []() { return std::vector<double>{0.0, 0.1}; };
//
    std::unique_ptr<MathModel> mathModel{new MathModel()};

    ConsoleInterface consoleInterface(mathModel->setDataFunc(), mathModel->getResultFunc());

    consoleInterface.run();


    std::cin;
    return 0;
}
