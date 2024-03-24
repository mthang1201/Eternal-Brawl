#include "player.hpp"
#include "entity.hpp"
#include "vector2f.hpp"
#include "inputHandler.hpp"

Player::Player(Vector2f pos, SDL_Rect currentFrame, SDL_Texture *pTex) : Entity(pos, currentFrame, pTex)
{
}

void Player::draw()
{
}

void Player::update()
{
    m_velocity.setX(0);
    m_velocity.setY(0);

    handleInput();
    
    Entity::update();
}

void Player::clean()
{
}

void Player::handleInput()
{
    if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT))
    {
        m_velocity.setX(2);
    }
    if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT))
    {
        m_velocity.setX(-2);
    }
    if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP))
    {
        m_velocity.setY(-2);
    }
    if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN))
    {
        m_velocity.setY(2);
    }
}
