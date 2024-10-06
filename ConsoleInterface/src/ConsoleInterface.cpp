//#include "ConsoleInterface.h"


//const double Params::epsilon{0.0001};


//void ConsoleInterface::printRusItems(const std::vector<std::tuple<std::string, std::wstring>> &data) const noexcept {
//    for (size_t i = 0; i < data.size(); i++) {
//        std::wcout << "[ " << i << " ] - " << std::get<1>(data[i]) << std::endl;
//    }
//}


//void ConsoleInterface::printEngItems(const std::vector<std::tuple<std::string, std::wstring>> &data) const noexcept {
//    for (size_t i = 0; i < data.size(); i++) {
//        std::cout << "[ " << i << " ] - " << std::get<0>(data[i]) << std::endl;
//    }
//}


//ConsoleInterface::ConsoleInterface(std::function<void(const Params &)> *setParams /* функция для передачи*/,
//                                   std::function<std::vector<double>()> *getResult /*функция для получения результата*/)
//        : m_readParamsFunction(getResult),
//          m_writeParamsFunction(setParams) {

//    //  m_readParamsFunction = getResult;
//    initData();

//}


//bool Params::operator==(const Params &other) const {


//    if (resistanceСoefficientList.size() != other.resistanceСoefficientList.size()) {
//        return false;
//    }

//    for (size_t i = 0; i < resistanceСoefficientList.size(); i++) {
//        if (std::fabs(this->resistanceСoefficientList[i] - other.resistanceСoefficientList[i]) > epsilon)
//            return false;
//    }

//    return std::fabs(this->consumptionPerHour - other.consumptionPerHour) <= epsilon &&
//           std::fabs(this->compressStress - other.compressStress) <= epsilon &&
//           std::fabs(this->viscosity - other.viscosity) <= epsilon &&
//           std::fabs(this->crystallizerLength - other.crystallizerLength) <= epsilon &&
//           std::fabs(this->crystallizerChannelDiameter - other.crystallizerChannelDiameter) <= epsilon;
//}

//void ConsoleInterface::initData() {


//    m_nameParams.emplace_back("Consumption per hour (kg/h)", L"Расход за час (кг/ч)");
//    m_nameParams.emplace_back("Density (kg*m^2)", L"Плотность (кг* м^2)");
//    m_nameParams.emplace_back("Viscosity (Pa*s)", L"Вязкость (Па*с)"); // +
//    m_nameParams.emplace_back("Crystallizer length (m)", L"Длина кристаллизатора (м)"); // +
//    m_nameParams.emplace_back("Сrystallizer сhannel diameter (m)", L"Диаметр канала кристаллизатора (м)");
//    m_nameParams.emplace_back("Count pipe curve", L"Количество колен трубы");
//    m_nameParams.emplace_back("Resistance coefficient list", L"Список коэффициентов сопротивления ");
//    m_nameParams.emplace_back("Exit", L"Выход");


//    m_mainMenu.emplace_back("Show params", L"Показать параметры");
//    m_mainMenu.emplace_back("Edit params menu", L"Меню редактирования параметров");
//    m_mainMenu.emplace_back("Calculate", L"Рассчитать ");
//    m_mainMenu.emplace_back("Show result", L"Показать расчеты");
//    m_mainMenu.emplace_back("Save results", L"Сохранить результаты");
//    m_mainMenu.emplace_back("Change locale", L"Сменить язык");
//    m_mainMenu.emplace_back("Exit", L"Выход");


//    m_menuParams.emplace_back("Edit", L"Редактировать");
//    m_menuParams.emplace_back("Save changes", L"Сохранить изменения");
//    m_menuParams.emplace_back("Exit", L"Выход");

//}

//void ConsoleInterface::run() {

//    int32_t selectedItemMenu{0};

//    while (!m_isExit) {
//        showMenu();

//        std::string data;
//        std::cin >> data;
//        if (m_currentMenu != CurrentMenu::ShowCalculateResult) {
//            selectedItemMenu = stoi(data);
//        }
//        processMenu(selectedItemMenu);
//    }


//}

