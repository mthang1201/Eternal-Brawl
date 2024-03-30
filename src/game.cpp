#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <vector>

#include "game.hpp"
#include "renderWindow.hpp"
#include "entity.hpp"
#include "player.hpp"
#include "item.hpp"
#include "utils.hpp"
#include "inputHandler.hpp"
#include "loaderAssets.hpp"
#include "menuState.hpp"
#include "playState.hpp"

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720

Game *Game::s_pInstance = nullptr;

bool Game::init()
{
    if (TheRenderWindow::Instance()->init("GAME v1.0", SCREEN_WIDTH, SCREEN_HEIGHT))
    {
        m_pAssets = new LoaderAssets();
        m_pAssets->loadTextures();
        m_pGameStateMachine = new GameStateMachine();
        m_pGameStateMachine->changeState(new PlayState());

        return true;
    }
    return false;
}

void Game::handleEvents()
{
    TheInputHandler::Instance()->update();
    if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RETURN))
    {
        m_pGameStateMachine->changeState(new PlayState());
    }
}

void Game::update()
{
    m_pGameStateMachine->update();
    // for (std::vector<Entity *>::size_type i = 0; i != m_entities.size(); i++)
    // {
    //     m_entities[i]->update();
    // }
}

void Game::render()
{
    TheRenderWindow::Instance()->clear();
    m_pGameStateMachine->render();
    // for (std::vector<Entity *>::size_type i = 0; i != m_entities.size(); i++)
    // {
    //     TheRenderWindow::Instance()->drawFrame(*m_entities[i]);
    // }
    // TheRenderWindow::Instance()->draw(*m_entities[0]);
    // TheRenderWindow::Instance()->draw(*m_entities[1]);
    // TheRenderWindow::Instance()->draw(*m_entities[2]);
    // TheRenderWindow::Instance()->draw(*m_entities[3]);
    // TheRenderWindow::Instance()->draw(*m_entities[4]);
    // TheRenderWindow::Instance()->draw(*m_entities[5]);
    // TheRenderWindow::Instance()->draw(*m_entities[6]);
    // TheRenderWindow::Instance()->draw(*m_entities[7]);
    // TheRenderWindow::Instance()->draw(*m_entities[8]);
    // TheRenderWindow::Instance()->draw(*m_entities[9]);
    // TheRenderWindow::Instance()->draw(*m_entities[10]);
    // TheRenderWindow::Instance()->draw(*m_entities[11]);
    // TheRenderWindow::Instance()->draw(*m_entities[12]);
    // TheRenderWindow::Instance()->draw(*m_entities[13]);
    // TheRenderWindow::Instance()->drawFrame(*m_entities[14]);
    // TheRenderWindow::Instance()->draw(ground_grass1);
}

void Game::display()
{
    TheRenderWindow::Instance()->display();
}

void Game::pause(int &frameTicks)
{
    if (frameTicks < 1000 / TheRenderWindow::Instance()->getRefreshRate())
        SDL_Delay(1000 / TheRenderWindow::Instance()->getRefreshRate() - frameTicks);
}

void Game::clean()
{
    TheRenderWindow::Instance()->clean();
    SDL_Quit();
}