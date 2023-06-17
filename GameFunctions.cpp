#include"Game.h"


void Game::PaintCross() {
	PoligonObject a("cross.png", 100, 100, 1, 1, 1);
	glPushMatrix();
	glTranslatef(-200.f / (float)Screen_Width, -200.f / (float)Screen_Height, 0);
	//a.Paint();
	glPopMatrix();
}