#pragma once
#include <iostream>
#include "Entity.h"

enum States
{
	IdleState,
	TurnAState,
	TurnBState,
	FinalState
};

class Arena 
{
private:
	Entity* entity_a;
	Entity* entity_b;
	States state;

public:
	Arena(Entity *entity_a, Entity *entity_b);
	void fight();
	void display_health();
	void prompt();
};