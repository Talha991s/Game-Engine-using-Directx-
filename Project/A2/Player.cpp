#include "Player.h"
#include "Game.hpp"

Player::Player(Game* game, std::string name) : Entity(game, name)
{
	mSprite = "Eagle";
	mName = "Player";
	//Create Listeners

	aKey.bindChar = 'A';
	aKey.name = "AKey";

	dKey.bindChar = 'D';
	dKey.name = "DKey";
	// Add listeners to listener manager
	listenerManager.AddListener(aKey);
	listenerManager.AddListener(dKey);
}

void Player::input(const GameTimer& gt)
{
	float speed = 2.0f * gt.DeltaTime();

	if (listenerManager.CheckListener(dKey))
	{
		move(speed, 0, 0);
	}

	if (listenerManager.CheckListener(aKey))
	{
		move(-speed, 0, 0);
	}
}

void Player::drawCurrent() const
{
}

void Player::buildCurrent()
{
	auto render = std::make_unique<RenderItem>();
	renderer = render.get();
	renderer->World = getTransform();
	renderer->ObjCBIndex = game->getRenderItems().size();
	renderer->Mat = game->getMaterials()[mSprite].get();
	renderer->Geo = game->getGeometries()["boxGeo"].get();
	renderer->PrimitiveType = D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST;
	renderer->IndexCount = renderer->Geo->DrawArgs["box"].IndexCount;
	renderer->StartIndexLocation = renderer->Geo->DrawArgs["box"].StartIndexLocation;
	renderer->BaseVertexLocation = renderer->Geo->DrawArgs["box"].BaseVertexLocation;

	game->getRenderItems().push_back(std::move(render));
}
