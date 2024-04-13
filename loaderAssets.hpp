#pragma once
#include <SDL.h>
#include <SDL_mixer.h>
#include <string>
#include <vector>

enum class TextureType {
	PLAY_BUTTON,
	EXIT_BUTTON,
	MAIN_BUTTON,
	RESTART_BUTTON,
	RESUME_BUTTON,
	GAME_OVER_TEXT,
	GROUND_GRASS,
	SKY,
	BACKGROUND,
	TILED_LEFT,
	TILED_RIGHT,
	TILED_UP,
	TILED_DOWN,
	GARBAGE,
	LEFT_WALL,
	EXIT_DOOR_ROOF,

	HULKING_KNIGHT,
	MR_HOANG,

	GOKU_IDLE,
	GOKU_FLYING_IDLE,

	GOKU_KI,
	GOKU_TRANSFORM_01,
	GOKU_TRANSFORM_02,

	GOKU_RUN,
	GOKU_TELEPORT,
	GOKU_JUMPING,
	GOKU_FALLING,

	GOKU_FLYING_HORIZONTAL,
	GOKU_FLYING_UP,
	GOKU_FLYING_DOWN,
	GOKU_LANDING,

	GOKU_ATTACK,
	GOKU_HEAVY_ATTACK,
	GOKU_FLYING_ATTACK,
	GOKU_KICK,
	GOKU_DEFEND,
	GOKU_FLYING_DEFEND,

	GOKU_KNOCKBACK,
	GOKU_DEATH,

	VAGABOND_IDLE,
	VAGABOND_RUN,
	VAGABOND_RUN_END,
	VAGABOND_DASH,
	VAGABOND_AIR_DASH,
	VAGABOND_ATTACK,
	VAGABOND_HEAVY_ATTACK,
	VAGABOND_BLOCK,
	VAGABOND_JUMP,
	VAGABOND_JUMP_ATTACK,
	VAGABOND_JUMP_FLIP,
	VAGABOND_LANDING_PREP_JUMP,
	VAGABOND_KNOCKBACK,
	VAGABOND_DEATH
};

enum class MusicType {
	BACKGROUND,
	ALLEY,
	DOWNTOWN,
	HEROES_BATTLE
};

enum class SoundType {
	GOKU_ATTACK,
	GOKU_KI,
};

class LoaderAssets
{
public:
	LoaderAssets();
	~LoaderAssets();
	void loadTextures();
	void loadMusics();
	void loadSounds();
	// void loadFonts();

	SDL_Texture* getTexture(const TextureType& name);
	Mix_Music* getMusic(const MusicType& name);
	Mix_Chunk* getSound(const SoundType& name);
	// TTF_Font *getFont(const std::string& name) { return m_fonts[name]; }

private:
	std::vector<std::pair<TextureType, SDL_Texture*>> m_textures;
	std::vector<std::pair<MusicType, Mix_Music*>> m_musics;
	std::vector<std::pair<SoundType, Mix_Chunk*>> m_sounds;
	// std::map<std::string, TTF_Font *> m_fonts;
};