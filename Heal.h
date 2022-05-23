#ifndef HEAL_H
#define HEAL_H

#include "Move.h"

class Heal : public Move
{
private:
public:
    void executeMove(Player &player1, Player &player2);
};

#endif
