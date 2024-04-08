#include <SDL.h>
#include <SDL_image.h>

#include "loaderParams.hpp"
#include "vector2f.hpp"

LoaderParams::LoaderParams(Vector2f pos, SDL_Rect currentFrame, SDL_Texture *pTex)
{
    m_pos.setX(pos.getX());
    m_pos.setY(pos.getY());
    m_currentFrame.x = currentFrame.x;
    m_currentFrame.y = currentFrame.y;
    m_currentFrame.w = currentFrame.w;
    m_currentFrame.h = currentFrame.h;
    m_pTex = pTex;
}
