#pragma once
#include <SDL_mixer.h>

#include "entity.hpp"

class Enemy : public Entity
{
public:
    Enemy(const LoaderParams* pParams);

    virtual void draw();
    virtual void update();
    virtual void clean();
    virtual Mix_Chunk* getSound() { return m_pSound; }
};