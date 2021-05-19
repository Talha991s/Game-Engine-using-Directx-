#include "MenuState.h"
#include <iostream>

MenuState::MenuState(Game* window)
{
	mGame = window;
	mSceneGraph = new SceneNode(window, "Menu State");
	mBg = nullptr;
	mArrow = nullptr;
	option = 0;
	mStateType = States::MENU_STATE;
	mOrder = 1;
}

void MenuState::update(const GameTimer& gt)
{
	mSceneGraph->setPosition(0, 0, 2 * mOrder);
	mSceneGraph->update(gt);
	getInputs(gt);
}

void MenuState::getInputs(const GameTimer& gt)
{
	if (listenerManager.CheckListener(up))
	{
		if (option == 1)
		{
			mArrow->setPosition(-1.8f, 0.25, 0);
			option = 0;

		}
	}
	else if (listenerManager.CheckListener(down))
	{
		if (option == 0)
		{
			mArrow->setPosition(-1.8f, -1.4f, 0);
			option = 1;
			
		}
	}
}

void MenuState::draw(const GameTimer& gt)
{
	mSceneGraph->draw();
}

void MenuState::load()
{
	std::unique_ptr<SpriteNode> arrow(new SpriteNode(mGame, "Selector", "Arrow"));
	mArrow = arrow.get();
	mArrow->setPosition(-1.8f, 0.25, 0 + mOrder);
	mArrow->setScale(0.5, 0.5, 0.5);
	mArrow->setWorldRotation(90 * XM_PI / 180, 0, 180 * XM_PI / 180);
	mSceneGraph->attachChild(std::move(arrow));

	std::unique_ptr<SpriteNode> bg(new SpriteNode(mGame, "Menu", "BG"));
	mBg = bg.get();
	mBg->setPosition(0, 0, 1 + mOrder);
	mBg->setScale(15.0, 1.0, 10 );
	mBg->setWorldRotation(90 * XM_PI / 180, 0, 180 * XM_PI / 180);
	mSceneGraph->attachChild(std::move(bg));
	mSceneGraph->build();


	up.bindChar = 'W';
	up.name = "ToggleUP";

	down.bindChar = 'S';
	down.name = "ToggleDOWN";

	listenerManager.AddListener(up);
	listenerManager.AddListener(down);
}
