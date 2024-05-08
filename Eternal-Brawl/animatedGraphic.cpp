#include <SDL.h>

#include "animatedGraphic.hpp"

AnimatedGraphic::AnimatedGraphic(const LoaderParams* pParams, int animSpeed) : Entity(pParams), m_animSpeed(animSpeed) 
{
}

void AnimatedGraphic::draw()
{
}

void AnimatedGraphic::update()
{
	 m_currentFrame.x = int(((SDL_GetTicks() / (1000 / m_animSpeed)) % 2/*m_numFrames*/));
}

void AnimatedGraphic::clean()
{
}