//void ConsoleInterface::showMenu() {


//    switch (m_currentMenu) {
//        case CurrentMenu::MainMenu: {
//            showMainMenu();
//            break;
//        }
//        case CurrentMenu::EditParams: {
//            showEditParamsMenu();
//            break;
//        }
//        case CurrentMenu::SelectEditParams: {
//            showEditSelectParamsMenu();
//            break;
//        }
//        case CurrentMenu::ShowParams: {
//            showParamsMenu(m_params);
//            break;
//        }
//        case CurrentMenu::ShowCalculateResult: {
//            showCalculateResult();
//            break;
//        }
//        case CurrentMenu::SaveResult: {
//            showSaveResult();
//            break;
//        }
//        case CurrentMenu::ChangeLanguage: {
//            showChangeLanguage();
//            break;
//        }
//        case CurrentMenu::AlertExit: {
//            showAlertExit();
//            break;
//        }
//        case CurrentMenu::consumptionPerHour: {
//            showEditConsumptionPerHour();
//            break;
//        }
//        case CurrentMenu::compressStress: {
//            showEditCompressStress();
//            break;
//        }
//        case CurrentMenu::viscosity: {
//            showEditViscosity();
//            break;
//        }
//        case CurrentMenu::crystallizerLength: {
//            showEditCrystallizerLength();
//            break;
//        }
//        case CurrentMenu::crystallizerChannelDiameter: {
//            showEditCrystallizerChannelDiameter();
//            break;
//        }
//        case CurrentMenu::resistanceСoefficientList: {
//            showEditResistanceСoefficientList();
//            break;
//        }
//        case CurrentMenu::pipeCurve: {
//            showEditPipeCurve();
//        }

//        default:
//            break;
//    }

//}

//void ConsoleInterface::showMainMenu() {

//    switch (m_currenLocale) {

//        case Locale::Rus: {
//            printRusItems(m_mainMenu);
//            break;
//        }
//        case Locale::Eng: {
//            printEngItems(m_mainMenu);
//            break;
//        }
//        default: {
//            std::cout << "Locale don't support";
//        }
//    }
//}

//void ConsoleInterface::showEditParamsMenu() {
//    switch (m_currenLocale) {

//        case Locale::Rus: {
//            std::wcout << L"Меню редактирования параметров" << std::endl;
//            printRusItems(m_menuParams);
//            break;
//        }
//        case Locale::Eng: {
//            std::cout << "Menu edit params" << std::endl;
//            printEngItems(m_menuParams);
//            break;
//        }
//        default: {
//            std::cout << "Locale don't support";
//        }
//    }
//}

//void ConsoleInterface::showEditSelectParamsMenu() {
//    switch (m_currenLocale) {

//        case Locale::Rus: {
//            printRusItems(m_nameParams);

//            break;
//        }
//        case Locale::Eng: {
//            printEngItems(m_nameParams);
//            break;
//        }
//        default: {
//            std::cout << "Locale don't support";
//        }

//    }
//}


//void ConsoleInterface::processMenu(int32_t item) {

//    switch (m_currentMenu) {
//        case CurrentMenu::MainMenu: {
//            processMainMenu(item);
//            break;
//        }
//        case CurrentMenu::EditParams: {
//            processParamsMenu(item);
//            break;
//        }

//        case CurrentMenu::SelectEditParams: {
//            processEditParamsMenu(item);
//            break;
//        }
//        case CurrentMenu::ShowParams: {
//            processShowParams(item);
//            break;
//        }
//        case CurrentMenu::ShowCalculateResult: {
//            processShowCalculateResult();
//            break;
//        }
//        case CurrentMenu::SaveResult: {
//            processSaveResult(item);
//            break;
//        }
//        case CurrentMenu::ChangeLanguage: {
//            processChangeLanguage(item);
//            break;
//        }
//        case CurrentMenu::AlertExit: {
//            processAlertExit(item);
//            break;
//        }
//        case CurrentMenu::consumptionPerHour: {
//            processConsumptionPerHour(item);
//            break;
//        }
//        case CurrentMenu::compressStress: {
//            processCompressStress(item);
//            break;
//        }
//        case CurrentMenu::viscosity: {
//            processViscosity(item);
//            break;
//        }
//        case CurrentMenu::crystallizerLength: {
//            processCrystallizerLength(item);
//            break;
//        }
//        case CurrentMenu::crystallizerChannelDiameter: {
//            processCrystallizerChannelDiameter(item);
//            break;
//        }
//        case CurrentMenu::resistanceСoefficientList: {
//            processResistanceСoefficientList(item);
//            break;
//        }
//        case CurrentMenu::pipeCurve: {
//            processPipeCurve(item);
//            break;
//        }
//        default: {
//            break;
//        }

