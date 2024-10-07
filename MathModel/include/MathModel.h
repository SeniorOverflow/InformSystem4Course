#pragma once

#include <functional>
#include <ConsoleInterface.h>
#include <memory>

#include <Lab2Core.h>
#include <Lab3Core.h>
#include <Lab5Core.h>




class MathModel final {
private:


public:
      explicit MathModel();

      std::function<void (std::vector<std::array<int, 2>> &)> * lab2_InitData();
      std::function<lab2_core::ResultData()> * lab2_ResultFunc();

      std::function<void (const lab3_core::Params &)> * lab3_InitData();
      std::function<lab3_core::ResultData()> * lab3_ResultFunc();

      std::function<void (const lab5_core::Params &)> * lab5_InitData();
      std::function<lab5_core::ResultData()> * lab5_ResultFunc();
      ~MathModel();

private:
    std::unique_ptr<std::function<void (std::vector<std::array<int, 2>> &)>> lab2_setData {nullptr};
    std::unique_ptr<std::function<lab2_core::ResultData()>> lab2_getData{nullptr};

    std::unique_ptr<std::function<void (const lab3_core::Params &)>> lab3_setData {nullptr};
    std::unique_ptr<std::function<lab3_core::ResultData()>> lab3_getData {nullptr};

    std::unique_ptr<std::function<void (const lab5_core::Params &)>> lab5_setData {nullptr};
    std::unique_ptr<std::function<lab5_core::ResultData()>> lab5_getData {nullptr};

    std::unique_ptr<lab2_core::Lab2Core> lab2Core_{nullptr};
    std::unique_ptr<lab3_core::Lab3Core> lab3Core_{nullptr};
    std::unique_ptr<lab5_core::Lab5Core> lab5Core_{nullptr};
};
