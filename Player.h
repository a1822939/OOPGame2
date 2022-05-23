/*
    Derived class from Character object
*/

#ifndef PLAYER_H
#define PLAYER_H

#include "Character.h"
#include <iostream>
#include <string>

class Player : public Character
{
private:
    std::string playerName; // Name of the user using character
public:
    Player();                 // Default player constructor
    Player(std::string name); // Constructor for Player class that allowcates the user name to name of character

    std::string getPlayerName(); // Returns playerName

    void setStrength(int strength);       // initialises the value of strength
    void setSpeed(int speed);             // initialises the value of speed
    void setHP(int hp);                   // initialises the value of HP
    void setPlayerName(std::string name); // Sets the name of the player to playerName

    void applyCharacter(Character character); // initialises a player object by taking in a character type

    ~Player(); // Default destructor for player classes
};

#endif