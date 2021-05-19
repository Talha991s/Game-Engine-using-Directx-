#include "GameState.h"


GameState::GameState(Game* window)
{
	mGame = window;
	mSceneGraph = new SceneNode(window, "Game State");
	mPlayer = nullptr;
	mBackground = nullptr;
	mEnemy1 = nullptr;
	mEnemy2 = nullptr;
	mStateType = States::GAME_STATE;
	mOrder = 3;
	paused = false;
}

void GameState::update(const GameTimer& gt)
{
	mSceneGraph->setPosition(0,0, 2 * mOrder);
	if (paused)
	{
		mPause->setPosition(0, 0, -0.1f);
	}
	else
	{
		mPause->setPosition(0, 0, -50);
		mSceneGraph->update(gt);
	}
	getInputs(gt);
}

void GameState::getInputs(const GameTimer& gt)
{
	mPlayer->input(gt);
}

void GameState::draw(const GameTimer& gt)
{
	mSceneGraph->draw();
}

void GameState::load()
{
	std::unique_ptr<Player> player(new Player(mGame, "Player"));
	mPlayer = player.get();
	mPlayer->setPosition(0, -2.5, 0);
	mPlayer->setWorldRotation(90 * XM_PI / 180, 0, 180 * XM_PI / 180);
	mPlayer->setScale(1, 1, 1);
	mSceneGraph->attachChild(std::move(player));


	std::unique_ptr<Enemy> enemy1(new Enemy(mGame, "Enemy 1"));
	mEnemy1 = enemy1.get();
	mEnemy1->setPosition(1.0f, -3.5f, 0.0f);
	mEnemy1->setWorldRotation(90 * XM_PI / 180, 0, 180 * XM_PI / 180);
	mEnemy1->setScale(1, 1, 1);
	mSceneGraph->attachChild(std::move(enemy1));

	std::unique_ptr<Enemy> enemy2(new Enemy(mGame, "Enemy 2"));
	mEnemy2 = enemy2.get();
	mEnemy2->setPosition(-1.0, -3.5f, 0);
	mEnemy2->setWorldRotation(90 * XM_PI / 180, 0, 180 * XM_PI / 180);
	mEnemy2->setScale(1, 1, 1);
	mSceneGraph->attachChild(std::move(enemy2));

	std::unique_ptr<SpriteNode> backgroundSprite(new SpriteNode(mGame, "Desert", "Bg"));
	mBackground = backgroundSprite.get();
	mBackground->setPosition(0, 0, 1);
	mBackground->setScale(15.0, 1.0, 500.0);
	mBackground->setWorldRotation(90 * XM_PI / 180, 0, 0);
	mBackground->setVelocity(0, -2);
	mSceneGraph->attachChild(std::move(backgroundSprite));

	std::unique_ptr<SpriteNode> pauseSprite(new SpriteNode(mGame, "Pause", "stop"));
	mPause = pauseSprite.get();
	mPause->setPosition(0, 0, -50);
	mPause->setScale(15.0, 1.0, 15.0);
	mPause->setWorldRotation(90 * XM_PI / 180, 0, 180 * XM_PI /180);
	mPause->setVelocity(0, -2);
	mSceneGraph->attachChild(std::move(pauseSprite));

	mSceneGraph->build();
}
