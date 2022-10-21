#include <iostream>
#include "Entity.h"
#include "Arena.h"


auto main() -> int
{
    srand((unsigned)time(0));
    Entity *player = new Entity("Player");
    Entity *enemy = new Entity("Enemy");
    int input = 0;
    std::cout << "Enter any key to start\n";
    std::cin >> input;
    Arena arena = Arena(player, enemy);
    arena.fight();

    delete player;
    delete enemy;
}
