#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>

#include "vector2f.hpp"

class LoaderParams
{
public:
	LoaderParams(Vector2f pos, SDL_Rect currentFrame, SDL_Texture* pTex, Mix_Chunk* pSound);
	Vector2f getPos() const { return m_pos; }
	SDL_Rect getCurrentFrame() const { return m_currentFrame; }
	SDL_Texture* getTex() const { return m_pTex; }
	Mix_Chunk* getSound() const { return m_pSound; }

private:
	Vector2f m_pos;
	SDL_Rect m_currentFrame;
	SDL_Texture* m_pTex;
	Mix_Chunk* m_pSound;
};