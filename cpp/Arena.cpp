#include <iostream>
#include <chrono>
#include <thread>
#include "Arena.h" 
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif
#include <shellapi.h>

using namespace std::this_thread;
using namespace std::chrono_literals;
using std::chrono::system_clock;

Arena::Arena(Entity* entity_a, Entity* entity_b) 
{
	this->entity_a = entity_a;
	this->entity_b = entity_b;
	done = false;
	state = States::IdleState;
}

bool Arena::is_done() 
{
	return done;
}

void Arena::fight() 
{
	int randomize = rand() % 2;
	switch (randomize) 
	{
	case 0:
		state = States::TurnAState;
		break;
	case 1:
		state = States::TurnBState;
		break;
	}
	int turn = 1;
	while (state != States::FinalState) 
	{
		int a_damage = entity_a->assign_attack_damage(50);
		int b_damage = entity_b->assign_attack_damage(50);

		std::cout << "============Turn " << turn << "=============== \n";
		switch (state) 
		{
		case States::TurnAState:
			entity_a->deal_damage_to(entity_b, a_damage);
			display_health();
			if (entity_b->get_hp() > 0)
				std::cout << entity_b->get_name() << " Turn!\n\n";
			state = States::TurnBState;
			break;
		case States::TurnBState:
			entity_b->deal_damage_to(entity_a, b_damage);
			display_health();
			if (entity_a->get_hp() > 0)
				std::cout << entity_b->get_name() << " Turn!\n\n";
			state = States::TurnAState;
			break;
		default:
			break;
		}

		if (entity_a->get_hp() < 1) 
		{
			state = States::FinalState;
			std::cout << entity_b->get_name() << " Wins!\n";
			continue;
		}

		if (entity_b->get_hp() < 1)
		{
			state = States::FinalState;
			std::cout << entity_a->get_name() << " Wins!\n";
			continue;
		}
		turn++;
		sleep_for(10ns);
		sleep_until(system_clock::now() + 1s);
	}
	prompt();
	done = true;
}

void Arena::prompt() 
{
	int any = 0;
	std::cout << "Type 0 or above to continue the game, type -1 to exit!\n";
	std::cin >> any;
	if (any > -1) 
	{
		entity_a->set_hp(100);
		entity_b->set_hp(100);
		fight();
	}
}

void Arena::display_health() 
{
	std::cout << entity_a->get_name() << " has " << entity_a->get_hp() << " HP\n";
	std::cout << entity_b->get_name() << " has " << entity_b->get_hp() << " HP\n";
}
