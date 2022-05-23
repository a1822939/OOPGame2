#include "Player.h"

// Default player constructor
Player::Player()
{
    playerName = "default";
}

// Constructor for Player class that allowcates the name of the user as the name of the player
Player::Player(std::string name)
{
    playerName = name;
}

// Set functions for player objects
void Player::setSpeed(int speed) { this->speed = speed; }
void Player::setStrength(int strength) { this->strength = strength; }
void Player::setHP(int hp) { this->hp = hp; }
void Player::setPlayerName(std::string name) { playerName = name; }

// initialises a player object by taking in a character type
void Player::applyCharacter(Character character)
{
    setSpeed(character.getSpeed());
    setStrength(character.getStrength());
    setHP(character.getHP());
    this->full_hp = character.getHP();
}

// Returns playerName
std::string Player::getPlayerName()
{
    return playerName;
}

// Default destructor for player classes
Player::~Player() {}