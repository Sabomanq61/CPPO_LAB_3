#include <iostream>
#include "folder_strategy.h"
#include "strategy_type.h"
#include <QFileInfo>
#include <QDir>
#include <QTextStream>

void Print(const QString& text) // Обертка для выводы
{
    QTextStream(stdout) << text << endl << flush;
}

void CheckPointer(const std::shared_ptr<DirInfo>& point) // Проверка на случай пустого указателя
{
    if(point)
        point->PrintInfo();
}

int main()
{

    StrategyFolder *stratFolder = new StrategyFolder;
    StrategyType *stratType = new StrategyType;

    // 1 Случай пустой директории
    QString path("../Lab3/test/test1");
    Print("TEST 1\n");
    Print("Test strategy folder");

    stratFolder->Explore(path);
    CheckPointer(stratFolder->Explore(path));

    Print("\nTest strategy type");

    CheckPointer(stratType->Explore(path));

    //2 Случай директории с файлами без внутр. папок
    Print("\nTEST 2\n");
    path = "../Lab3/test/test2";

    Print("Test strategy folder");
    CheckPointer(stratFolder->Explore(path));

    Print("\nTest strategy type");
    CheckPointer(stratType->Explore(path));

    //3 Случай директории с файлами и внутр. папками
    path = "../Lab3/test/test3";
    Print("\nTEST 3\n");
    Print("Test strategy folder");
    CheckPointer(stratFolder->Explore(path));

    Print("\nTest strategy type");
    CheckPointer(stratType->Explore(path));

    //4 Случай пустой директори с вложениями
    path = "../Lab3/test/test4";
    Print("\nTEST 4\n");

    Print("Test strategy folder");
    CheckPointer(stratFolder->Explore(path));

    Print("\nTest strategy type");
    CheckPointer(stratType->Explore(path));

    delete stratType;
    delete stratFolder;
    return 0;
}













