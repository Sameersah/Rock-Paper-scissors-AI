//
// Created by Sameer on 24/03/25.
//

// SmartStrategyFactory.h
#ifndef SMART_STRATEGY_FACTORY_H
#define SMART_STRATEGY_FACTORY_H

#include "StrategyFactory.h"
#include "SmartStrategy.h"

class SmartStrategyFactory : public StrategyFactory {
public:
    std::unique_ptr<Strategy> createStrategy() const override {
        return std::make_unique<SmartStrategy>();
    }
};

#endif // SMART_STRATEGY_FACTORY_H
