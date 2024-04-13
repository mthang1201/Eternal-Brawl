#include <SDL.h>

#include "enemy.hpp"
#include "inputHandler.hpp"

const float GRAVITY = 0.3;
const float MAX_GRAVITY = 15;

Enemy::Enemy(const LoaderParams* pParams) : Entity(pParams)
{
	m_velocity.setX(3);
	m_velocity.setY(0);
}

void Enemy::draw()
{
}

void Enemy::update()
{
	if (!grounded) {
		m_velocity.setY(m_velocity.getY() + GRAVITY);
		if (m_velocity.getY() > MAX_GRAVITY) m_velocity.setY(MAX_GRAVITY);
	}
	else m_velocity.setY(GRAVITY);


	if (m_currentFrame.w == 64) m_currentFrame.x = int(((SDL_GetTicks() / 120) % 5));

	if (m_pos.getX() < 500)
	{
		m_velocity.setX(3);
		m_bFlip = false;
	}
	else if (m_pos.getX() > 900)
	{
		m_velocity.setX(-3);
		m_bFlip = true;
	}

	checkCollision();

	Entity::update();
}

void Enemy::checkCollision()
{
	if (m_pos.getX() < 0 || m_pos.getX() > 1280 - m_currentFrame.w)
	{
		m_velocity.setX(0);
		m_pos.setX((m_pos.getX() < 0) ? (m_pos.getX() + m_moveSpeed) : (m_pos.getX() - m_moveSpeed));
	}
	if (m_pos.getY() < 0 || m_pos.getY() > 720 - m_currentFrame.h)
	{
		m_velocity.setY(0);
		m_pos.setY((m_pos.getY() < 0) ? (m_pos.getY() + m_moveSpeed) : (m_pos.getY() - m_moveSpeed));
	}
}


void Enemy::clean()
{
}