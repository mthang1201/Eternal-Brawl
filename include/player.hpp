#pragma once

#include "entity.hpp"
#include "loaderParams.hpp"

class Player : public Entity
{
public:
    Player(const LoaderParams* pParams);

    virtual void draw();
    virtual void update();
    virtual void clean();
private:
    void handleInput();
};