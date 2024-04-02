#pragma once

#include "entity.hpp"
#include "loaderParams.hpp"

enum class PlayerState {
    IDLE,
    MOVING,
    JUMPING,
    FALLING
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
};