//    }
//}

//void ConsoleInterface::processMainMenu(int32_t item) {
//    switch (item) {

//        case 0: {
//            changeCurrentMenu(CurrentMenu::ShowParams);
//            break;
//        }
//        case 1: {

//            changeCurrentMenu(CurrentMenu::EditParams);
//            break;
//        }

//        case 2: {
//            //changeCurrentMenu();
//            calculate();
//            break;
//        }
//        case 3: {
//            changeCurrentMenu(CurrentMenu::ShowCalculateResult);
//            break;
//        }
//        case 4: {
//            changeCurrentMenu(CurrentMenu::SaveResult);
//            break;
//        }
//        case 5: {
//            changeCurrentMenu(CurrentMenu::ChangeLanguage);
//            break;
//        }
//        case 6: {
//            changeCurrentMenu(CurrentMenu::AlertExit);
//            break;
//        }
//        default: {
//            break;
//        }


//    }

//}

//void ConsoleInterface::calculate() {

//    (*m_writeParamsFunction)(m_params);

//}

//void ConsoleInterface::processParamsMenu(int32_t item) {
//    switch (item) {

//        case 0: {
//            //editSelectParamsMenu();
//            changeCurrentMenu(CurrentMenu::SelectEditParams);
//            break;
//        }
//        case 1: {
//            changeCurrentMenu(CurrentMenu::SaveResult);
//            break;
//        }
//        case 2: {
//            changeCurrentMenu(CurrentMenu::MainMenu);
//            break;
//        }
//        default: {
//            break;
//        }
//    }
//}

//void ConsoleInterface::processEditParamsMenu(int32_t item) {

//    switch (item) {
//        case 0: {
//            changeCurrentMenu(CurrentMenu::consumptionPerHour);
//            break;
//        }
//        case 1: {
//            changeCurrentMenu(CurrentMenu::compressStress);
//            break;
//        }
//        case 2: {
//            changeCurrentMenu(CurrentMenu::viscosity);
//            break;
//        }
//        case 3: {
//            changeCurrentMenu(CurrentMenu::crystallizerLength);
//            break;
//        }
//        case 4: {
//            changeCurrentMenu(CurrentMenu::crystallizerChannelDiameter);
//            break;
//        }
//        case 5: {
//            changeCurrentMenu(CurrentMenu::pipeCurve);
//            break;
//        }

//        case 6: {
//            changeCurrentMenu(CurrentMenu::resistanceСoefficientList);
//            break;
//        }
//        default: {
//            changeCurrentMenu(CurrentMenu::EditParams);
//            break;
//        }

//    }

//}

//int ConsoleInterface::enterMenuItem() {
//    return 0;
//}

//int ConsoleInterface::printMenu() {
//    return 0;
//}


//void ConsoleInterface::showCalculateResult() {
//    auto result = (*m_readParamsFunction)();


//    // for (auto item: result) {
//    //     std::cout << item << std::endl;
//    // }


//    switch (m_currenLocale) {
//        case Locale::Rus: {
//            std::wcout << L" Скорость движения потока =\t" << result[0] << std::endl;
//            std::wcout << L" Число Рейнольдса =\t" <<  result[1] << std::endl;
//            std::wcout << L" Потерея давления потока =\t" <<  result[2] << std::endl;

//            std::wcout << L"\tВведите любую кнопку... " << std::endl;

