#include <SDL.h>
#include <vector>

#include "entity.hpp"

class Game
{
public:
    static Game *Instance()
    {
        if (s_pInstance == 0)
        {
            s_pInstance = new Game();
            return s_pInstance;
        }
        return s_pInstance;
    }
    bool init();
    bool isRunning() const { return m_bGameRunning; }
    void handleEvents();
    void update();
    void render();
    void display();
    void pause(int &frameTicks);
    void clean();
    void quit();

private:
    Game() {}
    static Game *s_pInstance;
    std::vector<Entity> m_entities;
    bool m_bGameRunning = true;
};

typedef Game TheGame;