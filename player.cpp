#define GL_SILENCE_DEPRECATION
#ifdef __APPLE__
#include <glut/glut.h>
#else
#include <windows.h>
#include <gl/glut.h>
#endif
#include <stdio.h>
//#include <GL/glew.h>
//#include <GL/freeglut.h>
#include <math.h>
#include <string.h>
#include "player.h"

// Cannon Mesh material
GLfloat cannon_mat_ambient[] = { 0.0f, 0.0f, 0.0f, 1.0f };
GLfloat cannon_mat_diffuse[] = { 0.01f,0.0f,0.01f,0.01f };
GLfloat cannon_mat_specular[] = { 0.5f, 0.5f, 0.5f, 1.0f };
GLfloat cannon_mat_shininess[] = { 100.0F };

GLfloat playerCannonRadius = 0.5;
GLfloat playerCannonHeight = 7.0;

int lastMouseX;
int lastMouseY;
bool mouseUpdated = false;

float playerCannonAngleX = 0.0;
float playerCannonAngleY = 0.0;

void Player::drawPlayerCannon()
{
    glMaterialfv(GL_FRONT, GL_AMBIENT, cannon_mat_ambient);
    glMaterialfv(GL_FRONT, GL_SPECULAR, cannon_mat_specular);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, cannon_mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SHININESS, cannon_mat_shininess);

//    glPushMatrix();
//    glTranslatef(0, 0, 22.5);
//    glRotatef(playerCannonAngleX, 1.0, 0.0, 0.0);
//    glTranslatef(0, 0, -22.5);

    glPushMatrix();
    glTranslatef(0, 0, 28.0);

    glPushMatrix();
    // Creating cylinder object for cannon
    GLUquadricObj *myCannon;
    myCannon = gluNewQuadric();
    gluQuadricDrawStyle(myCannon, GLU_SMOOTH);
    glRotatef(playerCannonAngleX, 1, 0, 0); //x-axis rotate
    glRotatef(playerCannonAngleY, 0, 1, 0); //y-axis rotate
    glRotatef(180, 0, 1, 0);
    gluCylinder(myCannon, playerCannonRadius, playerCannonRadius, playerCannonHeight, 100, 100);

    glPopMatrix();
    glPopMatrix();
    glPopMatrix();
}

void Player::mouseMotion(int x, int y) {
    
    int dx, dy;
    if (!mouseUpdated) {

        lastMouseX = x;
        lastMouseY = y;

        mouseUpdated = true;

    }
    else {

        // calc delta
        dx = x - lastMouseX;
        dy = y - lastMouseY;

        const float sensitivity = 0.2f;
        dx *= sensitivity;
        dy *= sensitivity;

        lastMouseX = x;
        lastMouseY = y;

        // determine rotation amount
        playerCannonAngleX -= dy;
        playerCannonAngleY -= dx;
        glutPostRedisplay();
    }
    
}
