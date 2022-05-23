#ifndef MOVE_H
#define MOVE_H

#include <iostream>
#include <string>
#include "Player.h"

/*
Abstract class for move types, with derived classes including healing and attacking. 
Allows for future implementation of additional move types.
*/

class Move
{
private:
public:
    virtual void executeMove(Player &player1, Player &player2) = 0; // virtual function for performing a move on a player
};

#endif