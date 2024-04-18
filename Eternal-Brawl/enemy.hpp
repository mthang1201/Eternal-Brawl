#pragma once
#include <SDL_mixer.h>

#include "entity.hpp"

enum EnemyState
{
	RUN,
	DASH,
	ATTACK,
	DEATH
};

class Enemy : public Entity
{
public:
	Enemy(const LoaderParams* pParams);

	virtual void draw();
	virtual void update();
	virtual void clean();
	virtual std::string getObjectState();

	float healthPoints;
	SDL_Color healthColor;
	SDL_Rect healthBarRect;
	int healthBarWidth;

	int m_indexInEnemyList;

	Vector2f m_playerPos;
private:
	void checkCollision();
	void moveTowardsPlayer();

	//EnemyState m_state;
	EnemyState m_state;
	float m_moveSpeed = 5;
	int idleCounter = 0, walkCounter = 0, fallingCounter = 0, attackingCounter = 0, beingHitCounter = 0;
	bool grounded = true, walking = false, idling = true, falling = false, attacking = false, beingHit = false, dead = false;
};