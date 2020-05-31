#include <QCoreApplication>
#include <iostream>
#include "folder_strategy.h"
#include "strategy_type.h"
#include <QFileInfo>
#include <QDir>
#include <QTextStream>

void Print(const QString& text)
{
    QTextStream(stdout) << text << endl << flush;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QString path("../Lab3/test");

    StrategyFolder *stratFolder = new StrategyFolder;
    StrategyType *stratType = new StrategyType;

    Print("Test strategy folder");
    stratFolder->Explore(path);

    Print("Test strategy type");
    //stratType->Explore(path);

    delete stratType;
    delete stratFolder;
    return a.exec();
}
