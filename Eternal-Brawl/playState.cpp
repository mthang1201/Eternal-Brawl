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
#include "map.hpp"

const std::string PlayState::s_playID = "PLAY";

//const Uint32 enemyGenerationInterval = 180000;
const Uint32 enemyGenerationInterval = 10000;
Uint32 lastEnemyGenerationTime = SDL_GetTicks();

void PlayState::update()
{
	// Press ESCAPE to pause game
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE))
	{
		TheGame::Instance()->getStateMachine()->pushState(new PauseState());
	}

	Uint32 currentTime = SDL_GetTicks();
	if (currentTime - lastEnemyGenerationTime >= enemyGenerationInterval) {
		if ((int)m_enemies.size() <= 15)
		{
			generateEnemies();
		}
		lastEnemyGenerationTime = currentTime;
	}

	// entites update
	for (int i = 0; i < (int)m_entities.size(); i++)
	{
		m_entities[i]->update();
	}
	// player update
	m_player->update();
	// enemies update
	for (int i = 0; i < (int)m_enemies.size(); i++)
	{
		m_enemies[i]->m_indexInEnemyList = i;
		//m_enemies[i]->m_playerPos.setPos(m_player->getPos().getX(), m_player->getPos().getY());
		m_enemies[i]->m_playerPos = m_player->getPos();
		m_enemies[i]->update();
	}

	// collision
	for (int i = 0; i < (int)m_enemies.size(); i++)
	{
		interactionBetweenPlayerAndEnemy(m_player, m_enemies[i]);
	}

	// check player alive or not
	if (m_player->getObjectState() == "DEATH")
	{
		if (m_player->m_lives > 0)
		{
			m_player->revive();
		}
		else
		{
			TheGame::Instance()->getStateMachine()->changeState(new GameOverState(m_player->m_scores));
		}
	}
	// check enemies alive or not
	for (int i = 0; i < (int)m_enemies.size(); i++)
	{
		if (m_enemies[i]->healthPoints <= 0)
		{
			delete m_enemies[i];
			m_enemies.erase(m_enemies.begin() + i);
			m_player->m_scores += 300;
		}
	}
	//std::cout << m_player->m_scores << std::endl;
}

