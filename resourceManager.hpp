#pragma once
#include <SDL.h>
#include <SDL_image.h>

#include "entity.hpp"

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
	void drawPlayer(Entity& entity);
	void drawEnemy1(Entity& entity);
	void drawEnemy2(Entity& entity);
	void display();

private:
	ResourceManager() {}
	static ResourceManager* s_pInstance;
	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;
};

typedef ResourceManager TheResourceManager;