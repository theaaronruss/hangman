#include "../include/mistakes.h"
#include <iostream>

void printMistakes(int amount)
{
    if (amount < 1 || amount > mistakes.size() + 1)
    {
        return;
    }
    std::cout << mistakes[amount - 1];
}
