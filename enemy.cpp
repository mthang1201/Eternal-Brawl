#include <SDL.h>

#include "enemy.hpp"
#include "inputHandler.hpp"

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
	if (m_currentFrame.w == 64) m_currentFrame.x = int(((SDL_GetTicks() / 120) % 5));

	if (m_pos.getX() < 0)
	{
		m_velocity.setX(3);
		m_bFlip = false;
	}
	else if (m_pos.getX() > 720)
	{
		m_velocity.setX(-3);
		m_bFlip = true;
	}

	Entity::update();
}

void Enemy::clean()
{
}