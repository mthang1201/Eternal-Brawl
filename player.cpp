#include "player.hpp"
#include "entity.hpp"
#include "loaderParams.hpp"
#include "vector2f.hpp"
#include "inputHandler.hpp"
#include "game.hpp"

bool xKeyCurrentlyPressed = false;
const Uint32 COMBO_RESET_TIME = 1000; // 1000 ms or 1 second

int comboStep = 0; // Track the current combo step
Uint32 lastKeyPressTime = 0; // Track the time of the last key press

Player::Player(const LoaderParams* pParams) : Entity(pParams)
{
}

void Player::draw()
{
}

void Player::update()
{
	m_velocity.setX(0);
	m_velocity.setY(0);
	m_state = PlayerState::IDLE;

	// if (m_currentFrame.x <= 320) m_currentFrame.x += 64;
	// else m_currentFrame.x -= 320;

	handleInput();

	//m_currentFrame.x = int(((SDL_GetTicks() / 120) % 2));
	changeStates();

	Entity::update();
}

void Player::clean()
{
}

void Player::handleInput()
{
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT))
	{
		m_velocity.setX(5);
		m_bFlip = false;
		m_state = PlayerState::RUN;
	}
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT))
	{
		m_velocity.setX(-5);
		m_bFlip = true;
		m_state = PlayerState::RUN;
	}
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP))
	{
		m_velocity.setY(-5);
		m_state = PlayerState::JUMPING;
	}
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN))
	{
		m_velocity.setY(5);
		m_state = PlayerState::FALLING;
	}
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_D))
	{
		m_pos.setX(m_pos.getX() + 100);
		m_bFlip = false;
	}
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_A))
	{
		m_pos.setX(m_pos.getX() - 100);
		m_bFlip = true;
	}
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_W))
	{
		m_pos.setY(m_pos.getY() - 100);
	}
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_S))
	{
		m_pos.setY(m_pos.getY() + 100);
	}

	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_X))
	{

		if (!xKeyCurrentlyPressed) {
			m_state = PlayerState::KICK;
			//performAttack();
		}
		else {
			m_state = PlayerState::IDLE2;
		}
	}
	else xKeyCurrentlyPressed = false;
	/*else if (TheInputHandler::Instance()->isKeyUp(SDL_SCANCODE_X))
	{
		xKeyReleased = true;
	}*/
}

void Player::changeStates()
{
	if (m_state == PlayerState::IDLE)
	{
		m_pTex = TheGame::Instance()->getAssets()->getTexture(TextureType::GOKU_IDLE2);
		m_currentFrame.x = 0;

		m_currentFrame.w = 64;
		m_currentFrame.h = 64;
		//m_currentFrame.x = int(((SDL_GetTicks() / 120) % 1));
	}
	else if (m_state == PlayerState::RUN)
	{
		m_pTex = TheGame::Instance()->getAssets()->getTexture(TextureType::GOKU_FLYING_HORIZONTAL);
		m_currentFrame.x = 0;

		m_currentFrame.w = 64;
		m_currentFrame.h = 64;
	}
	else if (m_state == PlayerState::JUMPING)
	{
		m_pTex = TheGame::Instance()->getAssets()->getTexture(TextureType::GOKU_FLYING_UP);
		m_currentFrame.x = 0;

		m_currentFrame.w = 64;
		m_currentFrame.h = 64;
	}
	else if (m_state == PlayerState::FALLING)
	{
		m_pTex = TheGame::Instance()->getAssets()->getTexture(TextureType::GOKU_FLYING_DOWN);
		m_currentFrame.x = 0;

		m_currentFrame.w = 64;
		m_currentFrame.h = 64;
	}
	else if (m_state == PlayerState::KICK)
	{
		m_pTex = TheGame::Instance()->getAssets()->getTexture(TextureType::GOKU_KICK);

		Uint32 currentTime = SDL_GetTicks();
		Uint32 timeElapsed = currentTime - lastKeyPressTime;

		// If time elapsed is less than the reset threshold, progress the combo
		if (!xKeyCurrentlyPressed) {
			if (timeElapsed < COMBO_RESET_TIME) {
				lastKeyPressTime = currentTime;
				kickCount++;
				xKeyCurrentlyPressed = true;
			}
		}
		m_currentFrame.x = int((kickCount % 12));

		m_currentFrame.w = 64;
		m_currentFrame.h = 64;
	}
}
