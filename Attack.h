#ifndef ATTACK_H
#define ATTACK_H

#include "Move.h"


class Attack : public Move
{
private:
public:
    void executeMove(Player &player1, Player &player2);
};

#endif