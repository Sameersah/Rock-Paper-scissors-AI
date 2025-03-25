// main.cpp
#include <iostream>
#include <memory>
#include "Game.h"
#include "RandomStrategyFactory.h"
#include "SmartStrategyFactory.h"

int main() {
    srand(time(0));

    std::cout << "Choose strategy: (1) Random (2) Smart): ";
    int choice;
    std::cin >> choice;

    std::unique_ptr<StrategyFactory> factory;
    if (choice == 2) {
        factory = std::make_unique<SmartStrategyFactory>();
    } else {
        factory = std::make_unique<RandomStrategyFactory>();
    }

    std::unique_ptr<Strategy> strategy = factory->createStrategy();
    Game game(strategy.get());
    game.playGame();

    return 0;
}