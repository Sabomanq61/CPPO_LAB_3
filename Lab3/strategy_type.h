#pragma once
#include "explorer_stategy.h"
#include <map>
//Стратегия группировки по типам файлов
class StrategyType : public ExplorerStategy
{
public:
    StrategyType() = default;
    ///Вывод процент. соотношения размера файлов одного типа относительно общего размера папки
    /// param path Путь к папке.
    void Explore(const QString& path) const override;

    ///@brief Подсчет размеров элементов папки по типам.
    ///param[in] path путь к папке
    ///param[in] Контейнер std::map .Используется для хранения общего размера по типу файла.
    ///return Общий размер папки
    int64_t Size(const QString& path, std::map<QString, int64_t>& hash) const;
    ~StrategyType() = default;
};


