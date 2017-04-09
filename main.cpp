#include <GL/glew.h>
#include <GL/glut.h>

#include "MainGame.h"

using fjfj::MainGame;

int main(int argc, char** argv) {
        glutInit(&argc, argv);
        glutInitWindowSize(800, 600);
        glutCreateWindow("OpenGL");
        glutDisplayFunc(MainGame::render);
        glutIdleFunc(MainGame::update);
        glewInit();

        glutMainLoop();
        return 0;
}