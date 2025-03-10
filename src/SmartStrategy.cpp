//
// Created by Sameer on 10/03/25.
//

#include "SmartStrategy.h"
#include <fstream>
#include <algorithm>

SmartStrategy::SmartStrategy() { loadFrequencies(); }
SmartStrategy::~SmartStrategy() { saveFrequencies(); }

std::string SmartStrategy::historyToString(const std::vector<Choice>& history) const {
    if (history.size() < N) return "";
    std::string s;
    for (size_t i = history.size() - N; i < history.size(); ++i)
        s += std::to_string(static_cast<int>(history[i]));
    return s;
}

void SmartStrategy::loadFrequencies() {
    std::ifstream inFile("strategy_data.txt");
    if (!inFile) return;
    std::string seq;
    int r, p, s;
    while (inFile >> seq >> r >> p >> s) {
        frequencyMap[seq] = {{Choice::ROCK, r}, {Choice::PAPER, p}, {Choice::SCISSORS, s}};
    }
    inFile.close();
}

void SmartStrategy::saveFrequencies() const {
    std::ofstream outFile("strategy_data.txt");
    for (const auto& pair : frequencyMap) {
        outFile << pair.first << " " << pair.second.at(Choice::ROCK) << " "
                << pair.second.at(Choice::PAPER) << " " << pair.second.at(Choice::SCISSORS) << std::endl;
    }
    outFile.close();
}

Choice SmartStrategy::getChoice(const std::vector<Choice>& history) {
    std::string seq = historyToString(history);
    if (seq.empty() || frequencyMap.find(seq) == frequencyMap.end()) {
        return static_cast<Choice>(rand() % 3);
    }
    auto &freq = frequencyMap[seq];
    Choice predicted = std::max_element(freq.begin(), freq.end(),
        [](const auto& a, const auto& b) { return a.second < b.second; })->first;
    return (predicted == Choice::ROCK) ? Choice::PAPER :
           (predicted == Choice::PAPER) ? Choice::SCISSORS : Choice::ROCK;
}

void SmartStrategy::updateHistory(const std::vector<Choice>& history) {
    std::string seq = historyToString(history);
    if (!seq.empty()) {
        frequencyMap[seq][history.back()]++;
    }
}