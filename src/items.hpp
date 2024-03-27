#pragma once
#include <SDL.h>
#include <iostream>

#include "entity.hpp"
#include "loaderParams.hpp"

class Items : public Entity
{
public:
    Items(Vector2f pos, SDL_Rect currentFrame, SDL_Texture *pTex);

    virtual void draw();
    virtual void update();
    virtual void clean();
};

class GroundEntity : public Entity {
public:
    GroundEntity(const Vector2f& position, const Rect& bounds, EntityType type) 
        : Entity(position, bounds, type) {
        // Additional initialization specific to GroundEntity
    }

    // Implement any pure virtual functions from the Entity class
    void draw() override {
        // Code to draw the ground entity
    }
};