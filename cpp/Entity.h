#pragma once
#include <iostream>

class Entity
{
private:
    std::string name;
    int hp;
public:
    std::string get_name();
    Entity();
    Entity(const char* name);
    int get_hp();
    void set_hp(int value);
    void deal_damage_to(Entity* entity, int damage);
    int assign_attack_damage(int max);
};