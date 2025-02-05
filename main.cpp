#include <array>
#include <iostream>
#include <string>
#include <vector>

std::array<std::string, 5> mistakes {
    // Mistake 1
    " *--*\n"
    " |  |\n"
    "    |\n"
    "    |\n"
    "    |\n"
    "    |\n"
    "    |\n"
    "-----\n",
    // Mistake 2
    " *--*\n"
    " |  |\n"
    " 0  |\n"
    "    |\n"
    "    |\n"
    "    |\n"
    "    |\n"
    "-----\n",
    // Mistake 3
    " *--*\n"
    " |  |\n"
    " 0  |\n"
    " |  |\n"
    " |  |\n"
    "    |\n"
    "    |\n"
    "-----\n",
    // Mistake 4
    " *--*\n"
    " |  |\n"
    " 0  |\n"
    "/|\\ |\n"
    " |  |\n"
    "    |\n"
    "    |\n"
    "-----\n",
    // Mistake 5
    " *--*\n"
    " |  |\n"
    " 0  |\n"
    "/|\\ |\n"
    " |  |\n"
    "/ \\ |\n"
    "    |\n"
    "-----\n"
};
std::vector<std::string> easy {
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
std::vector<std::string> medium {
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
std::vector<std::string> hard {
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
std::vector<std::string> expert {
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

void printPhrase(std::string& phrase, std::string& guesses)
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

int main()
{
    // TODO: Implement game
    return 0;
}
