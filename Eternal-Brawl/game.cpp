#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <vector>

#include "game.hpp"
#include "resourceManager.hpp"
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

Game::Game() : m_pAssets(nullptr), m_pGameStateMachine(nullptr)
{
}

bool Game::init()
{
    if (TheResourceManager::Instance()->init("Eternal Brawl", SCREEN_WIDTH, SCREEN_HEIGHT))
    {
        std::cout << "Refresh Rate: " << TheResourceManager::Instance()->getRefreshRate() << std::endl;
        m_pAssets = new LoaderAssets();
        m_pGameStateMachine = new GameStateMachine();
        m_pGameStateMachine->pushState(new MenuState());

        return true;
    }
    return false;
}

void Game::handleEvents()
{
    TheInputHandler::Instance()->update();
}

void Game::update()
{
    m_pGameStateMachine->update();
}

void Game::render()
{
    TheResourceManager::Instance()->clear();
    m_pGameStateMachine->render();
}

void Game::display()
{
    TheResourceManager::Instance()->display();
}

void Game::pause(int &frameTicks)
{
    if (frameTicks < 1000 / TheResourceManager::Instance()->getRefreshRate())
        SDL_Delay(1000 / TheResourceManager::Instance()->getRefreshRate() - frameTicks);
}

void Game::clean()
{
    delete m_pAssets;
    while (!m_pGameStateMachine->getGameStates().empty())
    {
        m_pGameStateMachine->popState();
    }
    delete m_pGameStateMachine;
    TheResourceManager::Instance()->clean();
    SDL_Quit();
}