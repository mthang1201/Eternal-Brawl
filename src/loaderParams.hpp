#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <vector>

#include "vector2f.hpp"

class LoaderParams
{
public:
    LoaderParams(Vector2f pos, SDL_Rect currentFrame, SDL_Texture* pTex);
    Vector2f& getPos() { return m_pos; }
    SDL_Rect getCurrentFrame() { return m_currentFrame; }
    SDL_Texture* getTex() { return m_pTex; }
private:
    Vector2f m_pos;
    SDL_Rect m_currentFrame;
    SDL_Texture* m_pTex;
};