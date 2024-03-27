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