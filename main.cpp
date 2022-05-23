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
    defaultCharacters.push_back(Character("Dwarf", 300, 10, 50));
    defaultCharacters.push_back(Character("Giant", 100, 40, 20));
    defaultCharacters.push_back(Character("Snake", 200, 90, 30));
    defaultCharacters.push_back(Character("Viking", 350, 30, 50));

    Game game(defaultCharacters);

    Display display(&game);

    display.menu();

    return 0;
}