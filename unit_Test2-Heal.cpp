#include <iostream>
#include <stdlib.h>
#include <string.h>

#include "Character.h"
#include "Player.h"
#include "Move.h"
#include "Heal.h"

using namespace std;

// create pair of player objects to insert into heal function
std::pair<Player, Player> testSetUp()
{

    Character A;
    A = Character("Dwarf", 500, 80, 70);
    Character B;
    B = Character("Dwarf", 100, 80, 70);

    Player C;
    C.applyCharacter(A);
    Player D;
    D.applyCharacter(B);

    return {C, D};
}

int main()
{
    Heal heal;

    std::pair<Player, Player> result = testSetUp();

    {
        // Test 1//

        // Establish initial health
        int initialHealth = result.first.getFullHP(); // In this situation, the player is at 100% health
        result.first.setHP(initialHealth);

        // execute heal on player
        heal.executeMove(result.first, result.second);

        // record new health
        int newHP = result.first.getHP();

        int healthGained = newHP - initialHealth;

        // Test to see if expected health gained is correct
        if (healthGained != 0)
        {
            cout << "Test FAILED!!!" << endl;
            cout << "Health gained: " << healthGained << endl;
            cout << "Expected health gained: 0" << endl;
        }
    }

    {
        // Test 2//

        // Establish initial health and set health to player
        int initialHealth = result.first.getHP() - 200; // In this situation, player has taken more damage than they can heal
        result.first.setHP(initialHealth);

        // execute heal on player
        heal.executeMove(result.first, result.second);

        // record new health
        int newHP = result.first.getHP();

        // Test to see if expected health gained is correct
        int healthGained = newHP - initialHealth;

        if (healthGained != 125)
        {
            cout << "- Test FAILED!!!" << endl;
            cout << "- Health gained: " << healthGained << endl;
            cout << "- Expected health gained: 125" << endl;
        }
    }

    {
        // Test 3//

        // Establish initial health
        int initialHealth = result.first.getFullHP() - 100; // In this situation, player has taken less damage than they can heal
        result.first.setHP(initialHealth);

        // execute heal on player
        heal.executeMove(result.first, result.second);

        // record new health
        int newHP = result.first.getHP();

        int healthGained = newHP - initialHealth;

        // Test to see if expected health gained is correct
        if (healthGained != 100)
        {
            cout << "Test FAILED!!!" << endl;
            cout << "Health gained: " << healthGained << endl;
            cout << "Expected health gained: 100" << endl;
        }
    }

    return 0;
}