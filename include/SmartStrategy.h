//
// Created by Sameer on 10/03/25.
//

#ifndef SMART_STRATEGY_H
#define SMART_STRATEGY_H

#include "Strategy.h"
#include <map>
#include <string>

class SmartStrategy : public Strategy {
private:
    std::map<std::string, std::map<Choice, int>> frequencyMap;
    const int N = 5;
    std::string historyToString(const std::vector<Choice>& history);
    void loadFrequencies();
    void saveFrequencies();
public:
    SmartStrategy();
    ~SmartStrategy();
    Choice getChoice(const std::vector<Choice>& history) override;
    void updateHistory(const std::vector<Choice>& history);
};

#endif // SMART_STRATEGY_H