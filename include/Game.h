//
// Created by Sameer on 10/03/25.
//

#ifndef GAME_H
#define GAME_H

#include "Strategy.h"
#include <vector>
#include <iostream>

class Game {
private:
    Strategy* strategy;
    std::vector<Choice> history;
    int humanScore = 0, computerScore = 0;
    Choice getHumanChoice();
    void determineWinner(Choice human, Choice computer);
public:
    Game(Strategy* strat);
    void playGame();
};

#endif // GAME_H