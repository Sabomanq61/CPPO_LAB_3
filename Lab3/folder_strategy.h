#pragma once

#include "explorer_stategy.h"
//Стратегия группировка по элементам
class StrategyFolder : public ExplorerStategy
{
public:
    StrategyFolder() = default;

    ///@brief Вывод процент. соотн. элементов папки относит. общего размера
    void Explore(const QString& ) const override;

    //Подсчет размера папки
    //param path - Путь к папке
    //return размер папки
    int64_t Size(const QString& path) const;
    ~StrategyFolder() = default;
};
