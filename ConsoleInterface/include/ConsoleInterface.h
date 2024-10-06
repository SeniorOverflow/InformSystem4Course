#pragma once

#include <iostream>
#include <array>
#include <string>
#include <vector>
#include <tuple>
#include <functional>
#include <cstdint>
#include <cmath>
#include <algorithm>




enum class Locale : uint8_t {
    Rus = 0x00,
    Eng = 0x01
};


enum class CurrentMenu : uint8_t {
    MainMenu = 0x00,
    EditParams = 0x01,
    SelectEditParams = 0x02,
    ShowParams = 0x03,

    ShowCalculateResult = 0x05,
    SaveResult = 0x06,
    ChangeLanguage = 0x07,
    AlertExit = 0x08,

    consumptionPerHour = 0x09,
    compressStress = 0x0A,
    viscosity = 0x0B,
    crystallizerLength = 0x0C,
    crystallizerChannelDiameter = 0x0D,
    resistanceCoefficientList = 0x0E,
    pipeCurve = 0x0F


};


class ConsoleInterface final {

private:
    using MainMenu = std::vector<std::tuple<std::string, std::wstring>>;
    using ParamsMenu = std::vector<std::tuple<std::string, std::wstring>>;
    using NameParams = std::vector<std::tuple<std::string, std::wstring>>;



public:


    explicit ConsoleInterface ();


    void run();


    ~ConsoleInterface() = default;

    int printMenu();

    void showMenu();


private:
    MainMenu m_mainMenu;
    ParamsMenu m_menuParams;
    NameParams m_nameParams;


//    std::function<void(const Params &)> *m_writeParamsFunction;  /* функция для передачи*/
//    std::function<std::vector<double>()> *m_readParamsFunction; /*функция для получения результата*/

    Locale m_currenLocale{Locale::Eng};
    CurrentMenu m_currentMenu{CurrentMenu::MainMenu};
    bool m_isExit{false};

};
