#include <SDL.h>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

#include "enemy.hpp"
#include "inputHandler.hpp"
#include "map.hpp"
#include "game.hpp"

const float GRAVITY = 0.5;
const float MAX_GRAVITY = 15;

const Uint32 knockbackInterval = 20000;
Uint32 lastKnockbackTime = SDL_GetTicks();

Enemy::Enemy(const LoaderParams* pParams) : Entity(pParams)
{
	m_velocity.setX(1);
	//m_velocity.setX(0);
	m_velocity.setY(0);
	pathFound = false;
	healthPoints = 300;
}

void Enemy::draw()
{
}

const int HEALTHBAR_WIDTH = 200;
const int HEALTHBAR_HEIGHT = 10;

void Enemy::update()
{
	// draw health bar
	if (m_indexInEnemyList < 5)
	{
		healthBarRect = { 420, 10 + ((m_indexInEnemyList % 5) * 15), HEALTHBAR_WIDTH, HEALTHBAR_HEIGHT };
	}
	else if (m_indexInEnemyList < 10)
	{
		healthBarRect = { 660, 10 + ((m_indexInEnemyList % 5) * 15), HEALTHBAR_WIDTH, HEALTHBAR_HEIGHT };
	}
	else if (m_indexInEnemyList < 15)
	{
		healthBarRect = { 900, 10 + ((m_indexInEnemyList % 5) * 15), HEALTHBAR_WIDTH, HEALTHBAR_HEIGHT };
	}

	healthBarWidth = static_cast<int>((static_cast<float>(healthPoints) / 300) * HEALTHBAR_WIDTH);
	healthColor = { 0, 255, 0, 255 }; // Green by default
	if (healthPoints < 50)
		healthColor = { 255, 0, 0, 255 }; // Red if health is below 50

	/*void Player::jump() {
		if (grounded) {
			m_velocity.setY(m_velocity.getY() - 10);
			grounded = false;
		}
	}*/

	/*{ 647, 649, 9, 71 },
	{ 656, 655, 8 , 65 },
	{ 664, 661, 8 , 59 },
	{ 672, 668, 8 , 52 },
	{ 680, 674, 3 , 46 },
	{ 683, 677, 5 , 43 },*/

	/*if (m_pos.getX() >= 647 && m_pos.getX() <= 683)
	{
		grounded = true;
	}*/

	/*if (!grounded) {
		m_velocity.setY(m_velocity.getY() + GRAVITY);
		if (m_velocity.getY() > MAX_GRAVITY) m_velocity.setY(MAX_GRAVITY);
	}
	else m_velocity.setY(GRAVITY);*/

	Uint32 currentTime = SDL_GetTicks();
	if (m_state == EnemyState::KNOCKBACK && currentTime - lastKnockbackTime < knockbackInterval) {
		lastKnockbackTime = currentTime;
		//std::cout << "Knockback" << std::endl;
	}
	else {
		moveTowardsPlayer();
		handleMovement();
		//std::cout << "Run or attack" << std::endl;
	}
	handleAnimation();

	Entity::update();

	checkCollision();

	// doDyingAnimation()
	if (healthPoints <= 0) {
		m_state = EnemyState::DEATH;
		Uint32 m_deathTime = SDL_GetTicks();
	}
}

