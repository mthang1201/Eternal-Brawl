#pragma once
#include <SDL.h>
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

    HULKING_KNIGHT,
    MR_HOANG,

    GOKU_IDLE,
    GOKU_MOVEMENT,
    GOKU_JUMPING,
    GOKU_FALLING,

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

class LoaderAssets
{
public:
    LoaderAssets();
    ~LoaderAssets();
    void loadTextures();
    // void loadSounds();
    // void loadFonts();

    SDL_Texture *getTexture(const TextureType& name);
    // Mix_Chunk *getSound(const std::string& name) { return m_sounds[name]; }
    // TTF_Font *getFont(const std::string& name) { return m_fonts[name]; }

private:
    std::vector<std::pair<TextureType, SDL_Texture*>> m_textures;
    // std::map<std::string, Mix_Chunk *> m_sounds;
    // std::map<std::string, TTF_Font *> m_fonts;
};