void PlayState::render()
{
	for (int i = 0; i <= 0; i++)
	{
		TheResourceManager::Instance()->draw(*m_entities[i]);
	}


	/*SDL_Rect rect1 = { 100, 100, 100, 100 };
	SDL_Rect tile1 = { 80, 508, 100, 100 };
	SDL_Rect tile2 = { 400, 350, 100, 80 };*/
	/*for (SDL_Rect tile : tiles)
	{
		TheResourceManager::Instance()->drawRect(tile);
	}*/
	//TheResourceManager::Instance()->drawRect(rect1);
	
	TheResourceManager::Instance()->drawLives(m_player->m_lives);
	TheResourceManager::Instance()->drawScores(m_player->m_scores);

	TheResourceManager::Instance()->drawHealthBar(m_player->healthBarRect, m_player->healthBarWidth, m_player->healthColor);
	TheResourceManager::Instance()->drawBar(m_player->agilityBarRect, m_player->agilityBarWidth, m_player->agilityColor);
	for (int i = 0; i < (int)m_enemies.size(); i++)
	{
		TheResourceManager::Instance()->drawHealthBar(m_enemies[i]->healthBarRect, m_enemies[i]->healthBarWidth, m_enemies[i]->healthColor);
	}

	//std::cout << m_enemies[0]->m_playerPos.getX() << ", " << m_enemies[0]->m_playerPos.getY() << std::endl;
	//std::cout << m_player->getPos().getX() << ", " << m_player->getPos().getY() << std::endl;
	/*for (int i = 0; i < (int)m_enemies.size(); i++)
	{
		std::cout << m_enemies[i]->getPos().getX() << ", " << m_enemies[i]->getPos().getY() << std::endl;
	}*/

	if (m_player->getObjectState() == "KI")
		TheResourceManager::Instance()->drawPlayerKI(*m_player);
	else
		TheResourceManager::Instance()->drawPlayer(*m_player);

	for (int i = 0; i < (int)m_enemies.size(); i++)
	{
		if (m_enemies[i]->getObjectState() == "ATTACK")
			TheResourceManager::Instance()->drawEnemyAttack(*m_enemies[i]);
		else if (m_enemies[i]->getObjectState() == "HEAVY_ATTACK")
			TheResourceManager::Instance()->drawEnemyHeavyAttack(*m_enemies[i]);
		else
			TheResourceManager::Instance()->drawEnemy1(*m_enemies[i]);
	}
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

	m_player = new Player(new LoaderParams(Vector2f(200, 197), { 0, 0, 64, 64 }, TheGame::Instance()->getAssets()->getTexture(TextureType::GOKU_IDLE), nullptr));
	/*m_enemies.push_back(new Enemy(new LoaderParams(Vector2f(820, 616), {0, 0, 64, 64}, TheGame::Instance()->getAssets()->getTexture(TextureType::VAGABOND_RUN), nullptr)));*/
	m_enemies.push_back(new Enemy(new LoaderParams(Vector2f(820, 316), { 0, 0, 64, 64 }, TheGame::Instance()->getAssets()->getTexture(TextureType::VAGABOND_RUN), nullptr)));
	//m_enemies.push_back(new Enemy(new LoaderParams(Vector2f(200, 192), { 0, 0, 64, 64 }, TheGame::Instance()->getAssets()->getTexture(TextureType::VAGABOND_RUN), nullptr)));
	//m_enemies.push_back(new Enemy(new LoaderParams(Vector2f(700, 616), { 0, 0, 64, 64 }, TheGame::Instance()->getAssets()->getTexture(TextureType::VAGABOND_RUN), nullptr)));

	//m_enemies.push_back(new Enemy(new LoaderParams(Vector2f(200, 567), { 0, 0, 64, 64 }, TheGame::Instance()->getAssets()->getTexture(TextureType::VAGABOND_RUN), nullptr)));
	//m_enemies.push_back(new Enemy(new LoaderParams(Vector2f(1000, 200), { 0, 0, 64, 64 }, TheGame::Instance()->getAssets()->getTexture(TextureType::VAGABOND_AIR_DASH), nullptr)));
	//m_enemies.push_back(new Enemy(new LoaderParams(Vector2f(1000, 200), { 0, 0, 64, 64 }, TheGame::Instance()->getAssets()->getTexture(TextureType::VAGABOND_DASH), nullptr)));

	//TheResourceManager::Instance()->playMusic(TheGame::Instance()->getAssets()->getMusic(MusicType::HEROES_BATTLE), -1);
	TheResourceManager::Instance()->playMusic(TheResourceManager::Instance()->loadMusic("res/music/HeroesBattle.mp3"), -1);

	//Map::calculateMap();


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

	delete m_player;

	while (!m_enemies.empty())
	{
		delete m_enemies.back();
		m_enemies.pop_back();
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

bool PlayState::checkPlayerEnemyCollision(Player* player, Enemy* enemy)
{
	SDL_Rect p1 = player->getRigidBody();
	SDL_Rect e1 = enemy->getRigidBody();
	SDL_bool isColliding = SDL_HasIntersection(&p1, &e1);

	if (isColliding) return true;
	return false;
}

void PlayState::generateEnemies()
{
	if (int((SDL_GetTicks() / 120) % 6) == 0)
	m_enemies.push_back(new Enemy(new LoaderParams(Vector2f(463, 166), { 0, 0, 64, 64 }, TheGame::Instance()->getAssets()->getTexture(TextureType::VAGABOND_RUN), nullptr)));
	else if (int((SDL_GetTicks() / 120) % 6) == 1)
	m_enemies.push_back(new Enemy(new LoaderParams(Vector2f(700, 616), { 0, 0, 64, 64 }, TheGame::Instance()->getAssets()->getTexture(TextureType::VAGABOND_RUN), nullptr)));
	else if (int((SDL_GetTicks() / 120) % 6) == 2)
	m_enemies.push_back(new Enemy(new LoaderParams(Vector2f(200, 192), { 0, 0, 64, 64 }, TheGame::Instance()->getAssets()->getTexture(TextureType::VAGABOND_RUN), nullptr)));
	else if (int((SDL_GetTicks() / 120) % 6) == 3)
	m_enemies.push_back(new Enemy(new LoaderParams(Vector2f(275, 531), { 0, 0, 64, 64 }, TheGame::Instance()->getAssets()->getTexture(TextureType::VAGABOND_RUN), nullptr)));
	else if (int((SDL_GetTicks() / 120) % 6) == 4)
	m_enemies.push_back(new Enemy(new LoaderParams(Vector2f(279, 156), { 0, 0, 64, 64 }, TheGame::Instance()->getAssets()->getTexture(TextureType::VAGABOND_RUN), nullptr)));
	else
	m_enemies.push_back(new Enemy(new LoaderParams(Vector2f(820, 616), { 0, 0, 64, 64 }, TheGame::Instance()->getAssets()->getTexture(TextureType::VAGABOND_RUN), nullptr)));
}

void PlayState::interactionBetweenPlayerAndEnemy(Player* player, Enemy* enemy)
{
	if (checkPlayerEnemyCollision(player, enemy))
	{
		enemy->m_state = EnemyState::ATTACK;
		enemy->immovable();
		if (enemy->getObjectState() == "ATTACK")
		{
			player->healthPoints -= 1;
			//player->knockback();
		}
		else if (enemy->getObjectState() == "HEAVY_ATTACK")
		{
			player->healthPoints -= 5;
			//player->knockback();
		}
		//player->healthPoints -= 1;
		/*player->setXPos(player->getPos().getX() - player->getVelocity().getX());
		player->setYPos(player->getPos().getY() - player->getVelocity().getY());

		enemy->setXPos(enemy->getPos().getX() - enemy->getVelocity().getX());
		enemy->setYPos(enemy->getPos().getY() - enemy->getVelocity().getY());*/

		if (player->getObjectState() == "ATTACK")
		{
			enemy->healthPoints -= 1;
			enemy->m_state = EnemyState::KNOCKBACK;
			enemy->knockback();
		}
		else if (player->getObjectState() == "HEAVY_ATTACK")
		{
			enemy->healthPoints -= 5;
			enemy->m_state = EnemyState::KNOCKBACK;
			enemy->knockback();
		}
	}
	else
	{
		//enemy->m_state = EnemyState::DEATH;
		//enemy->m_state = EnemyState::KNOCKBACK;
		//enemy->m_state = EnemyState::HEAVY_ATTACK;
		enemy->m_state = EnemyState::RUN;
		enemy->movable();
	}
	enemy->immovable();
}