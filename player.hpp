#pragma once

#include "entity.hpp"
#include "loaderParams.hpp"

enum class PlayerState {
    IDLE,
    IDLE2,
    FLYING_IDLE,
    ON_GROUND,
    ON_AIR,

    KI,
    TRANSFORM_01,
    TRANSFORM_02,

    RUN,
    TELEPORT,
    JUMPING,
    FALLING,

    FLYING_HORIZONTAL,
    FLYING_UP,
    FLYING_DOWN,
    LANDING,

    ATTACK,
    HEAVY_ATTACK,
    FLYING_ATTACK,
    KICK,
    DEFEND,
    FLYING_DEFEND,

    KNOCKBACK,
    DEATH,
};

class Player : public Entity
{
public:
    Player(const LoaderParams* pParams);

    virtual void draw();
    virtual void update();
    virtual void clean();
private:
    void handleInput();
    void changeStates();
    PlayerState m_state;
    int kickCount = 0;
};