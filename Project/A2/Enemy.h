#pragma once
#include "Entity.hpp"
#include <string>

class Enemy : public Entity
{
public:
	Enemy(Game* game, std::string name);
private:
	virtual void		drawCurrent() const;
	virtual void		buildCurrent();
private:
	std::string			mSprite;
};
