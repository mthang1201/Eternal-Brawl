#include "player.hpp"
#include "entity.hpp"
#include "loaderParams.hpp"
#include "vector2f.hpp"
#include "inputHandler.hpp"
#include "game.hpp"

Player::Player(const LoaderParams *pParams) : Entity(pParams)
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

    // m_currentFrame.y = 64 * int(((SDL_GetTicks() / 100) % 2));
    changeStates();

    handleInput();

    Entity::update();

    // if (m_velocity.getX() == 0)
    // {
    //     m_state = PlayerState::IDLE;
    // }
    // else if (m_velocity.getX() != 0)
    // {
    //     m_state = PlayerState::MOVING;
    // }
}

void Player::clean()
{
}

void Player::handleInput()
{
    if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT))
    {
        m_velocity.setX(10);
        m_bFlip = false;
        m_state = PlayerState::MOVING;
    }
    if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT))
    {
        m_velocity.setX(-10);
        m_bFlip = true;
        m_state = PlayerState::MOVING;
    }
    if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP))
    {
        m_velocity.setY(-10);
        m_state = PlayerState::JUMPING;
    }
    if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN))
    {
        m_velocity.setY(10);
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
}

void Player::changeStates()
{
    // if (m_state == PlayerState::IDLE)
    // {
        // m_pTex = TheGame::Instance()->getAssets()->getTexture("goku");
        m_currentFrame.x = 48 * int(((SDL_GetTicks() / 100) % 6));
        m_currentFrame.y = 58;
    // }
    // else if (m_state == PlayerState::MOVING)
    // {
        // m_pTex = TheGame::Instance()->getAssets()->getTexture("goku_moving");
        // m_currentFrame.x = 58 * int(((SDL_GetTicks() / 100) % 6));
        // m_currentFrame.y = 58;
    // }
    // else if (m_state == PlayerState::JUMPING)
    // {
    //     m_currentFrame.x = 48 * int(((SDL_GetTicks() / 100) % 6));
    // }
    // else if (m_state == PlayerState::FALLING)
    // {
    //     m_currentFrame.x = 48 * int(((SDL_GetTicks() / 100) % 6));
    // }
}
