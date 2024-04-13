#include "menuButton.hpp"
#include "inputHandler.hpp"
#include "vector2f.hpp"
#include "resourceManager.hpp"

MenuButton::MenuButton(const LoaderParams* pParams, void (*callback)()) : Entity(pParams), m_callback(callback), m_bReleased(false)
{
	m_currentFrame.x = MOUSE_OUT; // start at frame 0
}

void MenuButton::draw()
{
}

void MenuButton::update()
{
	Vector2f* pMousePos = TheInputHandler::Instance()->getMousePosition();

	if (pMousePos->getX() < (m_pos.getX() + m_currentFrame.w) && pMousePos->getX() > m_pos.getX() && pMousePos->getY() < (m_pos.getY() + m_currentFrame.h) && pMousePos->getY() > m_pos.getY())
	{
		if (TheInputHandler::Instance()->getMouseButtonState(LEFT))
		{
			m_currentFrame.x = CLICKED;
			//TheResourceManager::Instance()->playSound(m_pSound, 0);
			TheResourceManager::Instance()->playSound(TheResourceManager::Instance()->loadSound("res/sound/MenuOK.wav"), 0);
			m_callback();
			m_bReleased = false;
		}
		else if (!TheInputHandler::Instance()->getMouseButtonState(LEFT))
		{
			m_bReleased = true;
			m_currentFrame.x = MOUSE_OVER;
		}
	}
	else
	{
		m_currentFrame.x = MOUSE_OUT;
	}

	//if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RETURN))
	//{
	//	//m_currentFrame.x = 400;
	//	m_callback();
	//}/*
	//else if (TheInputHandler::Instan/*ce()->isKeyDown(SDL_SCANCODE_RETURN))
	//{

	//}*/*/
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