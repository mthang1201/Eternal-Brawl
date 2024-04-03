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
    if (TheRenderWindow::Instance()->init("Mythical Combat: Endless Encounter", SCREEN_WIDTH, SCREEN_HEIGHT))
    {
        m_pAssets = new LoaderAssets();
        m_pGameStateMachine = new GameStateMachine();
        m_pGameStateMachine->changeState(new MenuState());

        return true;
    }
    return false;
}

void Game::handleEvents()
{
    TheInputHandler::Instance()->update();
    // if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RETURN))
    // {
    //     m_pGameStateMachine->changeState(new PlayState());
    // }
}

void Game::update()
{
    m_pGameStateMachine->update();
}

void Game::render()
{
    TheRenderWindow::Instance()->clear();
    m_pGameStateMachine->render();
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
    delete m_pAssets;
    while (!m_pGameStateMachine->getGameStates().empty())
    {
        m_pGameStateMachine->popState();
    }
    delete m_pGameStateMachine;
    TheRenderWindow::Instance()->clean();
    SDL_Quit();
}