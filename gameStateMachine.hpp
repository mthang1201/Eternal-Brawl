#pragma once
#include <vector>

#include "gameState.hpp"

class GameStateMachine
{
public:
    void pushState(GameState *pState);
    void changeState(GameState *pState);
    void popState();

    void update();
    void render();

    std::vector<GameState *> getGameStates() { return m_gameStates; }

private:
    std::vector<GameState *> m_gameStates;
};