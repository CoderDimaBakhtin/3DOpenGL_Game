#pragma once
#ifndef _PLAYER_H_
#define _PLAYER_H_

#include<iostream>


#include"Header.h"
#include"Figures.h"

class Player {
protected:
    float alpha = 0.f;
    float beta = 0.f;
    float xCor = 0, yCor = 0, zCor = 0;
    GLFWwindow* window;
    float xSpeed = 0.5, ySpeed = 0.5;
    
    int width, height;
public:
    
    virtual void move() = 0;
    virtual void paint() = 0;
    Player();
    


    void Execute();//move+paint

    void SetFieldWidth(int width);
    void SetFieldHeight(int height);
 
};



//Human
class Human :public Player {
private:
    void move();
    void paint();
    std::vector<std::shared_ptr<PoligonObject>> skin_move;
   
public:
    Human();
    Human(GLFWwindow* window, std::vector<std::shared_ptr<PoligonObject>> skin_move);
    
    ~Human();
};

#endif