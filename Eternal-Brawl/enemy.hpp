#pragma once
#include <SDL_mixer.h>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

#include "entity.hpp"
#include "game.hpp"

enum EnemyState
{
	IDLE,
	RUN,
	DASH,
	ATTACK,
	HEAVY_ATTACK,
	KNOCKBACK,
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

	EnemyState m_state;
	void immovable();
	void movable();
	int test;
private:
	void checkCollision();
	void moveTowardsPlayer();

	void followCalculatedPath();
	void calculatePlayerPosBriefly();
	bool isValid(int x, int y);
	bool findPath(int x1, int y1, int x2, int y2);
	bool pathFound;
	float m_dirX, m_dirY;
	int pathStep;
	int pathCount;
	std::vector<int> pathToPlayer;
	std::vector<std::vector<bool>> visited;

	void handleMovement();
	void handleAnimation();

	float m_moveSpeed = 3;
	int idleCounter = 0, walkCounter = 0, fallingCounter = 0, attackingCounter = 0, beingHitCounter = 0;
	bool grounded = true, walking = false, idling = true, falling = false, attacking = false, beingHit = false, dead = false;
};