#pragma once
#include <SDL.h>
#include <iostream>

#include "entity.hpp"
#include "loaderParams.hpp"

class TileLayer : public Entity
{
public:
    TileLayer(const LoaderParams* pParams);

    virtual void draw();
    virtual void update();
    virtual void clean();
};