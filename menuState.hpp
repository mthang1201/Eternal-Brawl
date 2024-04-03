#pragma once
#include <vector>
#include <string>

#include "gameState.hpp"
#include "entity.hpp"

class MenuState : public GameState
{
public:
	virtual void update();
	virtual void render();

	virtual bool onEnter();
	virtual bool onExit();

	virtual std::string getStateID() const { return s_menuID; }

private:
	static void s_menuToPlay();
	static void s_exitFromMenu();

	static const std::string s_menuID;
	std::vector<Entity *> m_entities;

	// typedef void (*Callback)();
	// virtual void setCallbacks(const std::vector<Callback> &callbacks) = 0;

	// std::vector<Callback> m_callbacks;
};