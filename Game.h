#pragma once
#ifndef _GAME_H_
#define _GAME_H_



#include"Header.h"
#include"Player.h"
#include"Map.h"





class Game {
private:
    GLFWwindow* window;
    bool SomethingWrong = 0;
    int Screen_Width = 1920;
    int Screen_Height = 1080;

    std::shared_ptr<Map> map;
    std::shared_ptr<Player> player;


    /*others objects pointers*/



    /*functions*/
    void PaintCross();
public:
    Game();

    int Init();
    //Seters...

    void SetMap(std::shared_ptr<Map> map);

    void SetPlayer(std::shared_ptr<Player> player);

    GLFWwindow* GetWindow();
    bool GameActive();

    int GameProcess();

    void SetFrustumProjection();
    void SetOrthogonalProjection();

    void FrustumLighting();
    void OrthogonalLighting();

    ~Game();


};


#endif