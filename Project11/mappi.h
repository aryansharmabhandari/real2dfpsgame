#pragma once
# include<SFML/Graphics.hpp>
# include"tile.h"
class mappi
{private:
	sf::Texture tileSheetTexture;


	Tile* tiles ;
	int totalTiles ;
	int tileWidth;
	int tileHeight;
	int totalTilesX;
	int totalTilesY;
	static const int mapSize = 6;
	int mapHeight;
	int mapWidth;
	int mapNumbers[mapSize] =
	{ 120,121,122 ,                          
	144,145,146
	};
	sf:: Sprite mapSprites[mapSize];
public:
	mappi();
	~mappi();
	void initialize();
	void load();
	void update(double deltatime);
	void Draw(sf::RenderWindow& window);
};