//            break;
//        }
//        case Locale::Eng: {
//            std::cout << "\tPress any button... " << std::endl;
//            break;
//        }
//    }

//}

//void ConsoleInterface::showSaveResult() {


//    switch (m_currenLocale) {
//        case Locale::Rus: {
//            std::wcout << L"\tТекущие параметры " << std::endl;

//            break;
//        }
//        case Locale::Eng: {
//            std::cout << "\tCurrent  Params " << std::endl;
//            break;
//        }
//    }

//    showParams(m_params);


//    std::cout << std::endl;
//    if (m_params != m_unSaveParams) {
//        switch (m_currenLocale) {


//            case Locale::Rus: {
//                std::wcout << L"\tИзмененные параметры " << std::endl;
//                break;
//            }
//            case Locale::Eng: {
//                std::cout << "\tEdited params " << std::endl;
//                break;
//            }
//        }

//        showParams(m_unSaveParams);
//    }

//    switch (m_currenLocale) {
//        case Locale::Rus: {
//            std::wcout << "[ " << 0 << " ]" << L" Сохранить параметры" << std::endl;
//            std::wcout << "[ " << 1 << " ]" << L" Выход" << std::endl;
//            break;
//        }
//        case Locale::Eng: {
//            std::cout << "[ " << 0 << " ]" << " Save params" << std::endl;
//            std::cout << "[ " << 1 << " ]" << " Exit" << std::endl;
//            break;
//        }
//    }

//}

//void ConsoleInterface::showChangeLanguage() {


//    switch (m_currenLocale) {


//        case Locale::Rus: {

//            std::wcout << "[ " << 0 << " ]" << L" Русский [ текущий ]" << std::endl;
//            std::wcout << "[ " << 1 << " ]" << L" Английский " << std::endl;
//            std::wcout << "[ " << 2 << " ]" << L" Выход" << std::endl;
//            break;
//        }
//        case Locale::Eng: {

//            std::cout << "[ " << 0 << " ]" << " Russian " << std::endl;
//            std::cout << "[ " << 1 << " ]" << " English [ current ]" << std::endl;
//            std::cout << "[ " << 2 << " ]" << " Exit" << std::endl;

//            break;
//        }
//    }


//}

//void ConsoleInterface::showAlertExit() {

//}

//void ConsoleInterface::showEditConsumptionPerHour() {

//    switch (m_currenLocale) {


//        case Locale::Rus: {

//            std::wcout << "[ " << 0 << " ]" << std::get<1>(m_nameParams[0]) << " = "
//                       << m_unSaveParams.consumptionPerHour
//                       << std::endl;

//            std::wcout << "[ " << 1 << " ]" << L" Выход" << std::endl;

//            break;
//        }
//        case Locale::Eng: {
//            std::cout << "[ " << 0 << " ]" << std::get<0>(m_nameParams[0]) << " = "
//                      << m_unSaveParams.consumptionPerHour
//                      << std::endl;
//            std::cout << "[ " << 1 << " ]" << " Exit" << std::endl;
//            break;
//        }
//    }


//}

//void ConsoleInterface::showEditCompressStress() {

//    switch (m_currenLocale) {


//        case Locale::Rus: {

//            std::wcout << "[ " << 0 << " ]" << std::get<1>(m_nameParams[1]) << " = "
//                       << m_unSaveParams.compressStress
//                       << std::endl;

//            std::wcout << "[ " << 1 << " ]" << L" Выход" << std::endl;

//            break;
//        }
//        case Locale::Eng: {
//            std::cout << "[ " << 0 << " ]" << std::get<0>(m_nameParams[1]) << " = "
//                      << m_unSaveParams.compressStress
//                      << std::endl;
//            std::cout << "[ " << 1 << " ]" << " Exit" << std::endl;
//            break;
//        }
//    }
//}

//void ConsoleInterface::showEditViscosity() {

//    switch (m_currenLocale) {


//        case Locale::Rus: {

//            std::wcout << "[ " << 0 << " ]" << std::get<1>(m_nameParams[2]) << " = "
//                       << m_unSaveParams.viscosity
//                       << std::endl;

