#pragma once
#include <SDL.h>
#include <SDL_image.h>

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
	int getRefreshRate();
	void clean();
	void clear();
	void draw(Entity& entity);
	void drawFrame(Entity& entity);
	void drawRect(SDL_Rect rect);
	void drawPlayer(Player& player);
	void drawPlayerKI(Player& player);
	void drawEnemy1(Enemy& enemy);
	void drawEnemy2(Enemy& enemy);
	void display();

private:
	ResourceManager() {}
	static ResourceManager* s_pInstance;
	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;
};

typedef ResourceManager TheResourceManager;