void Enemy::checkCollision()
{
	if (m_pos.getX() < 0 || m_pos.getX() > 1280 - m_currentFrame.w + 18)
	{
		m_pos.setX(m_pos.getX() - m_velocity.getX());
	}
	if (m_pos.getY() < 0 || m_pos.getY() > 720 - m_currentFrame.h + 18)
	{
		m_pos.setY(m_pos.getY() - m_velocity.getY());
	}
	m_rigidBody = { static_cast<int>(m_pos.getX()), static_cast<int>(m_pos.getY() + 22), static_cast <int>(42), static_cast <int>(42) };
	std::vector<SDL_Rect> m_tiles;
	/*m_tiles.push_back({ 80, 508, 100, 100 });
	m_tiles.push_back({ 400, 350, 100, 80 });*/
	for (SDL_Rect tile : tiles)
	{
		/*SDL_Rect modifiedTile = { tile.x + 18, tile.y + 18, tile.w - 18, tile.h - 18 };*/
		SDL_Rect modifiedTile = { tile.x, tile.y, tile.w, tile.h };
		SDL_bool isColliding = SDL_HasIntersection(&m_rigidBody, &modifiedTile);

		if (isColliding)
		{
			// topLeftElevator
			if (tile.x == 106 && tile.y == 194 && tile.w == 73 && tile.h == 62)
			{
				m_pos.setX(156 + m_moveSpeed * 3);
				m_pos.setY(572 - 15 + 4);
				m_velocity.setX(m_moveSpeed);
			}
			//bottomDownElevator
			else if (tile.x == 106 && tile.y == 568 && tile.w == 50 && tile.h == 192)
			{
				m_pos.setX(179 + m_moveSpeed * 3);
				m_pos.setY(197 - 15 + 4);
				m_velocity.setX(m_moveSpeed);
			}
			//topRightElevator
			else if (tile.x == 1048 && tile.y == 399 && tile.w == 72 && tile.h == 60)
			{
				m_pos.setX(984 - m_moveSpeed * 3);
				m_pos.setY(622 - 15 + 4);
				m_velocity.setX(-m_moveSpeed);
			}
			//bottomRightElevator
			else if (tile.x == 1048 && tile.y == 629 && tile.w == 72 && tile.h == 51)
			{
				m_pos.setX(984 - m_moveSpeed * 3);
				m_pos.setY(402 - 15 + 4);
				m_velocity.setX(-m_moveSpeed);
			}
			//stair
			//stair 1
			else if (tile.x == 647 && tile.y == 649 && tile.w == 9 && tile.h == 71 && m_velocity.getX() > 0) //right
			{
				m_pos.setY(m_pos.getY() + 9);
			}
			else if (tile.x == 647 && tile.y == 649 && tile.w == 9 && tile.h == 71 && m_velocity.getX() < 0) //left
			{
				m_pos.setY(m_pos.getY() - 10);
			}
			//stair 2
			else if (tile.x == 656 && tile.y == 655 && tile.w == 8 && tile.h == 65 && m_velocity.getX() > 0) //right
			{
				m_pos.setY(m_pos.getY() + 8);
			}
			else if (tile.x == 656 && tile.y == 655 && tile.w == 8 && tile.h == 65 && m_velocity.getX() < 0) //left
			{
				m_pos.setY(m_pos.getY() - 6);
			}
			//stair 3
			else if (tile.x == 664 && tile.y == 661 && tile.w == 8 && tile.h == 59 && m_velocity.getX() > 0) //right
			{
				m_pos.setY(m_pos.getY() + 8);
			}
			else if (tile.x == 664 && tile.y == 661 && tile.w == 8 && tile.h == 59 && m_velocity.getX() < 0) //left
			{
				m_pos.setY(m_pos.getY() - 6);
			}
			//stair 4
			else if (tile.x == 672 && tile.y == 668 && tile.w == 8 && tile.h == 52 && m_velocity.getX() > 0) //right
			{
				m_pos.setY(m_pos.getY() + 8);
			}
			else if (tile.x == 672 && tile.y == 668 && tile.w == 8 && tile.h == 52 && m_velocity.getX() < 0) //left
			{
				m_pos.setY(m_pos.getY() - 7);
			}
			//stair 5
			else if (tile.x == 680 && tile.y == 674 && tile.w == 3 && tile.h == 46 && m_velocity.getX() > 0) //right
			{
				m_pos.setY(m_pos.getY() + 3);
			}
			else if (tile.x == 680 && tile.y == 674 && tile.w == 3 && tile.h == 46 && m_velocity.getX() < 0) //left
			{
				m_pos.setY(m_pos.getY() - 6);
			}
			//stair 6
			else if (tile.x == 683 && tile.y == 677 && tile.w == 5 && tile.h == 43 && m_velocity.getX() > 0) //right
			{
				m_pos.setY(m_pos.getY() + 5);
			}
			else if (tile.x == 683 && tile.y == 677 && tile.w == 5 && tile.h == 43 && m_velocity.getX() < 0) //left
			{
				m_pos.setY(m_pos.getY() - 3);
			}
			/*else if (abs(tile.x - m_pos.getX()) < 10 && m_pos.getY() + m_currentFrame.h/2 + m_rigidBody.h/2 - tile.y < 10)
			{
				grounded = true;
			}*/
			else
			{
				m_pos.setX(m_pos.getX() - m_velocity.getX());
				m_pos.setY(m_pos.getY() - m_velocity.getY());
			}
		}
	}
}

