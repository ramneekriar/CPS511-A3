//#include <stdio.h>
//#include <windows.h>
//#include <GL/glew.h>
//#include <GL/freeglut.h>
//#include <math.h>
//#include <string.h>
//#include "main.h"
//#include <iostream>

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
#include "main.h"
#include <iostream>
#include "robot.h"
#include "player.h"
#include "laser.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

using namespace std;

GLdouble worldLeft = -12;
GLdouble worldRight = 12;
GLdouble worldBottom = -9;
GLdouble worldTop = 9;
GLdouble worldCenterX = 0.0;
GLdouble worldCenterY = 0.0;
GLdouble wvLeft = -12;
GLdouble wvRight = 12;
GLdouble wvBottom = -9;
GLdouble wvTop = 9;

GLint glutWindowWidth = 800;
GLint glutWindowHeight = 600;
GLint viewportWidth = glutWindowWidth;
GLint viewportHeight = glutWindowHeight;

float *vertices;
float *normals;
unsigned int *indices;

bool runAnimation = true;
bool stepForward = true;

// screen window identifiers
int window3D;

int window3DSizeX = 800, window3DSizeY = 600;
GLdouble aspect = (GLdouble)window3DSizeX / window3DSizeY;

// Object declarations
Player *playerPtr;
Player player;

Laser *laserPtr;
Laser laser(0.0, 0.0, 28.0, 0.06, 100.0);

Robot robot1(20.0, 20.0); //left
Robot robot2(0.0, 0.0); //middle
Robot robot3(-20.0, -20.0); //right

Laser robot1Laser(-17.0, 5.0, -20.0, 0.03, 100.0);
Laser robot2Laser(0.0, 9.0, -15.0, 0.03, 100.0);
Laser robot3Laser(17.0, 5.0, -20.0, 0.03, 100.0);

bool laserVisible = false;

bool robot1LaserVisible = false;
bool robot2LaserVisible = false;
bool robot3LaserVisible = false;

int main(int argc, char* argv[])
{
	glutInit(&argc, (char **)argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(glutWindowWidth, glutWindowHeight);
	glutInitWindowPosition(200, 30);

	// The 3D Window
	window3D = glutCreateWindow("CPS511-A3 Ramneek Riar");
	glutPositionWindow(400, 60);
	//    glewinit();
	glutDisplayFunc(display3D);
	glutReshapeFunc(reshape3D);
	glutPassiveMotionFunc(handleMouse);
    glutKeyboardFunc(keyboard);
	init3DSurfaceWindow();

	// Annnd... ACTION!!
	//GLEW Call
    #ifndef __APPLE__
    GLenum res = glewInit();
    if (res != GLEW_OK) {
        fprintf(stderr, "Error: '%s'\n", glewGetErrorString(res));
        return 1;
    }
    #endif
	glutMainLoop();

	return 0;
}

void handleMouse(int x, int y)
{
   playerPtr->mouseMotion(x, y);
    laserPtr->mouseMotion(x, y);
}

 
 // Ground Mesh material
GLfloat groundMat_ambient[] = { 0.4, 0.4, 0.4, 1.0 };
GLfloat groundMat_specular[] = { 0.01, 0.01, 0.01, 1.0 };
GLfloat groundMat_diffuse[] = { 0.4, 0.4, 0.7, 1.0 };
GLfloat groundMat_shininess[] = { 1.0 };

GLfloat light_position0[] = { 4.0, 8.0, 8.0, 1.0 };
GLfloat light_diffuse0[] = { 1.0, 1.0, 1.0, 1.0 };

GLfloat light_position1[] = { -4.0, 8.0, 8.0, 1.0 };
GLfloat light_diffuse1[] = { 1.0, 1.0, 1.0, 1.0 };

GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat model_ambient[] = { 0.5, 0.5, 0.5, 1.0 };

GLfloat normalMat_ambient[] = { 0.0, 0.0, 1.0, 0.0 };

GLdouble fov = 60.0;

GLdouble eyeX = 0.0, eyeY = 3.0, eyeZ = 30.0;
GLdouble radius = eyeZ;
GLdouble zNear = 0.1, zFar = 100.0;
int yaw = 0;
int pitch = 0;
GLdouble zoom = 0.0f;


void init3DSurfaceWindow()
{
	glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse0);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position0);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
	glLightfv(GL_LIGHT0, GL_AMBIENT, model_ambient);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, light_diffuse1);
	glLightfv(GL_LIGHT1, GL_SPECULAR, light_specular);
	glLightfv(GL_LIGHT1, GL_AMBIENT, model_ambient);
	glLightfv(GL_LIGHT1, GL_POSITION, light_position1);

	glShadeModel(GL_SMOOTH);
	glEnable(GL_NORMALIZE);    // Renormalize normal vectors 
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);

	glClearDepth(1.0f);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LINE_SMOOTH);
	glClearColor(0.4F, 0.4F, 0.4F, 0.0F);  // Color and depth for glClear

	glViewport(0, 0, (GLsizei)window3DSizeX, (GLsizei)window3DSizeY);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(fov, aspect, zNear, zFar);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(eyeX, eyeY, eyeZ, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}


