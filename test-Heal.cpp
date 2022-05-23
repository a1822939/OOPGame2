#include <iostream>
#include <stdlib.h>
#include <string.h>

#include "Character.h"
#include "Player.h"
#include "Move.h"
#include "Heal.h"

int main()
{
    Heal heal;
    Player A;
    Player B;

    A.setHP(100);
    B.setHP(100);

    heal.executeMove(A, B);

    return 0;
}