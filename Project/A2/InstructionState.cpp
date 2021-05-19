#include "InstructionState.h"

InstructionState::InstructionState(Game* window) 
{
	mGame = window;
	mSceneGraph = new SceneNode(window, "Instruction State");
	mBg = nullptr;
	mStateType = States::INSTRUCTIONS_STATE;
	mOrder = 2;
}

void InstructionState::update(const GameTimer& gt)
{
	mSceneGraph->setPosition(0, 0, 2 * mOrder);
	mSceneGraph->update(gt);
}

void InstructionState::getInputs(const GameTimer& gt)
{

}

void InstructionState::draw(const GameTimer& gt)
{
	mSceneGraph->draw();
}

void InstructionState::load()
{
	std::unique_ptr<SpriteNode> bg(new SpriteNode(mGame, "Instruction", "Bg"));
	mBg = bg.get();
	mBg->setPosition(0, 0, 1 + mOrder);
	mBg->setScale(12.0, 1.0, 9.0);
	mBg->setWorldRotation(90 * XM_PI / 180, 0, 180 * XM_PI / 180);
	mSceneGraph->attachChild(std::move(bg));
	mSceneGraph->build();
}
