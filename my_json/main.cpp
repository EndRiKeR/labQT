#include "mainwindow.h"

#include <QApplication>
#include <QFileDialog>
#include <iostream>
#include <fstream>

std::string openFileAndTakeName();
void inputDataFromFile();
void printJSON(std::vector<std::string> vec);
std::string clearJSON(std::vector<std::string> vec);

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    inputDataFromFile();

    return a.exec();
}

std::string openFileAndTakeName()
{
    std::string filePath = QFileDialog::getOpenFileName(0,
                                                        "Open File",
                                                        "C:/Users/Acer2/Downloads/data.JSON",
                                                        "Excel Files (*.JSON)").toStdString();
    return filePath;
}

void inputDataFromFile()
{
    std::string str;
    std::vector<std::string> vec;
    std::ifstream fileForRead(openFileAndTakeName());
    while(getline(fileForRead, str)) {
         vec.push_back(str);
    }
    std::cout << clearJSON(vec) << std::endl;
    //printJSON(vec);
}

std::string clearJSON(std::vector<std::string> vec)
{
    std::string str;
    for (const auto& el : vec) {
        for (const auto& ch : el) {
            if (ch != '\n' && ch != ' ') {
                str += ch;
            }
        }
    }
    return str;
}

void printJSON(std::vector<std::string> vec)
{
    for (const auto& el : vec) {
        std::cout << el << std::endl;
    }
}
