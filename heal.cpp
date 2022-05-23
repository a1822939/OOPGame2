#include "Heal.h"
#include <chrono>
#include <thread>

void Heal::executeMove(Player &player1, Player &player2)
{

    if (player1.getHP() == 0)
    {
        return;
    }
    
    int playerNewHP = player1.getHP() + (player1.getFullHP() / 4);

    if (playerNewHP > player1.getFullHP())
    {
        playerNewHP = player1.getFullHP();
    }

    std::cout << player1.getPlayerName() << " healed " << player1.getFullHP() / 4 << " HP!\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(2000));

    player1.setHP(playerNewHP);
}
