#include "Map.h"




Map::Map() {
	std::cout << "Map";
	//poligon.push_back(std::make_shared<PoligonObject>("button.png", 700, 210, 0, 1, 0, 0, 1, 1, 0, 10,10,10));
	poligon.push_back(std::make_shared<PoligonObject>("flour.png", 1200, 799, 10, 10, 10));
	
	//poligon.push_back(std::make_shared<PoligonObject>("cards.png", 910, 455,90,1,0,0,0,0,-2, 10, 10, 10));
	//poligon.push_back(std::make_shared<PoligonObject>("cards.png", 910, 455, 1, 1, 1));
	srand(time(0));
	poligon.push_back(std::make_shared<Enemy>(this,"cards.png", 910, 455, 1, 1, 1));
	poligon.push_back(std::make_shared<Enemy>(this, "flour.png", 910, 455, 0, 4,
		0, 1, /*4*/0, /*4*/0, 0, 5, 5, 1));
	poligon.push_back(std::make_shared<Enemy>(this, "cards.png", 910, 455, 1, 1, 1));
	poligon.push_back(std::make_shared<Enemy>(this, "flour.png", 910, 455, 1, 1, 1));
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
	for (int i = 1; i < poligon.size(); i++) {
		poligon[i]->Paint();
	}
	

	////poligon[1]->SetPosition(0,  0, 0, 0,  3, 3, 0,  1, 1, 1);
	//poligon[1]->Paint();
	////poligon[2]->SetPosition(0, 0, 0, 0, 0, 0, 0, 1, 1, 1);
	//poligon[2]->Paint();
	//poligon[3]->Paint();
	//for (int i = 0; i < 2; i++) {
	//	for (int j = 0; j < 2; j++) {
	//		//poligon[1]->SetPosition(0, 0, 0, 0, i, j, 0, 1, 1, 1);
	//		//poligon[1]->Paint();
	//	}
	//}
	//for (int k = 0; k < 1; k++) {
	//	for (int i = 0; i < 1; i++) {
	//		for (int j = 0; j < 1; j++) {
	//			//PaintCube(poligon[2], 5 + i * 0.5, 5 + j * 0.5, k*0.5);
	//			//PaintCube(poligon[1], i, j, 0);
	//		}
	//	}
	//}
	
}

int Map::GetWidth() {
	return width;
}

int Map::GetHeight() {
	return height;
}

Map::~Map() {
	//std::cout << "~Map";
}