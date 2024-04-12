#include <SDL.h>
#include <string>

#include "player.hpp"
#include "entity.hpp"
#include "loaderParams.hpp"
#include "vector2f.hpp"
#include "inputHandler.hpp"
#include "game.hpp"

bool zKeyCurrentlyPressed = false;
bool xKeyCurrentlyPressed = false;
bool cKeyCurrentlyPressed = false;
const Uint32 COMBO_RESET_TIME = 3000;
const Uint32 MAX_ACTION_TIME = 1000;

int comboStep = 0; // Track the current combo step
Uint32 lastKeyPressTime = 0; // Track the time of the last key press

Player::Player(const LoaderParams* pParams) : Entity(pParams)
{
	healthPoints = 300;
	frameTime = SDL_GetTicks();
    startTime = SDL_GetTicks();
	//jumpTime = SDL_GetTicks();
	attackTime = SDL_GetTicks();
	heavyAttackTime = SDL_GetTicks();
	kickTime = SDL_GetTicks();
	//transformTime = SDL_GetTicks();
	//throwingObjectTime = SDL_GetTicks();
}

void Player::draw()
{
}

void Player::update()
{
	m_velocity.setX(0);
	m_velocity.setY(0);

	Uint32 currentTime = SDL_GetTicks();
	Uint32 timeElapsed = currentTime - lastKeyPressTime;
	if (timeElapsed < MAX_ACTION_TIME) {
		inAction = true;
	}
	else inAction = false;

	if (healthPoints <= 0) {
		m_state = PlayerState::DEATH;
	}

	if (!inAction)
	{
		m_state = PlayerState::IDLE;
		if (m_pos.getY() < 550) m_state = PlayerState::FLYING_IDLE;
	}

	m_interactWithEnemy = PlayerState::NONE;

	handleInput();

	changeStates();
	
	checkCollision();

	Entity::update();
}

void Player::clean()
{
}

std::string Player::getObjectState()
{
	if (m_state == PlayerState::KI || m_state == PlayerState::TRANSFORM_02) return "KI";
	if (m_state == PlayerState::DEATH) return "DEATH";
	return "NONE";
}

void Player::checkCollision()
{
	if (m_pos.getX() < 0 || m_pos.getX() > 1280 - m_currentFrame.w)
	{
		m_velocity.setX(0);
		m_pos.setX((m_pos.getX() < 0) ? (m_pos.getX() + 1) : (m_pos.getX() - 10));
	}
	if (m_pos.getY() < 0 || m_pos.getY() > 720 - m_currentFrame.h)
	{
		m_velocity.setY(0);
		m_pos.setY((m_pos.getY() < 0) ? (m_pos.getY() + 1) : (m_pos.getY() - 10));
	}
}

void Player::handleInput()
{
	if (!inputLocked1 && !inputLocked2 && !inputLocked3 && m_state != PlayerState::DEATH)
	{
		if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP))
		{
			m_velocity.setY(-5);
			m_state = PlayerState::FLYING_UP;
		}
		if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN))
		{
			m_velocity.setY(5);
			m_state = PlayerState::FLYING_DOWN;
		}
		if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT))
		{
			m_velocity.setX(5);
			m_bFlip = false;
			m_state = PlayerState::FLYING_HORIZONTAL;
		}
		if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT))
		{
			m_velocity.setX(-5);
			m_bFlip = true;
			m_state = PlayerState::FLYING_HORIZONTAL;
		}

		if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_D))
		{
			m_pos.setX(m_pos.getX() + 100);
			m_bFlip = false;
			m_state = PlayerState::TELEPORT;
		}
		if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_A))
		{
			m_pos.setX(m_pos.getX() - 100);
			m_bFlip = true;
			m_state = PlayerState::TELEPORT;
		}
		if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_W))
		{
			m_pos.setY(m_pos.getY() - 100);
			m_state = PlayerState::TELEPORT;
		}
		if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_S))
		{
			m_pos.setY(m_pos.getY() + 100);
			m_state = PlayerState::TELEPORT;
		}

		if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_Z))
		{
			//if (!zKeyCurrentlyPressed) {
				m_state = PlayerState::ATTACK;
			//}
		}
		/*else
		{
			zKeyCurrentlyPressed = false;
		}*/

		if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_X))
		{

			//if (!xKeyCurrentlyPressed) {
				m_state = PlayerState::KICK;
			//}
		}
		/*else
		{
			xKeyCurrentlyPressed = false;
		}*/
	}

	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_C))
	{
		m_state = PlayerState::KI;
		inputLocked1 = true;
	}
	else
	{
		inputLocked1 = false;
	}
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_V))
	{
		m_state = PlayerState::TRANSFORM_01;
		inputLocked2 = true;
	}
	else
	{
		inputLocked2 = false;
	}
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_F))
	{
		m_state = PlayerState::TRANSFORM_02;
		inputLocked3 = true;
	}
	else
	{
		inputLocked3 = false;
	}
}

