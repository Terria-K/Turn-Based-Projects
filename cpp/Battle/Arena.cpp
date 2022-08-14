#include <iostream>
#include <chrono>
#include <thread>
#include "Arena.h" 
#include <windows.h>
#include <shellapi.h>

using namespace std::this_thread;
using namespace std::chrono_literals;
using std::chrono::system_clock;

Arena::Arena(Entity* contestantA, Entity* contestantB) 
{
	A = contestantA;
	B = contestantB;
	done = false;
	state = States::IdleState;
}

bool Arena::IsDone() 
{
	return done;
}

void Arena::Fight() 
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
		int ADamage = A->AssignAttackDamage(50);
		int BDamage = B->AssignAttackDamage(50);

		switch (state) 
		{
		case States::TurnAState:
			A->DealDamageTo(B, ADamage);
			DisplayHealth();
			std::cout << "============Turn " << turn << "=============== \n";
			if (B->GetHp() > 0)
				std::cout << B->GetName() << " Turn!\n";
			state = States::TurnBState;
			break;
		case States::TurnBState:
			B->DealDamageTo(A, BDamage);
			DisplayHealth();
			std::cout << "============Turn " << turn << "=============== \n";
			if (A->GetHp() > 0)
				std::cout << B->GetName() << " Turn!\n";
			state = States::TurnAState;
			break;
		}

		if (A->GetHp() < 1) 
		{
			state = States::FinalState;
			std::cout << B->GetName() << " Wins!\n";
			continue;
		}

		if (B->GetHp() < 1)
		{
			state = States::FinalState;
			std::cout << A->GetName() << " Wins!\n";
			continue;
		}
		turn++;
		sleep_for(10ns);
		sleep_until(system_clock::now() + 1s);
	}
	Prompt();
	done = true;
}

void Arena::Prompt() 
{
	int any = 0;
	std::cout << "Type 0 or above to continue the game, type -1 to exit!\n";
	std::cin >> any;
	if (any > -1) 
	{
		A->SetHp(100);
		B->SetHp(100);
		Fight(any);
	}
}

void Arena::DisplayHealth() 
{
	std::cout << A->GetName() << " has " << A->GetHp() << " health\n";
	std::cout << B->GetName() << " has " << B->GetHp() << " health\n";
}