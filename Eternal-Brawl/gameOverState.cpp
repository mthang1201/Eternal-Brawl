#include <iostream>

#include "gameOverState.hpp"
// #include "MainMenuState.h"
#include "menuState.hpp"
#include "playState.hpp"
#include "game.hpp"
#include "resourceManager.hpp"
#include "animatedGraphic.hpp"
#include "menuButton.hpp"
#include "item.hpp"

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
		TheResourceManager::Instance()->drawFrame(*m_entities[i]);
	}
}

bool GameOverState::onEnter()
{
	m_entities.push_back(new Item(new LoaderParams(Vector2f(0, 0), { 0, 0, 1280, 720 }, TheGame::Instance()->getAssets()->getTexture(TextureType::BACKGROUND_BLUR), nullptr)));
	m_entities.push_back(new AnimatedGraphic(new LoaderParams(Vector2f(200, 100), { 0, 0, 190, 30 }, TheGame::Instance()->getAssets()->getTexture(TextureType::GAME_OVER_TEXT), nullptr), 2));
	m_entities.push_back(new MenuButton(new LoaderParams(Vector2f(540, 380), { 0, 0, 200, 80 }, TheGame::Instance()->getAssets()->getTexture(TextureType::MAIN_BUTTON), TheGame::Instance()->getAssets()->getSound(SoundType::MENU_OK)), s_gameOverToMain));
	m_entities.push_back(new MenuButton(new LoaderParams(Vector2f(540, 180), { 0, 0, 200, 80 }, TheGame::Instance()->getAssets()->getTexture(TextureType::RESTART_BUTTON), TheGame::Instance()->getAssets()->getSound(SoundType::MENU_OK)), s_restartPlay));
	std::cout << "entering PauseState\n";

	return true;
}


bool GameOverState::onExit()
{
	while (!m_entities.empty())
	{
		delete m_entities.back();
		m_entities.pop_back();

	}

	if (!m_entities.empty() && m_entities.back() != nullptr)
	{
		std::cerr << "Error: Failed to delete entity\n";
		return false;
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