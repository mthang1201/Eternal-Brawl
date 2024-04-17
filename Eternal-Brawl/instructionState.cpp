#include <vector>

#include "instructionState.hpp"
#include "resourceManager.hpp"
#include "inputHandler.hpp"
#include "menuButton.hpp"
#include "game.hpp"
#include "playState.hpp"
#include "entity.hpp"
#include "item.hpp"

const std::string InstructionState::s_instructionID = "INSTRUCTION";

void InstructionState::update()
{
	for (int i = 0; i < (int)m_entities.size(); i++)
	{
		m_entities[i]->update();
	}
}

void InstructionState::render()
{
	for (int i = 0; i < (int)m_entities.size(); i++)
	{
		TheResourceManager::Instance()->drawFrame(*m_entities[i]);
	}
}

bool InstructionState::onEnter()
{
	m_entities.push_back(new Item(new LoaderParams(Vector2f(0, 0), { 0, 0, 1280, 720 }, TheGame::Instance()->getAssets()->getTexture(TextureType::INSTRUCTION_BACKGROUND), nullptr)));
	m_entities.push_back(new MenuButton(new LoaderParams(Vector2f(540, 600), { 0, 0, 200, 80 }, TheGame::Instance()->getAssets()->getTexture(TextureType::MAIN_BUTTON), TheGame::Instance()->getAssets()->getSound(SoundType::MENU_OK)), s_resumeMenu));

	std::cout << "entering InstructionState\n";

	return true;
}

bool InstructionState::onExit()
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

	std::cout << "exiting InstructionState\n";
	return true;
}

void InstructionState::s_resumeMenu()
{
	TheGame::Instance()->getStateMachine()->popState();
}