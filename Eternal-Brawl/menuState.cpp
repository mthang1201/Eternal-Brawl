#include <vector>

#include "menuState.hpp"
#include "resourceManager.hpp"
#include "inputHandler.hpp"
#include "menuButton.hpp"
#include "game.hpp"
#include "playState.hpp"
#include "instructionState.hpp"
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
	m_entities.push_back(new Item(new LoaderParams(Vector2f(0, 0), { 0, 0, 1280, 720 }, TheGame::Instance()->getAssets()->getTexture(TextureType::MENU_BACKGROUND), nullptr)));
	m_entities.push_back(new MenuButton(new LoaderParams(Vector2f(100, 100), { 0, 0, 400, 100 }, TheGame::Instance()->getAssets()->getTexture(TextureType::PLAY_BUTTON), TheGame::Instance()->getAssets()->getSound(SoundType::MENU_OK)), s_menuToPlay));
	m_entities.push_back(new MenuButton(new LoaderParams(Vector2f(100, 300), { 0, 0, 400, 100 }, TheGame::Instance()->getAssets()->getTexture(TextureType::INSTRUCTION_BUTTON), TheGame::Instance()->getAssets()->getSound(SoundType::MENU_OK)), s_menuToInstruction));
	m_entities.push_back(new MenuButton(new LoaderParams(Vector2f(100, 500), { 0, 0, 400, 100 }, TheGame::Instance()->getAssets()->getTexture(TextureType::EXIT_BUTTON), TheGame::Instance()->getAssets()->getSound(SoundType::MENU_OK)), s_exitFromMenu));
	//TheResourceManager::Instance()->playMusic(TheGame::Instance()->getAssets()->getMusic(MusicType::ALLEY), -1);
	TheResourceManager::Instance()->playMusic(TheResourceManager::Instance()->loadMusic("res/music/Alley.mp3"), -1);

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

void MenuState::s_menuToInstruction()
{
	TheGame::Instance()->getStateMachine()->pushState(new InstructionState());
}

void MenuState::s_exitFromMenu()
{
	TheGame::Instance()->quit();
}