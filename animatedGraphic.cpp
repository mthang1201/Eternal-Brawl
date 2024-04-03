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
	// m_currentFrame = int(((SDL_GetTicks() / (1000 / m_animSpeed)) % m_numFrames));
}

void AnimatedGraphic::clean()
{
}