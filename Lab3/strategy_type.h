#pragma once
#include "explorer_stategy.h"
#include <map>

class StrategyType : public ExplorerStategy
{
public:
    StrategyType() = default;
    void Explore(const QString& ) const override;
    int64_t Size(const QString&, std::map<QString, int64_t>&) const;
    ~StrategyType() = default;
};


