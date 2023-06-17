
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
  


    std::unique_ptr<Game> game(new Game);
    std::shared_ptr<Map> map(new Map);

    std::vector<std::shared_ptr<PoligonObject>> skin_move;

    

    //skin_move.push_back(std::make_shared<PoligonObject>("cards.png", 910, 455, 1, 1, 1));
    //skin_move.push_back(std::make_shared<PoligonObject>("button.png", 700, 210, 1, 1, 1));
    //skin_move.push_back(std::make_shared<PoligonObject>("button.png", 700, 210, 1, 1, 1));
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



//
//int main(int argc, char* argv[])
//{
//    GLFWwindow* window;
//    /* Initialize the library */
//    if (!glfwInit())
//        return -1;
//
//    /* Create a windowed mode window and its OpenGL context */
//    window = glfwCreateWindow(1000, 800, "Hello World", NULL, NULL);
//    if (!window)
//    {
//        glfwTerminate();
//        return -1;
//    }
//
//    /* Make the window's context current */
//    glfwMakeContextCurrent(window);
//    float alpha = 0.f;
//    float beta = 0.f;
//    float xCor = 0, yCor = 0;
//    double mouseX = 0, mouseY = 0;
//    /* Loop until the user closes the window */
//    //glFrustum(-0.5, 0.5, -0.5, 0.5, 0.5, 50);
//
//    /*glLoadIdentity();
//    glOrtho(-2, 2, -2, 2, -1, 1);*/
//    bool flag = 1;
//    float a = 0.1;
//    unsigned int texture = 0;
//    unsigned int texture2 = 0;
//
//    //int x, y, n;
//    //unsigned char *data = stbi_load("button.png", &x, &y, &n, 0);
//    //x = 700;
//    //y = 210;
//    //n = 0;
//
//    //int x1, y1, n1;
//    //unsigned char* data2 = stbi_load("digits.png", &x1, &y1, &n1, 0);
//    //x1 = 100;
//    //y1 = 52;
//    //n1 = 0;
//    ////////////////
//    //glEnable(GL_TEXTURE_2D);
//    ////glGenTextures(0, &texture2);
//    ////glBindTexture(GL_TEXTURE_2D, texture2);
//
//
//    //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
//    //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
//    //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
//    //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
//
//    //glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 100, 52, 0, GL_RGBA, GL_UNSIGNED_BYTE, data2);
//    //glGenTextures(0, &texture2);
//    ////glBindTexture(GL_TEXTURE_2D, 0);
//
//    ///////////////////
//
//    //
//    ////glGenTextures(0,&texture);
//    ////glBindTexture(GL_TEXTURE_2D, texture);
//
//
//    //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
//    //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
//    //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
//    //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
//
//    //glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,700,210,0, GL_RGBA,GL_UNSIGNED_BYTE,data);
//    //glGenTextures(0, &texture);
//    ////glBindTexture(GL_TEXTURE_2D, 0);
//
//    
//    ShowCursor(FALSE);
//
//    glEnable(GL_ALPHA_TEST);
//    glAlphaFunc(GL_GREATER, 0.99);
//    glEnable(GL_DEPTH_TEST);
//    glEnable(GL_LIGHTING);
//    glEnable(GL_LIGHT0);
//    glEnable(GL_COLOR_MATERIAL);
//    glEnable(GL_NORMALIZE);
//    //glEnable(GL_BLEND);
//    //glBlendFunc(GL_ONE,GL_ONE);
//    float t = 0.0;
//    
//    while (!glfwWindowShouldClose(window)&&flag == 1)
//    {
//        glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
//        glMatrixMode(GL_PROJECTION);
//        glLoadIdentity();
//        glFrustum(-1.25*a, 1.25*a, -a, a, 2*a, 500);
//        glMatrixMode(GL_MODELVIEW);
//        glLoadIdentity();
//
//        /* Poll for and process events */
//        glfwPollEvents();
//        
//        
//
//        glEnable(GL_DEPTH_TEST);
//        if (GLFW_PRESS == glfwGetKey(window, GLFW_KEY_ESCAPE)) {
//            flag = 0;
//        }
//        
//        /* Render here */
//        glClearColor(0, 1, 1,0);
//        glClear(GL_COLOR_BUFFER_BIT);
//        
//        glPushMatrix();
//        POINT p;
//        GetCursorPos(&p);
//
//        if (/*GLFW_PRESS == glfwGetKey(window, GLFW_KEY_W)*/500- p.y>0) {
//            alpha -= 3.0;
//        }
//        if (/*GLFW_PRESS == glfwGetKey(window, GLFW_KEY_S)*/500 - p.y<0) {
//            alpha += 3.0;
//        }
//        if (/*GLFW_PRESS == glfwGetKey(window, GLFW_KEY_A)*/500 -p.x>0) {
//            beta -= 3.0;
//        }
//        if (/*GLFW_PRESS == glfwGetKey(window, GLFW_KEY_D)*/500 - p.x<0) {
//            beta += 3.0;
//        }
//        SetCursorPos(500, 500);
//        /// //////////////////////////////////
//        if (alpha <= -180) { alpha = -180; }
//        if (alpha >= 0) { alpha = 0; }
//
//
//        if (GLFW_PRESS == glfwGetKey(window, GLFW_KEY_DOWN)|| GLFW_PRESS == glfwGetKey(window, GLFW_KEY_S)) {
//            xCor -= sin(((2.f * 3.1415) / 360.f) * (beta));
//            yCor -= cos(((2.f * 3.1415) / 360.f) * (beta));
//        }
//        if (GLFW_PRESS == glfwGetKey(window, GLFW_KEY_UP) || GLFW_PRESS == glfwGetKey(window, GLFW_KEY_W)) {
//            xCor += sin(((2.f * 3.1415) / 360.f) * (beta));
//            yCor += cos(((2.f * 3.1415) / 360.f) * (beta));
//        }
//        if (GLFW_PRESS == glfwGetKey(window, GLFW_KEY_LEFT) || GLFW_PRESS == glfwGetKey(window, GLFW_KEY_A)) {
//            xCor -= sin(((2.f * 3.1415) / 360.f) * (beta));
//            yCor += cos(((2.f * 3.1415) / 360.f) * (beta));
//        }
//        if (GLFW_PRESS == glfwGetKey(window, GLFW_KEY_RIGHT) || GLFW_PRESS == glfwGetKey(window, GLFW_KEY_D)) {
//            xCor += sin(((2.f * 3.1415) / 360.f) * (beta));
//            yCor -= cos(((2.f * 3.1415) / 360.f) * (beta));
//        }
//
//        glRotatef(alpha, 1, 0, 0);
//        glRotatef(beta, 0, 0, 1);
//        glTranslatef(0, 0, -1.0);
//        glTranslatef(-xCor/3.0, -yCor/3.0, 0);
//
//        glPushMatrix();
//        glRotatef(t, 1, 0, 0);
//        float position[] = { 0,0,5,0 };
//        glLightfv(GL_LIGHT0, GL_POSITION, position);
//        
//        glPopMatrix();
//
//        t++; 
//
//        
//
//        //glBegin(GL_TRIANGLES);
//
//        //if (GLFW_PRESS == glfwGetMouseButton(window, 0)) {
//        //    glColor3f(1.0, 1.0, 1.0);
//        //}
//        //else {
//        //    glColor3f(1.0, 0.0, 1.0);
//        //}
//        //if (GLFW_PRESS == glfwGetKey(window, GLFW_KEY_Q)) {
//        //    glColor3f(1.0, 0.0, 0.0);
//        //}
//        //
//       
//        
//        float vertex1[] = { 0,0,0, -10,0,0, -10,-10,0, 0,-10,0 };
//        float texCoord1[] = { 0,0, 1,0, 1,1, 0,1 };
//        float normal[] = {1,1,1,  -1,1,1, -1,-1,1, 1,-1,1};
//        //glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 700, 210, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
//        //glGenTextures(0, &texture);
//        glPushMatrix();
//       // glColor3f(1, 1, 1);
//        
//
//        glEnableClientState(GL_VERTEX_ARRAY);
//        //glEnableClientState(GL_TEXTURE_COORD_ARRAY);
//        glEnableClientState(GL_NORMAL_ARRAY);
//
//        //glTexCoordPointer(2, GL_FLOAT, 0, texCoord1);
//        glVertexPointer(3, GL_FLOAT, 0, vertex1);
//        glNormalPointer(GL_FLOAT,0, normal);
//
//
//        //glBindTexture(GL_TEXTURE_2D, texture);
//
//        glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
//
//        glDisableClientState(GL_VERTEX_ARRAY);
//        //glDisableClientState(GL_TEXTURE_COORD_ARRAY);
//        glDisableClientState(GL_NORMAL_ARRAY);
//
//
//        glPopMatrix();
//        
//       
//        Sleep(1);
//        
//
//        glPopMatrix();
//
//
//
//
//
//
//        ///* Poll for and process events */
//        //glfwPollEvents();
//      
//    
//        glfwGetCursorPos(window, &mouseX, &mouseY);
//        
//        
//        
///////////////////////////////////////ortho
//        glMatrixMode(GL_PROJECTION);
//        glLoadIdentity();
//        glOrtho(-2, 2, -2, 2, -1, 1);
//        glMatrixMode(GL_MODELVIEW);
//        glLoadIdentity();
//
//
//        glPushMatrix();
//        //glRotatef(t, 1, 0, 0);
//        float position1[] = { 0,0,1,0 };
//        glLightfv(GL_LIGHT0, GL_POSITION, position1);
//
//        glPopMatrix();
//
//
//        float vertex[] = { 0,0,0, 1,0,0, 1,1,0, 0,1,0 };
//        float vertex2[] = { 0,0,0, -1,0,0, -1,-1,0, 0,-1,0 };
//        float texCoord[] = {0,0, 1,0, 1,1, 0,1};
//
//        
//
//
//
//       /* glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 100, 52, 0, GL_RGBA, GL_UNSIGNED_BYTE, data2);
//        glGenTextures(0, &texture2);
//        glPushMatrix();
//        glEnableClientState(GL_VERTEX_ARRAY);
//        glEnableClientState(GL_TEXTURE_COORD_ARRAY);
//        */
//
//
//        glVertexPointer(3, GL_FLOAT, 0, vertex);
//       // glTexCoordPointer(2, GL_FLOAT, 0, texCoord);
//        
//
//
//        //glBindTexture(GL_TEXTURE_2D, texture2);
//        glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
//
//
//        glDisableClientState(GL_VERTEX_ARRAY);
//        glDisableClientState(GL_TEXTURE_COORD_ARRAY);
//        
//        
//        glPopMatrix();
//        
//        //////////////////////////////////
//        
//        ////////////////////////////////////
//       
//        glfwSwapBuffers(window);
//    }
//    //stbi_image_free(data);
//    //stbi_image_free(data2);
//    glfwTerminate();
//    return 0;
//}