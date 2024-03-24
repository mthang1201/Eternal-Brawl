#pragma once
#include <SDL.h>

#include "vector2f.hpp"

class Entity
{
public:
    Entity(Vector2f pos, SDL_Rect currentFrame, SDL_Texture *pTex);
    virtual void draw()=0;
    virtual void update()=0;
    virtual void clean()=0;
    virtual Vector2f getPos() { return m_pos; }
    virtual SDL_Rect getCurrentFrame() { return m_currentFrame; }
    virtual SDL_Texture* getTex() { return m_pTex; }
protected:
    Vector2f m_pos;
    Vector2f m_velocity;
    Vector2f m_acceleration;
    SDL_Rect m_currentFrame;
    SDL_Texture* m_pTex;
};