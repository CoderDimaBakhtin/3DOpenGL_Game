#include "Game.h"


extern GLuint vertexVBO;
extern GLuint normalVBO;
extern GLuint texCoordVBO;

float vertex[12] = { 0,0,0,  0,1,0,  1,1,0,  1,0,0 };
float normal[12] = { 1,1,1,  -1,1,1, -1,-1,1, 1,-1,1 };
float texCoord[8] = { 0,0, 1,0, 1,1, 0,1 };




Game::Game() {
    std::cout << "Game";
    SomethingWrong = 0;
    
    //assigning Screen_Width and Height should be here
    //...
   

   


    /* Initialize the library */
    if (!glfwInit())
        SomethingWrong = 1;
    else {
        /* Create a windowed mode window and its OpenGL context */
        window = glfwCreateWindow(Screen_Width, Screen_Height, "Hello World", NULL, NULL);
        
        if (!window)
        {
            glfwTerminate();
            SomethingWrong = 1;
        }
        /* Make the window's context current */
        glfwMakeContextCurrent(window);



        ShowCursor(FALSE);

        gladLoadGL();

        glGenBuffers(1, &vertexVBO);
        glBindBuffer(GL_ARRAY_BUFFER, vertexVBO);
        glBufferData(GL_ARRAY_BUFFER,sizeof(vertex),vertex,GL_STATIC_DRAW);
        //glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(data), data);
        glBindBuffer(GL_ARRAY_BUFFER,0);

        glGenBuffers(1, &vertexVBO);
        glBindBuffer(GL_ARRAY_BUFFER, vertexVBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(normal), normal, GL_STATIC_DRAW);
        //glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(data), data);
        glBindBuffer(GL_ARRAY_BUFFER, 0);

        glGenBuffers(1, &vertexVBO);
        glBindBuffer(GL_ARRAY_BUFFER, vertexVBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(texCoord), texCoord, GL_STATIC_DRAW);
        //glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(data), data);
        glBindBuffer(GL_ARRAY_BUFFER, 0);



        glEnable(GL_ALPHA_TEST);
        glAlphaFunc(GL_GREATER, 0.99);
        glEnable(GL_DEPTH_TEST);
        glEnable(GL_LIGHTING);
        glEnable(GL_LIGHT0);
        glEnable(GL_COLOR_MATERIAL);
        glEnable(GL_NORMALIZE);


    }
    
    //glGenBuffers
}

GLFWwindow* Game::GetWindow() {
    return window;
}


int Game::Init() {


}
//Seters...

void Game::SetMap(std::shared_ptr<Map> map) {
    this->map = map;

}

void Game::SetPlayer(std::shared_ptr<Player> player) {
    this->player = player;
}
bool Game::GameActive() {
    return !SomethingWrong;
}

int Game::GameProcess() {

    /* Render here */
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //glScalef(1, 1, 1);
    
    SetFrustumProjection();
    /* Poll for and process events */
    glfwPollEvents();

    
    /* Render here */
    glClearColor(0, 140,255, 0);
    glClear(GL_COLOR_BUFFER_BIT);
 
    glPushMatrix();/********************__Begin_Frustum__**************************/
    
    glScalef((float)Screen_Height / (float)Screen_Width, 1, 1);//Scaling

    player->Execute();//move+paint

    map->paint();

    /*other objects execute*/
    //...

    glPopMatrix();/***********************__End_Frustum__**************************/

   
    SetOrthogonalProjection();

    glPushMatrix();/********************__Begin_Ortho__**************************/

    glScalef((float)Screen_Height / (float)Screen_Width, 1, 1);//Scaling

    //paint 
    PaintCross();
    
           
    glPopMatrix();/***********************__End_Ortho__**************************/

    glfwSwapBuffers(window);
    return 0;
}

void Game::SetFrustumProjection() {
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_LIGHTING);


    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glLoadIdentity();
    glFrustum(-0.1, 0.1, -0.1, 0.1, 0.2, 50);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();


    FrustumLighting();

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
}




void Game::SetOrthogonalProjection() {
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_LIGHTING);


    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-2, 2, -2, 2, -1, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    OrthogonalLighting();
    

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);

}

void Game::FrustumLighting() {
    static float t = 0.0;
    glPushMatrix();
    glRotatef(t, 1, 0, 0);
    if (t == 360) { t = 0; }
    float position[] = { 0,0,5,0 };
    glLightfv(GL_LIGHT0, GL_POSITION, position);
    glPopMatrix();
    t += 0.1;
}


void Game::OrthogonalLighting() {
    glPushMatrix();

    float position1[] = { 0,0,1,0 };
    glLightfv(GL_LIGHT0, GL_POSITION, position1);

    glPopMatrix();
}

Game::~Game() {
    std::cout << "~Game";
    glDeleteBuffers(1, &vertexVBO);
}