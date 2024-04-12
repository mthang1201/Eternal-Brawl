#include "inputHandler.hpp"
#include "game.hpp"
#include "vector2f.hpp"

InputHandler *InputHandler::s_pInstance = nullptr;

Vector2f *m_mouseposition = 0;

InputHandler::InputHandler()
{
    for (int i = 0; i < 3; i++)
    {
        m_mouseButtonStates.push_back(false);
    }
    m_mousePosition = new Vector2f(0, 0);
}

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
        case SDL_MOUSEBUTTONDOWN:
            onMouseButtonDown();
            break;
        case SDL_MOUSEBUTTONUP:
            onMouseButtonUp();
            break;
        case SDL_MOUSEMOTION:
            onMouseMotion();
            break;
        default:
            break;
        }
    }
}

void InputHandler::clean()
{
}

void InputHandler::onKeyDown()
{
    m_keystates = SDL_GetKeyboardState(NULL);
}

void InputHandler::onKeyUp()
{
    m_keystates = SDL_GetKeyboardState(NULL);
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

bool InputHandler::isKeyUp(SDL_Scancode key)
{
}

bool InputHandler::getMouseButtonState(int buttonNumber)
{
	return m_mouseButtonStates[buttonNumber];
}

void InputHandler::onMouseButtonDown()
{
	if (m_event.button.button == SDL_BUTTON_LEFT)
	{
		m_mouseButtonStates[LEFT] = true;
	}
	if (m_event.button.button == SDL_BUTTON_MIDDLE)
	{
		m_mouseButtonStates[MIDDLE] = true;
	}
	if (m_event.button.button == SDL_BUTTON_RIGHT)
	{
		m_mouseButtonStates[RIGHT] = true;
	}
}

void InputHandler::onMouseButtonUp()
{
	if (m_event.button.button == SDL_BUTTON_LEFT)
	{
		m_mouseButtonStates[LEFT] = false;
	}
	if (m_event.button.button == SDL_BUTTON_MIDDLE)
	{
		m_mouseButtonStates[MIDDLE] = false;
	}
	if (m_event.button.button == SDL_BUTTON_RIGHT)
	{
		m_mouseButtonStates[RIGHT] = false;
	}
}

Vector2f* InputHandler::getMousePosition()
{
	return m_mousePosition;
}

void InputHandler::onMouseMotion()
{
	m_mousePosition->setX(m_event.motion.x);
	m_mousePosition->setY(m_event.motion.y);
}