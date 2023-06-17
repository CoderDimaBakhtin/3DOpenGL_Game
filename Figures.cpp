#include "Figures.h"


void PaintCube(std::shared_ptr<PoligonObject> poligon, float xCor, float yCor, float zCor) {
	poligon->SetScale(0.5, 0.5, 0.5);
	
	
	glPushMatrix();
	glTranslatef(xCor, yCor, zCor);
	poligon->Paint();

	glPushMatrix();//1
	glRotatef(90, 1, 0, 0);
	poligon->Paint();
	glPopMatrix();//2

	glPushMatrix();//1
	glRotatef(90, 1, 0, 0);
	glTranslatef(0, 0, -0.5);

	poligon->Paint();
	glPopMatrix();//2

	glPushMatrix();//1
	glRotatef(-90, 0, 1, 0);
	glTranslatef(0, 0, 0);

	poligon->Paint();
	glPopMatrix();//2

	glPushMatrix();//1
	glRotatef(-90, 0, 1, 0);
	glTranslatef(0, 0, -0.5);

	poligon->Paint();
	glPopMatrix();//2

	glPushMatrix();
	glTranslatef(0, 0, 0.5);
	poligon->Paint();
	glPopMatrix();

	glPopMatrix();
}



void PaintRect(std::shared_ptr<PoligonObject> poligon, float xCor, float yCor, float zCor) {
	poligon->SetScale(0.5, 0.5, 0.5);
	
	glPushMatrix();
	glTranslatef(xCor, yCor, zCor);
	
	glRotatef(90, 1, 0, 0);
	glTranslatef(0, 0, 0);

	poligon->Paint();
	

	glPopMatrix();
}