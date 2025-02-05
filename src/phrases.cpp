#include "phrases.h"
#include <iostream>
#include <random>
#include <string>

std::string Phrases::getPhrase(Difficulty difficulty) {
    std::random_device r;
    std::mt19937 gen(r());
    if (difficulty == Difficulty::EASY) {
        std::uniform_int_distribution<int> dist(0, easy.size());
        return easy[dist(gen)];
    } else if (difficulty == Difficulty::MEDIUM) {
        std::uniform_int_distribution<int> dist(0, medium.size());
        return medium[dist(gen)];
    } else if (difficulty == Difficulty::HARD) {
        std::uniform_int_distribution<int> dist(0, hard.size());
        return hard[dist(gen)];
    } else if (difficulty == Difficulty::EXPERT) {
        std::uniform_int_distribution<int> dist(0, expert.size());
        return expert[dist(gen)];
    }
    return std::string{""};
}

void Phrases::printPhrase(const std::string& phrase, std::set<char> guesses) {
    for (int i = 0; i < phrase.length(); i++) {
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
    return phrase.find(guess) != std::string::npos;
}

bool Phrases::isWon(const std::string& phrase, std::set<char> guesses) {
    for (char c : phrase) {
        if (c != ' ' && guesses.find(c) == guesses.end()) {
            return false;
        }
    }
    return true;
}
