#include <SDL.h>
#include <SDL_image.h>

#include "loaderParams.hpp"
#include "vector2f.hpp"
#include "loaderAssets.hpp"
#include "renderWindow.hpp"

LoaderAssets::LoaderAssets()
{
    // loadTextures();
    // loadSounds();
    // loadFonts();
}

void LoaderAssets::loadTextures()
{
    m_textures["playbutton"] = TheRenderWindow::Instance()->loadTexture("../res/gfx/button.png");
    m_textures["exitbutton"] = TheRenderWindow::Instance()->loadTexture("../res/gfx/exit.png");
    
    m_textures["mainbutton"] = TheRenderWindow::Instance()->loadTexture("../res/gfx/main.png");
    m_textures["resumebutton"] = TheRenderWindow::Instance()->loadTexture("../res/gfx/resume.png");
    
    m_textures["ground_grass"] = TheRenderWindow::Instance()->loadTexture("../res/gfx/ground_grass_1.png");
    m_textures["sky"] = TheRenderWindow::Instance()->loadTexture("../res/gfx/skye_0.png");
    m_textures["hulking_knight"] = TheRenderWindow::Instance()->loadTexture("../res/gfx/hulking_knight.png");
    m_textures["mrHoang"] = TheRenderWindow::Instance()->loadTexture("../res/gfx/hoang.jpg");
}

// void LoaderAssets::loadSounds()
// {
//     m_sounds["game_over"] = TheRenderWindow::Instance()->loadSound("path_to_game_over_sound");
// }

// void LoaderAssets::loadFonts()
// {
//     m_fonts["main_font"] = TheRenderWindow::Instance()->loadFont("path_to_main_font", 24);
// }