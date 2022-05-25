#include "Game.h"
#include <stdlib.h>
#include <typeinfo>
#include <limits>
#include <iostream>
#include <ios> //for stream size
#include <limits>
#include <cassert>

Game::Game(std::vector<Character> defaultCharacters)
{
    this->characterList = defaultCharacters;
    choice = 0;
    updatePlayer(&player1, 0);
    updatePlayer(&player2, 1);
}

Game::Game(){};

void Game::addCharacter(Character newCharacter)
{
    characterList.push_back(newCharacter); // adds new character to end of list
}

void Game::deleteCharacter(int index)
{
    characterList.erase(characterList.begin() + index); // erases character in given index
}

void Game::inputPlayerNames()
{
    system("clear");

    std::string input; // initialises input variable
    std::cout << "Enter player one name: ";
    std::cin >> input; // requests user input
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignores spacing so only first word entered is used

    player1.setPlayerName(input);

    system("clear");

    std::cout << "Enter player two name: ";
    std::cin >> input; // requests user input
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignores spacing so only first word entered is used

    player2.setPlayerName(input);
}

void Game::updatePlayer(Player *playerPtr, int index)
{
    std::cout << playerPtr << std::endl;
    currentPlayerPtrs[index] = playerPtr;
}

int Game::getNumCharacters() { return characterList.size(); }

Character Game::getCharacter(int index) { return characterList[index]; }

Player *Game::getPlayer(int index) { return currentPlayerPtrs[index]; }

int Game::getInput(int range) // gets valid user input with number of selections as parameter

{
    bool invalidChoice = true; // initialise invalid choice as true

    do {
        std::cout << "Enter integer between 1 and " << range << ": ";

        if (!(std::cin >> choice))
        {
            std::cout << "Please enter a number only." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else{

        if (choice > 0 && choice <= range)
        {
            invalidChoice = false;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else
        {
            std::cout << "Invalid number." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        }
    }
    while(invalidChoice);

    return choice;
}

void Game::executeTurn(int p1MoveChoice, int p2MoveChoice)
{
    // instanitate attack and heal objects
    Attack attack;
    Heal heal;
    Move **moves = new Move *[2];
    moves[0] = &attack;
    moves[1] = &heal;

    if (currentPlayerPtrs[0]->getSpeed() >= currentPlayerPtrs[1]->getSpeed())
    {
        moves[p1MoveChoice - 1]->executeMove(*currentPlayerPtrs[0], *currentPlayerPtrs[1]);
        if (currentPlayerPtrs[1]->getHP() == 0)
        {
            return;
        }
        else
        {
            moves[p2MoveChoice - 1]->executeMove(*currentPlayerPtrs[1], *currentPlayerPtrs[0]);
        }
    }
    else
    {
        moves[p2MoveChoice - 1]->executeMove(*currentPlayerPtrs[1], *currentPlayerPtrs[0]);

        if (currentPlayerPtrs[0]->getHP() == 0)
        {
            return;
        }
        else
        {
            moves[p1MoveChoice - 1]->executeMove(*currentPlayerPtrs[0], *currentPlayerPtrs[1]);
        }
    }

    delete[] moves;
}

Game::~Game() {}
