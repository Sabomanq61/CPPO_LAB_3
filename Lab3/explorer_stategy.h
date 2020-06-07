#pragma once

#include <QString>
#include "dir_info.h"
#include <memory>

class ExplorerStategy // Интерфейс стратегии
{
public:
    ExplorerStategy() = default; //Дефолтный деструктор

    // param [in] path путь к директории
    // return указатель на DirInfo
    virtual std::shared_ptr<DirInfo> Explore(const QString& path)const = 0;

    virtual ~ExplorerStategy() = default; // Виртуальный дефолтный деструктор для правильного освобождения памяти
};


