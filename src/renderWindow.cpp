#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

#include "renderWindow.hpp"
#include "entity.hpp"

RenderWindow *RenderWindow::s_pInstance = nullptr;

bool RenderWindow::init(const char* title, int width, int height)
{
    if (SDL_Init(SDL_INIT_VIDEO) > 0)
    {
        std::cout << "HEY... SDL_Init HAS FAILED. SDL_ERROR: " << SDL_GetError() << std::endl;
        return false;
    }

    if (!(IMG_Init(IMG_INIT_PNG)))
    {
        std::cout << "IMG_Init has failed. Error: " << SDL_GetError() << std::endl;
        return false;
    }

    if (!(IMG_Init(IMG_INIT_JPG)))
    {
        std::cout << "IMG_Init has failed. Error: " << SDL_GetError() << std::endl;
        return false;
    }

    m_pWindow = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);

    if (m_pWindow == nullptr)
    {
        std::cout << "Window failed to init. Error: " << SDL_GetError() << std::endl;
        return false;
    }

    m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    // Virtual machine
    // renderer = SDL_CreateSoftwareRenderer(SDL_GetWindowSurface(m_pWindow));
    
    if (m_pRenderer == nullptr)
    {
        std::cout << "Renderer failed to init. Error: " << SDL_GetError() << std::endl;
        return false;
    }

    return true;
}

// SDL_Texture* RenderWindow::loadAsset()
// {
    
// }

SDL_Texture* RenderWindow::loadTexture(const char* filePath)
{
    SDL_Texture* texture = nullptr;
    texture = IMG_LoadTexture(m_pRenderer, filePath);

    if (texture == nullptr)
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

void RenderWindow::clean()
{
    SDL_DestroyWindow(m_pWindow);
    SDL_DestroyRenderer(m_pRenderer);
}

void RenderWindow::clear()
{
    SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 0, 255);
    SDL_RenderClear(m_pRenderer);
}

void RenderWindow::draw(Entity& entity)
{
    SDL_Rect src;
    src.x = entity.getCurrentFrame().x;
    src.y = entity.getCurrentFrame().y;
    src.w = entity.getCurrentFrame().w;
    src.h = entity.getCurrentFrame().h;
    
    SDL_Rect dst;
    dst.x = entity.getPos().getX();
    dst.y = entity.getPos().getY();
    dst.w = entity.getCurrentFrame().w;
    dst.h = entity.getCurrentFrame().h;
    
    SDL_RenderCopy(m_pRenderer, entity.getTex(), NULL, &dst);
}

void RenderWindow::drawFrame(Entity& entity)
{
    SDL_Rect src;
    src.x = entity.getCurrentFrame().x;
    src.y = entity.getCurrentFrame().y;
    src.w = entity.getCurrentFrame().w;
    src.h = entity.getCurrentFrame().h;
    
    SDL_Rect dst;
    dst.x = entity.getPos().getX();
    dst.y = entity.getPos().getY();
    dst.w = entity.getCurrentFrame().w * 4;
    dst.h = entity.getCurrentFrame().h * 4;
    
    if (entity.getFlip()) SDL_RenderCopyEx(m_pRenderer, entity.getTex(), &src, &dst, 0, 0, SDL_FLIP_HORIZONTAL);
    else SDL_RenderCopy(m_pRenderer, entity.getTex(), &src, &dst);
}

void RenderWindow::display()
{
    SDL_RenderPresent(m_pRenderer);
    // Virtual machine
    // SDL_UpdateWindowSurface(m_pWindow);
}