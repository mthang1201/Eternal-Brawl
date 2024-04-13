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

private:
    void checkCollision();

    int m_health;
    float m_moveSpeed = 5;
    int idleCounter = 0, walkCounter = 0, fallingCounter = 0, attackingCounter = 0, beingHitCounter = 0;
    bool grounded = true, walking = false, idling = true, falling = false, attacking = false, beingHit = false, dead = false;
};