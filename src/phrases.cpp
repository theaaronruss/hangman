#include "../include/phrases.h"
#include <iostream>
#include <random>
#include <string>

std::string Phrases::getPhrase(int difficulty)
{
    std::random_device r;
    std::mt19937 gen(r());
    if (difficulty == 1)
    {
        std::uniform_int_distribution<int> dist(0, easy.size());
        return easy[dist(gen)];
    }
    else if (difficulty == 2)
    {
        std::uniform_int_distribution<int> dist(0, medium.size());
        return medium[dist(gen)];
    }
    else if (difficulty == 3)
    {
        std::uniform_int_distribution<int> dist(0, hard.size());
        return hard[dist(gen)];
    } else if (difficulty == 4)
    {
        std::uniform_int_distribution<int> dist(0, expert.size());
        return expert[dist(gen)];
    }
    return std::string{""};
}

void Phrases::printPhrase(const std::string& phrase, const std::string& guesses)
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
