#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <iostream>

#include "resourceManager.hpp"
#include "entity.hpp"
#include "player.hpp"
#include "enemy.hpp"

ResourceManager* ResourceManager::s_pInstance = nullptr;

ResourceManager::ResourceManager() : m_pWindow(nullptr), m_pRenderer(nullptr)
{
}

bool ResourceManager::init(const char* title, int width, int height)
{
	if (SDL_Init(SDL_INIT_VIDEO) > 0)
	{
		std::cout << "HEY... SDL_Init HAS FAILED. SDL_ERROR: " << SDL_GetError() << std::endl;
		return false;
	}

	if (!(IMG_Init(IMG_INIT_PNG)))
	{
		std::cout << "IMG_Init has failed. Error: " << SDL_GetError() << std::endl;
		return false;
	}

	if (!(IMG_Init(IMG_INIT_JPG)))
	{
		std::cout << "IMG_Init has failed. Error: " << SDL_GetError() << std::endl;
		return false;
	}

	if (SDL_Init(SDL_INIT_AUDIO) < 0) {
		std::cout << "Failed to initialize SDL: " << SDL_GetError() << std::endl;
		return false;
	}

	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
		std::cout << "Failed to initialize SDL_mixer: " << Mix_GetError() << std::endl;
		SDL_Quit();
		return false;
	}

	m_pWindow = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);

	if (m_pWindow == nullptr)
	{
		std::cout << "Window failed to init. Error: " << SDL_GetError() << std::endl;
		return false;
	}

	m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	// Virtual machine
	// renderer = SDL_CreateSoftwareRenderer(SDL_GetWindowSurface(m_pWindow));

	if (m_pRenderer == nullptr)
	{
		std::cout << "Renderer failed to init. Error: " << SDL_GetError() << std::endl;
		return false;
	}

	return true;
}

SDL_Texture* ResourceManager::loadTexture(const char* filePath)
{
	SDL_Texture* texture = nullptr;
	texture = IMG_LoadTexture(m_pRenderer, filePath);

	if (texture == nullptr)
		std::cout << "Failed to load texture. Error: " << SDL_GetError() << std::endl;
	return texture;
}

Mix_Music* ResourceManager::loadMusic(const char* filePath)
{
	Mix_Music* music = nullptr;
	music = Mix_LoadMUS(filePath);

	if (music == nullptr)
		std::cout << "Failed to load music. Error: " << SDL_GetError() << std::endl;
	return music;
}

Mix_Chunk* ResourceManager::loadSound(const char* filePath)
{
	Mix_Chunk* sound = nullptr;
	sound = Mix_LoadWAV(filePath);

	if (sound == nullptr)
		std::cout << "Failed to load sound. Error: " << SDL_GetError() << std::endl;
	return sound;
}

int ResourceManager::getRefreshRate()
{
	int displayIndex = SDL_GetWindowDisplayIndex(m_pWindow);

	SDL_DisplayMode mode;

	SDL_GetDisplayMode(displayIndex, 0, &mode);

	return mode.refresh_rate;
}

void ResourceManager::clean()
{
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	Mix_CloseAudio();
}

void ResourceManager::clear()
{
	SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 0, 255);
	SDL_RenderClear(m_pRenderer);
}

void ResourceManager::setDrawColor(SDL_Color)
{
	SDL_SetRenderDrawColor(m_pRenderer, 100, 100, 100, 255);
}

void ResourceManager::draw(Entity& entity)
{
	SDL_Rect src;
	src.x = entity.getCurrentFrame().x;
	src.y = entity.getCurrentFrame().y;
	src.w = entity.getCurrentFrame().w;
	src.h = entity.getCurrentFrame().h;

	SDL_Rect dst;
	dst.x = entity.getPos().getX();
	dst.y = entity.getPos().getY();
	dst.w = entity.getCurrentFrame().w;
	dst.h = entity.getCurrentFrame().h;

	SDL_RenderCopy(m_pRenderer, entity.getTex(), NULL, &dst);
}

void ResourceManager::drawFrame(Entity& entity)
{
	SDL_Rect src;
	src.x = entity.getCurrentFrame().w * entity.getCurrentFrame().x;
	src.y = entity.getCurrentFrame().h * entity.getCurrentFrame().y;
	src.w = entity.getCurrentFrame().w;
	src.h = entity.getCurrentFrame().h;

	SDL_Rect dst;
	dst.x = entity.getPos().getX();
	dst.y = entity.getPos().getY();
	dst.w = entity.getCurrentFrame().w;
	dst.h = entity.getCurrentFrame().h;

	if (entity.getFlip()) SDL_RenderCopyEx(m_pRenderer, entity.getTex(), &src, &dst, 0, 0, SDL_FLIP_HORIZONTAL);
	else SDL_RenderCopy(m_pRenderer, entity.getTex(), &src, &dst);
}

