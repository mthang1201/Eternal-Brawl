#include <vector>

#include "menuState.hpp"
#include "resourceManager.hpp"
#include "inputHandler.hpp"
#include "menuButton.hpp"
#include "game.hpp"
#include "playState.hpp"
#include "entity.hpp"
#include "item.hpp"

const std::string MenuState::s_menuID = "MENU";

void MenuState::update()
{
	for (int i = 0; i < (int)m_entities.size(); i++)
	{
		m_entities[i]->update();
	}
}

void MenuState::render()
{
	for (int i = 0; i < (int)m_entities.size(); i++)
	{
		TheResourceManager::Instance()->drawFrame(*m_entities[i]);
	}
}

bool MenuState::onEnter()
{
	m_entities.push_back(new MenuButton(new LoaderParams(Vector2f(100, 100), { 0, 0, 400, 100 }, TheGame::Instance()->getAssets()->getTexture(TextureType::PLAY_BUTTON), nullptr), s_menuToPlay));
	m_entities.push_back(new MenuButton(new LoaderParams(Vector2f(100, 300), { 0, 0, 400, 100 }, TheGame::Instance()->getAssets()->getTexture(TextureType::EXIT_BUTTON), nullptr), s_exitFromMenu));
	
	TheResourceManager::Instance()->playMusic(TheGame::Instance()->getAssets()->getMusic(MusicType::ALLEY), -1);
	
	std::cout << "entering MenuState\n";

	return true;
}

bool MenuState::onExit()
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

	Mix_HaltMusic();

	std::cout << "exiting MenuState\n";
	return true;
}

void MenuState::s_menuToPlay()
{
	TheGame::Instance()->getStateMachine()->changeState(new PlayState());
}
void MenuState::s_exitFromMenu()
{
	TheGame::Instance()->quit();
}