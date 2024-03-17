#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

#include "renderWindow.hpp"
#include "entity.hpp"

RenderWindow::RenderWindow(const char* title, int width, int height) : m_pWindow(NULL), m_pRenderer(NULL)
{
    m_pWindow = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);

    if (m_pWindow == nullptr)
    {
        std::cout << "Window failed to init. Error: " << SDL_GetError() << std::endl;
    }

    m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    // Virtual machine
    // renderer = SDL_CreateSoftwareRenderer(SDL_GetWindowSurface(m_pWindow));
}

SDL_Texture* RenderWindow::loadTexture(const char* filePath)
{
    SDL_Texture* texture = NULL;
    texture = IMG_LoadTexture(m_pRenderer, filePath);

    if (texture == NULL)
        std::cout << "Failed to load texture. Error: " << SDL_GetError() << std::endl;
    return texture;
}

int RenderWindow::getRefreshRate()
{
    int displayIndex = SDL_GetWindowDisplayIndex(m_pWindow);

    SDL_DisplayMode mode;

    SDL_GetDisplayMode(displayIndex, 0, &mode);

    return mode.refresh_rate;
}

void RenderWindow::cleanUp()
{
    SDL_DestroyWindow(m_pWindow);
}

void RenderWindow::clear()
{
    SDL_RenderClear(m_pRenderer);
}

void RenderWindow::render(Entity& entity)
{
    SDL_Rect src;
    src.x = entity.getCurrentFrame().x;
    src.y = entity.getCurrentFrame().y;
    src.w = entity.getCurrentFrame().w;
    src.h = entity.getCurrentFrame().h;
    
    SDL_Rect dst;
    dst.x = entity.getPos().m_x * 4;
    dst.y = entity.getPos().m_y * 5;
    dst.w = entity.getCurrentFrame().w * 4;
    dst.h = entity.getCurrentFrame().h * 4;
    
    SDL_RenderCopy(m_pRenderer, entity.getTex(), &src, &dst);
}

void RenderWindow::display()
{
    SDL_RenderPresent(m_pRenderer);
    // Virtual machine
    // SDL_UpdateWindowSurface(m_pWindow);
}
