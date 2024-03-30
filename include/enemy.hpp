#pragma once

#include "entity.hpp"

class Enemy : public Entity
{
public:
    Enemy(const LoaderParams* pParams);

    virtual void draw();
    virtual void update();
    virtual void clean();
};