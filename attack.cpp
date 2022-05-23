#include "Attack.h"
#include <chrono>
#include <thread>

void Attack::executeMove(Player &attackingPlayer, Player &victim)
{
    int attackMultiplier = 1;
    int victimNewHP = victim.getHP() - attackingPlayer.getStrength() * attackMultiplier;

    if (victimNewHP < 0)
    {
        victimNewHP = 0;
    }

    std::cout << attackingPlayer.getPlayerName() << " dealt " << attackingPlayer.getStrength() * attackMultiplier << " damage to " << victim.getPlayerName() << "!\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(2000));

    victim.setHP(victimNewHP);
}
