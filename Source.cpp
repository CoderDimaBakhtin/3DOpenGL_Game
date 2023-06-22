
#define STB_IMAGE_IMPLEMENTATION




#include"Header.h"
#include"Game.h"
#include"Player.h"

#include"PoligonObject.h"


#include<memory>


GLuint vertexVBO;
GLuint normalVBO;
GLuint texCoordVBO;

int main(int argc, char* argv[]) {
    //srand(time(0));


    std::unique_ptr<Game> game(new Game);
    std::shared_ptr<Map> map(new Map);

    std::vector<std::shared_ptr<PoligonObject>> skin_move;

    
    skin_move.push_back(std::make_shared<PoligonObject>("LittleManL.png", 388, 530, 1, 1, 1));
    skin_move.push_back(std::make_shared<PoligonObject>("LittleManR.png", 388, 530, 1, 1, 1));

    std::shared_ptr<Player> player(new Human(game->GetWindow(), skin_move));
    
    game->SetMap(map);

    game->SetPlayer(player);
    
    while (game->GameActive()) {

        if (GLFW_PRESS == glfwGetKey(game->GetWindow(), GLFW_KEY_ESCAPE))break;
        game->GameProcess();

        Sleep(1);
    }

    
    return 0;
}


