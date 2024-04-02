
#include "mappi.h"
#include<iostream>
 
using namespace sf;
mappi::mappi(): 
tileWidth(16),
tileHeight(16),
totalTilesX(0),
 totalTilesY(0),
	totalTiles(0),mapWidth(3),
	mapHeight(2),tiles(nullptr)
{
}

mappi::~mappi()
{
}

void mappi::initialize()
{
}

void mappi::load()
{
	if (tileSheetTexture.loadFromFile("C:/Users/hp/source/repos/Project11/Project11/assets/world/prision/oBagWb.png")) {
		std::cout << "World prision title sheet in assets has been loaded successfully" << std::endl;
		totalTilesX = tileSheetTexture.getSize().x / tileWidth;
		totalTilesY = tileSheetTexture.getSize().y / tileHeight;
		totalTiles = totalTilesX * totalTilesY;

		 tiles = new Tile[totalTiles];

		for (int y = 0; y < totalTilesY; y++) {
			for (int x = 0; x < totalTilesX; x++) {
				int i = x + y * totalTilesX;
				 tiles[i].id = i;

				tiles[i].position = Vector2i(x * tileWidth, y * tileHeight);
 

			}
		}
	}
	else {
		std::cout << "fail to load world prision tilesheet in Assets  " << std::endl;
	}
	for (size_t y = 0; y < mapHeight; y++)
	{
		for (size_t x = 0; x < mapWidth; x++)
		{
			int i = x + y * mapWidth;
			int index = mapNumbers[i];
			mapSprites[i].setTexture(tileSheetTexture);
			mapSprites[i].setTextureRect(IntRect(
				tiles[index].position.x,
				tiles[index].position.y,
				tileWidth,
				tileHeight)
			);
			mapSprites[i].setScale(Vector2f(5, 5));
			mapSprites[i].setPosition(Vector2f(x * tileWidth * mapSprites[i].getScale().x, 100 + y * tileHeight * mapSprites[i].getScale().y));
		}
	}
}

void mappi::update(double deltatime)
{
}

void mappi::Draw(sf::RenderWindow& window)
{
	for (size_t i = 0; i < mapSize; i++) 
		window.draw(mapSprites[i]);
	 
}
