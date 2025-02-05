#include "../include/phrases.h"
#include <cstdio>
#include <cctype>
#include <iostream>
#include <regex>

char getGuess()
{
    bool valid { false };
    char guess = ' ';
    while (!valid)
    {
        std::cout << "Enter your guess: ";
        guess = getchar();
        std::fflush(stdin);
        valid = std::regex_match(std::string(1, guess), std::regex("[a-zA-Z]"));
        if (!valid)
        {
            std::cout << "Invalid input! Please enter a letter!\n";
        }
    }
    return std::toupper(guess);
}

int main()
{
    std::string phrase = Phrases::getPhrase(4);
    std::string guesses;
    int mistakes = 0;
    while (mistakes < 5)
    {
        Phrases::printPhrase(phrase, guesses);
        char guess = getGuess();
        guesses.push_back(guess);
        mistakes++;
        std::cout << "\n";
    }
    return 0;
}
