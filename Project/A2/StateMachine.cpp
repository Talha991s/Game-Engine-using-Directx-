#include "StateMachine.h"

StateMachine::StateMachine(Game* game)
{
	mGame = game;
	titleState = new TitleState(game);
	menuState = new MenuState(game);
	instructionState = new InstructionState(game);
	gameState = new GameState(game);

	states.push_back(titleState);
	states.push_back(menuState);
	states.push_back(instructionState);
	states.push_back(gameState);

	a.name = "accept";
	a.bindInt = 0x20;
	a.active = true;

	d.name = "deselect";
	d.bindInt = 0x08;
	d.active = true;

	//AllocConsole();
	//freopen_s((FILE**)stdout, "CONOUT$", "w", stdout);
}

void StateMachine::load()
{
	for (int i = 0; i < states.size(); i++)
	{
		states[i]->mOrder = i;
		states[i]->load();
	}
}

void StateMachine::update(const GameTimer& gt)
{
	for (int i = 0; i < states.size(); i++)
	{
		states[i]->update(gt);
	}
}

void StateMachine::draw(const GameTimer& gt)
{
	for (int i = 0; i < states.size(); i++)
	{
		states[i]->draw(gt);
	}
}

void StateMachine::input(const GameTimer& gt)
{
	for (int i = 0; i < states.size(); i++)
	{
		if (states[i]->mOrder == 0)
		{
			states[i]->getInputs(gt);
			if (states[i] == titleState)
			{
				if (listeners.CheckTrigger(a))
				{
					SetState(menuState);
				}
			}
			else if (states[i] == menuState)
			{
				if (listeners.CheckTrigger(a))
				{
					if (menuState->option == 0)
					{
						SetState(gameState);
					}
					if (menuState->option == 1)
					{
						SetState(instructionState);
					}
				}
			}
			else if (states[i] == instructionState)
			{
				if (listeners.CheckTrigger(d))
				{
					SetState(menuState);
				}
			}
			else if (states[i] == gameState)
			{
				if (listeners.CheckTrigger(a))
				{
					if (gameState->paused)
					{
						gameState->paused = false;
					}
					else
					{
						gameState->paused = true;
					}
				}
				if (listeners.CheckTrigger(d))
				{
					if (gameState->paused)
					{
						gameState->paused = false;
						SetState(menuState);
					}
				}
			}
		}
	}
}

void StateMachine::SetState(State* s)
{
	for (int i = 0; i < states.size(); i++)
	{
		if (states[i] == s)
		{
			states[i]->mOrder = 0;
		}
		else
		{
			states[i]->mOrder = 10;
		}
	}
}
