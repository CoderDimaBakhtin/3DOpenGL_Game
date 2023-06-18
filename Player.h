#pragma once
#ifndef _PLAYER_H_
#define _PLAYER_H_

#include<iostream>


#include"Header.h"
#include"Figures.h"
#include "Map.h"

class Player {
protected:
    float alpha = 0.f;
    float beta = 0.f;
    float xCor = 0, yCor = 0, zCor = 0;
    GLFWwindow* window;
    float xSpeed = 0.5*0.3, ySpeed = 0.5*0.3;
    
    int width, height;


    void MapInteraction(std::shared_ptr<Map> map);
public:
    
    virtual void move(std::shared_ptr<Map> map) = 0;
    virtual void paint() = 0;
    Player();
    


    void Execute(std::shared_ptr<Map> map);//move+paint

    void SetFieldWidth(int width);
    void SetFieldHeight(int height);
 
};



//Human
class Human :public Player {
private:
    void move(std::shared_ptr<Map> map);
    void paint();
    std::vector<std::shared_ptr<PoligonObject>> skin_move;
   
public:
    Human();
    Human(GLFWwindow* window, std::vector<std::shared_ptr<PoligonObject>> skin_move);
    
    ~Human();
};

#endif