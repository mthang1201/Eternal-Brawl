#pragma once
#include <SDL.h>
#include <SDL_image.h>

#include "entity.hpp"

class RenderWindow
{
public:
    RenderWindow(const char* title, int width, int height);
    SDL_Texture* loadTexture(const char* filePath);
    
    int getRefreshRate();
    
    void cleanUp();
    void clear();
    void render(Entity& entity);
    void display();
private:
    SDL_Window* m_pWindow;
    SDL_Renderer* m_pRenderer;
};