#pragma once
#include "TitleState.h"
#include "MenuState.h"
#include "GameState.h"
#include "InstructionState.h"
#include "StateList.h"

class StateMachine
{
public:
	StateMachine(Game* game);
	void load();
	void update(const GameTimer& gt);
	void draw(const GameTimer& gt);
	void input(const GameTimer& gt);
	void SetState(State* s);
private:
	Game* mGame;
	std::vector<State*> states;
	GameState* gameState;
	TitleState* titleState;
	MenuState* menuState;
	InstructionState* instructionState;

	ListenerManager listeners;
	Listener a;
	Listener d;
};