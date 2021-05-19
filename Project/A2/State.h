#pragma once
#include "Input.h"
#include "SceneNode.hpp"
#include "SpriteNode.h"
#include "StateList.h"


class State
{
public:
	virtual void update(const GameTimer& gt);
	virtual void getInputs(const GameTimer& gt);
	virtual void draw(const GameTimer& gt);
	virtual void load();
public:
	States mStateType;
	SceneNode* mWorld;
	SceneNode* mSceneGraph;
	ListenerManager	listenerManager;
	Game* mGame;
	float mOrder;
};
