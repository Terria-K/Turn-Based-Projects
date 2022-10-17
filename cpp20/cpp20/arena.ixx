export module arena;
import <iostream>;
import <chrono>;
import <thread>;

import entity;

using namespace std::this_thread;
using namespace std::chrono_literals;
using std::chrono::system_clock;

enum States {
	Idle,
	TurnA,
	TurnB,
	Final
};

export struct Arena {
private:
	Entity* entity_a;
	Entity* entity_b;
	States state;
	void display_health();
	void prompt();

public:
	Arena(Entity* entity_a, Entity* entity_b);
	void fight();
};

Arena::Arena(Entity* entity_a, Entity* entity_b) {
	this->entity_a = entity_a;
	this->entity_b = entity_b;
	state = States::Idle;
}

void Arena::fight() {
	int randomize = rand() % 2;
	state = randomize == 0 ? States::TurnA : States::TurnB;
	int turn = 1;
	while (state != States::Final) {
		int a_damage = entity_a->assign_attack_damage(50);
		int b_damage = entity_b->assign_attack_damage(50);

		std::cout << std::format("============Turn {0}=============== \n", turn);
		switch (state)
		{
		case States::TurnA:
			entity_a->deal_damage_to(entity_b, a_damage);
			display_health();
			if (entity_b->hp > 0)
				std::cout << std::format("{0} Turn!\n\n", entity_a->name);
			state = States::TurnB;
			break;
		case States::TurnB:
			entity_b->deal_damage_to(entity_a, b_damage);
			display_health();
			if (entity_a->hp > 0)
				std::cout << std::format("{0} Turn!\n\n", entity_b->name);
			state = States::TurnA;
			break;
		default:
			break;
		}

		if (entity_a->hp < 1)
		{
			state = States::Final;
			std::cout << std::format("{0} Wins!!\n", entity_b->name);
			continue;
		}

		if (entity_b->hp < 1)
		{
			state = States::Final;
			std::cout << std::format("{0} Wins!\n", entity_a->name);
			continue;
		}
		turn++;
		sleep_for(10ns);
		sleep_until(system_clock::now() + 1s);
	}

	prompt();
}


void Arena::prompt()
{
	int any = 0;
	std::cout << "Type 0 or above to continue the game, type -1 to exit!\n";
	std::cin >> any;
	if (any > -1)
	{
		entity_a->hp = 100;
		entity_b->hp = 100;
		fight();
	}
}

void Arena::display_health()
{
	std::cout << std::format("{0} has {1} HP\n", entity_a->name, entity_a->hp);
	std::cout << std::format("{0} has {1} HP\n", entity_b->name, entity_b->hp);
}
