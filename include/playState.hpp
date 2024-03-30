#pragma once
#include <string>
#include <vector>

#include "entity.hpp"
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
	bool checkCollision(Entity *p1, Entity *p2);

private:
	static const std::string s_playID;
	std::vector<Entity *> m_entities;
};