#include <vector>

#include "menuState.hpp"
#include "renderWindow.hpp"
#include "inputHandler.hpp"
#include "menuButton.hpp"
#include "game.hpp"
#include "playState.hpp"
#include "entity.hpp"
#include "item.hpp"

const std::string MenuState::s_menuID = "MENU";

void MenuState::update()
{
    for (std::vector<Entity *>::size_type i = 0; i < m_entities.size(); i++)
    {
        m_entities[i]->update();
    }
    if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RETURN))
	{
		s_menuToPlay();
	}
}

void MenuState::render()
{
    // for (std::vector<Entity *>::size_type i = 0; i < m_entities.size(); i++)
    // {
    //     TheRenderWindow::Instance()->drawFrame(*m_entities[i]);
    // }
    TheRenderWindow::Instance()->drawFrame(*m_entities[0]);
    TheRenderWindow::Instance()->drawFrame(*m_entities[1]);
}

bool MenuState::onEnter()
{
    m_entities.push_back(new Item(new LoaderParams(Vector2f(100, 100), {0, 0, 400, 100}, TheGame::Instance()->getAssets()->getTexture(TextureType::PLAY_BUTTON))));
    m_entities.push_back(new Item(new LoaderParams(Vector2f(100, 300), {0, 0, 400, 100}, TheGame::Instance()->getAssets()->getTexture(TextureType::EXIT_BUTTON))));
    // m_entities.push_back(new MenuButton(new LoaderParams(Vector2f(100, 100), {0, 0, 400, 100}, TheGame::Instance()->getAssets()->getTexture(TextureType::PLAY_BUTTON)), s_menuToPlay));
    // m_entities.push_back(new MenuButton(new LoaderParams(Vector2f(100, 300), {0, 0, 400, 100}, TheGame::Instance()->getAssets()->getTexture(TextureType::EXIT_BUTTON)), s_exitFromMenu));
    std::cout << "entering MenuState\n";

    return true;
}

// for (vector<Entity *>::size_type i = 0; i < m_entities.size(); i++)
// {
//     m_entities[i]->clean();
// }
bool MenuState::onExit()
{
    while (!m_entities.empty())
    {
        delete m_entities.back();
        m_entities.pop_back();

        // Check if deletion was successful
        if (!m_entities.empty() && m_entities.back() != nullptr)
        {
            std::cerr << "Error: Failed to delete entity\n";
            // return false;
        }
    }
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