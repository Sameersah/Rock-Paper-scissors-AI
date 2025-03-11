//
// Created by Sameer on 10/03/25.
//

#include "SmartStrategy.h"
#include <fstream>
#include <algorithm>
#include <iostream>

SmartStrategy::SmartStrategy() { loadFrequencies(); }
SmartStrategy::~SmartStrategy() { saveFrequencies(); }

std::string SmartStrategy::historyToString(const std::vector<Choice>& history) const {
    if (history.size() < N) return "";
    std::string s;
    for (size_t i = history.size() - N; i < history.size(); ++i)
        s += std::to_string(history[i]);
    return s;
}

void SmartStrategy::loadFrequencies() {
    std::cout << "Loading frequencies..." << std::endl;
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
    std::cout << "Saving frequencies..." << std::endl;

    if (frequencyMap.empty()) {
        std::cerr << "Error: frequencyMap is empty! No data to write." << std::endl;
        return;
    }

    std::ofstream outFile("strategy_data.txt", std::ios::trunc);
    if (!outFile) {
        std::cerr << "Error: Unable to open file for writing!" << std::endl;
        return;
    }

    std::cout << "Data to be written:" << std::endl;
    for (const auto& pair : frequencyMap) {
        // Use operator[] instead of .at() to prevent exception
        int r = pair.second.count(Choice::ROCK) ? pair.second.at(Choice::ROCK) : 0;
        int p = pair.second.count(Choice::PAPER) ? pair.second.at(Choice::PAPER) : 0;
        int s = pair.second.count(Choice::SCISSORS) ? pair.second.at(Choice::SCISSORS) : 0;

        std::cout << pair.first << " " << r << " " << p << " " << s << std::endl;
        outFile << pair.first << " " << r << " " << p << " " << s << std::endl;
    }

    outFile.flush();
    outFile.close();
    std::cout << "File successfully updated!" << std::endl;
}


Choice SmartStrategy::getChoice(const std::vector<Choice>& history) {
    std::cout << "Getting choice..." << std::endl;
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
    std::cout << "Updating history with latest choice..." << std::endl;
    std::string seq = historyToString(history);

    if (!seq.empty()) {
        // Ensure all choices are initialized before updating
        if (frequencyMap.find(seq) == frequencyMap.end()) {
            frequencyMap[seq] = {{Choice::ROCK, 0}, {Choice::PAPER, 0}, {Choice::SCISSORS, 0}};
        }

        // Now safely increment the count
        frequencyMap[seq][history.back()]++;
    }
}