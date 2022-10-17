import entity;
import arena;
#include <iostream> // time don't work in import

int main()
{
    srand((unsigned)time(0));
    Entity* player = new Entity("Player");
    Entity* enemy = new Entity("Enemy");
    char useless_input = '0';
    std::cout << "Enter any key to start\n";
    std::cin >> useless_input;
    Arena arena = Arena(player, enemy);
    arena.fight();

    delete player;
    delete enemy;
}