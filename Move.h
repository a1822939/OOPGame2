#ifndef MOVE_H
#define MOVE_H

#include <iostream>
#include <string>
#include "Player.h"

class Move
{
private:
public:
    virtual void executeMove(Player &player1, Player &player2) = 0;
};

#endif