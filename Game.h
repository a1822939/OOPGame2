#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <string>
#include <vector>
#include "Player.h"
#include "Character.h"
#include "Move.h"
#include "Attack.h"
#include "Heal.h"

class Game
{
private:
    std::vector<Character> characterList; // List of characters
    Player *currentPlayerPtrs[2];         // stores location of player object
    int choice;                           // stores current
    Player player1;
    Player player2;
public:
    Game(std::vector<Character> defaultCharacters); // main game constructor
    Game();                                         // Default game constructor

    int getNumCharacters();            // Get the number of characters
    Character getCharacter(int index); // Get the character
    Player *getPlayer(int index);       // gets the list of adresses of current Players
    int getInput(int range); //Checks if input by user is allowable

    void inputPlayerNames(); //Sequence for users inputting their names
    void addCharacter(Character newCharacter); //Adds chosen character by user to list of character
    void deleteCharacter(int index); //Deletes the character in character list at position 'index'
    void updatePlayer(Player *playerPtr, int index); //Updates the character in character list at position 'index'
    void executeTurn(int p1MoveChoice, int p2MoveChoice);

    ~Game();
};

#endif
