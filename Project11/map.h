//# include<SFML/Graphics.hpp>
# include"tile.h"
class map
{
public:
	map();
 
	void initialize();
	void load();
	void update(double deltatime);
	void Draw(sf::RenderWindow& window);
};
/*#pragma once
# include<SFML/Graphics.hpp>
# include"tile.h"
 
class Map
{
	sf::Texture tileSheetTexture;


	Tile* tiles;
	int totalTiles;
	int tileWidth;
	int tileHeight;
	int totalTilesX;
	int totalTilesY;
	int mapNumbers[6] =
	{120,121,122 , 
	144,145,146
	};
	Sprite mapSprites[6];
public:
	Map();
	~Map();
	void initialize();
	void load();
	void update(double deltatime);
	void Draw(sf::RenderWindow& window);
};

*/