#ifndef STRATEGY_H
#define STRATEGY_H

#include <vector>
#include "Choice.h"  // Ensure Choice is defined before usage

class Strategy {
public:
    virtual Choice getChoice(const std::vector<Choice>& history) = 0;
    virtual void updateHistory(const std::vector<Choice>& history) = 0;
    virtual ~Strategy() = default;
};

#endif // STRATEGY_H
