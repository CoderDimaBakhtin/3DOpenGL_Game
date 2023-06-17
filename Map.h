#pragma once

#ifndef _MAP_H_
#define _MAP_H_






#include "Header.h"
#include "PoligonObject.h"
#include"Figures.h"
#include<vector>


class Map{
private:
	std::vector<std::shared_ptr<PoligonObject>> poligon;
public:
	Map();
	void paint();


    ~Map();

};

#endif

