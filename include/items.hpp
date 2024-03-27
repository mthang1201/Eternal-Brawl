#pragma once
#include <SDL.h>
#include <iostream>

#include "entity.hpp"
#include "loaderParams.hpp"

class Items : public Entity
{
public:
    Items(const LoaderParams* pParams);

    virtual void draw();
    virtual void update();
    virtual void clean();
};