#include <iostream>

#include "pauseState.hpp"
#include "game.hpp"
#include "resourceManager.hpp"
#include "inputHandler.hpp"
#include "menuButton.hpp"
#include "menuState.hpp"
#include "entity.hpp"
#include "item.hpp"

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
		TheResourceManager::Instance()->drawFrame(*m_entities[i]);
	}
}

bool PauseState::onEnter()
{
	m_entities.push_back(new MenuButton(new LoaderParams(Vector2f(1000, 100), { 0, 0, 200, 80 }, TheGame::Instance()->getAssets()->getTexture(TextureType::MAIN_BUTTON), nullptr), s_pauseToMain));
	m_entities.push_back(new MenuButton(new LoaderParams(Vector2f(1000, 300), { 0, 0, 200, 80 }, TheGame::Instance()->getAssets()->getTexture(TextureType::RESUME_BUTTON), nullptr), s_resumePlay));

	std::cout << "entering PauseState\n";

	return true;
}

bool PauseState::onExit()
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

	std::cout << "exiting PauseState\n";
	return true;
}

void PauseState::s_resumePlay()
{
	TheGame::Instance()->getStateMachine()->popState();
}

void PauseState::s_pauseToMain()
{
	TheGame::Instance()->getStateMachine()->popState();
	TheGame::Instance()->getStateMachine()->changeState(new MenuState());
}