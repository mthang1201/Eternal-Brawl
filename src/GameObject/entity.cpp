#include <SDL.h>
#include <SDL_image.h>

#include "entity.hpp"
#include "vector2f.hpp"
#include "loaderParams.hpp"

Entity::Entity(const LoaderParams* pParams)
{
    m_pos.setX(pParams->getPos().getX());
    m_pos.setY(pParams->getPos().getY());
    m_currentFrame.w = pParams->getCurrentFrame().w;
    m_currentFrame.h = pParams->getCurrentFrame().h;
    m_pTex = pParams->getTex();
}

void Entity::update()
{
	m_velocity += m_acceleration;
	m_pos += m_velocity;
}