void Enemy::moveTowardsPlayer()
{
	/*if (m_pos.getX() < 537)
	{
		m_velocity.setX(m_moveSpeed);
	}
	else if (m_pos.getX() > 1048)
	{
		m_velocity.setX(-m_moveSpeed);
	}*/

	//float length = sqrt(pow(m_playerPos.getX() - m_pos.getX(), 2) + pow(m_playerPos.getY() - m_pos.getY(), 2));
	/*int x1 = static_cast<int>(m_pos.getX() / TILE_SIZE);
	int y1 = static_cast<int>(m_pos.getY() / TILE_SIZE);
	int x2 = static_cast<int>(m_playerPos.getX() / TILE_SIZE);
	int y2 = static_cast<int>(m_playerPos.getY() / TILE_SIZE);*/

	float dirX, dirY;
	if (m_pos.getX() - m_playerPos.getX() > 0) dirX = -1;
	else dirX = 1;
	if (m_pos.getY() - m_playerPos.getY() > 0) dirY = -1;
	else dirY = 1;

	m_velocity.setPos(dirX * m_moveSpeed, dirY * m_moveSpeed);
	//Vector2f diff = Vector2f(m_pos.getX() - m_playerPos.getX(), m_pos.getY() - m_playerPos.getY());
	//diff.normalize();
	////if (length < 400)
	////{
		//calculatePlayerPosBriefly();
		//static Vector2f currentPlayerPos;
		//if (currentPlayerPos != m_playerPos)
		/*if (currentPlayerPos.getX() != m_playerPos.getX() || currentPlayerPos.getY() != m_playerPos.getY())*/
		//if (!true)
		//{
		//	//currentPlayerPos = m_playerPos;
		//	pathToPlayer.clear();
		//	visited.clear();
		//	pathToPlayer.resize(100000);
		//	visited.resize(MAP_HEIGHT);
		//	for (int y = 0; y < MAP_HEIGHT; y++) {
		//		visited[y].resize(MAP_WIDTH, false);
		//	}
		//	pathCount = 0;
		//	if (findPath(x1, y1, x2, y2))
		//	//if (!true)
		//	{
		//		pathStep = 0;
		//		followCalculatedPath();
		//		pathStep++;
		//		pathFound = true;
		//	}
		//	else
		//	{
		//		/*if (m_pos.getX() < 537)
		//		{
		//			m_velocity.setX(m_moveSpeed);
		//		}
		//		else if (m_pos.getX() > 1048)
		//		{
		//			m_velocity.setX(-m_moveSpeed);
		//		}*/
		//		pathFound = false;
		//	}
		//}
		//else if (pathFound)
		//{
		//	//followCalculatedPath();
		//	std::cout << pathToPlayer[pathStep];
		//	pathStep++;
		//}
		//else
		//{
		//	//std::cout << /*"error" << MAP_HEIGHT << MAP_WIDTH << std::endl << x1 << " " <<*/ /*x2 << std::endl <<*/ y1 << " " << y2 << std::endl;
		//}
	////}
}

void Enemy::followCalculatedPath()
{
	if (pathToPlayer[pathStep] == 1) //UP
	{
		m_dirX = 0;
		m_dirY = -1;
	}
	else if (pathToPlayer[pathStep] == 2) //DOWN
	{
		m_dirX = 0;
		m_dirY = 1;
	}
	else if (pathToPlayer[pathStep] == 3) //LEFT
	{
		m_dirX = -1;
		m_dirY = 0;
	}
	else if (pathToPlayer[pathStep] == 4) //RIGHT
	{
		m_dirX = 1;
		m_dirY = 0;
	}
	m_dirX = pathToPlayer[pathStep];
	m_dirY = pathToPlayer[pathStep];
	m_velocity.setX(m_moveSpeed * m_dirX);
	m_velocity.setY(m_moveSpeed * m_dirY);
	/*m_pos.setX(m_moveSpeed * m_dirX);
	m_pos.setY(m_moveSpeed * m_dirY);*/
}

void Enemy::calculatePlayerPosBriefly()
{
	if (m_pos.getX() < m_playerPos.getX()) {
		m_dirX = 1;
	}
	else if (m_pos.getX() > m_playerPos.getX()) {
		m_dirX = -1;
	}
	if (m_pos.getY() < m_playerPos.getY()) {
		m_dirY = -1;
	}
	else if (m_pos.getY() > m_playerPos.getY()) {
		m_dirY = 1;
	}
}

bool Enemy::isValid(int x, int y)
{
	if (x >= 0 && x < MAP_WIDTH && y >= 0 && y < MAP_HEIGHT && worldMap[y][x] != 1) return true;
	return false;
}

