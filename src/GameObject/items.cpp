#include "player.hpp"
#include "entity.hpp"
#include "loaderParams.hpp"
#include "vector2f.hpp"
#include "inputHandler.hpp"

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

    handleInput();
    
    Entity::update();
}

void Player::clean()
{
}