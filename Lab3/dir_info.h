#pragma once

#include <map>
#include <QString>
#include <QTextStream>
#include <iostream>
//Результирующая структура содержит инфу о директории.

struct DirInfo
{
    QString path_; // Путь к директории
    uint64_t totalSize_; // Общий размер директории
    std::map<QString, double> hash_; //map объектов и их размеров

    void PrintInfo() //Функция вывода имени директории и ее содержимого
    {
        QTextStream cout_(stdout);

        cout_ << path_  << " total size = " << totalSize_ << endl << flush;

        for(const auto& it : hash_)
        {
            cout_ << it.first << ' ' << it.second << '%' << endl << flush;
        }
    }
};
