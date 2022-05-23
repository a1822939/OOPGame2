#ifndef HEAL_H
#define HEAL_H

#include "Move.h"

/*
Class Heal derivived from abstract class Move.
*/

class Heal : public Move
{
private:
public:
    void executeMove(Player &player1, Player &player2); // overriding executeMove function for heal class
};

#endif
