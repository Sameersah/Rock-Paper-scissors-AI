#include <iostream>
#include <memory>
#include "Game.h"
#include "RandomStrategy.h"
#include "SmartStrategy.h"

int main() {
    srand(time(0));

    std::cout << "Choose strategy: (1) Random (2) Smart): ";
    int choice;
    std::cin >> choice;

    std::unique_ptr<Strategy> strategy;
    if (choice == 2) {
        strategy = std::make_unique<SmartStrategy>();
    } else {
        strategy = std::make_unique<RandomStrategy>();
    }

    Game game(strategy.get());
    game.playGame();

    return 0;  // Destructor will be called automatically, saving data
}
