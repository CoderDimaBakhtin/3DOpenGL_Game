#include "Map.h"




Map::Map() {
	std::cout << "Map";
	//poligon.push_back(std::make_shared<PoligonObject>("button.png", 700, 210, 0, 1, 0, 0, 1, 1, 0, 10,10,10));
	poligon.push_back(std::make_shared<PoligonObject>("flour.png", 1200, 799, 10, 10, 10));

	/*poligon.push_back(std::make_shared<PoligonObject>("button.png", 700, 210,10, 10, 10));
	poligon.push_back(std::make_shared<PoligonObject>("button.png", 700, 210, 1, 5, 10));*/


	//poligon.push_back(std::make_shared<PoligonObject>("cards.png", 910, 455,90,1,0,0,0,0,-2, 10, 10, 10));
	poligon.push_back(std::make_shared<PoligonObject>("cards.png", 910, 455, 1, 1, 1));
	poligon.push_back(std::make_shared<PoligonObject>("cat.jpg", 600, 459, 10, 10, 10));
	
}






void Map::paint() {
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			glPushMatrix();
			glTranslatef(10*i,10*j,0);
			poligon[0]->Paint();
			glPopMatrix();
		}
	}
	
	for (int k = 0; k < 1; k++) {
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				//PaintCube(poligon[2], 5 + i * 0.5, 5 + j * 0.5, k*0.5);
				PaintCube(poligon[1], 0, 0, 0);
			}
		}
	}
	
	

	
	
	
}

Map::~Map() {
	//std::cout << "~Map";
}