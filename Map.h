#pragma once

#ifndef _MAP_H_
#define _MAP_H_






#include "Header.h"
#include "PoligonObject.h"
#include"Figures.h"
#include<vector>

class PoligonObject;
class Map{
private:
	std::vector<std::shared_ptr<PoligonObject>> poligon;
	int width = 20, height = 20;
public:
	Map();
	void paint();

	int GetWidth();
	int GetHeight();

    ~Map();

};

#endif

