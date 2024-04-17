#include <SDL.h>
#include <SDL_image.h>

#include "loaderParams.hpp"
#include "vector2f.hpp"
#include "loaderAssets.hpp"
#include "resourceManager.hpp"

LoaderAssets::LoaderAssets()
{
	loadTextures();
	loadMusics();
	loadSounds();
	// loadFonts();
}

LoaderAssets::~LoaderAssets()
{
	for (auto& pair : m_textures)
	{
		SDL_DestroyTexture(pair.second);
	}
	for (auto& pair : m_musics)
	{
		Mix_FreeMusic(pair.second);
	}
	for (auto& pair : m_sounds)
	{
		Mix_FreeChunk(pair.second);
	}
}

void LoaderAssets::loadTextures()
{
	m_textures.push_back({ TextureType::PLAY_BUTTON, TheResourceManager::Instance()->loadTexture("res/button.png") });
	m_textures.push_back({ TextureType::INSTRUCTION_BUTTON, TheResourceManager::Instance()->loadTexture("res/instruction.png") });
	m_textures.push_back({ TextureType::EXIT_BUTTON, TheResourceManager::Instance()->loadTexture("res/exit.png") });
	m_textures.push_back({ TextureType::MAIN_BUTTON, TheResourceManager::Instance()->loadTexture("res/main.png") });
	m_textures.push_back({ TextureType::RESTART_BUTTON, TheResourceManager::Instance()->loadTexture("res/restart.png") });
	m_textures.push_back({ TextureType::RESUME_BUTTON, TheResourceManager::Instance()->loadTexture("res/resume.png") });
	m_textures.push_back({ TextureType::GAME_OVER_TEXT, TheResourceManager::Instance()->loadTexture("res/gameover.png") });

	//m_textures.push_back({ TextureType::GROUND_GRASS, TheResourceManager::Instance()->loadTexture("res/ground_grass_1.png") });
	//m_textures.push_back({ TextureType::SKY, TheResourceManager::Instance()->loadTexture("res/skye_0.png") });

	m_textures.push_back({ TextureType::MENU_BACKGROUND, TheResourceManager::Instance()->loadTexture("res/city/menu_background.png") });
	m_textures.push_back({ TextureType::INSTRUCTION_BACKGROUND, TheResourceManager::Instance()->loadTexture("res/city/instruction_background.png") });
	m_textures.push_back({ TextureType::BACKGROUND, TheResourceManager::Instance()->loadTexture("res/city/background.png") });
	m_textures.push_back({ TextureType::BACKGROUND_BLUR, TheResourceManager::Instance()->loadTexture("res/city/background_blur.png") });
	/*m_textures.push_back({ TextureType::TILED_LEFT, TheResourceManager::Instance()->loadTexture("res/city/tiled_left.png") });
	m_textures.push_back({ TextureType::TILED_RIGHT, TheResourceManager::Instance()->loadTexture("res/city/tiled_right.png") });
	m_textures.push_back({ TextureType::TILED_UP, TheResourceManager::Instance()->loadTexture("res/city/tiled_up.png") });
	m_textures.push_back({ TextureType::TILED_DOWN, TheResourceManager::Instance()->loadTexture("res/city/tiled_down.png") });
	m_textures.push_back({ TextureType::GARBAGE, TheResourceManager::Instance()->loadTexture("res/city/garbage.png") });
	m_textures.push_back({ TextureType::LEFT_WALL, TheResourceManager::Instance()->loadTexture("res/city/leftWall.png") });
	m_textures.push_back({ TextureType::EXIT_DOOR_ROOF, TheResourceManager::Instance()->loadTexture("res/city/exitDoorRoof.png") });*/
	//m_textures.push_back({ TextureType::HULKING_KNIGHT, TheResourceManager::Instance()->loadTexture("res/hulking_knight.png") });
	//m_textures.push_back({ TextureType::MR_HOANG, TheResourceManager::Instance()->loadTexture("res/hoang.jpg") });

	m_textures.push_back({ TextureType::GOKU_FLYING_IDLE, TheResourceManager::Instance()->loadTexture("res/goku_flying_idle.png") });
	m_textures.push_back({ TextureType::GOKU_IDLE, TheResourceManager::Instance()->loadTexture("res/goku_idle.png") });

	m_textures.push_back({ TextureType::GOKU_KI, TheResourceManager::Instance()->loadTexture("res/goku_ki.png") });
	m_textures.push_back({ TextureType::GOKU_TRANSFORM_01, TheResourceManager::Instance()->loadTexture("res/goku_transform/goku_transform_01.png") });
	m_textures.push_back({ TextureType::GOKU_TRANSFORM_02, TheResourceManager::Instance()->loadTexture("res/goku_transform/goku_transform_02.png") });

	//m_textures.push_back({ TextureType::GOKU_RUN, TheResourceManager::Instance()->loadTexture("res/goku_run.png") });
	m_textures.push_back({ TextureType::GOKU_TELEPORT, TheResourceManager::Instance()->loadTexture("res/goku_teleport.png") });
	m_textures.push_back({ TextureType::GOKU_JUMPING, TheResourceManager::Instance()->loadTexture("res/3.png") });
	m_textures.push_back({ TextureType::GOKU_FALLING, TheResourceManager::Instance()->loadTexture("res/3.png") });

	m_textures.push_back({ TextureType::GOKU_FLYING_HORIZONTAL, TheResourceManager::Instance()->loadTexture("res/goku_flying_horizontal.png") });
	m_textures.push_back({ TextureType::GOKU_FLYING_UP, TheResourceManager::Instance()->loadTexture("res/goku_flying_up.png") });
	m_textures.push_back({ TextureType::GOKU_FLYING_DOWN, TheResourceManager::Instance()->loadTexture("res/goku_flying_down.png") });
	m_textures.push_back({ TextureType::GOKU_LANDING, TheResourceManager::Instance()->loadTexture("res/goku_landing.png") });

	//m_textures.push_back({ TextureType::GOKU_ATTACK, TheResourceManager::Instance()->loadTexture("res/goku_attack.png") });
	m_textures.push_back({ TextureType::GOKU_HEAVY_ATTACK, TheResourceManager::Instance()->loadTexture("res/goku_heavy_attack.png") });
	//m_textures.push_back({ TextureType::GOKU_FLYING_ATTACK, TheResourceManager::Instance()->loadTexture("res/goku_flying_attack.png") });
	m_textures.push_back({ TextureType::GOKU_KICK, TheResourceManager::Instance()->loadTexture("res/goku_kick.png") });
	m_textures.push_back({ TextureType::GOKU_DEFEND, TheResourceManager::Instance()->loadTexture("res/goku_defend.png") });
	m_textures.push_back({ TextureType::GOKU_FLYING_DEFEND, TheResourceManager::Instance()->loadTexture("res/goku_flying_defend.png") });

	//m_textures.push_back({ TextureType::GOKU_KNOCKBACK, TheResourceManager::Instance()->loadTexture("res/goku_knockback.png") });
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

void LoaderAssets::loadMusics()
{
	m_musics.push_back({ MusicType::ALLEY, TheResourceManager::Instance()->loadMusic("res/music/Alley.mp3") });
	m_musics.push_back({ MusicType::DOWNTOWN, TheResourceManager::Instance()->loadMusic("res/music/Downtown.mp3") });
	m_musics.push_back({ MusicType::HEROES_BATTLE, TheResourceManager::Instance()->loadMusic("res/music/HeroesBattle.mp3") });
}

void LoaderAssets::loadSounds()
{
	m_sounds.push_back({ SoundType::MENU_OK, TheResourceManager::Instance()->loadSound("res/sound/MenuOK.wav") });
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

Mix_Music* LoaderAssets::getMusic(const MusicType& name)
{
	for (const auto& pair : m_musics)
	{
		if (pair.first == name)
		{
			return pair.second;
		}
	}
	return nullptr;
}

Mix_Chunk* LoaderAssets::getSound(const SoundType& name)
{
	for (const auto& pair : m_sounds)
	{
		if (pair.first == name)
		{
			return pair.second;
		}
	}
	return nullptr;
}

// void LoaderAssets::loadFonts()
// {
//     m_fonts["main_font"] = TheResourceManager::Instance()->loadFont("path_to_main_font", 24);
// }