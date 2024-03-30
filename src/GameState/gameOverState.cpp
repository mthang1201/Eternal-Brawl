#include <iostream>

#include "gameOverState.hpp"
// #include "MainMenuState.h"
#include "menuState.hpp"
#include "playState.hpp"
#include "game.hpp"
#include "renderWindow.hpp"
#include "animatedGraphic.hpp"
#include "menuButton.hpp"

const std::string GameOverState::s_gameOverID = "GAMEOVER";

void GameOverState::update()
{
	for (int i = 0; i < (int)m_entities.size(); i++)
	{
		m_entities[i]->update();
	}
}

void GameOverState::render()
{
	for (int i = 0; i < (int)m_entities.size(); i++)
	{
		TheRenderWindow::Instance()->drawFrame(*m_entities[i]);
	}
}

bool GameOverState::onEnter()
{
	m_entities.push_back(new AnimatedGraphic(new LoaderParams(Vector2f(200, 100), {0, 0, 190, 30}, TheGame::Instance()->getAssets()->getTexture("gameovertext")), 2));
	m_entities.push_back(new MenuButton(new LoaderParams(Vector2f(200, 200), {0, 0, 200, 80}, TheGame::Instance()->getAssets()->getTexture("mainbutton")), s_gameOverToMain));
	m_entities.push_back(new MenuButton(new LoaderParams(Vector2f(200, 300), {0, 0, 200, 80}, TheGame::Instance()->getAssets()->getTexture("restartbutton")), s_restartPlay));
	std::cout << "entering PauseState\n";

	return true;
}


bool GameOverState::onExit()
{
	for (int i = 0; i < (int)m_entities.size(); i++)
	{
		m_entities[i]->clean();
	}
	
	std::cout << "exiting GameOverState" << std::endl;
	return true;
}

void GameOverState::s_gameOverToMain()
{
	TheGame::Instance()->getStateMachine()->changeState(new MenuState());
}

void GameOverState::s_restartPlay()
{
	TheGame::Instance()->getStateMachine()->changeState(new PlayState());
}