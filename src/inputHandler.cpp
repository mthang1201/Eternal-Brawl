#include "inputHandler.hpp"
#include "game.hpp"

InputHandler *InputHandler::s_pInstance = nullptr;

void InputHandler::update()
{
    while (SDL_PollEvent(&m_event))
    {
        if (m_event.type == SDL_QUIT || (m_event.type == SDL_KEYDOWN && m_event.key.keysym.sym == SDLK_ESCAPE))
        {
            TheGame::Instance()->quit();
        }
        if (m_event.type == SDL_KEYDOWN)
        {
            onKeyDown();
        }
        if (m_event.type == SDL_KEYUP)
        {
            onKeyUp();
        }
    }
}

void InputHandler::onKeyDown()
{
    m_keystates = SDL_GetKeyboardState(0);
}

void InputHandler::onKeyUp()
{
}

bool InputHandler::isKeyDown(SDL_Scancode key)
{
    if (m_keystates != 0)
    {
        if (m_keystates[key] == 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    return false;
}

void InputHandler::clean()
{
}
