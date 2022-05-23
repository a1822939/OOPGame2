#include <iostream>
#include <stdlib.h>
#include <string.h>

#include "Character.h"
#include "Player.h"
#include "Move.h"
#include "Heal.h"

using namespace std;

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

    // Test 1//

    // Establish initial health
    int initialHealth1 = result.first.getFullHP(); // In this situation, the player is at 100% health
    result.first.setHP(initialHealth1);

    // execute heal on player
    heal.executeMove(result.first, result.second);

    // record new health
    int newHP1 = result.first.getHP();

    int healthGained1 = newHP1 - initialHealth1;

    // Test to see if expected health gained is correct
    if (healthGained1 != 0)
    {
        cout << "Test FAILED!!!" << endl;
        cout << "Health gained: " << healthGained1 << endl;
        cout << "Expected health gained: 0" << endl;
    }

    // Test 2//

    // Establish initial health and set health to player
    int initialHealth2 = result.first.getHP() - 200; // In this situation, player has taken more damage than they can heal
    result.first.setHP(initialHealth2);

    // execute heal on player
    heal.executeMove(result.first, result.second);

    // record new health
    int newHP2 = result.first.getHP();

    // Test to see if expected health gained is correct
    int healthGained2 = newHP2 - initialHealth2;

    if (healthGained2 != 125)
    {
        cout << "- Test FAILED!!!" << endl;
        cout << "- Health gained: " << healthGained2 << endl;
        cout << "- Expected health gained: 125" << endl;
    }

    // Test 3//

    // Establish initial health
    int initialHealth3 = result.first.getFullHP() - 100; // In this situation, player has taken less damage than they can heal
    result.first.setHP(initialHealth3);

    // execute heal on player
    heal.executeMove(result.first, result.second);

    // record new health
    int newHP3 = result.first.getHP();

    int healthGained3 = newHP3 - initialHealth3;

    // Test to see if expected health gained is correct
    if (healthGained3 != 100)
    {
        cout << "Test FAILED!!!" << endl;
        cout << "Health gained: " << healthGained3 << endl;
        cout << "Expected health gained: 100" << endl;
    }

    return 0;
}