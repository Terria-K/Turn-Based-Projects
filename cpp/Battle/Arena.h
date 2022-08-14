#pragma once
#include <iostream>
#include "Entity.h"

enum class States
{
	IdleState,
	TurnAState,
	TurnBState,
	FinalState
};

class Arena 
{
private:
	Entity* A;
	Entity* B;
	bool done;
	States state;

public:
	bool IsDone();
	Arena(Entity* contestantA, Entity* contestantB);
	void Fight();
	void DisplayHealth();
	void Prompt();
};