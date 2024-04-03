#pragma once
#include <SDL.h>
#include <SDL_image.h>

#include "entity.hpp"

class RenderWindow
{
public:
    static RenderWindow* Instance()
    {
        if (s_pInstance == 0)
        {
            s_pInstance = new RenderWindow();
            return s_pInstance;
        }
        return s_pInstance;
    }

    bool init(const char* title, int width, int height);

    SDL_Texture *loadTexture(const char *filePath);
    int getRefreshRate();
    void clean();
    void clear();
    void draw(Entity &entity);
    void drawFrame(Entity &entity);
    void display();

private:
    RenderWindow() {}
    static RenderWindow *s_pInstance;
    SDL_Window *m_pWindow;
    SDL_Renderer *m_pRenderer;
};

typedef RenderWindow TheRenderWindow;