//
// Created by Sameer on 10/03/25.
//

#include "RandomStrategy.h"

#include <cstdlib>
#include <vector>

Choice RandomStrategy::getChoice(const std::vector<Choice>& history) {
    int randChoice = rand() % 3;
    return static_cast<Choice>(randChoice);
}


