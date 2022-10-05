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
	bool done;
	States state;

public:
	bool is_done();
	Arena(Entity* contestantA, Entity* contestantB);
	void fight();
	void display_health();
	void prompt();
};