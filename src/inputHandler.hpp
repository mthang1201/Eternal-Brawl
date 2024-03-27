#pragma once
#include <SDL.h>

class InputHandler
{
public:
    static InputHandler* Instance()
    {
        if (s_pInstance == 0)
        {
            s_pInstance = new InputHandler();
        }
        return s_pInstance;
    }
    
    void update();

    void onKeyDown();
    void onKeyUp();
    bool isKeyDown(SDL_Scancode key);

    void clean();
private:
    InputHandler() {}
    static InputHandler* s_pInstance;
    SDL_Event m_event;
    const Uint8* m_keystates;
};

typedef InputHandler TheInputHandler;