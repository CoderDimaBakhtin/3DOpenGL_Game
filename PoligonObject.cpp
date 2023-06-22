#include "PoligonObject.h"



PoligonObject::PoligonObject(std::string texture_path, int xSize, int ySize){
	//srand(time(0));
	data = stbi_load(texture_path.c_str(), &x, &y, &n, 0);
	x = xSize;
	y = ySize;
	n = 0;

	glEnable(GL_TEXTURE_2D);
	glGenTextures(0, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);


	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);



	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, xSize, ySize, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
	glGenTextures(0, &texture);
	glBindTexture(GL_TEXTURE_2D, 0);
}

PoligonObject::PoligonObject(std::string texture_path, int xSize, int ySize,
	float angle, float RotX, float RotY, float RotZ, float Xmove, float Ymove, float Zmove,
	float ScaleX, float ScaleY, float ScaleZ)
	:PoligonObject::PoligonObject(texture_path, xSize, ySize) {
	

	SetPosition(angle, RotX, RotY, RotZ, Xmove, Ymove, Zmove,
		ScaleX, ScaleY, ScaleZ);
	this->angle = angle;
	this->RotX = RotX;
	this->RotY = RotY;
	this->RotZ = RotZ;
	this->Xmove = Xmove;
	this->Ymove = Ymove;
	this->Zmove = Zmove;
	this->ScaleX = ScaleX;
	this->ScaleY = ScaleY;
	this->ScaleZ = ScaleZ;
	
}


PoligonObject::PoligonObject(std::string texture_path, int xSize, int ySize, 
	float ScaleX, float ScaleY, float ScaleZ):PoligonObject::PoligonObject(texture_path, xSize, ySize) {

	SetScale(ScaleX, ScaleY, ScaleZ);
}

void PoligonObject::SetPosition(float angle, float RotX, float RotY, float RotZ, float Xmove, float Ymove, float Zmove,
	float ScaleX, float ScaleY, float ScaleZ) {
	

	this->angle = angle;
	this->RotX = RotX;
	this->RotY = RotY;
	this->RotZ = RotZ;
	this->Xmove = Xmove;
	this->Ymove = Ymove;
	this->Zmove = Zmove;
	this->ScaleX = ScaleX;
	this->ScaleY = ScaleY;
	this->ScaleZ = ScaleZ;

	
}


void PoligonObject::SetScale(float ScaleX, float ScaleY, float ScaleZ) {
	this->ScaleX = ScaleX;
	this->ScaleY = ScaleY;
	this->ScaleZ = ScaleZ;
}

extern GLuint vertexVBO;
extern GLuint normalVBO;
extern GLuint texCoordVBO;

void PoligonObject::Paint() {

	glPushMatrix();

	//glRotatef(this->angle, this->RotX, this->RotY, this->RotZ);
	//glTranslatef(this->Xmove, this->Ymove, this->Zmove);
	glScalef(this->ScaleX, this->ScaleY, this->ScaleZ);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, x, y, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
	glBindTexture(GL_TEXTURE_2D, texture);
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	glEnableClientState(GL_NORMAL_ARRAY);


	/*glBindBuffer(GL_ARRAY_BUFFER, vertexVBO);
	glVertexPointer(3, GL_FLOAT, 0, NULL);
	glBindBuffer(GL_ARRAY_BUFFER, 0);*/

	glVertexPointer(3, GL_FLOAT, 0, vertex);

	//glBindBuffer(GL_ARRAY_BUFFER, texCoordVBO);
	glTexCoordPointer(2, GL_FLOAT, 0, texCoord);
	//glTexCoordPointer(2, GL_FLOAT, 0, NULL);
	//glBindBuffer(GL_ARRAY_BUFFER, texCoordVBO);
	

	
	//glBindBuffer(GL_ARRAY_BUFFER, normalVBO);
	glNormalPointer(GL_FLOAT, 0, normal);
	//glNormalPointer(GL_FLOAT, 0, NULL);
	//glBindBuffer(GL_ARRAY_BUFFER, normalVBO);

	glBindTexture(GL_TEXTURE_2D, texture);

	glDrawArrays(GL_TRIANGLE_FAN, 0, size);

	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	glDisableClientState(GL_NORMAL_ARRAY);
	glBindTexture(0, texture);

	glPopMatrix();
}

PoligonObject::~PoligonObject() {
	
	if(data != nullptr)
	stbi_image_free(data);

}

int PoligonObject::GetTextureWidth() {
	return x;
}


int PoligonObject::GetTextureHeight() {
	return y;
}


Enemy::Enemy(Map* map, std::string texture_path, int xSize, int ySize)
	:PoligonObject(texture_path, xSize, ySize) {
	this->map = map;
}

Enemy::Enemy(Map* map, std::string texture_path, int xSize, int ySize,
	float angle, float RotX, float RotY, float RotZ, float Xmove, float Ymove, float Zmove,
	float ScaleX, float ScaleY, float ScaleZ)
	:PoligonObject(texture_path, xSize, ySize,
		angle, RotX, RotY, RotZ, Xmove, Ymove, Zmove,
		ScaleX, ScaleY, ScaleZ) {
	this->map = map;
}

Enemy::Enemy(Map* map, std::string texture_path, int xSize, int ySize,
	float ScaleX, float ScaleY, float ScaleZ)
	:PoligonObject(texture_path, xSize, ySize,
		ScaleX, ScaleY, ScaleZ) {
	this->map = map;
}

void Enemy::Paint() {
	//
	move();
	
	SetScale(0.5, 0.5, 0.5);
	glPushMatrix();
	glTranslatef(Xmove, Ymove, Zmove);
	
	PoligonObject::Paint();

	glPushMatrix();//1
	glRotatef(90, 1, 0, 0);
	PoligonObject::Paint();
	glPopMatrix();//2

	glPushMatrix();//1
	glRotatef(90, 1, 0, 0);
	glTranslatef(0, 0, -0.5);

	PoligonObject::Paint();
	glPopMatrix();//2

	glPushMatrix();//1
	glRotatef(-90, 0, 1, 0);
	glTranslatef(0, 0, 0);

	PoligonObject::Paint();
	glPopMatrix();//2

	glPushMatrix();//1
	glRotatef(-90, 0, 1, 0);
	glTranslatef(0, 0, -0.5);

	PoligonObject::Paint();
	glPopMatrix();//2

	glPushMatrix();
	glTranslatef(0, 0, 0.5);
	PoligonObject::Paint();
	glPopMatrix();

	glPopMatrix();
}

void Enemy::move() {
	//SetPosition(0, 0, 0, 0, Xmove, Ymove, 0, 1, 1, 1);
	
	//float a1 = 0.01 /** Xmove*//*(rand() % 8 + 1) * 0*/;
	//float b1 = 0.01 /** Ymove*//*(rand() % 8 + 1)*/;
	if (Xmove > map->GetHeight()-0.5 || Xmove < 0) { a1 = -a1; }
	
	if (Ymove > map->GetWidth()-0.5 || Ymove < 0) { b1 = -b1; }
	
	Xmove += a1;
	Ymove += b1;
	//SetPosition(0, 0, 0, 0, a, b, 0, 1, 1, 1);
	//SetPosition(0, 0, 0, 0,a,b, 0, 1, 1, 1);
	
	
}
