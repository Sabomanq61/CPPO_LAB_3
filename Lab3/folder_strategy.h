#pragma once

#include "explorer_stategy.h"

class StrategyFolder : public ExplorerStategy
{
public:
    StrategyFolder() = default;

    void Explore(const QString& ) const override;

    ~StrategyFolder() = default;
};
