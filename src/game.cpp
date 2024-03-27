#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <vector>

#include "game.hpp"
#include "renderWindow.hpp"
#include "entity.hpp"
#include "player.hpp"
#include "utils.hpp"
#include "inputHandler.hpp"
#include "loaderAssets.hpp"

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720

Game *Game::s_pInstance = nullptr;

bool Game::init()
{
    if (TheRenderWindow::Instance()->init("GAME v1.0", SCREEN_WIDTH, SCREEN_HEIGHT))
    {
        m_assets.loadTextures();
        m_entities.push_back(new Player(new LoaderParams(Vector2f(0, 0), {0, 0, 30, 30}, m_assets.getTexture("hulking_knight"))));
        // m_entities.push_back(new Player(new LoaderParams(Vector2f(0, 0), {0, 0, 30, 30}, m_assets.getTexture(HULKING_KNIGHT))));
        // Player ground_grass(Vector2f(30, 0), {0, 0, 30, 30}, GROUND_GRASS);
        // m_entities.push_back(new Player(Vector2f(30, 30), {0, 0, 30, 30}, METAL_KNIGHT));
        // TheRenderWindow::Instance()->draw(ground_grass);
        // m_entities.push_back(new Player({300, 300}, {NULL, NULL, 128, 82}, "animate"));
        // m_entities.push_back(new Enemy(new LoaderParams(300, 300, 128, 82, "animate")));
        // Entity ground_grass1(Vector2f(0, 0), {0, 0, 1280, 720}, GROUND_GRASS);

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
        m_entities[i]->update();
    }
}

void Game::render()
{
    TheRenderWindow::Instance()->clear();
    for (std::vector<Entity *>::size_type i = 0; i != m_entities.size(); i++)
    {
        TheRenderWindow::Instance()->draw(*m_entities[i]);
    }
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