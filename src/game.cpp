#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <vector>

#include "game.hpp"
#include "renderWindow.hpp"
#include "entity.hpp"
#include "utils.hpp"
#include "inputHandler.hpp"

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720

Game *Game::s_pInstance = nullptr;

bool Game::init()
{
    if (TheRenderWindow::Instance()->init("GAME v1.0", SCREEN_WIDTH, SCREEN_HEIGHT))
    {
        TheRenderWindow::Instance()->loadTexture("../res/gfx/ground_grass_1.png");

            // m_entities.push_back(new Player({300, 300}, {NULL, NULL, 128, 82}, "animate"));
        // m_entities.push_back(new Enemy(new LoaderParams(300, 300, 128, 82, "animate")));
        
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
    for (std::vector<Entity *>::size_type i = 0; i != m_entities.size(); i++)
    {
        m_entities[i].update();
    }
}

void Game::render()
{
    TheRenderWindow::Instance()->clear();
    for (std::vector<Entity *>::size_type i = 0; i != m_entities.size(); i++)
    {
        TheRenderWindow::Instance()->draw(m_entities[i]);
    }
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

void Game::quit()
{
    m_bGameRunning = false;
}
