#ifndef ATTACK_H
#define ATTACK_H

#include "Move.h"

/*
Class Attack derivived from abstract class Move.
*/

class Attack : public Move
{
private:
public:
    void executeMove(Player &player1, Player &player2); // overriding executeMove function for attack class
};

#endif