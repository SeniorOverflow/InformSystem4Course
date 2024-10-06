//#include <iostream>
//#include "ConsoleInterface.h"
#include "MathModel.h"
//#include <memory>

//int main() {
//    setlocale(LC_ALL, "Russian");


//    std::unique_ptr<MathModel> mathModel{new MathModel()};
//    //ConsoleInterface consoleInterface(mathModel->setDataFunc(), mathModel->getResultFunc());
//    //consoleInterface.run();


//    std::cin;
//    return 0;
//}

#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
