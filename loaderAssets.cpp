#include <SDL.h>
#include <SDL_image.h>

#include "loaderParams.hpp"
#include "vector2f.hpp"
#include "loaderAssets.hpp"
#include "renderWindow.hpp"

LoaderAssets::LoaderAssets()
{
    loadTextures();
    // loadSounds();
    // loadFonts();
}

LoaderAssets::~LoaderAssets()
{
    for (auto &pair : m_textures)
    {
        SDL_DestroyTexture(pair.second);
    }
}

void LoaderAssets::loadTextures()
{
    m_textures.push_back({TextureType::PLAY_BUTTON, TheRenderWindow::Instance()->loadTexture("C:/Users/Minh Thang Bui/source/repos/Game/res/button.png")});
    m_textures.push_back({TextureType::EXIT_BUTTON, TheRenderWindow::Instance()->loadTexture("C:/Users/Minh Thang Bui/source/repos/Game/res/exit.png")});

    m_textures.push_back({TextureType::MAIN_BUTTON, TheRenderWindow::Instance()->loadTexture("C:/Users/Minh Thang Bui/source/repos/Game/res/main.png")});
    m_textures.push_back({TextureType::RESUME_BUTTON, TheRenderWindow::Instance()->loadTexture("C:/Users/Minh Thang Bui/source/repos/Game/res/resume.png")});
    m_textures.push_back({TextureType::GAME_OVER_TEXT, TheRenderWindow::Instance()->loadTexture("C:/Users/Minh Thang Bui/source/repos/Game/res/gameover.png")});

    m_textures.push_back({TextureType::GROUND_GRASS, TheRenderWindow::Instance()->loadTexture("C:/Users/Minh Thang Bui/source/repos/Game/res/ground_grass_1.png")});
    m_textures.push_back({TextureType::SKY, TheRenderWindow::Instance()->loadTexture("C:/Users/Minh Thang Bui/source/repos/Game/res/skye_0.png")});
    m_textures.push_back({TextureType::HULKING_KNIGHT, TheRenderWindow::Instance()->loadTexture("C:/Users/Minh Thang Bui/source/repos/Game/res/hulking_knight.png")});
    m_textures.push_back({TextureType::MR_HOANG, TheRenderWindow::Instance()->loadTexture("C:/Users/Minh Thang Bui/source/repos/Game/res/hoang.jpg")});

    m_textures.push_back({TextureType::GOKU_IDLE, TheRenderWindow::Instance()->loadTexture("C:/Users/Minh Thang Bui/source/repos/Game/res/1.png")});
    m_textures.push_back({TextureType::GOKU_MOVEMENT, TheRenderWindow::Instance()->loadTexture("C:/Users/Minh Thang Bui/source/repos/Game/res/2.png")});
}

SDL_Texture *LoaderAssets::getTexture(const TextureType &name)
{
    for (const auto &pair : m_textures)
    {
        if (pair.first == name)
        {
            return pair.second;
        }
    }
    return nullptr;
}

// void LoaderAssets::loadSounds()
// {
//     m_sounds["game_over"] = TheRenderWindow::Instance()->loadSound("path_to_game_over_sound");
// }

// void LoaderAssets::loadFonts()
// {
//     m_fonts["main_font"] = TheRenderWindow::Instance()->loadFont("path_to_main_font", 24);
// }