void reshape3D(int w, int h)
{
	glutWindowWidth = (GLsizei)w;
	glutWindowHeight = (GLsizei)h;
	glViewport(0, 0, glutWindowWidth, glutWindowHeight);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(fov, aspect, zNear, zFar);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(eyeX, eyeY, eyeZ, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}

void display3D()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(fov, aspect, zNear, zFar);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	// Set up the Viewing Transformation (V matrix)	
	gluLookAt(eyeX, eyeY, eyeZ, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    
	drawGround();
    
    if (laserVisible)
        laser.drawLaser();
    
	player.drawPlayerCannon();
    
    robot1.drawRobot();
    robot2.drawRobot();
    robot3.drawRobot();
    
    if (robot1LaserVisible)
        robot1Laser.drawRobotLaser(1);
    if (robot2LaserVisible)
        robot2Laser.drawRobotLaser(2);
    if (robot3LaserVisible)
        robot3Laser.drawRobotLaser(3);
    
    robot1.respawn();
    robot2.respawn();
    robot3.respawn();
    
    if (runAnimation)
    {
        glutTimerFunc(1000 / 60, animationHandler, 0);
        glutTimerFunc(200, robot1LaserAnimation, 0);
        glutTimerFunc(400, robot2LaserAnimation, 0);
        glutTimerFunc(300, robot3LaserAnimation, 0);
        runAnimation = false;
    }
    
	glutSwapBuffers();
}

void drawGround()
{
	glPushMatrix();
    
    int width, height, nrChannels;
    unsigned char *data = stbi_load("ground-texture.jpg", &width, &height, &nrChannels, 0);
    
    unsigned int groundTexture;
    glGenTextures(1, &groundTexture);
    glBindTexture(GL_TEXTURE_2D, groundTexture);
    
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
    
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, groundMat_ambient);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, groundMat_specular);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, groundMat_diffuse);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, groundMat_shininess);
    
    glBindTexture(GL_TEXTURE_2D, groundTexture);
	glBegin(GL_QUADS);
	glNormal3f(0, 1, 0);
    
    glTexCoord2f(0.0, 0.0);
	glVertex3f(-22.0f, -4.0f, -22.0f);
    
    glTexCoord2f(0.0, 1.0);
	glVertex3f(-22.0f, -4.0f, 22.0f);
	
    glTexCoord2f(1.0, 1.0);
    glVertex3f(22.0f, -4.0f, 22.0f);
    
    glTexCoord2f(1.0, 0.0);
	glVertex3f(22.0f, -4.0f, -22.0f);
    
	glEnd();
    glBindTexture(groundTexture, 0);
    glDeleteTextures(1, &groundTexture);
	glPopMatrix();
}

void animationHandler(int param)
{
    glutTimerFunc(500, stepHandler, 0);
    glutTimerFunc(1000 / 60, animationHandler, 0);
    glutPostRedisplay();
}

void stepHandler(int param){
    glutTimerFunc(250, forwardStepHandler, 0);
    glutTimerFunc(250, backwardStepHandler, 0);
    glutTimerFunc(500, stepHandler, 0);
}

void forwardStepHandler(int param)
{
    robot1.animateGun();
    robot2.animateGun();
    robot3.animateGun();
    
    robot1.walkForwardAnimation();
    robot2.walkForwardAnimation();
    robot3.walkForwardAnimation();
    
    glutPostRedisplay();
    glutTimerFunc(250, forwardStepHandler, 0);
}

void backwardStepHandler(int param)
{
    robot1.walkBackwardAnimation();
    robot2.walkBackwardAnimation();
    robot3.walkBackwardAnimation();
    
    glutPostRedisplay();
    glutTimerFunc(250, backwardStepHandler, 0);
}
      
void laserAnimation(int param){
    laser.checkCollision(robot2.x_pos, robot2.y_pos, robot2.z_pos);
    if (laserVisible)
        laserVisible = false;
    glutTimerFunc(1, laserAnimation, 0);
    glutPostRedisplay();
}

void robot1LaserAnimation(int param){
    if(robot1LaserVisible)
        robot1LaserVisible = false;
    else
        robot1LaserVisible = true;
    glutTimerFunc(200, robot1LaserAnimation, 0);
    glutPostRedisplay();
}

void robot2LaserAnimation(int param){
    if(robot2LaserVisible)
        robot2LaserVisible = false;
    else
        robot2LaserVisible = true;
    glutTimerFunc(400, robot2LaserAnimation, 0);
    glutPostRedisplay();
}

void robot3LaserAnimation(int param){
    if(robot3LaserVisible)
        robot3LaserVisible = false;
    else
        robot3LaserVisible = true;
    glutTimerFunc(300, robot3LaserAnimation, 0);
    glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 32:
            laserVisible = true;
            glutTimerFunc(1, laserAnimation, 0);
        break;
    }

    glutPostRedisplay();   // Trigger a window redisplay
}
