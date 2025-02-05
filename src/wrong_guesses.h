#ifndef WRONG_GUESSES_H
#define WRONG_GUESSES_H

#include <array>
#include <string>

namespace WrongGuesses {

    const std::array<std::string, 5> wrongGuesses {
        // wrong guess 1
        " *--*\n"
        " |  |\n"
        "    |\n"
        "    |\n"
        "    |\n"
        "    |\n"
        "    |\n"
        "-----\n",

        // wrong guess 2
        " *--*\n"
        " |  |\n"
        " 0  |\n"
        "    |\n"
        "    |\n"
        "    |\n"
        "    |\n"
        "-----\n",

        // wrong guess 3
        " *--*\n"
        " |  |\n"
        " 0  |\n"
        " |  |\n"
        " |  |\n"
        "    |\n"
        "    |\n"
        "-----\n",

        // wrong guess 4
        " *--*\n"
        " |  |\n"
        " 0  |\n"
        "/|\\ |\n"
        " |  |\n"
        "    |\n"
        "    |\n"
        "-----\n",

        // wrong guess 5
        " *--*\n"
        " |  |\n"
        " 0  |\n"
        "/|\\ |\n"
        " |  |\n"
        "/ \\ |\n"
        "    |\n"
        "-----\n"
    };

    void printWrongGuesses(int amount);

}

#endif
