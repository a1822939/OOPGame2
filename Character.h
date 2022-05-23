/*
    Parent class for Player object
*/

#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>

class Character
{
private:
protected:
    std::string name;   //Name of character
    int full_hp;        //Complete health points of character -- >Remains unchanged<
    int hp;             //current hp
    int strength;       //How much damage a player is able to deal to another character
    int speed;          //Determines the speed of a player, where faster players attack first
    
public:
    Character();                                                        //Default constructor for Character class
    Character(std::string name,int full_hp,int strength,int speed);     //Constructor for Character class that takes in the character's name, health, strength and speed

    std::string getName();      //returns the string for name
    int getHP();                //returns current value of hp
    int getFullHP();            //returns the value of the characters full hp
    int getStrength();          //returns the value of strength in character
    int getSpeed();             //returns the value of speed

   ~Character();        //Default destructor for character class

};

#endif