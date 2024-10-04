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

struct Params {
    double consumptionPerHour{12000};
    double compressStress{810};
    double viscosity{0.0009};
    double crystallizerLength{55};
    double crystallizerChannelDiameter{0.034};
    uint32_t pipeCurve{2};
    std::array<double, 5> resistanceСoefficientList{0.5, 1, 6, 0.5, 1.8};

    static const double epsilon;

    bool operator==(const Params &other) const;
};


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
    resistanceСoefficientList = 0x0E,
    pipeCurve = 0x0F


};


class ConsoleInterface final {

private:
    using MainMenu = std::vector<std::tuple<std::string, std::wstring>>;
    using ParamsMenu = std::vector<std::tuple<std::string, std::wstring>>;
    using NameParams = std::vector<std::tuple<std::string, std::wstring>>;


    int enterMenuItem();


    void initData();

    void showMainMenu();

    void showEditParamsMenu();

    void showEditSelectParamsMenu();

    void printRusItems(const std::vector<std::tuple<std::string, std::wstring>> &mainMenu) const noexcept;

    void printEngItems(const std::vector<std::tuple<std::string, std::wstring>> &mainMenu) const noexcept;


    void calculate();

    void showParamsMenu(const Params &params);

    void showParams(const Params &params);

    void showResistanceCoefficientList(const Params &params);

    void showCalculateResult();

    void showSaveResult();

    void showChangeLanguage();

    void showAlertExit();

    void showEditConsumptionPerHour();

    void showEditCompressStress();

    void showEditViscosity();

    void showEditCrystallizerLength();

    void showEditCrystallizerChannelDiameter();

    void showEditResistanceСoefficientList();

    void showEditPipeCurve();

    void changeCurrentMenu(CurrentMenu menu);


    void processMenu(int32_t item);

    void processMainMenu(int32_t item);

    void processParamsMenu(int32_t item);

    void processEditParamsMenu(int32_t item);

    void processShowParams(int32_t item);

    void processShowCalculateResult();

    void processSaveResult(uint32_t item);

    void processChangeLanguage(uint32_t item);

    void processAlertExit(uint32_t item);

    void processConsumptionPerHour(uint32_t item);

    void processCompressStress(uint32_t item);

    void processViscosity(uint32_t item);

    void processCrystallizerLength(uint32_t item);

    void processCrystallizerChannelDiameter(uint32_t item);

    void processResistanceСoefficientList(uint32_t item);

    void processPipeCurve(uint32_t item);

    void saveChangesEditParams();


public:


    explicit ConsoleInterface(std::function<void(const Params &)> *   /* функция для передачи*/,
                              std::function<std::vector<double>()> * /*функция для получения результата*/);


    void run();


    ~ConsoleInterface() = default;

    int printMenu();

    void showMenu();


private:
    MainMenu m_mainMenu;
    ParamsMenu m_menuParams;
    NameParams m_nameParams;

    Params m_params;
    Params m_unSaveParams;

    std::function<void(const Params &)> *m_writeParamsFunction;  /* функция для передачи*/
    std::function<std::vector<double>()> *m_readParamsFunction; /*функция для получения результата*/

    Locale m_currenLocale{Locale::Eng};
    CurrentMenu m_currentMenu{CurrentMenu::MainMenu};
    bool m_isExit{false};

};