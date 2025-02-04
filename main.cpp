#include <array>
#include <string>

std::array<std::string, 5> hangman = {
    // 1 mistake
    " *--*\n"
    " |  |\n"
    "    |\n"
    "    |\n"
    "    |\n"
    "    |\n"
    "    |\n"
    "-----\n",
    // 2 mistake
    " *--*\n"
    " |  |\n"
    " 0  |\n"
    "    |\n"
    "    |\n"
    "    |\n"
    "    |\n"
    "-----\n",
    // 3 mistake
    " *--*\n"
    " |  |\n"
    " 0  |\n"
    " |  |\n"
    " |  |\n"
    "    |\n"
    "    |\n"
    "-----\n",
    // 4 mistake
    " *--*\n"
    " |  |\n"
    " 0  |\n"
    "/|\\ |\n"
    " |  |\n"
    "    |\n"
    "    |\n"
    "-----\n",
    // 5 mistake
    " *--*\n"
    " |  |\n"
    " 0  |\n"
    "/|\\ |\n"
    " |  |\n"
    "/ \\ |\n"
    "    |\n"
    "-----\n"
};

int main()
{
    // TODO: Implement game
    return 0;
}
