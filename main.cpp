#include <iostream>
#include <stdlib.h>
#include "Move.h"
#include "Player.h"
#include "Character.h"
#include "Game.h"
#include "Display.h"
#include <chrono>
#include <thread>

int main()
{
    // define character player list
    std::vector<Character> defaultCharacters;

    // adds characters to character vector
    defaultCharacters.push_back(Character("Dwarf", 500, 80, 70));
    defaultCharacters.push_back(Character("Giant", 1000, 50, 20));
    defaultCharacters.push_back(Character("Snake", 250, 150, 100));
    defaultCharacters.push_back(Character("Viking", 600, 70, 80));

    Game game(defaultCharacters); // instantiates game with default characters

    Display display(&game);

    display.menu();

    return 0;
}