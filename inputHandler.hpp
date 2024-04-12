#pragma once
#include <SDL.h>
#include <vector>

#include "vector2f.hpp"

#define KEYBOARD_SIZE 282

enum mouse_buttons
{
	LEFT = 0,
	MIDDLE = 1,
	RIGHT = 2
};

class InputHandler
{
public:
    static InputHandler *Instance()
    {
        if (s_pInstance == 0)
        {
            s_pInstance = new InputHandler();
        }
        return s_pInstance;
    }

    void update();
    void clean();

    bool isKeyDown(SDL_Scancode key);

    bool getMouseButtonState(int buttonNumber);
    Vector2f *getMousePosition();

private:
    InputHandler();
    static InputHandler *s_pInstance;

    void onKeyDown();
    void onKeyUp();
    void onMouseButtonDown();
    void onMouseButtonUp();
    void onMouseMotion();

    SDL_Event m_event;
    std::vector<bool> m_mouseButtonStates;
    Vector2f *m_mousePosition;

    const Uint8 *m_keystates;
    bool m_keyDown[KEYBOARD_SIZE];
    bool m_keyUp[KEYBOARD_SIZE];
};

typedef InputHandler TheInputHandler;