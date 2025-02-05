#include "wrong_guesses.h"
#include "phrases.h"
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <iostream>
#include <regex>
#include <set>
#include <string>

char getGuess() {
    bool valid { false };
    char guess = ' ';
    // keep asking until a valid guess is entered
    while (!valid) {
        std::cout << "Enter your guess: ";
        std::string guessLine;
        getline(std::cin, guessLine);
        if (!guessLine.empty()) {
            guess = guessLine[0];
        }
        valid = std::isalpha(guess);
        if (!valid) {
            std::cout << "Invalid input! Please enter a letter!\n";
        }
    }
    // make sure all guesses are capitalized
    return std::toupper(guess);
}

void printUsage() {
    std::cout << "usage: hangman <difficulty>\n\n";
    std::cout << "Difficulty can be either 'easy', 'medium', 'hard', or 'expert'\n";
}

std::string getPhraseGivenDifficulty(const std::string& difficultyString) {
    std::string difficultyLowercase = difficultyString;
    std::transform(difficultyLowercase.begin(), difficultyLowercase.end(), difficultyLowercase.begin(), ::tolower);
    if (difficultyLowercase == "medium") {
        return Phrases::getPhrase(Phrases::Difficulty::MEDIUM);
    }
    else if (difficultyLowercase == "hard") {
        return Phrases::getPhrase(Phrases::Difficulty::HARD);
    }
    else if (difficultyLowercase == "expert") {
        return Phrases::getPhrase(Phrases::Difficulty::EXPERT);
    } else {
        // default to easy if difficulty isn't recognized
        return Phrases::getPhrase(Phrases::Difficulty::EASY);
    }
}

void printGameOverMessage(int wrongGuessCount, const std::string& phrase) {
    if (wrongGuessCount == WrongGuesses::wrongGuesses.size()) {
        std::cout << "You lost!\n";
    } else {
        std::cout << "You won!\n";
    }
    std::cout << "The answer was " << phrase << "\n";
}

void printGuesses(const std::set<char>& guesses) {
    std::cout << "Guesses: ";
    for (char guess : guesses) {
        std::cout << guess << " ";
    }
    std::cout << "\n";
}

int main(int argc, char* argv[]) {
    // arguments: 1. program name 2. difficulty (easy, medium, hard, or expert)
    if (argc != 2) {
        printUsage();
        return 1;
    }
    std::string phrase = getPhraseGivenDifficulty(argv[1]);
    std::set<char> guesses;
    int wrongGuessCount { 0 };
    while (wrongGuessCount < WrongGuesses::wrongGuesses.size() && !Phrases::isWon(phrase, guesses)) {
        Phrases::printPhrase(phrase, guesses);
        char guess = getGuess();
        guesses.insert(guess);
        if (!Phrases::isCorrectGuess(phrase, guess)) {
            wrongGuessCount++;
        }
        WrongGuesses::printWrongGuesses(wrongGuessCount);
        printGuesses(guesses);
        // add some spacing to help differentiate between turns
        std::cout << "\n\n";
    }
    printGameOverMessage(wrongGuessCount, phrase);
    return 0;
}
