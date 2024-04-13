#pragma once
#include <SDL.h>
#include <SDL_mixer.h>
#include <string>

#include "vector2f.hpp"
#include "loaderParams.hpp"

class Entity
{
public:
	Entity(const LoaderParams* pParams);
	virtual void draw() = 0;
	virtual void update() = 0;
	virtual void clean() = 0;
	virtual Vector2f getPos() { return m_pos; }
	virtual SDL_Rect getCurrentFrame() { return m_currentFrame; }
	virtual SDL_Texture* getTex() { return m_pTex; }
	virtual bool getFlip() { return m_bFlip; }
	virtual std::string getObjectState() { return ""; }
	virtual Mix_Chunk* getSound() { return m_pSound; }
protected:
	Vector2f m_pos;
	Vector2f m_velocity;
	Vector2f m_acceleration;
	SDL_Rect m_currentFrame;
	SDL_Texture* m_pTex;
	Mix_Chunk* m_pSound;
	bool m_bFlip = false;
};