void ResourceManager::drawRect(SDL_Rect rect)
{
	SDL_SetRenderDrawColor(m_pRenderer, 255, 0, 0, 255);
	SDL_RenderDrawRect(m_pRenderer, &rect);
	SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 255, 255);
}

void ResourceManager::drawBar(SDL_Rect bar, int realBarWidth, SDL_Color barColor)
{
	SDL_SetRenderDrawColor(m_pRenderer, 100, 100, 100, 255);
	SDL_RenderFillRect(m_pRenderer, &bar);

	// Render the actual health bar (green or red)
	SDL_SetRenderDrawColor(m_pRenderer, barColor.r, barColor.g, barColor.b, barColor.a);
	SDL_Rect realBar = { bar.x, bar.y, realBarWidth, bar.h };
	SDL_RenderFillRect(m_pRenderer, &realBar);
}

void ResourceManager::drawHealthBar(SDL_Rect healthBarBackground, int healthBarWidth, SDL_Color healthColor)
{
	SDL_SetRenderDrawColor(m_pRenderer, 100, 100, 100, 255);
	SDL_RenderFillRect(m_pRenderer, &healthBarBackground);

	// Render the actual health bar (green or red)
	SDL_SetRenderDrawColor(m_pRenderer, healthColor.r, healthColor.g, healthColor.b, healthColor.a);
	SDL_Rect healthBar = { healthBarBackground.x, healthBarBackground.y, healthBarWidth, healthBarBackground.h };
	SDL_RenderFillRect(m_pRenderer, &healthBar);
}

void ResourceManager::drawPlayer(Player& player)
{
	SDL_Rect src;
	src.x = player.getCurrentFrame().w * player.getCurrentFrame().x;
	src.y = player.getCurrentFrame().h * player.getCurrentFrame().y;
	src.w = player.getCurrentFrame().w;
	src.h = player.getCurrentFrame().h;

	SDL_Rect dst;
	dst.x = player.getPos().getX();
	dst.y = player.getPos().getY();
	dst.w = player.getCurrentFrame().w;
	dst.h = player.getCurrentFrame().h;

	SDL_SetRenderDrawColor(m_pRenderer, 255, 0, 0, 255);
	SDL_RenderDrawRect(m_pRenderer, &dst);
	SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 255, 255);

	if (player.getFlip()) SDL_RenderCopyEx(m_pRenderer, player.getTex(), &src, &dst, 0, 0, SDL_FLIP_HORIZONTAL);
	else SDL_RenderCopy(m_pRenderer, player.getTex(), &src, &dst);
}

void ResourceManager::drawPlayerKI(Player& player)
{
	SDL_Rect src;
	src.x = player.getCurrentFrame().w * player.getCurrentFrame().x;
	src.y = player.getCurrentFrame().h * player.getCurrentFrame().y;
	src.w = player.getCurrentFrame().w;
	src.h = player.getCurrentFrame().h;

	SDL_Rect dst;
	dst.x = player.getPos().getX();
	dst.y = player.getPos().getY() - 40;
	dst.w = player.getCurrentFrame().w;
	dst.h = player.getCurrentFrame().h;

	SDL_SetRenderDrawColor(m_pRenderer, 255, 0, 0, 255);
	SDL_RenderDrawRect(m_pRenderer, &dst);
	SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 255, 255);

	if (player.getFlip()) SDL_RenderCopyEx(m_pRenderer, player.getTex(), &src, &dst, 0, 0, SDL_FLIP_HORIZONTAL);
	else SDL_RenderCopy(m_pRenderer, player.getTex(), &src, &dst);
}

void ResourceManager::drawEnemy1(Enemy& enemy)
{
	SDL_Rect src;
	src.x = enemy.getCurrentFrame().w * enemy.getCurrentFrame().x;
	src.y = enemy.getCurrentFrame().h * enemy.getCurrentFrame().y;
	src.w = enemy.getCurrentFrame().w;
	src.h = enemy.getCurrentFrame().h;

	SDL_Rect dst;
	dst.x = enemy.getPos().getX();
	dst.y = enemy.getPos().getY();
	dst.w = enemy.getCurrentFrame().w;
	dst.h = enemy.getCurrentFrame().h;

	SDL_SetRenderDrawColor(m_pRenderer, 255, 0, 0, 255);
	SDL_RenderDrawRect(m_pRenderer, &dst);
	SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 255, 255);

	if (enemy.getFlip()) SDL_RenderCopyEx(m_pRenderer, enemy.getTex(), &src, &dst, 0, 0, SDL_FLIP_HORIZONTAL);
	else SDL_RenderCopy(m_pRenderer, enemy.getTex(), &src, &dst);
}

