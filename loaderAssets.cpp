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







	m_textures.push_back({ TextureType::GOKU_IDLE, TheResourceManager::Instance()->loadTexture("res/goku_idle.png") });;
	m_textures.push_back({ TextureType::GOKU_IDLE2, TheResourceManager::Instance()->loadTexture("res/goku_idle2.png") });
	
	m_textures.push_back({ TextureType::GOKU_KI, TheResourceManager::Instance()->loadTexture("res/goku_ki.png") });
	m_textures.push_back({ TextureType::GOKU_TRANSFORM_01, TheResourceManager::Instance()->loadTexture("res/goku_transform/goku_transform_01.png") });
	m_textures.push_back({ TextureType::GOKU_TRANSFORM_02, TheResourceManager::Instance()->loadTexture("res/goku_transform/goku_transform_01.png") });

	m_textures.push_back({ TextureType::GOKU_RUN, TheResourceManager::Instance()->loadTexture("res/2.png") });
	m_textures.push_back({ TextureType::GOKU_TELEPORT, TheResourceManager::Instance()->loadTexture("res/goku_teleport.png") });
	m_textures.push_back({ TextureType::GOKU_JUMPING, TheResourceManager::Instance()->loadTexture("res/3.png") });
	m_textures.push_back({ TextureType::GOKU_FALLING, TheResourceManager::Instance()->loadTexture("res/3.png") });
	
	m_textures.push_back({ TextureType::GOKU_FLYING_HORIZONTAL, TheResourceManager::Instance()->loadTexture("res/goku_flying_horizontal.png") });
	m_textures.push_back({ TextureType::GOKU_FLYING_UP, TheResourceManager::Instance()->loadTexture("res/goku_flying_up.png") });
	m_textures.push_back({ TextureType::GOKU_FLYING_DOWN, TheResourceManager::Instance()->loadTexture("res/goku_flying_down.png") });
	m_textures.push_back({ TextureType::GOKU_LANDING, TheResourceManager::Instance()->loadTexture("res/goku_landing.png") });
	
	m_textures.push_back({ TextureType::GOKU_ATTACK, TheResourceManager::Instance()->loadTexture("res/goku_attack.png") });
	m_textures.push_back({ TextureType::GOKU_HEAVY_ATTACK, TheResourceManager::Instance()->loadTexture("res/goku_heavy_attack.png") });
	m_textures.push_back({ TextureType::GOKU_FLYING_ATTACK, TheResourceManager::Instance()->loadTexture("res/goku_flying_attack.png") });
	m_textures.push_back({ TextureType::GOKU_KICK, TheResourceManager::Instance()->loadTexture("res/goku_kick.png") });
	m_textures.push_back({ TextureType::GOKU_DEFEND, TheResourceManager::Instance()->loadTexture("res/goku_defend.png") });
	m_textures.push_back({ TextureType::GOKU_FLYING_DEFEND, TheResourceManager::Instance()->loadTexture("res/goku_flying_defend.png") });
	
	m_textures.push_back({ TextureType::GOKU_KNOCKBACK, TheResourceManager::Instance()->loadTexture("res/goku_knockback.png") });
	m_textures.push_back({ TextureType::GOKU_DEATH, TheResourceManager::Instance()->loadTexture("res/goku_death.png") });


	m_textures.push_back({ TextureType::VAGABOND_IDLE, TheResourceManager::Instance()->loadTexture("res/vagabond/vagabond-idle.png") });
	m_textures.push_back({ TextureType::VAGABOND_RUN, TheResourceManager::Instance()->loadTexture("res/vagabond/vagabond-run.png") });
	m_textures.push_back({ TextureType::VAGABOND_DASH, TheResourceManager::Instance()->loadTexture("res/vagabond/vagabond-dash.png") });
	m_textures.push_back({ TextureType::VAGABOND_ATTACK, TheResourceManager::Instance()->loadTexture("res/vagabond/vagabond-attack.png") });
	m_textures.push_back({ TextureType::VAGABOND_HEAVY_ATTACK, TheResourceManager::Instance()->loadTexture("res/vagabond/vagabond-heavy-attack.png") });
	m_textures.push_back({ TextureType::VAGABOND_JUMP, TheResourceManager::Instance()->loadTexture("res/vagabond/vagabond-jump.png") });
	m_textures.push_back({ TextureType::VAGABOND_JUMP_ATTACK, TheResourceManager::Instance()->loadTexture("res/vagabond/vagabond-jump-attack.png") });
	m_textures.push_back({ TextureType::VAGABOND_JUMP_FLIP, TheResourceManager::Instance()->loadTexture("res/vagabond/vagabond-jump-flip.png") });
	m_textures.push_back({ TextureType::VAGABOND_LANDING_PREP_JUMP, TheResourceManager::Instance()->loadTexture("res/vagabond/vagabond-landing-prep-jump.png") });
	m_textures.push_back({ TextureType::VAGABOND_KNOCKBACK, TheResourceManager::Instance()->loadTexture("res/vagabond/vagabond-knockback.png") });
	m_textures.push_back({ TextureType::VAGABOND_DEATH, TheResourceManager::Instance()->loadTexture("res/vagabond/vagabond-death.png") });
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