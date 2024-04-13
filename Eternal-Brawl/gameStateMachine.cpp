#include <iostream>

#include "gameStateMachine.hpp"

void GameStateMachine::pushState(GameState* pState)
{	
	m_gameStates.push_back(pState);
	m_gameStates.back()->onEnter();
}

void GameStateMachine::popState()
{	
	if (!m_gameStates.empty())
	{	
		if (m_gameStates.back()->onExit())
		{	
			delete m_gameStates.back();
			m_gameStates.pop_back();
		}
		else
		{
			std::cerr << "Error: Failed to exit game state\n";
		}
	}
}

void GameStateMachine::changeState(GameState* pState)
{	
	popState();
	pushState(pState);
}

void GameStateMachine::update()
{
	if (!m_gameStates.empty())
	{
		m_gameStates.back()->update();
	}
}

void GameStateMachine::render()
{
	if (!m_gameStates.empty())
	{
		m_gameStates.back()->render();
	}
}