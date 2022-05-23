#include <iostream>
#include <stdlib.h>
#include <string.h>

#include "Character.h"
#include "Player.h"
#include "Move.h"
#include "Attack.h"

using namespace std;

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
    Attack attack;

    std::pair<Player, Player> result = testSetUp();

    // Test 1//

    // Establish initial health
    int initialHealth1 = 0; // In this situation, the player is at 0% health
    result.first.setHP(initialHealth1);

    // execute attack on player 1 (first) from player 2 (second)
    attack.executeMove(result.second, result.first);

    // record new health
    int newHP1 = result.first.getHP();

    int healthLost1 = initialHealth1 - newHP1;

    // Test to see if expected health gained is correct
    if (healthLost1 != 0)
    {
        cout << "Test FAILED!!!" << endl;
        cout << "Damage taken: " << healthLost1 << endl;
        cout << "Expected damage taken: 0" << endl;
    }

    // Test 2//

    // Establish initial health
    int initialHealth2 = result.first.getFullHP(); // In this situation, the player is at 100% health
    result.first.setHP(initialHealth2);

    // execute attack on player 1 (first) from player 2 (second)
    attack.executeMove(result.second, result.first);

    // record new health
    int newHP2 = result.first.getHP();
    int healthLost2 = initialHealth2 - newHP2;

    // Test to see if expected health gained is correct
    if (healthLost2 != 80)
    {
        cout << "Test FAILED!!!" << endl;
        cout << "Damage taken: " << healthLost2 << endl;
        cout << "Expected damage taken: 80" << endl;
    }

    // Test 3//

    // Establish initial health
    int initialHealth3 = 50; // In this situation, the player is at 50 health (about to die if attacked by 80 strength)
    result.first.setHP(initialHealth3);

    // execute attack on player 1 (first) from player 2 (second)
    attack.executeMove(result.second, result.first);

    // record new health
    int newHP3 = result.first.getHP();

    int healthLost3 = initialHealth3 - newHP3;

    // Test to see if expected health gained is correct
    if (healthLost3 != 50)
    {
        cout << "Test FAILED!!!" << endl;
        cout << "Damage taken: " << healthLost3 << endl;
        cout << "Expected damage taken: 50" << endl;
    }

    return 0;
}