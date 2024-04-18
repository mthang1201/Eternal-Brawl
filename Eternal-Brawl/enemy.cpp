#include <SDL.h>

#include "enemy.hpp"
#include "inputHandler.hpp"
#include "map.hpp"

const float GRAVITY = 0.5;
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
	}*/
	//else m_velocity.setY(GRAVITY);


	if (m_currentFrame.w == 64) m_currentFrame.x = int(((SDL_GetTicks() / 120) % 5));

	moveTowardsPlayer();

	/*if (m_pos.getX() < 537)
	{
		m_velocity.setX(m_moveSpeed);
	}
	else if (m_pos.getX() > 1048)
	{
		m_velocity.setX(-m_moveSpeed);
	}*/

	if (m_velocity.getX() >= 0)
		m_bFlip = false;
	else
		m_bFlip = true;

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

void Enemy::moveTowardsPlayer()
{
	float length = sqrt(pow(m_playerPos.getX() - m_pos.getX(), 2) + pow(m_playerPos.getY() - m_pos.getY(), 2));
	if (length < 400)
	{
		if (m_pos.getX() < m_playerPos.getX()) {
			m_velocity.setX(m_moveSpeed);
		}
		else if (m_pos.getX() > m_playerPos.getX()) {
			m_velocity.setX(-m_moveSpeed);
		}

		if (m_pos.getY() < m_playerPos.getY()) {
			m_velocity.setY(m_moveSpeed);
		}
		else if (m_pos.getY() > m_playerPos.getY()) {
			m_velocity.setY(-m_moveSpeed);
		}
	}

	static Vector2f currentPlayerPos;
	if (currentPlayerPos != m_playerPos)
	{
		currentPlayerPos = m_playerPos;

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