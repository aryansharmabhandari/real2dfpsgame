#pragma once
# include<string>
using namespace std;

struct MapData {
	string tilesheet = "";
	string name = "";
	int tileWidth = 0;
	int tileHeight = 0;
	int scaleX = 0;
	int scaleY = 0;
	int dataLength = 0;
	int* data = nullptr;
};
