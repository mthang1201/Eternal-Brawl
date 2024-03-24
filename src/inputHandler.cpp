#include "inputHandler.hpp"
#include "game.hpp"

InputHandler *InputHandler::s_pInstance = nullptr;

void InputHandler::update()
{
    while (SDL_PollEvent(&m_event))
    {
        switch (m_event.type)
        {
            case SDL_QUIT:
                TheGame::Instance()->quit();
                break;
            case SDL_KEYDOWN:
                onKeyDown();
                break;
            case SDL_KEYUP:
                onKeyUp();
                break;
            default:
                break;
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
