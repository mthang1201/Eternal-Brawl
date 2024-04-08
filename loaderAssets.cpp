#include <SDL.h>
#include <SDL_image.h>

#include "loaderParams.hpp"
#include "vector2f.hpp"
#include "loaderAssets.hpp"
#include "resourceManager.hpp"

LoaderAssets::LoaderAssets()
{
	loadTextures();
	// loadSounds();
	// loadFonts();
}

LoaderAssets::~LoaderAssets()
{
	for (auto& pair : m_textures)
	{
		SDL_DestroyTexture(pair.second);
	}
}

void LoaderAssets::loadTextures()
{
	m_textures.push_back({ TextureType::PLAY_BUTTON, TheResourceManager::Instance()->loadTexture("res/button.png") });
	m_textures.push_back({ TextureType::EXIT_BUTTON, TheResourceManager::Instance()->loadTexture("res/exit.png") });

	m_textures.push_back({ TextureType::MAIN_BUTTON, TheResourceManager::Instance()->loadTexture("res/main.png") });
	m_textures.push_back({ TextureType::RESTART_BUTTON, TheResourceManager::Instance()->loadTexture("res/restart.png") });
	m_textures.push_back({ TextureType::RESUME_BUTTON, TheResourceManager::Instance()->loadTexture("res/resume.png") });
	m_textures.push_back({ TextureType::GAME_OVER_TEXT, TheResourceManager::Instance()->loadTexture("res/gameover.png") });

	m_textures.push_back({ TextureType::GROUND_GRASS, TheResourceManager::Instance()->loadTexture("res/ground_grass_1.png") });
	m_textures.push_back({ TextureType::SKY, TheResourceManager::Instance()->loadTexture("res/skye_0.png") });
	m_textures.push_back({ TextureType::HULKING_KNIGHT, TheResourceManager::Instance()->loadTexture("res/hulking_knight.png") });
	m_textures.push_back({ TextureType::MR_HOANG, TheResourceManager::Instance()->loadTexture("res/hoang.jpg") });

	m_textures.push_back({ TextureType::GOKU_IDLE, TheResourceManager::Instance()->loadTexture("res/1.png") });
	m_textures.push_back({ TextureType::GOKU_MOVEMENT, TheResourceManager::Instance()->loadTexture("res/2.png") });
	m_textures.push_back({ TextureType::GOKU_JUMPING, TheResourceManager::Instance()->loadTexture("res/3.png") });
	m_textures.push_back({ TextureType::GOKU_FALLING, TheResourceManager::Instance()->loadTexture("res/3.png") });
}

SDL_Texture* LoaderAssets::getTexture(const TextureType& name)
{
	for (const auto& pair : m_textures)
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
//     m_sounds["game_over"] = TheResourceManager::Instance()->loadSound("path_to_game_over_sound");
// }

// void LoaderAssets::loadFonts()
// {
//     m_fonts["main_font"] = TheResourceManager::Instance()->loadFont("path_to_main_font", 24);
// }