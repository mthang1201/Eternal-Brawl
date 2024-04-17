#include <SDL.h>

#include "enemy.hpp"
#include "inputHandler.hpp"
#include "map.hpp"

const float GRAVITY = 0.3;
const float MAX_GRAVITY = 15;

Enemy::Enemy(const LoaderParams* pParams) : Entity(pParams)
{
	m_velocity.setX(3);
	m_velocity.setY(0);
	healthPoints = 300;
}

void Enemy::draw()
{
}

const int HEALTHBAR_WIDTH = 200;
const int HEALTHBAR_HEIGHT = 10;

void Enemy::update()
{
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
	/*if (!grounded) {
		m_velocity.setY(m_velocity.getY() + GRAVITY);
		if (m_velocity.getY() > MAX_GRAVITY) m_velocity.setY(MAX_GRAVITY);
	}
	else m_velocity.setY(GRAVITY);*/


	if (m_currentFrame.w == 64) m_currentFrame.x = int(((SDL_GetTicks() / 120) % 5));

	if (m_pos.getX() < 156)
	{
		m_velocity.setX(3);
		m_bFlip = false;
	}
	else if (m_pos.getX() > 1048)
	{
		m_velocity.setX(-3);
		m_bFlip = true;
	}

	Entity::update();

	checkCollision();

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
				m_pos.setY(572 - 15);
				m_velocity.setX(m_moveSpeed);
			}
			//bottomDownElevator
			else if (tile.x == 106 && tile.y == 568 && tile.w == 50 && tile.h == 192)
			{
				m_pos.setX(179 + m_moveSpeed * 3);
				m_pos.setY(197 - 15);
				m_velocity.setX(m_moveSpeed * 5);
			}
			//topRightElevator
			else if (tile.x == 1048 && tile.y == 399 && tile.w == 72 && tile.h == 60)
			{
				m_pos.setX(984 - m_moveSpeed * 3);
				m_pos.setY(622 - 15);
				m_velocity.setX(-m_moveSpeed * 5);
			}
			//bottomRightElevator
			else if (tile.x == 1048 && tile.y == 629 && tile.w == 72 && tile.h == 51)
			{
				m_pos.setX(984 - m_moveSpeed * 3);
				m_pos.setY(402 - 15);
				m_velocity.setX(-m_moveSpeed * 5);
			}
			else
			{
				m_pos.setX(m_pos.getX() - m_velocity.getX());
				m_pos.setY(m_pos.getY() - m_velocity.getY());
			}
			grounded = true;
		}
	}

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
}


void Enemy::clean()
{
}

std::string Enemy::getObjectState()
{
	/*if (m_state == EnemyState::KI || m_state == EnemyState::TRANSFORM_02) return "KI";
	if (m_state == EnemyState::DEATH) return "DEATH";
	if (m_state == EnemyState::ATTACK || m_state == EnemyState::KICK) return "ATTACK";
	if (m_state == EnemyState::HEAVY_ATTACK) return "HEAVY_ATTACK";*/
	return "NONE";
}