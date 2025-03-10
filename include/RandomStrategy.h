//
// Created by Sameer on 10/03/25.
//

#ifndef RANDOMSTRATEGY_H
#define RANDOMSTRATEGY_H

#include "Strategy.h"
#include <cstdlib>

class RandomStrategy : public Strategy {
public:
    Choice getChoice(const std::vector<Choice>& history) override;
};

#endif //RANDOMSTRATEGY_H
