#include "menuButton.hpp"
#include "inputHandler.hpp"
#include "vector2f.hpp"

MenuButton::MenuButton(const LoaderParams *pParams, void (*callback)()) : Entity(pParams), m_callback(callback)
{
	// m_currentFrame.x = MOUSE_OUT; // start at frame 0
}

void MenuButton::draw()
{
}

void MenuButton::update()
{
	// Vector2f *pMousePos = TheInputHandler::Instance()->getMousePosition();

	// if (pMousePos->getX() < (m_pos.getX() + m_currentFrame.w) && pMousePos->getX() > m_pos.getX() && pMousePos->getY() < (m_pos.getY() + m_currentFrame.h) && pMousePos->getY() > m_pos.getY())
	// {
	// 	if (TheInputHandler::Instance()->getMouseButtonState(LEFT))
	// 	{
	// 		m_currentFrame.x = CLICKED;
	// 		m_callback();
	// 		m_bReleased = false;
	// 	}
	// 	else if (!TheInputHandler::Instance()->getMouseButtonState(LEFT))
	// 	{
	// 		m_bReleased = true;
	// 		m_currentFrame.x = MOUSE_OVER;
	// 	}
	// }
	// else
	// {
	// 	m_currentFrame.x = MOUSE_OUT;
	// }
	m_currentFrame.x = 300 * int(((SDL_GetTicks() / 100) % 3));

	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_A))
	{
		m_callback();
	}
}

void MenuButton::clean()
{
}

// void MenuButton::load(const LoaderParams* pParams)
// {
// 	SDLGameObject::load(pParams);
// 	m_callbackID = pParams->getCallbackID();
// 	m_currentFrame = MOUSE_OUT;
// }