void Player::changeStates()
{
	if (m_state == PlayerState::IDLE)
	{
		m_pTex = TheGame::Instance()->getAssets()->getTexture(TextureType::GOKU_IDLE);
		m_currentFrame.x = 0;
		m_currentFrame.w = 64;
		m_currentFrame.h = 64;
	}
	else if (m_state == PlayerState::FLYING_IDLE)
	{
		m_pTex = TheGame::Instance()->getAssets()->getTexture(TextureType::GOKU_FLYING_IDLE);
		m_currentFrame.x = 0;
		m_currentFrame.w = 64;
		m_currentFrame.h = 64;
	}
	else if (m_state == PlayerState::FLYING_HORIZONTAL)
	{
		m_pTex = TheGame::Instance()->getAssets()->getTexture(TextureType::GOKU_FLYING_HORIZONTAL);
		m_currentFrame.x = 0;
		m_currentFrame.w = 64;
		m_currentFrame.h = 64;
	}
	else if (m_state == PlayerState::FLYING_UP)
	{
		m_pTex = TheGame::Instance()->getAssets()->getTexture(TextureType::GOKU_FLYING_UP);
		m_currentFrame.x = 0;
		m_currentFrame.w = 64;
		m_currentFrame.h = 64;
	}
	else if (m_state == PlayerState::FLYING_DOWN)
	{
		m_pTex = TheGame::Instance()->getAssets()->getTexture(TextureType::GOKU_FLYING_DOWN);
		m_currentFrame.x = 0;
		m_currentFrame.w = 64;
		m_currentFrame.h = 64;
	}
	else if (m_state == PlayerState::LANDING)
	{
		m_pTex = TheGame::Instance()->getAssets()->getTexture(TextureType::GOKU_LANDING);
		m_currentFrame.x = 0;
		m_currentFrame.w = 64;
		m_currentFrame.h = 64;
	}
	else if (m_state == PlayerState::TELEPORT)
	{
		m_pTex = TheGame::Instance()->getAssets()->getTexture(TextureType::GOKU_TELEPORT);
		m_currentFrame.x = int(((SDL_GetTicks() / 120) % 6));

		m_currentFrame.w = 64;
		m_currentFrame.h = 64;
	}
	else if (m_state == PlayerState::KI && m_interactWithEnemy == PlayerState::NONE)
	{
		m_pTex = TheGame::Instance()->getAssets()->getTexture(TextureType::GOKU_KI);
		m_currentFrame.x = int(((SDL_GetTicks() / 120) % 2)) + 1;

		m_currentFrame.w = 64;
		m_currentFrame.h = 128;
	}
	else if (m_state == PlayerState::ATTACK)
	{
		m_pTex = TheGame::Instance()->getAssets()->getTexture(TextureType::GOKU_HEAVY_ATTACK);
		m_currentFrame.x = int(((SDL_GetTicks() / 120) % 5));

		m_currentFrame.w = 64;
		m_currentFrame.h = 64;
	}
	else if (m_state == PlayerState::HEAVY_ATTACK)
	{
		m_pTex = TheGame::Instance()->getAssets()->getTexture(TextureType::GOKU_HEAVY_ATTACK);
		//m_currentFrame.x = int(((SDL_GetTicks() / 120) % 5));
		if (SDL_GetTicks() - frameTime >= 75) {
			m_currentFrame.x += 1 % 5;
			frameTime = SDL_GetTicks();
		}
		m_currentFrame.w = 64;
		m_currentFrame.h = 64;

		heavyAttackTime = SDL_GetTicks();
	}
	else if (m_state == PlayerState::FLYING_ATTACK)
	{
		goku_kick();
	}
	else if (m_state == PlayerState::KICK)
	{
		goku_kick();
	}
	else if (m_state == PlayerState::KI && m_interactWithEnemy == PlayerState::BEING_ATTACKED_ON_GROUND)
	{
		m_pTex = TheGame::Instance()->getAssets()->getTexture(TextureType::GOKU_DEFEND);
		m_currentFrame.x = 0;
		m_currentFrame.w = 64;
		m_currentFrame.h = 64;
	}
	else if (m_state == PlayerState::KI && m_interactWithEnemy == PlayerState::BEING_ATTACKED_IN_AIR)
	{
		m_pTex = TheGame::Instance()->getAssets()->getTexture(TextureType::GOKU_FLYING_DEFEND);
		m_currentFrame.x = 0;
		m_currentFrame.w = 64;
		m_currentFrame.h = 64;
	}
	else if (m_state == PlayerState::TRANSFORM_01)
	{
		m_pTex = TheGame::Instance()->getAssets()->getTexture(TextureType::GOKU_TRANSFORM_01);
		m_currentFrame.x = int(((SDL_GetTicks() / 120) % 7));

		m_currentFrame.w = 144;
		m_currentFrame.h = 128;
	}
	else if (m_state == PlayerState::TRANSFORM_02)
	{
		m_pTex = TheGame::Instance()->getAssets()->getTexture(TextureType::GOKU_TRANSFORM_02);
		m_currentFrame.x = int(((SDL_GetTicks() / 120) % 10));

		m_currentFrame.w = 64;
		m_currentFrame.h = 128;
		}
	else if (m_state == PlayerState::KNOCKBACK)
	{
		m_pTex = TheGame::Instance()->getAssets()->getTexture(TextureType::GOKU_KNOCKBACK);
		m_currentFrame.x = int(((SDL_GetTicks() / 120) % 2)) + 1;

		m_currentFrame.w = 64;
		m_currentFrame.h = 128;
	}
	else if (m_state == PlayerState::DEATH)
	{
		m_pTex = TheGame::Instance()->getAssets()->getTexture(TextureType::GOKU_DEATH);
		m_currentFrame.x = int(((SDL_GetTicks() / 120) % 5));

		m_currentFrame.w = 64;
		m_currentFrame.h = 64;
	}
}


void Player::goku_on_ground()
{
}

void Player::goku_in_air()
{
}

void Player::goku_kick()
{
	m_pTex = TheGame::Instance()->getAssets()->getTexture(TextureType::GOKU_KICK);

	//Uint32 currentTime = SDL_GetTicks();
	//Uint32 timeElapsed = currentTime - lastKeyPressTime;

	//static bool reset = false;

	//if (timeElapsed < COMBO_RESET_TIME) {
		//lastKeyPressTime = currentTime;
		m_currentFrame.x = int(((SDL_GetTicks() / 120) % 12));
	//}
	/*else
	{
		kickCount = 0;
		m_currentFrame.x = kickCount;*/
		//if (reset) lastKeyPressTime = currentTime;
		//reset = true;
	//}
	m_currentFrame.w = 64;
	m_currentFrame.h = 64;

	xKeyCurrentlyPressed = true;
	inAction = true;
}