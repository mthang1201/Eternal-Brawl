#pragma once
#include <vector>
#include <string>

#include "gameState.hpp"
#include "entity.hpp"

class InstructionState : public GameState
{
public:
	virtual void update();
	virtual void render();

	virtual bool onEnter();
	virtual bool onExit();

	virtual std::string getStateID() const { return s_instructionID; }

private:
	static void s_resumeMenu();

	static const std::string s_instructionID;
	std::vector<Entity*> m_entities;

	// typedef void (*Callback)();
	// virtual void setCallbacks(const std::vector<Callback> &callbacks) = 0;

	// std::vector<Callback> m_callbacks;
};