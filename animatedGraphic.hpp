#pragma once

#include "entity.hpp"

class AnimatedGraphic : public Entity
{
public:
    AnimatedGraphic(const LoaderParams *pParams, int animSpeed);

    void update();
    void draw();
    void clean();

private:
    int m_animSpeed;
};