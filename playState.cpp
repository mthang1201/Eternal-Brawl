#include <iostream>

#include "playState.hpp"
#include "pauseState.hpp"
#include "gameOverState.hpp"
#include "game.hpp"
#include "renderWindow.hpp"
#include "inputHandler.hpp"
#include "entity.hpp"
#include "player.hpp"
#include "enemy.hpp"
#include "item.hpp"

const std::string PlayState::s_playID = "PLAY";

void PlayState::update()
{
	// listen for ESC key to pause the game
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE))
	{
		TheGame::Instance()->getStateMachine()->pushState(new PauseState());
	}

	for (int i = 0; i < (int)m_entities.size(); i++)
	{
		m_entities[i]->update();
	}

	// if (checkCollision(dynamic_cast<Entity *>(m_entities[0]), dynamic_cast<Entity *>(m_entities[1])))
	// {
	// 	TheGame::Instance()->getStateMachine()->pushState(new GameOverState());
	// }
}

void PlayState::render()
{
	// for (std::vector<Entity *>::size_type i = 0; i < m_entities.size(); i++)
	// {
	//     TheRenderWindow::Instance()->drawFrame(*m_entities[i]);
	// }
	for (int i = 0; i < 13; i++)
	{
		TheRenderWindow::Instance()->draw(*m_entities[i]);
	}
	TheRenderWindow::Instance()->draw(*m_entities[13]);
	TheRenderWindow::Instance()->drawFrame(*m_entities[14]);
	// TheRenderWindow::Instance()->drawFrame(*m_entities[15]);
}

bool PlayState::onEnter()
{
	for (int i = 0; i < 13; i++)
	{
		float x = (i <= 10) ? (i * 100) : (1000 + 100 * (i - 10));
		m_entities.push_back(new Item(new LoaderParams(Vector2f(x, 620), {0, 0, 100, 100}, TheGame::Instance()->getAssets()->getTexture(TextureType::GROUND_GRASS))));
	}
	m_entities.push_back(new Item(new LoaderParams(Vector2f(0, 0), {0, 0, 1280, 620}, TheGame::Instance()->getAssets()->getTexture(TextureType::SKY))));

	m_entities.push_back(new Player(new LoaderParams(Vector2f(0, 0), {0, 0, 48, 58}, TheGame::Instance()->getAssets()->getTexture(TextureType::GOKU_IDLE))));
	// m_entities.push_back(new Enemy(new LoaderParams(Vector2f(0, 0), {10, 10, 130, 205}, TheGame::Instance()->getAssets()->getTexture(TextureType::MR_HOANG))));

	std::cout << "entering PlayState\n";
	return true;
}

bool PlayState::onExit()
{
	while (!m_entities.empty())
	{
		delete m_entities.back();
		m_entities.pop_back();

		// Check if deletion was successful
		/*if (!m_entities.empty() && m_entities.back() != nullptr)
		{
			std::cerr << "Error: Failed to delete entity\n";
			return false;
		}*/
	}

	std::cout << "exiting PlayState\n";
	return true;
}

bool PlayState::checkCollision(Entity *p1, Entity *p2)
{
	float leftA, leftB;
	float rightA, rightB;
	float topA, topB;
	float bottomA, bottomB;

	leftA = p1->getPos().getX();
	rightA = p1->getPos().getX() + p1->getCurrentFrame().w;
	topA = p1->getPos().getY();
	bottomA = p1->getPos().getY() + p1->getCurrentFrame().h;

	// Calculate the sides of rect B
	leftB = p2->getPos().getX();
	rightB = p2->getPos().getX() + p2->getCurrentFrame().w;
	topB = p2->getPos().getY();
	bottomB = p2->getPos().getY() + p2->getCurrentFrame().h;

	// If any of the sides from A are outside of B
	if (bottomA <= topB)
	{
		return false;
	}
	if (topA >= bottomB)
	{
		return false;
	}
	if (rightA <= leftB)
	{
		return false;
	}
	if (leftA >= rightB)
	{
		return false;
	}

	return true;
}