#include <stdio.h>
#include <windows.h>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <math.h>
#include <string.h>
#include "main.h"
#include <iostream>

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

// screen window identifiers
int window2D, window3D;

int window3DSizeX = 800, window3DSizeY = 600;
GLdouble aspect = (GLdouble)window3DSizeX / window3DSizeY;


int main(int argc, char* argv[])
{
	glutInit(&argc, (char **)argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(glutWindowWidth, glutWindowHeight);
	glutInitWindowPosition(50, 100);

	// The 3D Window
	window3D = glutCreateWindow("CPS511-A3 Ramneek Riar");
	glutPositionWindow(900, 100);
	//    glewinit();
	glutDisplayFunc(display3D);
	glutReshapeFunc(reshape3D);
	/*glutMouseFunc(mouseButtonHandler3D);
	glutMouseWheelFunc(mouseScrollWheelHandler3D);
	glutMotionFunc(mouseMotionHandler3D);
	glutKeyboardFunc(keyboardHandler3D);*/
	// Initialize the 3D system
	init3DSurfaceWindow();

	// Annnd... ACTION!!
	//GLEW Call
	GLenum res = glewInit();
	if (res != GLEW_OK) {
		fprintf(stderr, "Error: '%s'\n", glewGetErrorString(res));
		return 1;
	}
	glutMainLoop();

	return 0;
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

int lastMouseX;
int lastMouseY;

GLboolean drawAsLines = false;
GLboolean drawAsPoints = false;
GLboolean drawNormals = false;

GLdouble eyeX = 0.0, eyeY = 3.0, eyeZ = 10.0;
GLdouble radius = eyeZ;
GLdouble zNear = 0.1, zFar = 40.0;
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

	glPopMatrix();
	glutSwapBuffers();
}

void drawGround()
{
	glPushMatrix();
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, groundMat_ambient);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, groundMat_specular);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, groundMat_diffuse);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, groundMat_shininess);
	glBegin(GL_QUADS);
	glNormal3f(0, 1, 0);
	glVertex3f(-22.0f, -4.0f, -22.0f);
	glVertex3f(-22.0f, -4.0f, 22.0f);
	glVertex3f(22.0f, -4.0f, 22.0f);
	glVertex3f(22.0f, -4.0f, -22.0f);
	glEnd();
	glPopMatrix();
}



