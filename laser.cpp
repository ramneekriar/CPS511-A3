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
#include<cmath>
#include <string.h>
#include <stdio.h>
#include "laser.h"

GLfloat quadMat_ambient[] = { 0.0, 0.0, 0.0, 1.0 };
GLfloat quadMat_specular[] = { 0.45, 0.55, 0.45, 1.0 };
GLfloat quadMat_diffuse[] = { 0.1, 0.35, 0.1, 1.0 };
GLfloat quadMat_shininess[] = { 10.0 };

bool laser_mouseUpdated = false;

float laserAngleX = 0.0;
float laserAngleY = 0.0;

float laser_endX = 0.0;
float laser_endY = 0.0;

int laser_lastMouseX;
int laser_lastMouseY;

// laser constructor
Laser::Laser(float x_param, float y_param, float z_param, float radius, float height){
    x_pos = x_param;
    y_pos = y_param;
    z_pos = z_param;
    laser_radius = radius;
    laser_height = height;
}

void Laser::drawLaser(){
    
    glMaterialfv(GL_FRONT, GL_AMBIENT, quadMat_ambient);
    glMaterialfv(GL_FRONT, GL_SPECULAR, quadMat_specular);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, quadMat_diffuse);
    glMaterialfv(GL_FRONT, GL_SHININESS, quadMat_shininess);
    
    glPushMatrix();
    glTranslatef(x_pos, y_pos, z_pos);

    glPushMatrix();
    glRotatef(laserAngleX, 1, 0, 0); //x-axis rotate
    glRotatef(laserAngleY, 0, 1, 0); //y-axis rotate
    glRotatef(180.0, 0, 1, 0);
    glRotatef(30, 0, 0, 1);
    gluCylinder(gluNewQuadric(), laser_radius, laser_radius, laser_height, 100, 100);
    
    glPopMatrix();
    glPopMatrix();
}

void Laser::drawRobotLaser(int robot_id){
    
    glMaterialfv(GL_FRONT, GL_AMBIENT, quadMat_ambient);
    glMaterialfv(GL_FRONT, GL_SPECULAR, quadMat_specular);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, quadMat_diffuse);
    glMaterialfv(GL_FRONT, GL_SHININESS, quadMat_shininess);
    
    glPushMatrix();
    glTranslatef(x_pos, y_pos, z_pos);

    glPushMatrix();
    if (robot_id == 1){
        glRotatef(200.0, 1, 0, 0);
        glRotatef(160.0, 0, 1, 0);
    }
    else if (robot_id == 2){
        glRotatef(200.0, 1, 0, 0);
        glRotatef(180.0, 0, 1, 0);
    }
    else{
        glRotatef(200.0, 1, 0, 0);
        glRotatef(200.0, 0, 1, 0);
    }
    gluCylinder(gluNewQuadric(), laser_radius, laser_radius, laser_height, 100, 100);
    
    glPopMatrix();
    glPopMatrix();
}

void Laser::mouseMotion(int x, int y)
{
    int dx, dy;
    if (!laser_mouseUpdated) {

        laser_lastMouseX = x;
        laser_lastMouseY = y;

        laser_mouseUpdated = true;

    }
    else {

        // calc delta
        dx = x - laser_lastMouseX;
        dy = y - laser_lastMouseY;

        const float sensitivity = 0.2f;
        dx *= sensitivity;
        dy *= sensitivity;

        laser_lastMouseX = x;
        laser_lastMouseY = y;

        // determine rotation amount
        laserAngleX -= dy;
        laserAngleY -= dx;
        
        laser_endX = laser_endX + (1*cos(laserAngleX));
        laser_endY = laser_endY + (1*sin(laserAngleY));
        glutPostRedisplay();
    }
}

void Laser::checkCollision(float robot_x, float robot_y, float robot_z){
    // laser is translated 28.0 towards us
    float temp_z = -28.0;
    float distance = 0.0;
    distance = sqrt(pow(robot_x - laser_endX, 2) + pow(robot_y - laser_endY, 2) + pow(robot_z - temp_z, 2));
    
    printf("%f", distance);
}

void Laser::moveLaserForward(){
    z_pos += 0.005;
    y_pos -= 0.003;
}
