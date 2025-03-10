#include <iostream>

class Strategy;
using namespace std;

#include "Game.h"
#include "RandomStrategy.h"
#include "SmartStrategy.h"

int main() {
    srand(time(0));
    std::cout << "Choose strategy: (1) Random (2) Smart: ";
    int choice;
    std::cin >> choice;
    Strategy* strategy = (choice == 2) ? static_cast<Strategy*>(new SmartStrategy()) : static_cast<Strategy*>(new RandomStrategy());
    Game game(strategy);
    game.playGame();
    delete strategy;
    return 0;
}
