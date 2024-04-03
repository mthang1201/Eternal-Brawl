#include <SDL.h>

#include "enemy.hpp"
#include "inputHandler.hpp"

Enemy::Enemy(const LoaderParams* pParams) : Entity(pParams)
{
	m_velocity.setY(2);
	m_velocity.setX(0.001f);
}

void Enemy::draw()
{
}

void Enemy::update()
{
	// m_currentFrame = int(((SDL_GetTicks() / 100) % m_numFrames));

	if (m_pos.getY() < 0)
	{
		m_velocity.setY(2);
	}
	else if (m_pos.getY() > 400)
	{
		m_velocity.setY(-2);
	}

	Entity::update();
}

void Enemy::clean()
{
}