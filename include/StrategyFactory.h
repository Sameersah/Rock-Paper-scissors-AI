//
// Created by Sameer on 24/03/25.
//

// StrategyFactory.h
#ifndef STRATEGY_FACTORY_H
#define STRATEGY_FACTORY_H

#include "Strategy.h"
#include <memory>

class StrategyFactory {
public:
    virtual ~StrategyFactory() = default;
    virtual std::unique_ptr<Strategy> createStrategy() const = 0;
};

#endif // STRATEGY_FACTORY_H
