#include <iostream>

#include "playState.hpp"
#include "pauseState.hpp"
#include "gameOverState.hpp"
#include "game.hpp"
#include "resourceManager.hpp"
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

	m_player->update();
	m_enemy1->update();
	m_enemy2->update();
	m_enemy3->update();


	if (checkCollision(dynamic_cast<Player*>(m_player), dynamic_cast<Enemy*>(m_enemy1)))
	{
		m_player->healthPoints -= 100;
	}
	
	if (m_player->getObjectState() == "DEATH" && !m_player->inAction)
	{
		TheGame::Instance()->getStateMachine()->changeState(new GameOverState());
	}
}

void PlayState::render()
{
	for (int i = 0; i <= 0; i++)
	{
		TheResourceManager::Instance()->draw(*m_entities[i]);
	}


	SDL_Rect rect1 = { 100, 100, 100, 100 };
	TheResourceManager::Instance()->drawRect(rect1);



	if (m_player->getObjectState() == "KI")
		TheResourceManager::Instance()->drawPlayerKI(*m_player);
	else
		TheResourceManager::Instance()->drawPlayer(*m_player);
	TheResourceManager::Instance()->drawEnemy1(*m_enemy1);
	//TheResourceManager::Instance()->drawEnemy2(*m_enemy2);
	//TheResourceManager::Instance()->drawEnemy2(*m_enemy3);


	//TheResourceManager::Instance()->playSound(m_player->getSound(), 1);
	//TheResourceManager::Instance()->playSound(m_enemy1->getSound(), 1);
}

bool PlayState::onEnter()
{
	m_entities.push_back(new Item(new LoaderParams(Vector2f(0, 0), { 0, 0, 1280, 720 }, TheGame::Instance()->getAssets()->getTexture(TextureType::BACKGROUND), nullptr)));
	/*for (int i = 350; i < 470; i += 6)
	{
		m_entities.push_back(new Item(new LoaderParams(Vector2f(50, i), { 0, 0, 6, 6 }, TheGame::Instance()->getAssets()->getTexture(TextureType::TILED_LEFT))));
	}*/
	//m_entities.push_back(new Item(new LoaderParams(Vector2f(120, 300), { 0, 0, 19, 720 }, TheGame::Instance()->getAssets()->getTexture(TextureType::LEFT_WALL))));
	//m_entities.push_back(new Item(new LoaderParams(Vector2f(140, 300), { 0, 0, 83, 73 }, TheGame::Instance()->getAssets()->getTexture(TextureType::EXIT_DOOR_ROOF))));
	
	/*for (int i = 0; i < 13; i++)
	{
		float x = (i <= 10) ? (i * 100) : (1000 + 100 * (i - 10));
		m_entities.push_back(new Item(new LoaderParams(Vector2f(x, 620), { 0, 0, 100, 100 }, TheGame::Instance()->getAssets()->getTexture(TextureType::GROUND_GRASS))));
	}*/

	m_player = new Player(new LoaderParams(Vector2f(0, 0), { 0, 0, 64, 64 }, TheGame::Instance()->getAssets()->getTexture(TextureType::GOKU_IDLE), nullptr));
	m_enemy1 = new Enemy(new LoaderParams(Vector2f(500, 395), { 0, 0, 64, 64 }, TheGame::Instance()->getAssets()->getTexture(TextureType::VAGABOND_RUN), nullptr));
	m_enemy2 = new Enemy(new LoaderParams(Vector2f(1000, 200), { 0, 0, 64, 64 }, TheGame::Instance()->getAssets()->getTexture(TextureType::VAGABOND_AIR_DASH), nullptr));
	m_enemy3 = new Enemy(new LoaderParams(Vector2f(1000, 200), { 0, 0, 64, 64 }, TheGame::Instance()->getAssets()->getTexture(TextureType::VAGABOND_DASH), nullptr));

	TheResourceManager::Instance()->playMusic(TheGame::Instance()->getAssets()->getMusic(MusicType::HEROES_BATTLE), -1);

	std::cout << "entering PlayState\n";
	return true;
}

bool PlayState::onExit()
{
	while (!m_entities.empty())
	{
		delete m_entities.back();
		m_entities.pop_back();

	}

	if (!m_entities.empty() && m_entities.back() != nullptr)
	{
		std::cerr << "Error: Failed to delete entity\n";
		return false;
	}

	Mix_HaltMusic();

	std::cout << "exiting PlayState\n";
	return true;
}

bool PlayState::checkCollision(Player* p1, Enemy* p2)
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