//            std::wcout << "[ " << 1 << " ]" << L" Выход" << std::endl;

//            break;
//        }
//        case Locale::Eng: {
//            std::cout << "[ " << 0 << " ]" << std::get<0>(m_nameParams[2]) << " = "
//                      << m_unSaveParams.viscosity
//                      << std::endl;
//            std::cout << "[ " << 1 << " ]" << " Exit" << std::endl;
//            break;
//        }
//    }
//}

//void ConsoleInterface::showEditCrystallizerLength() {
//    switch (m_currenLocale) {

//        case Locale::Rus: {

//            std::wcout << "[ " << 0 << " ]" << std::get<1>(m_nameParams[3]) << " = "
//                       << m_unSaveParams.crystallizerLength
//                       << std::endl;

//            std::wcout << "[ " << 1 << " ]" << L" Выход" << std::endl;

//            break;
//        }
//        case Locale::Eng: {
//            std::cout << "[ " << 0 << " ]" << std::get<0>(m_nameParams[3]) << " = "
//                      << m_unSaveParams.crystallizerLength
//                      << std::endl;
//            std::cout << "[ " << 1 << " ]" << " Exit" << std::endl;
//            break;
//        }
//    }
//}

//void ConsoleInterface::showEditCrystallizerChannelDiameter() {

//    switch (m_currenLocale) {


//        case Locale::Rus: {

//            std::wcout << "[ " << 0 << " ]" << std::get<1>(m_nameParams[4]) << " = "
//                       << m_unSaveParams.crystallizerChannelDiameter
//                       << std::endl;

//            std::wcout << "[ " << 1 << " ]" << L" Выход" << std::endl;

//            break;
//        }
//        case Locale::Eng: {
//            std::cout << "[ " << 0 << " ]" << std::get<0>(m_nameParams[4]) << " = "
//                      << m_unSaveParams.crystallizerChannelDiameter
//                      << std::endl;
//            std::cout << "[ " << 1 << " ]" << " Exit" << std::endl;
//            break;
//        }
//    }
//}

//void ConsoleInterface::showEditResistanceСoefficientList() {

//    showResistanceCoefficientList(m_unSaveParams);

//    switch (m_currenLocale) {
//        case Locale::Rus: {
//            std::wcout << "[ " << m_unSaveParams.resistanceСoefficientList.size() << " ]" << L"Выход" << std::endl;

//            break;
//        }
//        case Locale::Eng: {

//            std::cout << "[ " << m_unSaveParams.resistanceСoefficientList.size() << " ]" << " Exit" << std::endl;
//            break;
//        }
//    }
//}

//void ConsoleInterface::showResistanceCoefficientList(const Params &params) {
//    switch (m_currenLocale) {

//        case Locale::Rus: {

//            std::wcout << L"\tСписок коэффициентов сопротивления :" << std::endl;

//            for (size_t i = 0; i < params.resistanceСoefficientList.size(); i++) {
//                std::wcout << "[ " << i << " ]" << L"коэффициент сопротивления - " << i << L" = "
//                           << params.resistanceСoefficientList[i]
//                           << std::endl;
//            }


//            break;
//        }
//        case Locale::Eng: {
//            std::wcout << "\tResistance coefficient list :" << std::endl;
//            for (size_t i = 0; i < params.resistanceСoefficientList.size(); i++) {
//                std::wcout << "[ " << i << " ]" << "resistance coefficient - " << i << " = "
//                           << params.resistanceСoefficientList[i]
//                           << std::endl;
//            }

//            break;
//        }

//    }
//}

//void ConsoleInterface::showParamsMenu(const Params &params) {
//    showParams(params);

//    switch (m_currenLocale) {

//        case Locale::Rus: {


//            std::wcout << "[ " << 0 << " ]" << L" Выход" << std::endl;
//            break;
//        }
//        case Locale::Eng: {

//            std::wcout << "[ " << 0 << " ]" << L" Exit" << std::endl;
//            break;
//        }

//    }

//}


//void ConsoleInterface::showParams(const Params &params) {

