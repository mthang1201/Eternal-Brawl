#pragma once
#include <SDL.h>
#include <string>
#include <vector>
#include <map>

class LoaderAssets
{
public:
    LoaderAssets();

    void loadTextures();
    // void loadSounds();
    // void loadFonts();

    SDL_Texture *getTexture(const std::string& name) { return m_textures[name]; }
    // Mix_Chunk *getSound(const std::string& name) { return m_sounds[name]; }
    // TTF_Font *getFont(const std::string& name) { return m_fonts[name]; }

private:
    std::map<std::string, SDL_Texture *> m_textures;
    // std::map<std::string, Mix_Chunk *> m_sounds;
    // std::map<std::string, TTF_Font *> m_fonts;
};