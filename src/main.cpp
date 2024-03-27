#include <SDL.h>

#include "game.hpp"
#include "utils.hpp"

int main(int argc, char *argv[])
{
    const float timeStep = 0.01f;
    float accumulator = 0.0f;
    float currentTime = utils::hireTimeInSeconds();

    if (TheGame::Instance()->init())
    {
        while (TheGame::Instance()->isRunning())
        {
            float newTime = utils::hireTimeInSeconds();
            float frameTime = newTime - currentTime;
            currentTime = newTime;
            
            accumulator += frameTime;

            while (accumulator >= timeStep)
            {
                TheGame::Instance()->handleEvents();

                accumulator -= timeStep;
            }
            const float alpha = accumulator / timeStep;

            TheGame::Instance()->update();
            
            TheGame::Instance()->render();
            
            TheGame::Instance()->display();

            int startTicks = SDL_GetTicks();
            int frameTicks = SDL_GetTicks() - startTicks;

            TheGame::Instance()->pause(frameTicks);
        }
    }
    
    TheGame::Instance()->clean();

    return 0;
}