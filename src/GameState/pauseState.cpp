#include <iostream>

#include "pauseState.hpp"
#include "game.hpp"
#include "renderWindow.hpp"
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
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RETURN))
	{
		s_resumePlay();
	}
	else if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE))
	{
		s_pauseToMain();
	}
}

void PauseState::render()
{
	// for (std::vector<Entity *>::size_type i = 0; i < m_entities.size(); i++)
	// {
	//     TheRenderWindow::Instance()->drawFrame(*m_entities[i]);
	// }
	TheRenderWindow::Instance()->draw(*m_entities[0]);
	TheRenderWindow::Instance()->draw(*m_entities[1]);
}

bool PauseState::onEnter()
{
	m_entities.push_back(new Item(new LoaderParams(Vector2f(100, 300), {0, 0, 400, 100}, TheGame::Instance()->getAssets()->getTexture(TextureType::MAIN_BUTTON))));
	m_entities.push_back(new Item(new LoaderParams(Vector2f(100, 300), {0, 0, 400, 100}, TheGame::Instance()->getAssets()->getTexture(TextureType::RESUME_BUTTON))));
	// m_entities.push_back(new MenuButton(new LoaderParams(Vector2f(100, 300), {0, 0, 400, 100}, TheGame::Instance()->getAssets()->getTexture(TextureType::MAIN_BUTTON)), s_pauseToMain));
	// m_entities.push_back(new MenuButton(new LoaderParams(Vector2f(100, 300), {0, 0, 400, 100}, TheGame::Instance()->getAssets()->getTexture(TextureType::RESUME_BUTTON)), s_resumePlay));
	std::cout << "entering PauseState\n";

	return true;
}

bool PauseState::onExit()
{
	// for (int i = 0; i < (int)m_entities.size(); ++i)
	// {
	// 	m_entities[i]->clean();
	// }
	while (!m_entities.empty())
    {
        delete m_entities.back();
        m_entities.pop_back();

        // Check if deletion was successful
        if (!m_entities.empty() && m_entities.back() != nullptr)
        {
            std::cerr << "Error: Failed to delete entity\n";
            return false;
        }
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