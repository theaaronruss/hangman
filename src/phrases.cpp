#include "phrases.h"
#include <iostream>
#include <random>
#include <string>

std::string Phrases::getPhrase(Difficulty difficulty) {
    std::random_device r;
    std::mt19937 gen(r());
    std::uniform_int_distribution<int> dist;
    switch (difficulty) {
        case Difficulty::EASY:
            dist = std::uniform_int_distribution<>(0, easyPhrases.size() - 1);
            return easyPhrases[dist(gen)];
        case Difficulty::MEDIUM:
            dist = std::uniform_int_distribution<>(0, mediumPhrases.size() - 1);
            return mediumPhrases[dist(gen)];
        case Difficulty::HARD:
            dist = std::uniform_int_distribution<>(0, hardPhrases.size() - 1);
            return hardPhrases[dist(gen)];
        case Difficulty::EXPERT:
            dist = std::uniform_int_distribution<>(0, expertPhrases.size() - 1);
            return expertPhrases[dist(gen)];
        default:
            return std::string{""};
    }
}

void Phrases::printPhrase(const std::string& phrase, std::set<char> guesses) {
    for (int i = 0; i < phrase.size(); i++) {
        if (guesses.find(phrase.at(i)) != guesses.end()) {
            std::cout << phrase.at(i) << " ";
        } else if (phrase.at(i) != ' ') {
            std::cout << "_ ";
        } else {
            std::cout << "  ";
        }
    }
    std::cout << "\n";
}

bool Phrases::isCorrectGuess(const std::string& phrase, const char guess) {
    return phrase.find_first_of(guess) != std::string::npos;
}

bool Phrases::isWon(const std::string& phrase, std::set<char> guesses) {
    for (char c : phrase) {
        if (c != ' ' && guesses.count(c) == 0) {
            return false;
        }
    }
    return true;
}
