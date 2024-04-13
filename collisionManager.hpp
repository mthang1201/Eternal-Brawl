#pragma once
#include <SDL.h>
#include <vector>

#include "entity.hpp"
#include "player.hpp"
#include "enemy.hpp"
#include "tileLayer.hpp"
#include "vector2f.hpp"

class CollisionManager
{
public:
	void checkPlayerEnemyBulletCollision(Player* pPlayer);
	void checkPlayerEnemyCollision(Player* pPlayer, const std::vector<Enemy*>& enemies);
	//void checkEnemyPlayerBulletCollision(const std::vector<GameObject*>& objects);
	void checkPlayerTileCollision(Player* pPlayer, const std::vector<TileLayer*>& collisionLayers);
	void setCollisionLayers(std::vector<TileLayer*>* layers) { m_pCollisionLayers = layers; }

private:
	std::vector<TileLayer*>* m_pCollisionLayers;
};

void CollisionManager::checkPlayerTileCollision(Player* pPlayer, const std::vector<TileLayer*>& collisionLayers)
{
	// iterate through collision layers
	for (std::vector<TileLayer*>::const_iterator it = collisionLayers.begin(); it != collisionLayers.end(); ++it)
	{
		TileLayer* pTileLayer = (*it);
		std::vector<std::vector<int>> tiles = pTileLayer->getTileIDs();
		// get this layers position
		Vector2f layerPos = pTileLayer->getPos();
		int x, y, tileColumn, tileRow, tileid = 0;
		// calculate position on tile map
		x = layerPos.getX() / pTileLayer->getTileSize();
		y = layerPos.getY() / pTileLayer->getTileSize();
		// if moving forward or upwards
		if (pPlayer->getVelocity().getX() >= 0 || pPlayer->getVelocity().getY() >= 0)
		{
			tileColumn = ((pPlayer->getPos().getX() + pPlayer->getWidth()) / pTileLayer->getTileSize());
			tileRow = ((pPlayer->getPos().getY() + pPlayer->getHeight()) / pTileLayer->getTileSize());
			tileid = tiles[tileRow + y][tileColumn + x];
		}
		else if (pPlayer->getVelocity().getX() < 0 || pPlayer->getVelocity().getY() < 0) // if moving backwards or downwards
		{
			tileColumn = pPlayer->getPos().getX() / pTileLayer->getTileSize();
			tileRow = pPlayer->getPos().getY() / pTileLayer->getTileSize();
			tileid = tiles[tileRow + y][tileColumn + x];
		}
		if (tileid != 0) // if the tile id not blank then collide
		{
			pPlayer->collision();
		}
	}
}