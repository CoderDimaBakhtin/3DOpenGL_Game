#include "PoligonObject.h"



PoligonObject::PoligonObject(std::string texture_path, int xSize, int ySize){

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
	std::cout << this->angle<<std::endl;
	std::cout << angle;
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

	glRotatef(this->angle, this->RotX, this->RotY, this->RotZ);
	glTranslatef(this->Xmove, this->Ymove, this->Zmove);
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

