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
#include <iostream>
#include "player.h"
#include "stb_image.h"

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
    
    glRotatef(playerCannonAngleX, 1, 0, 0); //x-axis rotate
    glRotatef(playerCannonAngleY, 0, 1, 0); //y-axis rotate
    glRotatef(270, 1, 0, 0);

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

void Player::createMesh()
{
    glPushMatrix();
    
    int width, height, nrChannels;
    unsigned char *data = stbi_load("metal-texture.jpg", &width, &height, &nrChannels, 0);
    
    unsigned int playerTexture;
    glGenTextures(1, &playerTexture);
    glBindTexture(GL_TEXTURE_2D, playerTexture);
    
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
    
    if (data)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        std::cout << "Failed to load texture" << std::endl;
    }
    
    glEnable(GL_TEXTURE_2D);
    
    
    stbi_image_free(data);
    
    glBindTexture(GL_TEXTURE_2D, playerTexture);
    for (int i = 0; i < 1584; i+= 12){
        glBegin(GL_QUADS);
        
        glTexCoord2f(0.0, 0.0);  // Map to the bottom left texel
        glNormal3f(normals[indices[i]], normals[indices[i] + 1], normals[indices[i] + 2]);
        glVertex3f(vertices[i], vertices[i + 1], vertices[i + 2]);

        glTexCoord2f(0.0, 1.0);  // Map to the bottom right texel
        glNormal3f(normals[indices[i] + 3], normals[indices[i] + 4], normals[indices[i] + 5]);
        glVertex3f(vertices[indices[i] + 3], vertices[indices[i] + 4], vertices[indices[i] + 5]);

        glTexCoord2f(1.0, 1.0);  // Map to the top right texel
        glNormal3f(normals[indices[i] + 6], normals[indices[i] + 7], normals[indices[i] + 8]);
        glVertex3f(vertices[indices[i] + 6], vertices[indices[i] + 7], vertices[indices[i] + 8]);

        glTexCoord2f(1.0, 0.0);  // Map to the top left texel
        glNormal3f(normals[indices[i] + 9], normals[indices[i] + 10], normals[indices[i] + 11]);
        glVertex3f(vertices[indices[i] + 9], vertices[indices[i] + 10], vertices[indices[i] + 11]);

        glEnd();
    }
    glFlush();
    glBindTexture(playerTexture, 0);
    glDeleteTextures(1, &playerTexture);
    glPopMatrix();
}

