//
// Created by Sameer on 10/03/25.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <cstdlib>
#include <ctime>

#include "Game.h"

Game::Game(Strategy* strat) : strategy(strat) {}

Choice Game::getHumanChoice() {
    char input;
    std::cout << "Enter choice (R/P/S): ";
    std::cin >> input;
    switch (toupper(input)) {
        case 'R': return Choice::ROCK;
        case 'P': return Choice::PAPER;
        case 'S': return Choice::SCISSORS;
        default: return getHumanChoice();
    }
}

void Game::determineWinner(Choice human, Choice computer) {
    if (human == computer) {
        std::cout << "It's a tie!" << std::endl;
    } else if ((human == Choice::ROCK && computer == Choice::SCISSORS) ||
               (human == Choice::PAPER && computer == Choice::ROCK) ||
               (human == Choice::SCISSORS && computer == Choice::PAPER)) {
        std::cout << "You win this round!" << std::endl;
        humanScore++;
               } else {
                   std::cout << "Computer wins this round!" << std::endl;
                   computerScore++;
               }
}

void Game::playGame() {
    for (int i = 0; i < 20; i++) {
        Choice humanChoice = getHumanChoice();
        Choice computerChoice = strategy->getChoice(history);
        history.push_back(humanChoice);
        std::cout << "Computer chose: " << (computerChoice == Choice::ROCK ? "Rock" : computerChoice == Choice::PAPER ? "Paper" : "Scissors") << std::endl;
        determineWinner(humanChoice, computerChoice);
    }
    std::cout << "Final Score - You: " << humanScore << " | Computer: " << computerScore << std::endl;
}