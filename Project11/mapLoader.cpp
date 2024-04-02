#include "mapLoader.h"
# include<fstream>
# include<string>
# include"mapdata.h"
using namespace std;


void mapLoader::Load(string filename)
{
	MapData data;
	string line;
	ifstream file(filename);
	bool isMapValid = false;
	if (file.is_open()) {
		while (getline(file, line)) {
			if (!isMapValid) {
				if (line == "[Map]") {
					isMapValid = true;
					continue;
				}
				else {
					cout << "rmap file is not valid" << endl;
				}
			}
			if (isMapValid) {
				int count = line.find('=');
				string variable = line.substr(0, count);
				string value = line.substr(count + 1, line.length() - count);
				cout << "My variable is called " << variable << endl;
				cout << "My value is " << value << endl;
				 

				data.tilesheet = "";
				data.name = "";

				data.tileWidth = 0;
				data.tileHeight = 0;

				data.scaleX = 0;
				data.scaleY = 0;

				data.dataLength = 0;
				data.data = nullptr;
				 
 
			}
		}
		file.close();
	}
	else {
		cout << " unable to open " << filename << endl;
	}
}
