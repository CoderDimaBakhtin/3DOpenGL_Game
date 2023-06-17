#include "Player.h"


void Player::Execute() {//move+paint
    this->move();
    this->paint();

}


void Player::SetFieldWidth(int width) {
    this->width = width;
}


void Player::SetFieldHeight(int height) {
    this->height = height;
}


//Human
void Human::move() {
    POINT p;
    GetCursorPos(&p);
    
    if (500- p.y>0) {
        alpha -= 3.0;
    }
    if (500 - p.y<0) {
        alpha += 3.0;
    }
    if (500 -p.x>0) {
        beta -= 3.0;
    }
    if (500 - p.x<0) {
        beta += 3.0;
    }
    SetCursorPos(500, 500);
    //////////////////////////////
    if (alpha <= -180) { alpha = -180; }//if (alpha <= -180) { alpha = -180; }
    if (alpha >= -30) { alpha = -30; }//if (alpha >= 0) { alpha = 0; }
    
    
    if (GLFW_PRESS == glfwGetKey(window, GLFW_KEY_DOWN)|| GLFW_PRESS == glfwGetKey(window, GLFW_KEY_S)) {
        xCor -= xSpeed* sin(((2.f * 3.1415) / 360.f) * (beta));
        yCor -= ySpeed*cos(((2.f * 3.1415) / 360.f) * (beta));
    }
    if (GLFW_PRESS == glfwGetKey(window, GLFW_KEY_UP) || GLFW_PRESS == glfwGetKey(window, GLFW_KEY_W)) {
        xCor += xSpeed * sin(((2.f * 3.1415) / 360.f) * (beta));
        yCor += ySpeed * cos(((2.f * 3.1415) / 360.f) * (beta));
    }
    if (GLFW_PRESS == glfwGetKey(window, GLFW_KEY_LEFT) || GLFW_PRESS == glfwGetKey(window, GLFW_KEY_A)) {
        xCor -= xSpeed * cos(((2.f * 3.1415) / 360.f) * (beta));
        yCor += ySpeed * sin(((2.f * 3.1415) / 360.f) * (beta));
    }
    if (GLFW_PRESS == glfwGetKey(window, GLFW_KEY_RIGHT) || GLFW_PRESS == glfwGetKey(window, GLFW_KEY_D)) {
        xCor += xSpeed * cos(((2.f * 3.1415) / 360.f) * (beta));
        yCor -= ySpeed * sin(((2.f * 3.1415) / 360.f) * (beta));
    }
    //////////////////////////////////////
    static float h = 0;
    static float c = 0;
    if (GLFW_PRESS == glfwGetKey(window, GLFW_KEY_SPACE)) {
        c = 1;
    }
    h += 0.03 * c;
    if (h >= 1 /*|| h <= 0*/) {
        h = 0;
        c = 0;
    }

    zCor = -6 * h * h + 6 * h;
   /////////////////////////////////////////////////
    glTranslatef(0, 4, 0);

    glRotatef(alpha, 1, 0, 0);

    
    glRotatef(beta, 0, 0, 1);
  
    
    glTranslatef(0, 0, -5.5);
    glTranslatef(-xCor/3.0, -yCor/3.0, 0);

    
    
}


Player::Player() {

}

Human::Human() {

}
Human::Human(GLFWwindow* window, std::vector<std::shared_ptr<PoligonObject>> skin_move) {
    this->window = window;
    
    this->skin_move = skin_move;
}



void Human::paint() {
    
    static int counter = 0;
    static int i = 0;
    glPushMatrix();
    glTranslatef(xCor / 3.0, yCor / 3.0, 0);
    
    glRotatef(-beta, 0, 0, 1);
 
    

    

    if (counter == 10) {
        counter = 0;
        if (i + 1 < skin_move.size()) {i++;}
        else {i = 0;}
    }
        
    PaintRect(skin_move[i],-0.25, 0, zCor);
    if (GLFW_PRESS == glfwGetKey(window, GLFW_KEY_UP) || GLFW_PRESS == glfwGetKey(window, GLFW_KEY_W)
        || GLFW_PRESS == glfwGetKey(window, GLFW_KEY_DOWN) || GLFW_PRESS == glfwGetKey(window, GLFW_KEY_S)
        || GLFW_PRESS == glfwGetKey(window, GLFW_KEY_LEFT) || GLFW_PRESS == glfwGetKey(window, GLFW_KEY_A)
        || GLFW_PRESS == glfwGetKey(window, GLFW_KEY_RIGHT) || GLFW_PRESS == glfwGetKey(window, GLFW_KEY_D)) {
        counter++;
    }
    
    glPopMatrix();
        
   
}


Human::~Human() {
    
}

