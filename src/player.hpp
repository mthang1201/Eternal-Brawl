#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

#include "entity.hpp"
#include "loaderParams.hpp"

class Player : public Entity
{
public:
    Player(Vector2f pos, SDL_Rect currentFrame, SDL_Texture *pTex);

    virtual void draw();
    virtual void update();
    virtual void clean();
private:
    void handleInput();
};