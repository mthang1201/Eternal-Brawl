#pragma once
#include <SDL.h>
#include <SDL_image.h>

#include "math.hpp"

class Entity
{
public:
    Entity(Vector2f pos, SDL_Texture* tex);
    Vector2f& getPos()
    {
        return m_pos;
    }
    SDL_Texture* getTex();
    SDL_Rect getCurrentFrame();
private:
    Vector2f m_pos;

    SDL_Rect m_currentFrame;
    SDL_Texture* m_tex;
};