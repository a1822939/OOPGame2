#include "Attack.h"
#include <chrono>
#include <thread>
#include <cstdlib>
#include <ctime>
#include <cmath>

void Attack::executeMove(Player &attackingPlayer, Player &victim)
{
    double attackMultiplier = (1.3 -0.7) * ( (double)rand() / (double)RAND_MAX ) + 0.7;
    int victimNewHP = victim.getHP() - round(attackingPlayer.getStrength() * attackMultiplier);

    if (victimNewHP < 0)
    {
        victimNewHP = 0;
    }

    std::cout << attackingPlayer.getPlayerName() << " dealt " << round(attackingPlayer.getStrength() * attackMultiplier) << " damage to " << victim.getPlayerName() << "!\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(2000));

    victim.setHP(victimNewHP);
}
