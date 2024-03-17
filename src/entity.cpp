#include "entity.hpp"
#include <SDL.h>
#include <SDL_image.h>

Entity::Entity(Vector2f pos, SDL_Texture* tex) : m_pos(pos), m_tex(tex)
{
    m_currentFrame.x = 0;
    m_currentFrame.y = 0;
    m_currentFrame.w = 32;
    m_currentFrame.h = 32;
}



SDL_Texture* Entity::getTex()
{
    return m_tex;
}

SDL_Rect Entity::getCurrentFrame()
{
    return m_currentFrame;
}