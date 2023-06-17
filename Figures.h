#pragma once
#ifndef _FIGURES_H_
#define _FIGURES_H_

#include<memory>
#include"PoligonObject.h"

void PaintCube(std::shared_ptr<PoligonObject> poligon, float xCor, float yCor, float zCor);

void PaintRect(std::shared_ptr<PoligonObject> poligon, float xCor, float yCor, float zCor);

#endif