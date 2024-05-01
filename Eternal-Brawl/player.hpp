#pragma once
#include <SDL_mixer.h>
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
    virtual void collision() {}
    virtual std::string getObjectState();

    int m_lives = 3;
    void revive();
    float healthPoints;
    SDL_Color healthColor;
    SDL_Rect healthBarRect;
    int healthBarWidth;
    
    float agilityPoints;
    SDL_Color agilityColor;
    SDL_Rect agilityBarRect;
    int agilityBarWidth;

    bool inAction = false;
private:
    void checkCollision();
    bool checkCollideTile(float newX, float newY, SDL_Rect tile);
    bool checkCollideTile(Vector2f pos);
    void handleInput();
    void handleMovement(Vector2f velocity);
    void handleAnimation();

    void goku_on_ground();
    void goku_in_air();
    void goku_kick();
    void doDyingAnimation();


    PlayerState m_state;
    PlayerState m_interactWithEnemy;

    float m_moveSpeed = 3;
    SDL_Rect rigidBody;
    int kickCount = 0;
    int idleCounter = 0, walkCounter = 0, jumpCounter = 0, fallingCounter = 0, deathCounter = 0;

    bool grounded = false, running = false, idling = true, jumping = false, falling = true, dead = false, beingHit = false;

    int m_attackTime;
    int m_heavyAttackTime;
    int m_kickTime;
    int m_dyingTime;
    int m_dyingCounter;
    Uint32 m_deathTime;

    int frameTime;
    int startTime;

    bool m_bRunning;
    bool m_bFlying;
    bool m_bMoveRight;
    bool m_bMoveLeft;
    /*bool m_bMoveLeft;
    bool m_bMoveLeft;
    bool m_bMoveLeft;*/

    bool inputLocked1 = false, inputLocked2 = false, inputLocked3 = false;
    
};