//    switch (m_currenLocale) {

//        case Locale::Rus: {

//            std::wcout << std::get<1>(m_nameParams[0]) << L" = " << params.consumptionPerHour << std::endl;
//            std::wcout << std::get<1>(m_nameParams[1]) << L" = " << params.compressStress << std::endl;
//            std::wcout << std::get<1>(m_nameParams[2]) << L" = " << params.viscosity << std::endl;
//            std::wcout << std::get<1>(m_nameParams[3]) << L" = " << params.crystallizerLength << std::endl;
//            std::wcout << std::get<1>(m_nameParams[4]) << L" = " << params.crystallizerChannelDiameter << std::endl;
//            std::wcout << std::get<1>(m_nameParams[5]) << L" = " << params.pipeCurve << std::endl;

//            std::wcout << L"Список коэффициентов сопротивления :" << std::endl;

//            for (size_t i = 0; i < params.resistanceСoefficientList.size(); i++) {
//                std::wcout << L"\tкоэффициент сопротивления - " << i << L" = " << params.resistanceСoefficientList[i]
//                           << std::endl;
//            }


////            std::wcout << "[ " << 0 << " ]" << L" Выход" << std::endl;
//            break;
//        }
//        case Locale::Eng: {
//            std::cout << std::get<0>(m_nameParams[0]) << " = " << params.consumptionPerHour << std::endl;
//            std::cout << std::get<0>(m_nameParams[1]) << " = " << params.compressStress << std::endl;
//            std::cout << std::get<0>(m_nameParams[2]) << " = " << params.viscosity << std::endl;
//            std::cout << std::get<0>(m_nameParams[3]) << " = " << params.crystallizerLength << std::endl;
//            std::cout << std::get<0>(m_nameParams[4]) << " = " << params.crystallizerChannelDiameter << std::endl;
//            std::cout << std::get<0>(m_nameParams[5]) << " = " << params.pipeCurve << std::endl;
//            std::wcout << "Resistance coefficient list :" << std::endl;

//            for (size_t i = 0; i < params.resistanceСoefficientList.size(); i++) {
//                std::wcout << "\tresistance coefficient - " << i << " = " << params.resistanceСoefficientList[i]
//                           << std::endl;
//            }
////            std::wcout << "[ " << 0 << " ]" << L" Exit" << std::endl;
//            break;
//        }

//    }


//}

//void ConsoleInterface::changeCurrentMenu(CurrentMenu menu) {
//    m_currentMenu = menu;
//}

//void ConsoleInterface::processShowParams(int32_t item) {

//    switch (item) {
//        case 0: {
//            changeCurrentMenu(CurrentMenu::MainMenu);
//            break;
//        }
//        default: {
//            changeCurrentMenu(CurrentMenu::MainMenu);
//            break;
//        }
//    }

//}

//void ConsoleInterface::processShowCalculateResult() {
//    changeCurrentMenu(CurrentMenu::MainMenu);
//}

//void ConsoleInterface::processSaveResult(uint32_t item) {
//    switch (item) {
//        case 0: {
//            saveChangesEditParams();
//            break;
//        }
//        default: {
//            m_currentMenu = CurrentMenu::EditParams;
//        }

//    }
//}

//void ConsoleInterface::processChangeLanguage(uint32_t item) {

//    switch (item) {
//        case 0: {
//            m_currenLocale = Locale::Rus;
//            break;
//        }
//        case 1: {
//            m_currenLocale = Locale::Eng;
//            break;
//        }
//        default: {
//            m_currentMenu = CurrentMenu::MainMenu;
//            break;
//        }
//    }
//}

//void ConsoleInterface::processAlertExit(uint32_t item) {

//}

//void ConsoleInterface::processConsumptionPerHour(uint32_t item) {

//    switch (item) {
//        case 0: {

//            std::string data;
//            std::cin >> data;
//            std::replace(data.begin(), data.end(), '.', ',');
//            m_unSaveParams.consumptionPerHour = stod(data);
//            changeCurrentMenu(CurrentMenu::consumptionPerHour);
//            break;

//        }
//        default: {

