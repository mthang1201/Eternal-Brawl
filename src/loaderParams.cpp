#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

#include "loaderParams.hpp"
#include "vector2f.hpp"

LoaderParams::LoaderParams(Vector2f pos, SDL_Rect currentFrame, SDL_Texture *pTex) : m_pos(pos), m_currentFrame(currentFrame), m_pTex(pTex)
{    
}
