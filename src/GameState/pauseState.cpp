#include <iostream>

#include "pauseState.hpp"
#include "game.hpp"
#include "renderWindow.hpp"
#include "inputHandler.hpp"
#include "menuButton.hpp"
#include "menuState.hpp"

const std::string PauseState::s_pauseID = "PAUSE";

void PauseState::update()
{
	for (int i = 0; i < (int)m_entities.size(); i++)
	{
		m_entities[i]->update();
	}
}

void PauseState::render()
{
	for (int i = 0; i < (int)m_entities.size(); i++)
	{
		m_entities[i]->draw();
	}
}

bool PauseState::onEnter()
{
	m_entities.push_back(new MenuButton(new LoaderParams(Vector2f(100, 300), {0, 0, 400, 100}, TheGame::Instance()->getAssets()->getTexture("mainbutton")), s_pauseToMain));
	m_entities.push_back(new MenuButton(new LoaderParams(Vector2f(100, 300), {0, 0, 400, 100}, TheGame::Instance()->getAssets()->getTexture("resumebutton")), s_resumePlay));
	std::cout << "entering PauseState\n";

	return true;
}

bool PauseState::onExit()
{
	for (int i = 0; i < (int)m_entities.size(); ++i)
	{
		m_entities[i]->clean();
	}

	std::cout << "exiting PauseState\n";
	return true;
}

void PauseState::s_resumePlay()
{
	TheGame::Instance()->getStateMachine()->popState();
}

void PauseState::s_pauseToMain()
{
	TheGame::Instance()->getStateMachine()->changeState(new MenuState());
}