//            changeCurrentMenu(CurrentMenu::SelectEditParams);
//            break;
//        }

//    }


//}

//void ConsoleInterface::processCompressStress(uint32_t item) {
//    switch (item) {
//        case 0: {

//            std::wstring data;
//            std::wcin >> data;
//            std::replace(data.begin(), data.end(), '.', ',');
//            m_unSaveParams.compressStress = stod(data);
//            changeCurrentMenu(CurrentMenu::compressStress);
//            break;
//        }
//        default: {
//            changeCurrentMenu(CurrentMenu::SelectEditParams);
//            break;
//        }

//    }

//}

//void ConsoleInterface::processViscosity(uint32_t item) {
//    switch (item) {
//        case 0: {

//            std::wstring data;
//            std::wcin >> data;
//            std::replace(data.begin(), data.end(), '.', ',');
//            m_unSaveParams.viscosity = stod(data);
//            changeCurrentMenu(CurrentMenu::viscosity);
//            break;
//        }
//        default: {
//            changeCurrentMenu(CurrentMenu::SelectEditParams);
//            break;
//        }

//    }

//}

//void ConsoleInterface::processCrystallizerLength(uint32_t item) {
//    switch (item) {
//        case 0: {

//            std::wstring data;
//            std::wcin >> data;
//            std::replace(data.begin(), data.end(), '.', ',');
//            m_unSaveParams.crystallizerLength = stod(data);
//            changeCurrentMenu(CurrentMenu::crystallizerLength);
//            break;
//        }
//        default: {
//            changeCurrentMenu(CurrentMenu::SelectEditParams);
//            break;
//        }

//    }

//}

//void ConsoleInterface::processCrystallizerChannelDiameter(uint32_t item) {
//    switch (item) {
//        case 0: {

//            std::wstring data;
//            std::wcin >> data;
//            std::replace(data.begin(), data.end(), '.', ',');
//            m_unSaveParams.crystallizerChannelDiameter = stod(data);
//            changeCurrentMenu(CurrentMenu::crystallizerChannelDiameter);
//            break;
//        }
//        default: {
//            changeCurrentMenu(CurrentMenu::SelectEditParams);
//            break;
//        }

//    }

//}

//void ConsoleInterface::processResistanceСoefficientList(uint32_t item) {

//    if (item < m_unSaveParams.resistanceСoefficientList.size()) {
//        std::wstring data;
//        std::wcin >> data;
//        std::replace(data.begin(), data.end(), '.', ',');
//        m_unSaveParams.resistanceСoefficientList[item] = stod(data);
//        changeCurrentMenu(CurrentMenu::resistanceСoefficientList);
//    } else {
//        changeCurrentMenu(CurrentMenu::SelectEditParams);
//    }

//}


//void ConsoleInterface::saveChangesEditParams() {

//    m_params = m_unSaveParams;

//}

//void ConsoleInterface::processPipeCurve(uint32_t item) {

//    switch (item) {
//        case 0: {

//            std::string data;
//            std::cin >> data;
//            m_unSaveParams.pipeCurve = stoi(data);
//            changeCurrentMenu(CurrentMenu::pipeCurve);
//            break;
//        }
//        default: {
//            changeCurrentMenu(CurrentMenu::SelectEditParams);
//            break;
//        }

//    }


//}

//void ConsoleInterface::showEditPipeCurve() {
//    switch (m_currenLocale) {


//        case Locale::Rus: {

//            std::wcout << "[ " << 0 << " ]" << std::get<1>(m_nameParams[5]) << " = "
//                       << m_unSaveParams.pipeCurve
//                       << std::endl;

//            std::wcout << "[ " << 1 << " ]" << L" Выход" << std::endl;

//            break;
//        }
//        case Locale::Eng: {
//            std::cout << "[ " << 0 << " ]" << std::get<0>(m_nameParams[5]) << " = "
//                      << m_unSaveParams.pipeCurve
//                      << std::endl;
//            std::cout << "[ " << 1 << " ]" << " Exit" << std::endl;
//            break;
//        }
//    }
//}

