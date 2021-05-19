#include "TitleState.h"

TitleState::TitleState(Game* window)
{
	mGame = window;
	mSceneGraph = new SceneNode(window, "Title State");
	mBg = nullptr;
	mStateType = States::TITLE_STATE;
	mOrder = 0;
}

void TitleState::update(const GameTimer& gt)
{
	mSceneGraph->setPosition(0, 0, 2 * mOrder);
	mSceneGraph->update(gt);
}

void TitleState::getInputs(const GameTimer& gt)
{

}

void TitleState::draw(const GameTimer& gt)
{
	mSceneGraph->draw();
}

void TitleState::load()
{
	std::unique_ptr<SpriteNode> titleImg(new SpriteNode(mGame, "Title", "BG"));
	mBg = titleImg.get();
	mBg->setPosition(0, 0, 0);
	mBg->setScale(12.0, 1.0, 8.5);
	mBg->setWorldRotation(90 * XM_PI / 180, 0, 180 * XM_PI / 180);
	mSceneGraph->attachChild(std::move(titleImg));
	mSceneGraph->build();
}

