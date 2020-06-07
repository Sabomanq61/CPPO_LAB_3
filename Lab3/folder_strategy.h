#pragma once

#include "explorer_stategy.h"
//Стратегия группировка по элементам

class StrategyFolder : public ExplorerStategy
{
public:
    StrategyFolder() = default;

    /// @brief Вывод процент. соотн. элементов папки относит. общего размера
    /// parh путь к директории
    /// return указатель на DirInfo
    std::shared_ptr<DirInfo> Explore(const QString& path) const override;

    //Подсчет размера объекта
    //return размер объекта
    int64_t Size(const QString& path) const;

    ~StrategyFolder() = default;
};