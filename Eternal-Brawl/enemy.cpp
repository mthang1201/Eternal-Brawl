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

void Enemy::update()
{
	/*void Player::jump() {
		if (grounded) {
			m_velocity.setY(m_velocity.getY() - 10);
			grounded = false;
		}
	}*/
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

	Entity::update();

	checkCollision();

	m_rigidBody = { static_cast<int>(m_pos.getX()), static_cast<int>(m_pos.getY()), 64, 64 };
	std::vector<SDL_Rect> m_tiles;
	/*m_tiles.push_back({ 80, 508, 100, 100 });
	m_tiles.push_back({ 400, 350, 100, 80 });*/
	for (SDL_Rect tile : tiles)
	{
		SDL_Rect modifiedTile = { tile.x + 18, tile.y + 18, tile.w - 18, tile.h - 18 };
		SDL_bool isColliding = SDL_HasIntersection(&m_rigidBody, &modifiedTile);

		if (isColliding)
		{
			m_pos.setX(m_pos.getX() - m_velocity.getX());
			m_pos.setY(m_pos.getY() - m_velocity.getY());
		}
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