void Enemy::immovable()
{
	m_velocity.setX(0);
	m_velocity.setY(0);
}

void Enemy::movable()
{
	m_velocity.setX(-3);
	m_velocity.setY(0);
}

void Enemy::knockback()
{
	bool firstTime = true;
	static int dir;
	if (firstTime) {
		int dir = (abs(m_velocity.getX()) / m_velocity.getX());
		firstTime = false;
	}
	m_velocity.setX(m_velocity.getX() + 30 * dir);
}

bool Enemy::findPath(int x1, int y1, int x2, int y2)
{
	// print(sol, width, height);cout << endl;
	if (x1 == x2 && y1 == y2)
	{
		pathToPlayer[pathCount] = 0;
		return true;
	}

	if (isValid(x1, y1))
	{
		if (!visited[y1][x1]) visited[y1][x1] = true;
		else return false;

		if (findPath(x1, y1 - 1, x2, y2))
		{
			pathToPlayer[pathCount++] = 1; // UP
			return true;
		}
		//if (findPath(x1, y1 + 1, x2, y2))
		//{
		//	pathToPlayer[pathCount++] = 2; // DOWN
		//	return true;
		//}
		if (findPath(x1 - 1, y1, x2, y2))
		{
			pathToPlayer[pathCount++] = 3; // LEFT
			return true;
		}
		//if (findPath(x1 + 1, y1, x2, y2))
		//{
		//	pathToPlayer[pathCount++] = 4; // RIGHT
		//	return true;
		//}

		if (!pathToPlayer.empty()) {
			pathToPlayer.pop_back();
		}
		return false;
	}

	return false;
}

void Enemy::clean()
{
}

std::string Enemy::getObjectState()
{
	if (m_state == EnemyState::DEATH) return "DEATH";
	if (m_state == EnemyState::ATTACK) return "ATTACK";
	if (m_state == EnemyState::HEAVY_ATTACK) return "HEAVY_ATTACK";
	return "NONE";
}

void Enemy::handleMovement()
{
	if (m_velocity.getX() != 0)
	{
		m_state == EnemyState::RUN;
	}
	else if (m_velocity.getX() == 0)
	{
		m_state == EnemyState::IDLE;
	}

	if (m_velocity.getX() >= 0)
		m_bFlip = false;
	else
		m_bFlip = true;
}

void Enemy::handleAnimation()
{
	if (m_state == EnemyState::IDLE)
	{
		m_pTex = TheGame::Instance()->getAssets()->getTexture(TextureType::VAGABOND_IDLE);
		m_currentFrame.x = int(((SDL_GetTicks() / 120) % 2));

		m_currentFrame.w = 64;
		m_currentFrame.h = 64;
	}
	else if (m_state == EnemyState::RUN)
	{
		m_pTex = TheGame::Instance()->getAssets()->getTexture(TextureType::VAGABOND_RUN);
		m_currentFrame.x = int(((SDL_GetTicks() / 120) % 8));

		m_currentFrame.w = 64;
		m_currentFrame.h = 64;
	}
	else if (m_state == EnemyState::ATTACK)
	{
		m_pTex = TheGame::Instance()->getAssets()->getTexture(TextureType::VAGABOND_ATTACK);
		m_currentFrame.x = int(((SDL_GetTicks() / 120) % 15));
		m_currentFrame.w = 256;
		m_currentFrame.h = 128;
		m_velocity.setPos(0, 0);
	}
	else if (m_state == EnemyState::HEAVY_ATTACK)
	{
		m_pTex = TheGame::Instance()->getAssets()->getTexture(TextureType::VAGABOND_HEAVY_ATTACK);
		m_currentFrame.x = int(((SDL_GetTicks() / 120) % 13));
		m_currentFrame.w = 352;
		m_currentFrame.h = 176;
		m_velocity.setPos(0, 0);
	}
	else if (m_state == EnemyState::KNOCKBACK)
	{
		m_pTex = TheGame::Instance()->getAssets()->getTexture(TextureType::VAGABOND_KNOCKBACK);
		m_currentFrame.x = int(((SDL_GetTicks() / 120) % 4));

		m_currentFrame.w = 64;
		m_currentFrame.h = 64;
	}
	else if (m_state == EnemyState::DEATH)
	{
		m_pTex = TheGame::Instance()->getAssets()->getTexture(TextureType::VAGABOND_DEATH);
		m_currentFrame.x = int(((SDL_GetTicks() / 120) % 7));

		m_currentFrame.w = 128;
		m_currentFrame.h = 64;
	}
}