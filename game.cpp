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
    characterList.push_back(newCharacter);
}

void Game::deleteCharacter(int index)
{
    characterList.erase(characterList.begin() + index);
}

void Game::inputPlayerNames()
{
    system("clear");

    std::string input;
    std::cout << "Enter player one name: ";
    std::cin >> input;

    player1.setPlayerName(input);

    system("clear");

    std::cout << "Enter player two name: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin >> input;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

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

int Game::getInput(int range)
{
    bool invalidChoice = true;
    std::cout << "Enter integer between 1 and " << range << ": ";
    while (invalidChoice)
    {
        choice = 0;
        std::cin.clear();
        std::cin >> choice; 
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (choice > 0 && choice <= range)
        {
            invalidChoice = false;
        }
        else
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid Input" << std::endl;
            std::cout << "Enter integer between 1 and " << range << ": ";
        }
    }

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
