#ifndef DISPLAY_H
#define DISPLAY_H

#include <iostream>
#include <string>
#include "Game.h"
#include "Move.h"
#include "Character.h"
#include "Player.h"

class Display
{
private:
    Game *game;

public:
    Display();                                                    // Default constructor for display
    Display(Game *game);                                          // Constructor allowing use of game functions
    void characterSelection();                                    // Displays the character options to each player
    void displayCharacterStats();                                 // Displays the stats of each character
    bool displayCurrentStats(int p1MoveChoice, int p2MoveChoice); // Checks each player's health and declares a winner
    void menu();                                                  // Displays the main menu
    void fight();                                                 // Displays and initiates the fight sequence
    //void displayPlayerMoves(int p1MoveChoice, int p2MoveChoice); 
    void HUD();                                                   // Displays updated health bar of each player.
    ~Display();                                                   // Destructor
};

#endif