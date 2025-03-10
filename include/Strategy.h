#ifndef STRATEGY_H
#define STRATEGY_H

#include <vector>
#include "Choice.h"  // Ensure Choice is known before usage

class Strategy {
public:
    virtual Choice getChoice(const std::vector<Choice>& history) = 0;
    virtual ~Strategy() {}
};

#endif // STRATEGY_H
