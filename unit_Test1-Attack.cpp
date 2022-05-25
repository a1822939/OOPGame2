#include <iostream>
#include <stdlib.h>
#include <string.h>

#include "Character.h"
#include "Player.h"
#include "Move.h"
#include "Attack.h"

using namespace std;

// create pair of player objects to insert into attack function
std::pair<Player, Player> testSetUp()
{

    Character A;
    A = Character("Dwarf", 500, 80, 70);
    Character B;
    B = Character("Dwarf", 500, 80, 70);

    Player C;
    C.applyCharacter(A);
    Player D;
    D.applyCharacter(B);

    return {C, D};
}

int main()
{
    std::pair<Player, Player> result = testSetUp();

    Attack attack;

    {
        // Test 1//

        // Establish initial health
        int initialHealth = 0; // In this situation, the player is at 0% health
        result.first.setHP(initialHealth);

        // execute attack on player 1 (first) from player 2 (second)
        attack.executeMove(result.second, result.first);

        // record new health
        int newHP = result.first.getHP();

        int healthLost = initialHealth - newHP;

        // Test to see if expected health gained is correct
        if (healthLost != 0)
        {
            cout << "Test FAILED!!!" << endl;
            cout << "Damage taken: " << healthLost << endl;
            cout << "Expected damage taken: 0" << endl;
        }
    }

    {

        // Test 2//

        // Establish initial health
        int initialHealth = result.first.getFullHP(); // In this situation, the player is at 100% health
        result.first.setHP(initialHealth);

        // execute attack on player 1 (first) from player 2 (second)
        attack.executeMove(result.second, result.first);

        // record new health
        int newHP = result.first.getHP();
        int healthLost = initialHealth - newHP;

        // Test to see if expected health gained is correct
        if (healthLost != 80)
        {
            cout << "Test FAILED!!!" << endl;
            cout << "Damage taken: " << healthLost << endl;
            cout << "Expected damage taken: 80" << endl;
        }
    }

    {
        // Test 3//

        // Establish initial health
        int initialHealth = 50; // In this situation, the player is at 50 health (about to die if attacked by 80 strength)
        result.first.setHP(initialHealth);

        // execute attack on player 1 (first) from player 2 (second)
        attack.executeMove(result.second, result.first);

        // record new health
        int newHP = result.first.getHP();

        int healthLost = initialHealth - newHP;

        // Test to see if expected health gained is correct
        if (healthLost != 50)
        {
            cout << "Test FAILED!!!" << endl;
            cout << "Damage taken: " << healthLost << endl;
            cout << "Expected damage taken: 50" << endl;
        }
    }

    return 0;
}