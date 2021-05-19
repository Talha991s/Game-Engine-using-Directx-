#pragma once
#include "Input.h"
#include "Entity.hpp"
#include <string>

class Player :public Entity
{
public:
	Player(Game* game ,std::string name);
	virtual void		input(const GameTimer& gt);
private:
	virtual void		drawCurrent() const;
	virtual void		buildCurrent();
private:
	std::string			mSprite;
	ListenerManager		listenerManager;
	Listener aKey;
	Listener dKey;
};
