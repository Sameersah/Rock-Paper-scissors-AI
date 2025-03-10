//
// Created by Sameer on 10/03/25.
//

#ifndef STRATEGY_H
#define STRATEGY_H

#include <vector>
#include "Choice.h"

class Strategy {
public:
    virtual Choice getChoice(const std::vector<Choice>& history) = 0;
    virtual ~Strategy() {}
};

#endif //STRATEGY_H
