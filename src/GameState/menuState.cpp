#include <vector>

#include "menuState.hpp"
#include "renderWindow.hpp"
#include "menuButton.hpp"
#include "game.hpp"
#include "playState.hpp"
#include "entity.hpp"

const std::string MenuState::s_menuID = "MENU";

void MenuState::update()
{
    for (std::vector<Entity *>::size_type i = 0; i < m_entities.size(); i++)
    {
        m_entities[i]->update();
    }
}

void MenuState::render()
{
    for (std::vector<Entity *>::size_type i = 0; i < m_entities.size(); i++)
    {
        TheRenderWindow::Instance()->draw(*m_entities[i]);
    }
}

bool MenuState::onEnter()
{
    m_entities.push_back(new MenuButton(new LoaderParams(Vector2f(100, 100), {0, 0, 400, 100}, TheGame::Instance()->getAssets()->getTexture("playbutton")), s_menuToPlay));
    m_entities.push_back(new MenuButton(new LoaderParams(Vector2f(100, 300), {0, 0, 400, 100}, TheGame::Instance()->getAssets()->getTexture("exitbutton")), s_exitFromMenu));
    std::cout << "entering MenuState\n";

    return true;
}

bool MenuState::onExit()
{
    // for (vector<Entity *>::size_type i = 0; i < m_entities.size(); i++)
    // {
    //     m_entities[i]->clean();
    // }
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