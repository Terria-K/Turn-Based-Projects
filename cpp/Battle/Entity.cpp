#include <iostream>
#include "Entity.h"

std::string Entity::GetName() 
{
	return name;
}

Entity::Entity() 
{
	this->name = "NoName Entity";
	this->hp = 100;
}

Entity::Entity(const char* name)
{
	this->name = name;
	this->hp = 100;
}

int Entity::GetHp() 
{
	return hp;
}

void Entity::SetHp(int value) 
{
	hp = value;
}

int Entity::AssignAttackDamage(int max) 
{
	return rand() % max + 1;
}
void Entity::DealDamageTo(Entity* entity, int damage) 
{
	int entityHP = entity->GetHp();
	entity->SetHp(entityHP - damage);
	std::cout << name << " Damage: " << entity->GetName() << " with " << damage << " dmg\n";
	std::cout << "===============================\n";

}