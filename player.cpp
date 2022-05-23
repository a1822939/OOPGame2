#include "Player.h"

// Default player constructor
Player::Player()
{
    playerName = "default";
}

Player::Player(std::string name)
{
    playerName = name;
}
// Set functions for player objects
void Player::setSpeed(int speed) { this->speed = speed; }
void Player::setStrength(int strength) { this->strength = strength; }
void Player::setHP(int hp) { this->hp = hp; }

//
void Player::applyCharacter(Character character)
{
    setSpeed(character.getSpeed());
    setStrength(character.getStrength());
    setHP(character.getHP());
    this->full_hp = character.getHP();
}

void Player::setPlayerName(std::string name) { playerName = name; }

std::string Player::getPlayerName()
{
    return playerName;
}

Player::~Player() {}