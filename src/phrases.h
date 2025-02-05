#ifndef PHRASES_H
#define PHRASES_H

#include <set>
#include <string>
#include <vector>

namespace Phrases {

    enum class Difficulty {
        EASY,
        MEDIUM,
        HARD,
        EXPERT
    };

    const std::vector<std::string> easy {
        "APPLE",
        "TIGER",
        "HAPPY",
        "OCEAN",
        "CHAIR",
        "HOUSE",
        "DANCE",
        "PIZZA",
        "GHOST",
        "MAGIC"
    };
    const std::vector<std::string> medium {
        "SUNSHINE",
        "THUNDER",
        "CHAMPION",
        "NOTEBOOK",
        "RAINBOW",
        "ADVENTURE",
        "DAYDREAM",
        "WILDFLOWER",
        "STARLIGHT",
        "SUPERHERO"
    };
    const std::vector<std::string> hard {
        "MISCHIEVOUS",
        "KALEIDOSCOPE",
        "UNBELIEVABLE",
        "CHANDELIER",
        "PHENOMENON",
        "QUICKSILVER",
        "LABYRINTH",
        "SYNERGY",
        "PARADOX",
        "GARGOYLE"
    };
    const std::vector<std::string> expert {
        "PIECE OF CAKE",
        "ONCE IN A BLUE MOON",
        "BREAK THE ICE",
        "JACK OF ALL TRADES",
        "CURIOSITY KILLED THE CAT",
        "THE PLOT THICKENS",
        "WHEN PIGS FLY",
        "LOST IN THE SAUCE",
        "UNDER THE WEATHER",
        "READ BETWEEN THE LINES"
    };

    std::string getPhrase(Difficulty difficulty);
    void printPhrase(const std::string& phrase, std::set<char> guesses);
    bool isCorrectGuess(const std::string& phrase, const char guess);
    bool isWon(const std::string& phrase, const std::set<char> guesses);

}

#endif
