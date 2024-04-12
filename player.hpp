#pragma once
#include <string>

#include "entity.hpp"
#include "loaderParams.hpp"

enum class PlayerState {
    IDLE,
    IDLE2,
    FLYING_IDLE,
    ON_GROUND,
    IN_AIR,

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

    NONE,
    BEING_ATTACKED_ON_GROUND,
    BEING_ATTACKED_IN_AIR,
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
    virtual std::string getObjectState();
    int healthPoints;
    bool inAction = false;
private:
    void checkCollision();
    void handleInput();
    void changeStates();

    void goku_on_ground();
    void goku_in_air();
    void goku_kick();
    


    PlayerState m_state;
    PlayerState m_interactWithEnemy;
    int kickCount = 0;
    
    int attackTime;
    int heavyAttackTime;
    int kickTime;
    int frameTime;
    int startTime;

    bool inputLocked1 = false, inputLocked2 = false, inputLocked3 = false;
    
};