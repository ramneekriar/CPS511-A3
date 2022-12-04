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
#include <stdio.h>
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

    glPushMatrix();
    glTranslatef(0, 0, 28.0);

    glPushMatrix();
//     Creating cylinder object for cannon
//    GLUquadricObj *myCannon;
//    myCannon = gluNewQuadric();
//    gluQuadricDrawStyle(myCannon, GLU_SMOOTH);
    glRotatef(playerCannonAngleX, 1, 0, 0); //x-axis rotate
    glRotatef(playerCannonAngleY, 0, 0, 1); //y-axis rotate
//    glRotatef(180, 0, 1, 0);
//    gluCylinder(myCannon, playerCannonRadius, playerCannonRadius, playerCannonHeight, 100, 100);
    glPushMatrix();
    createMesh();
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();
}

void Player::mouseMotion(int x, int y)
{
    
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

//void Player::readMesh()
//{
//    FILE *fp;
//
//    fp = fopen("mesh.obj", "r");
//
//    float v1, v2, v3, n1, n2, n3;
//    int i1, i2, i3, i4;
//
//    // Getting vertices values
//    for(int i = 0; i < 1584; i+= 3){
//        fscanf(fp, "v %f %f %f", &v1, &v2, &v3);
//        vertices[i] = v1;
//        vertices[i + 1] = v2;
//        vertices[i + 2] = v3;
//    }
//
//    // Getting normals values
//    for(int i = 0; i < 1584; i+= 3){
//        fscanf(fp, "vn %f %f %f", &n1, &n2, &n3);
//        normals[i] = n1;
//        normals[i + 1] = n2;
//        normals[i + 2] = n3;
//
//        printf("%f", n1);
//        printf("%f", n2);
//        printf("%f", n3);
//    }
//
//    // Getting index values
//    for(int i = 0; i < 2048; i+= 4){
//        fscanf(fp, "f %d %d %d %d", &i1, &i2, &i3, &i4);
//        indices[i] = i1;
//        indices[i + 1] = i2;
//        indices[i + 2] = i3;
//        indices[i + 3] = i4;
//    }
//    
//    fclose(fp);
//}

void Player::createMesh()
{
    
//    glPushMatrix();
    for (int i = 0; i < 1584; i+= 12){
        glBegin(GL_QUADS);
        
        glNormal3f(normals[i], normals[i + 1], normals[i + 2]);
        glVertex3f(vertices[i], vertices[i + 1], vertices[i + 2]);
        
        glNormal3f(normals[i + 3], normals[i + 4], normals[i + 5]);
        glVertex3f(vertices[i + 3], vertices[i + 4], vertices[i + 5]);
        
        glNormal3f(normals[i + 6], normals[i + 7], normals[i + 8]);
        glVertex3f(vertices[i + 6], vertices[i + 7], vertices[i + 8]);
        
        glNormal3f(normals[i + 9], normals[i + 10], normals[i + 11]);
        glVertex3f(vertices[i + 9], vertices[i + 10], vertices[i + 11]);
        
        glEnd();
    }
}
