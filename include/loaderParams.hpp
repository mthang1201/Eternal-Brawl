#pragma once
#include <SDL.h>
#include <SDL_image.h>

#include "vector2f.hpp"

class LoaderParams
{
public:
    LoaderParams(Vector2f pos, SDL_Rect currentFrame, SDL_Texture *pTex);
    Vector2f getPos() const { return m_pos; }
    SDL_Rect getCurrentFrame() const { return m_currentFrame; }
    SDL_Texture *getTex() const { return m_pTex; }

private:
    Vector2f m_pos;
    SDL_Rect m_currentFrame;
    SDL_Texture *m_pTex;
};