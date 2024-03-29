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

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720

Game *Game::s_pInstance = nullptr;

bool Game::init()
{
    if (TheRenderWindow::Instance()->init("GAME v1.0", SCREEN_WIDTH, SCREEN_HEIGHT))
    {
        m_assets = new LoaderAssets();
        m_assets->loadTextures();
        // for (int i = 0; i < 8; i+=100)
        m_entities.push_back(new Item(new LoaderParams(Vector2f(0, 620), {0, 0, 100, 100}, m_assets->getTexture("ground_grass"))));
        m_entities.push_back(new Item(new LoaderParams(Vector2f(100, 620), {0, 0, 100, 100}, m_assets->getTexture("ground_grass"))));
        m_entities.push_back(new Item(new LoaderParams(Vector2f(200, 620), {0, 0, 100, 100}, m_assets->getTexture("ground_grass"))));
        m_entities.push_back(new Item(new LoaderParams(Vector2f(300, 620), {0, 0, 100, 100}, m_assets->getTexture("ground_grass"))));
        m_entities.push_back(new Item(new LoaderParams(Vector2f(400, 620), {0, 0, 100, 100}, m_assets->getTexture("ground_grass"))));
        m_entities.push_back(new Item(new LoaderParams(Vector2f(500, 620), {0, 0, 100, 100}, m_assets->getTexture("ground_grass"))));
        m_entities.push_back(new Item(new LoaderParams(Vector2f(600, 620), {0, 0, 100, 100}, m_assets->getTexture("ground_grass"))));
        m_entities.push_back(new Item(new LoaderParams(Vector2f(700, 620), {0, 0, 100, 100}, m_assets->getTexture("ground_grass"))));
        m_entities.push_back(new Item(new LoaderParams(Vector2f(800, 620), {0, 0, 100, 100}, m_assets->getTexture("ground_grass"))));
        m_entities.push_back(new Item(new LoaderParams(Vector2f(900, 620), {0, 0, 100, 100}, m_assets->getTexture("ground_grass"))));
        m_entities.push_back(new Item(new LoaderParams(Vector2f(1000, 620), {0, 0, 100, 100}, m_assets->getTexture("ground_grass"))));
        m_entities.push_back(new Item(new LoaderParams(Vector2f(1100, 620), {0, 0, 100, 100}, m_assets->getTexture("ground_grass"))));
        m_entities.push_back(new Item(new LoaderParams(Vector2f(1200, 620), {0, 0, 100, 100}, m_assets->getTexture("ground_grass"))));
        m_entities.push_back(new Item(new LoaderParams(Vector2f(0, 0), {0, 0, 1280, 620}, m_assets->getTexture("sky"))));
        m_entities.push_back(new Player(new LoaderParams(Vector2f(0, 0), {0, 0, 64, 64}, m_assets->getTexture("hulking_knight"))));
        // m_entities.push_back(new Player(new LoaderParams(Vector2f(0, 0), {10, 10, 130, 205}, m_assets.getTexture("mrHoang"))));
        // m_entities.push_back(new Player(new LoaderParams(Vector2f(0, 0), {0, 0, 30, 30}, m_assets.getTexture(HULKING_KNIGHT))));
        // Player ground_grass(Vector2f(30, 0), {0, 0, 30, 30}, GROUND_GRASS);
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
        m_entities[i]->update();
    }
}

void Game::render()
{
    TheRenderWindow::Instance()->clear();
    // for (std::vector<Entity *>::size_type i = 0; i != m_entities.size(); i++)
    // {
    //     TheRenderWindow::Instance()->drawFrame(*m_entities[i]);
    // }
    TheRenderWindow::Instance()->draw(*m_entities[0]);
    TheRenderWindow::Instance()->draw(*m_entities[1]);
    TheRenderWindow::Instance()->draw(*m_entities[2]);
    TheRenderWindow::Instance()->draw(*m_entities[3]);
    TheRenderWindow::Instance()->draw(*m_entities[4]);
    TheRenderWindow::Instance()->draw(*m_entities[5]);
    TheRenderWindow::Instance()->draw(*m_entities[6]);
    TheRenderWindow::Instance()->draw(*m_entities[7]);
    TheRenderWindow::Instance()->draw(*m_entities[8]);
    TheRenderWindow::Instance()->draw(*m_entities[9]);
    TheRenderWindow::Instance()->draw(*m_entities[10]);
    TheRenderWindow::Instance()->draw(*m_entities[11]);
    TheRenderWindow::Instance()->draw(*m_entities[12]);
    TheRenderWindow::Instance()->draw(*m_entities[13]);
    TheRenderWindow::Instance()->drawFrame(*m_entities[14]);
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