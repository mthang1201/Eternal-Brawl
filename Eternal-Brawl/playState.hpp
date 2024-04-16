#pragma once
#include <string>
#include <vector>

#include "entity.hpp"
#include "player.hpp"
#include "enemy.hpp"
#include "gameState.hpp"

class GameObject;

class PlayState : public GameState
{
public:
	virtual void update();
	virtual void render();

	virtual bool onEnter();
	virtual bool onExit();

	virtual std::string getStateID() const { return s_playID; }

	// function to check collisions
	bool checkCollision(Player* p1, Enemy* p2);

private:
	static const std::string s_playID;
	bool checkPlayerEnemyCollision(Player* player, Enemy* enemy);
	std::vector<Entity*> m_entities;
	Player* m_player;
	int m_lives = 3;
	//Enemy* m_enemy1, * m_enemy2, * m_enemy3;
	std::vector<Enemy*> m_enemies;
};