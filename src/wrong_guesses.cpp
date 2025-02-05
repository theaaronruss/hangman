#include "wrong_guesses.h"
#include <iostream>

void WrongGuesses::printWrongGuesses(int amount) {
    if (amount < 1 || amount > wrongGuesses.size() + 1) {
        return;
    }
    std::cout << wrongGuesses[amount - 1];
}
