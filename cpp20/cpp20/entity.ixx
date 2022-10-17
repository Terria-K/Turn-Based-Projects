export module entity;

import <string>;
import <iostream>;
import <format>;

export struct Entity {
	std::string name;
	int hp;

	Entity(const char* name);
	void deal_damage_to(Entity* entity, int damage);
	int assign_attack_damage(int max);
};

Entity::Entity(const char* name) {
	this->name = name;
	this->hp = 100;
}

void Entity::deal_damage_to(Entity* entity, int damage) {
	entity->hp -= damage;
	std::cout << std::format("{0} Damage: {1} with {2} dmg\n", name, entity->name, damage);
	std::cout << "===============================\n";
}

int Entity::assign_attack_damage(int max) {
	return rand() % max + 1;
}