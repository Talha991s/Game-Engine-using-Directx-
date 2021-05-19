#pragma once
#include "State.h"

class InstructionState : public State
{
public:
	InstructionState(Game* window);
	void update(const GameTimer& gt) override;
	void getInputs(const GameTimer& gt) override;
	void draw(const GameTimer& gt) override;
	void load() override;
public:
	SpriteNode* mBg;
};