void ResourceManager::drawEnemy2(Enemy& enemy)
{
	SDL_Rect src;
	src.x = enemy.getCurrentFrame().w * enemy.getCurrentFrame().x;
	src.y = enemy.getCurrentFrame().h * enemy.getCurrentFrame().y;
	src.w = enemy.getCurrentFrame().w;
	src.h = enemy.getCurrentFrame().h;

	SDL_Rect dst;
	dst.x = enemy.getPos().getX();
	dst.y = enemy.getPos().getY();
	dst.w = enemy.getCurrentFrame().w * 4;
	dst.h = enemy.getCurrentFrame().h * 4;

	SDL_SetRenderDrawColor(m_pRenderer, 255, 0, 0, 255);
	SDL_RenderDrawRect(m_pRenderer, &dst);
	SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 255, 255);

	if (enemy.getFlip()) SDL_RenderCopyEx(m_pRenderer, enemy.getTex(), &src, &dst, 0, 0, SDL_FLIP_HORIZONTAL);
	else SDL_RenderCopy(m_pRenderer, enemy.getTex(), &src, &dst);
}

void ResourceManager::drawEnemyAttack(Enemy& enemy)
{
	SDL_Rect src;
	src.x = enemy.getCurrentFrame().w * enemy.getCurrentFrame().x;
	src.y = enemy.getCurrentFrame().h * enemy.getCurrentFrame().y;
	src.w = enemy.getCurrentFrame().w;
	src.h = enemy.getCurrentFrame().h;

	SDL_Rect dst;
	dst.x = enemy.getPos().getX() - 70;
	dst.y = enemy.getPos().getY() - 45;
	dst.w = enemy.getCurrentFrame().w * 0.88;
	dst.h = enemy.getCurrentFrame().h * 0.88;

	SDL_SetRenderDrawColor(m_pRenderer, 255, 0, 0, 255);
	SDL_RenderDrawRect(m_pRenderer, &dst);
	SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 255, 255);

	if (enemy.getFlip()) SDL_RenderCopyEx(m_pRenderer, enemy.getTex(), &src, &dst, 0, 0, SDL_FLIP_HORIZONTAL);
	else SDL_RenderCopy(m_pRenderer, enemy.getTex(), &src, &dst);
}

void ResourceManager::drawEnemyHeavyAttack(Enemy& enemy)
{
	SDL_Rect src;
	src.x = enemy.getCurrentFrame().w * enemy.getCurrentFrame().x;
	src.y = enemy.getCurrentFrame().h * enemy.getCurrentFrame().y;
	src.w = enemy.getCurrentFrame().w;
	src.h = enemy.getCurrentFrame().h;

	SDL_Rect dst;
	dst.x = enemy.getPos().getX();
	dst.y = enemy.getPos().getY();
	dst.w = enemy.getCurrentFrame().w;
	dst.h = enemy.getCurrentFrame().h;

	SDL_SetRenderDrawColor(m_pRenderer, 255, 0, 0, 255);
	SDL_RenderDrawRect(m_pRenderer, &dst);
	SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 255, 255);

	if (enemy.getFlip()) SDL_RenderCopyEx(m_pRenderer, enemy.getTex(), &src, &dst, 0, 0, SDL_FLIP_HORIZONTAL);
	else SDL_RenderCopy(m_pRenderer, enemy.getTex(), &src, &dst);
}

void ResourceManager::playMusic(Mix_Music* pMusic, int loop)
{
	if (pMusic == nullptr)
	{
		std::cout << "Failed to play music. Error: " << SDL_GetError() << std::endl;
	}
	else
	{
		Mix_PlayMusic(pMusic, loop);
	}
}

void ResourceManager::playSound(Mix_Chunk* pSound, int loop)
{
	if (pSound == nullptr)
	{
		std::cout << "Failed to play sound. Error: " << SDL_GetError() << std::endl;
	}
	else
	{
		Mix_PlayChannel(-1, pSound, loop);
	}
}

void ResourceManager::playPlayerSound(Player& player)
{
}

void ResourceManager::playEnemySound(Enemy& enemy)
{
}

void ResourceManager::display()
{
	SDL_RenderPresent(m_pRenderer);
	// Virtual machine
	// SDL_UpdateWindowSurface(m_pWindow);
}