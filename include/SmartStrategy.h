//
// Created by Sameer on 10/03/25.
//

#ifndef SMART_STRATEGY_H
#define SMART_STRATEGY_H

#include "Strategy.h"
#include <map>
#include <string>

class SmartStrategy final : public Strategy {
private:
    std::map<std::string, std::map<Choice, int>> frequencyMap;
    const int N = 5;
    [[nodiscard]] std::string historyToString(const std::vector<Choice>& history) const;
    void loadFrequencies();
    void saveFrequencies() const;
public:
    SmartStrategy();
    ~SmartStrategy() override;
    Choice getChoice(const std::vector<Choice>& history) override;
    void updateHistory(const std::vector<Choice>& history) override;
};

#endif // SMART_STRATEGY_H