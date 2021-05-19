#include "State.h"
#include "Player.h"
#include "Enemy.h"

class GameState : public State
{
public:
	GameState(Game* window);
	void update(const GameTimer& gt) override;
	void getInputs(const GameTimer& gt) override;
	void draw(const GameTimer& gt) override;
	void load() override;
public:
	bool paused;
private:

	Player* mPlayer;
	SpriteNode* mBackground;
	SpriteNode* mPause;
	Enemy* mEnemy1;
	Enemy* mEnemy2;
};