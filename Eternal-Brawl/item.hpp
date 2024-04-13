#pragma once
#include <SDL.h>
#include <iostream>

#include "entity.hpp"
#include "loaderParams.hpp"

class Item : public Entity
{
public:
    Item(const LoaderParams* pParams);

    virtual void draw();
    virtual void update();
    virtual void clean();
};