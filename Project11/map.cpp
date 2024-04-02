/*#include "map.h"

#include<iostream>
 
using namespace sf;
Map::Map():
	  tileWidth(16),
	  tileHeight(16),
	totalTilesX(0)
,totalTilesY(0)
{
}
Map::~Map() {

}

void Map::initialize()
{
}

void Map::load()
{if (tileSheetTexture.loadFromFile("C:/Users/hp/source/repos/Project11/Project11/assets/world/prision/oBagWb.png")) {
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
					
					//IntRect( , tileWidth, tileHeight);

				//tiles[i].sprite.setTexture(tileSheetTexture);
				//tiles[i].sprite.setTextureRect(IntRect(x * tileWidth, y * tileHeight, tileWidth, tileHeight));
				//tiles[i].sprite.setScale(Vector2f(5, 5));
				//tiles[i].sprite.setPosition(Vector2f(  x * tileWidth * 5, 50 + y * tileWidth * 5));

			}
		}
	}
	else {
		std::cout << "fail to load world prision tilesheet in Assets  " <<std:: endl;
	}
for (size_t y = 0; y <2; y++)
 {
	for (size_t x = 0; x <3; x++)
	 {
	int i = x + y *3;
		int index = mapNumbers[i];
		mapSprites[i].setTexture(tileSheetTexture);
		mapSprites[i].setTextureRect(IntRect(
		tiles[index].position.x,
			tiles[index].position.y,
			tileWidth,
			tileHeight)
			);
		mapSprites[i].setScale(Vector2f(5,5));
		mapSprites[i].setPosition(Vector2f(x*16*5,100+y*16*5));
	}
}
}

void Map::update(double deltatime)
{
}

void Map::Draw(sf::RenderWindow& window)
{
	for (size_t i = 0; i < totalTiles; i++) {
		window.draw(mapSprites[i]);
	}
 
}*/

#include "map.h"

void map::initialize()
{
}

void map::load()
{
}

void map::update(double deltatime)
{
}

void map::Draw(sf::RenderWindow& window)
{
}
