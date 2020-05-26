#pragma once

#include <QString>

class ExplorerStategy // Интерфейс стратегии
{
public:
    ExplorerStategy() =default;

    virtual void Explore(const QString&)const = 0;

    virtual ~ExplorerStategy() = default;
};


