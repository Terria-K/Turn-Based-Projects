#include <iostream>
#include "Entity.h"

std::string Entity::get_name() 
{
	return name;
}

Entity::Entity() 
{
	this->name = "NoName Entity";
	this->hp = 100;
}

Entity::Entity(const char *name)
{
	this->name = name;
	this->hp = 100;
}

int Entity::get_hp() 
{
	return hp;
}

void Entity::set_hp(int value) 
{
	hp = value;
}

int Entity::assign_attack_damage(int max) 
{
	return rand() % max + 1;
}
void Entity::deal_damage_to(Entity *entity, int damage) 
{
	int entity_hp = entity->get_hp();
	entity->set_hp(entity_hp - damage);
	std::cout << name << " Damage: " << entity->get_name() << " with " << damage << " dmg\n";
	std::cout << "===============================\n";
}