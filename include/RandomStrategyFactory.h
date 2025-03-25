//
// Created by Sameer on 24/03/25.
//

// RandomStrategyFactory.h
#ifndef RANDOM_STRATEGY_FACTORY_H
#define RANDOM_STRATEGY_FACTORY_H

#include "StrategyFactory.h"
#include "RandomStrategy.h"

class RandomStrategyFactory : public StrategyFactory {
public:
    std::unique_ptr<Strategy> createStrategy() const override {
        return std::make_unique<RandomStrategy>();
    }
};

#endif // RANDOM_STRATEGY_FACTORY_H
