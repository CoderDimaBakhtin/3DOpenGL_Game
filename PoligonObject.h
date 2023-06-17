#pragma once
#ifndef _PAINT_H_
#define _PAINT_H_



#include"Header.h"

#include<vector>

class PoligonObject {
private:
	float vertex[12] = {0,0,0,  0,1,0,  1,1,0,  1,0,0};
	float normal[12] = {1,1,1,  -1,1,1, -1,-1,1, 1,-1,1};
	float texCoord[8] = { 0,1, 0,0, 1,0, 1,1 };
	unsigned int texture = 0;
	int x, y, n;
	unsigned char* data = nullptr;

	int size = 4;


	float angle = 0, RotX = 1 , RotY = 0, RotZ = 0;
    float Xmove = 0, Ymove = 0, Zmove = 0;
	float ScaleX = 1, ScaleY = 1, ScaleZ = 1;

public:

	PoligonObject(std::string texture_path, int xSize, int ySize);

	PoligonObject(std::string texture_path, int xSize, int ySize,
		float angle, float RotX, float RotY, float RotZ, float Xmove, float Ymove, float Zmove,
		float ScaleX, float ScaleY, float ScaleZ);

	PoligonObject(std::string texture_path, int xSize, int ySize, float ScaleX, float ScaleY, float ScaleZ);

	void SetPosition(float angle, float RotX, float RotY, float RotZ, float Xmove, float Ymove, float Zmove,
		float ScaleX, float ScaleY, float ScaleZ);

	void SetScale(float ScaleX, float ScaleY, float ScaleZ);
	int GetTextureWidth();
	int GetTextureHeight();



	void Paint();

	void ChangePos(float arr[]){
		for(int i = 0;i<12;i++)
		vertex[i] = arr[i];
	}

	

	~PoligonObject();
	
};


class Poligon {
private:

public:


};



#endif