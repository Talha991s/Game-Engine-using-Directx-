#pragma once
#include "State.h"

class MenuState : public State
{
public:
	MenuState(Game* window);
	void update(const GameTimer& gt) override;
	void getInputs(const GameTimer& gt) override;
	void draw(const GameTimer& gt) override;
	void load() override;
public:
	SceneNode* mSceneGraph;
	int option;
private:
	Game* mGame;
	ListenerManager	listenerManager;
	SpriteNode* mBg;
	SpriteNode* mArrow;
	Listener up;
	Listener down;
};
