#include "../include/mistakes.h"
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

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        std::cout << "usage: hangman <difficulty>\n\n";
        std::cout << "Difficulty can be either 'easy', 'medium', 'hard', or 'expert'\n";
        return 0;
    }
    int difficulty = 1;
    if (std::strcmp(argv[1], "easy") == 0)
    {
        difficulty = 1;
    }
    else if (std::strcmp(argv[1], "medium") == 0)
    {
        difficulty = 2;
    }
    else if (std::strcmp(argv[1], "hard") == 0)
    {
        difficulty = 3;
    }
    else if (std::strcmp(argv[1], "expert") == 0)
    {
        difficulty = 4;
    }
    std::string phrase = Phrases::getPhrase(difficulty);
    std::string guesses;
    int mistakes = 0;
    while (mistakes < 5 && !Phrases::isWon(phrase, guesses))
    {
        Phrases::printPhrase(phrase, guesses);
        char guess = getGuess();
        guesses.push_back(guess);
        if (!Phrases::isCorrectGuess(phrase, guess))
        {
            mistakes++;
        }
        Mistakes::printMistakes(mistakes);
        std::cout << "Guesses: " << guesses << "\n";
        std::cout << "\n";
    }
    if (mistakes == 5)
    {
        std::cout << "You lost!\n";
        std::cout << "The answer was " << phrase << "\n";
    }
    else
    {
        std::cout << "You won!\n";
        std::cout << "The answer was " << phrase << "\n";
    }
    return 0;
}
