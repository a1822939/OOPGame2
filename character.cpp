#include "Character.h"

//Character constructor 
Character::Character(std::string name, int full_hp, int strength, int speed)
{
    this->name= name;
    this->hp= full_hp; //The beginning hp is set to both the current hp and the full hp
    this->full_hp = full_hp;
    this->strength= strength;
    this->speed= speed;
}

//Default constructer initialiser
Character::Character(){Character("null",1,1,1);}

//Get functions for character that returns the character's stats
std::string Character::getName(){return this->name;}
int Character::getHP() { return this->hp; }
int Character::getStrength() { return this->strength; }
int Character::getSpeed() { return this->speed; }
int Character::getFullHP(){return this->full_hp; }

//Default destructor for character
Character::~Character() {}
