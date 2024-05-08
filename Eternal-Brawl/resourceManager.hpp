#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>

#include "entity.hpp"
#include "player.hpp"
#include "enemy.hpp"

class ResourceManager
{
public:
	static ResourceManager* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new ResourceManager();
			return s_pInstance;
		}
		return s_pInstance;
	}

	bool init(const char* title, int width, int height);

	SDL_Texture* loadTexture(const char* filePath);
	Mix_Music* loadMusic(const char* filePath);
	Mix_Chunk* loadSound(const char* filePath);
	int getRefreshRate();
	void clean();
	void clear();

	void setDrawColor(SDL_Color);

	void draw(Entity& entity);
	void drawFrame(Entity& entity);
	void drawRect(SDL_Rect rect);
	void drawBar(SDL_Rect bar, int realBarWidth, SDL_Color color);
	void drawLives(int lives);
	void drawScores(int scores);
	void drawScores2(int scores);
	void drawHealthBar(SDL_Rect healthBarBackground, int healthBarWidth, SDL_Color healthColor);
	void drawPlayer(Player& player);
	void drawPlayerKI(Player& player);
	void drawEnemy1(Enemy& enemy);
	void drawEnemy2(Enemy& enemy);
	void drawEnemyAttack(Enemy& enemy);
	void drawEnemyHeavyAttack(Enemy& enemy);

	void playMusic(Mix_Music* pMusic, int loop);
	void playSound(Mix_Chunk* pSound, int loop);
	void playPlayerSound(Player& player);
	void playEnemySound(Enemy& enemy);


	void display();

private:
	ResourceManager();
	static ResourceManager* s_pInstance;
	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;
};

typedef ResourceManager TheResourceManager;