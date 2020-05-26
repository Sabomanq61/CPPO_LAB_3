#pragma once

#include "explorer_stategy.h"

class StrategyFolder : public ExplorerStategy
{
public:
    StrategyFolder() = default;

    void Explore(const QString& ) const override;
    int64_t Size(const QString&) const;
    ~StrategyFolder() = default;
};
