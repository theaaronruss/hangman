#include "../include/phrases.h"
#include <iostream>
#include <string>

void printPhrase(const std::string& phrase, const std::string& guesses)
{
    for (int i = 0; i < phrase.length(); i++)
    {
        if (guesses.find(phrase.at(i)) != std::string::npos)
        {
            std::cout << phrase.at(i) << " ";
        }
        else if (phrase.at(i) != ' ')
        {
            std::cout << "_ ";
        }
        else
        {
            std::cout << "  ";
        }
    }
    std::cout << "\n";
}
