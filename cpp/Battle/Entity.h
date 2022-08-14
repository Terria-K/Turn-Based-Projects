#pragma once
#include <iostream>

class Entity
{
private:
    std::string name;
    int hp;
public:
    std::string GetName();
    Entity();
    Entity(const char* name);
    int GetHp();
    void SetHp(int value);
    void DealDamageTo(Entity* entity, int damage);
    int AssignAttackDamage(int max);
};