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
#include "robot.h"

// Lighting/shading and material properties for robot - upcoming lecture - just copy for now
// Robot RGBA material properties (NOTE: we will learn about this later in the semester)
GLfloat robotBody_mat_ambient[] = { 0.0f,0.0f,0.0f,1.0f };
GLfloat robotBody_mat_specular[] = { 0.45f,0.55f,0.45f,1.0f };
GLfloat robotBody_mat_diffuse[] = { 0.1f,0.35f,0.1f,1.0f };
GLfloat robotBody_mat_shininess[] = { 32.0F };

GLfloat robotLeg_mat_ambient[] = { 0.0215f, 0.1745f, 0.0215f, 0.55f };
GLfloat robotLeg_mat_diffuse[] = { 0.5f,0.0f,0.0f,1.0f };
GLfloat robotLeg_mat_specular[] = { 0.7f, 0.6f, 0.6f, 1.0f };
GLfloat robotLeg_mat_shininess[] = { 32.0F };

GLfloat robotLowerBody_mat_ambient[] = { 0.25f, 0.25f, 0.25f, 1.0f };
GLfloat robotLowerBody_mat_diffuse[] = { 0.4f, 0.4f, 0.4f, 1.0f };
GLfloat robotLowerBody_mat_specular[] = { 0.774597f, 0.774597f, 0.774597f, 1.0f };
GLfloat robotLowerBody_mat_shininess[] = { 76.8F };

GLfloat gun_mat_ambient[] = { 0.0f, 0.0f, 0.0f, 1.0f };
GLfloat gun_mat_diffuse[] = { 0.01f,0.0f,0.01f,0.01f };
GLfloat gun_mat_specular[] = { 0.5f, 0.5f, 0.5f, 1.0f };
GLfloat gun_mat_shininess[] = { 100.0F };

// Robot constructor
Robot::Robot(float x_param, float hip_param){
    x_pos = x_param;
    hipAngle = hip_param;
}

void Robot::drawRobot()
{
//    glPushMatrix();
//    glTranslatef(-1*x_pos, y_pos, -1*z_pos);
//    glScalef(0.8, 0.8, 0.8);
//    glTranslatef(x_pos, -1*y_pos, z_pos);

    glPushMatrix();
    glTranslatef(-1*x_pos, y_pos, -1*z_pos);
    
    glPushMatrix();
    glScalef(0.8, 0.8, 0.8);
    
    glPushMatrix();
    glRotatef(robotAngle, 0.0, 1.0, 0.0); // spin robot on base.
    glPushMatrix();
    glRotatef(hipAngle, 0.0, 1.0, 0.0);  // spin robot on hip.
    drawBody();
    drawHead();
    drawCannon();
    glPopMatrix();
    glPopMatrix();

    glPushMatrix();
     //spin robot
     glRotatef(robotAngle, 0.0, 1.0, 0.0);
    drawLowerBody();
    drawLeftUpperLeg();
    drawRightUpperLeg();
    glPopMatrix();
    
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();
}


void Robot::drawBody()
{
    glMaterialfv(GL_FRONT, GL_AMBIENT, robotBody_mat_ambient);
    glMaterialfv(GL_FRONT, GL_SPECULAR, robotBody_mat_specular);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, robotBody_mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SHININESS, robotBody_mat_shininess);

    glPushMatrix();
    glScalef(robotBodyWidth, robotBodyLength, robotBodyDepth);
    glutSolidCube(1.0);
    glPopMatrix();
}

void Robot::drawHead()
{
    // Set robot material properties per body part. Can have seperate material properties for each part
    glMaterialfv(GL_FRONT, GL_AMBIENT, robotBody_mat_ambient);
    glMaterialfv(GL_FRONT, GL_SPECULAR, robotBody_mat_specular);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, robotBody_mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SHININESS, robotBody_mat_shininess);

    glPushMatrix();
    // Position head with respect to parent (body)
    glTranslatef(0, 0.5*robotBodyLength+0.5*headLength, 0); // this will be done last

    // Build Head
    glPushMatrix();
    glScalef(0.8*robotBodyWidth, 0.6*robotBodyWidth, 0.6*robotBodyWidth);
    glutSolidCube(1.0);
    glPopMatrix();

    glPopMatrix();
}

void Robot::drawCannon()
{
    // Set robot material properties per body part. Can have seperate material properties for each part
    glMaterialfv(GL_FRONT, GL_AMBIENT, gun_mat_ambient);
    glMaterialfv(GL_FRONT, GL_SPECULAR, gun_mat_specular);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, gun_mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SHININESS, gun_mat_shininess);

    glPushMatrix();
    glTranslatef(0, 0.05*robotBodyLength, 0.1*robotBodyWidth);
    glRotatef(cannonAngle, 0.0, 0.0, 1.0);
    glTranslatef(0, -(0.05*robotBodyLength), -(0.1*robotBodyWidth));

    glPushMatrix();
    //Position cannon with respect to parent (body)
    glTranslatef(0, 0.05*robotBodyLength, 0.1*robotBodyWidth);

    glPushMatrix();
    // Creating cylinder object for cannon
    GLUquadricObj *myCannon;
    myCannon = gluNewQuadric();
    gluQuadricDrawStyle(myCannon, GLU_LINE);
    gluCylinder(myCannon, cannonRadius, cannonRadius, cannonHeight, 100, 100);

    glPushMatrix();
    glTranslatef(0, 0.2*robotBodyLength, 0.68*robotBodyWidth);
    glRotatef(-90.0, 1.0, 0.0, 0.0);
    glTranslatef(0, -(0.2*robotBodyLength), -(0.68*robotBodyWidth));

    glPushMatrix();
    //Position cannon with respect to parent (body)
    glTranslatef(0, 0.2*robotBodyLength, 0.68*robotBodyWidth);

    glPushMatrix();
    GLUquadricObj *myCannon_subPart;
    myCannon_subPart = gluNewQuadric();
    gluQuadricDrawStyle(myCannon_subPart, GLU_LINE);
    gluCylinder(myCannon_subPart, 0.4*cannonRadius, 0.4*cannonRadius, 0.1*cannonHeight, 100, 100);

    glPopMatrix();
    glPopMatrix();
    glPopMatrix();

    glPopMatrix();
    glPopMatrix();
    glPopMatrix();
}

void Robot::drawLowerBody()
{
    glMaterialfv(GL_FRONT, GL_AMBIENT, robotLowerBody_mat_ambient);
    glMaterialfv(GL_FRONT, GL_SPECULAR, robotLowerBody_mat_specular);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, robotLowerBody_mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SHININESS, robotLowerBody_mat_shininess);

    glPushMatrix();
    glRotatef(90.0, 0.0, 1.0, 0.0);

    glPushMatrix();
    // Position lower cylindrical join in respect to body
    glTranslatef(0.0, -1.5*robotBodyLength, -0.15*robotBodyWidth);

    glPushMatrix();
    // Creating cylinder object for lower body
    gluCylinder(gluNewQuadric(), 0.2*robotBodyWidth, 0.2*robotBodyWidth, 0.5*robotBodyDepth, 100, 100);

    glPopMatrix();
    glPopMatrix();

    glPushMatrix();
    // Position disk object to close lower body cylinder left side
    glTranslatef(0.0, -1.5*robotBodyLength, 0.01*robotBodyWidth);

    glPushMatrix();
    // Creating disk object to close lower body cylinder sides
    GLUquadricObj *rightCylinderDisk;
    rightCylinderDisk = gluNewQuadric();
    gluQuadricDrawStyle(rightCylinderDisk, GLU_LINE);
    gluDisk(rightCylinderDisk, 0.0, 0.19*robotBodyWidth, 100, 100);

    glPopMatrix();
    glPopMatrix();

    glPushMatrix();
    // Position disk object to close lower body cylinder right side
    glTranslatef(0.0, -1.5*robotBodyLength, 0.15*robotBodyWidth);

    glPushMatrix();
    // Creating disk object to close lower body cylinder sides
    GLUquadricObj *leftCylinderDisk;
    leftCylinderDisk = gluNewQuadric();
    gluQuadricDrawStyle(leftCylinderDisk, GLU_LINE);
    gluDisk(leftCylinderDisk, 0.0, 0.19*robotBodyWidth, 100, 100);

    glPopMatrix();
    glPopMatrix();

    glPopMatrix();
}

void Robot::drawLeftUpperLeg()
{
    glMaterialfv(GL_FRONT, GL_AMBIENT, robotLeg_mat_ambient);
    glMaterialfv(GL_FRONT, GL_SPECULAR, robotLeg_mat_specular);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, robotLeg_mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SHININESS, robotLeg_mat_shininess);

    glPushMatrix();
    glTranslatef(0.25*robotBodyWidth + -0.25*upperLegWidth, -0.5*robotBodyWidth, -0.075*robotBodyWidth);
    glRotatef(leftHipAngle, 1.0, 0.0, 0.0);
    glTranslatef(-(0.25*robotBodyWidth + -0.25*upperLegWidth), -(-0.5*robotBodyWidth), -(-0.075*robotBodyWidth));

    glPushMatrix();
    glTranslatef(0.25*robotBodyWidth + -0.25*upperLegWidth, -0.5*robotBodyWidth, -0.075*robotBodyWidth);
    glRotatef(upperLegAngle, 1.0, 0.0, 0.0);
    glTranslatef(-(0.25*robotBodyWidth + -0.25*upperLegWidth), -(-0.5*robotBodyWidth), -(-0.075*robotBodyWidth));

    glPushMatrix();
    // Position upper leg with respect to parent body
    glTranslatef(0.25*robotBodyWidth + -0.25*upperLegWidth, -0.5*robotBodyWidth, -0.075*robotBodyWidth);

    // build upper leg
    glPushMatrix();
    glScalef(upperLegWidth, upperLegLength, upperLegWidth);
    glutSolidCube(1.0);

    glPopMatrix();
    glPopMatrix();
    glPopMatrix();

    drawLeftLowerLeg();
}

void Robot::drawRightUpperLeg()
{
    glMaterialfv(GL_FRONT, GL_AMBIENT, robotLeg_mat_ambient);
    glMaterialfv(GL_FRONT, GL_SPECULAR, robotLeg_mat_specular);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, robotLeg_mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SHININESS, robotLeg_mat_shininess);

    glPushMatrix();
    glTranslatef(-(0.25*robotBodyWidth + -0.25*upperLegWidth), -0.5*robotBodyWidth, -0.075*robotBodyWidth);
    glRotatef(upperLegAngle, 1.0, 0.0, 0.0);
    glTranslatef((0.25*robotBodyWidth + -0.25*upperLegWidth), 0.5*robotBodyWidth, 0.075*robotBodyWidth);

    glPushMatrix();
    // Position upper leg with respect to parent body
    glTranslatef(-(0.25*robotBodyWidth + -0.25*upperLegWidth), -0.5*robotBodyWidth, -0.075*robotBodyWidth);

    // build upper leg
    glPushMatrix();
    glScalef(upperLegWidth, upperLegLength, upperLegWidth);
    glutSolidCube(1.0);

    glPopMatrix();
    glPopMatrix();
    glPopMatrix();

    drawRightLowerLeg();
}

void Robot::drawLeftLowerLeg()
{
    glMaterialfv(GL_FRONT, GL_AMBIENT, robotLeg_mat_ambient);
    glMaterialfv(GL_FRONT, GL_SPECULAR, robotLeg_mat_specular);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, robotLeg_mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SHININESS, robotLeg_mat_shininess);

    glPushMatrix();
    glTranslatef(0.25*robotBodyWidth + -0.25*upperLegWidth, -0.79*robotBodyWidth, -0.055*robotBodyWidth);
    glRotatef(leftKneeAngle, 1.0, 0.0, 0.0);
    glTranslatef(-(0.25*robotBodyWidth + -0.25*upperLegWidth), -(-0.79*robotBodyWidth), -(-0.055*robotBodyWidth));

    glPushMatrix();
    glTranslatef(0.25*robotBodyWidth + -0.25*upperLegWidth, -0.79*robotBodyWidth, -0.055*robotBodyWidth);
    glRotatef(lowerLegAngle, 1.0, 0.0, 0.0);
    glTranslatef(-(0.25*robotBodyWidth + -0.25*upperLegWidth), -(-0.79*robotBodyWidth), -(-0.055*robotBodyWidth));

    glPushMatrix();
    // Position lower leg with respect to parent body
    glTranslatef(0.25*robotBodyWidth + -0.25*upperLegWidth, -0.79*robotBodyWidth, -0.055*robotBodyWidth);

    // build lower leg
    glPushMatrix();
    glScalef(lowerLegWidth, lowerLegLength, lowerLegWidth);
    glutSolidCube(1.0);

    glPopMatrix();
    glPopMatrix();
    glPopMatrix();

    drawLeftFoot();
}

void Robot::drawRightLowerLeg()
{
    glMaterialfv(GL_FRONT, GL_AMBIENT, robotLeg_mat_ambient);
    glMaterialfv(GL_FRONT, GL_SPECULAR, robotLeg_mat_specular);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, robotLeg_mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SHININESS, robotLeg_mat_shininess);
    
    glPushMatrix();
    glTranslatef(-(0.25*robotBodyWidth + -0.25*upperLegWidth), -0.79*robotBodyWidth, -0.055*robotBodyWidth);
    glRotatef(rightKneeAngle, 1.0, 0.0, 0.0);
    glTranslatef((0.25*robotBodyWidth + -0.25*upperLegWidth), 0.79*robotBodyWidth, 0.055*robotBodyWidth);

    glPushMatrix();
    glTranslatef(-(0.25*robotBodyWidth + -0.25*upperLegWidth), -0.79*robotBodyWidth, -0.055*robotBodyWidth);
    glRotatef(lowerLegAngle, 1.0, 0.0, 0.0);
    glTranslatef((0.25*robotBodyWidth + -0.25*upperLegWidth), 0.79*robotBodyWidth, 0.055*robotBodyWidth);

    glPushMatrix();
    // Position lower leg with respect to parent body
    glTranslatef(-(0.25*robotBodyWidth + -0.25*upperLegWidth), -0.79*robotBodyWidth, -0.055*robotBodyWidth);

    // build lower leg
    glPushMatrix();
    glScalef(lowerLegWidth, lowerLegLength, lowerLegWidth);
    glutSolidCube(1.0);

    glPopMatrix();
    glPopMatrix();
    glPopMatrix();

    drawRightFoot();
}

void Robot::drawLeftFoot()
{
    glMaterialfv(GL_FRONT, GL_AMBIENT, robotLowerBody_mat_ambient);
    glMaterialfv(GL_FRONT, GL_SPECULAR, robotLowerBody_mat_specular);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, robotLowerBody_mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SHININESS, robotLowerBody_mat_shininess);

    glPushMatrix();
    glTranslatef(-1.5*lowerLegWidth, -4.1*robotBodyLength, lowerLegWidth);
    glRotatef(leftFootAngle, 1.0, 0.0, 0.0);
    glTranslatef(1.5*lowerLegWidth, 4.1*robotBodyLength, -lowerLegWidth);

    glPushMatrix();
    glRotatef(90.0, 0.0, 1.0, 0.0);

    glPushMatrix();
    // Position lower cylindrical join in respect to body
    glTranslatef(-1.5*lowerLegWidth, -4.1*robotBodyLength, lowerLegWidth);

    glPushMatrix();
    // Creating cylinder object for lower body
    gluCylinder(gluNewQuadric(), 0.3*lowerLegWidth, 0.3*lowerLegWidth, 1.1*lowerLegWidth, 100, 100);

    glPopMatrix();
    glPopMatrix();

    glPushMatrix();
    // Position disk object to close lower body cylinder left side
    glTranslatef(-1.5*lowerLegWidth, -4.1*robotBodyLength, -(-2.1*lowerLegWidth));

    glPushMatrix();
    // Creating disk object to close lower body cylinder sides
    GLUquadricObj *leftFoot_rightDisk;
    leftFoot_rightDisk = gluNewQuadric();
    gluQuadricDrawStyle(leftFoot_rightDisk, GLU_LINE);
    gluDisk(leftFoot_rightDisk, 0.0, 0.29*lowerLegWidth, 100, 100);

    glPopMatrix();
    glPopMatrix();

    glPushMatrix();
    // Position disk object to close lower body cylinder right side
    glTranslatef(-1.5*lowerLegWidth, -4.1*robotBodyLength, -(-1.1*lowerLegWidth));

    glPushMatrix();
    // Creating disk object to close lower body cylinder sides
    GLUquadricObj *leftFoot_leftDisk;
    leftFoot_leftDisk = gluNewQuadric();
    gluQuadricDrawStyle(leftFoot_leftDisk, GLU_LINE);
    gluDisk(leftFoot_leftDisk, 0.0, 0.29*lowerLegWidth, 100, 100);

    glPopMatrix();
    glPopMatrix();
    glPopMatrix();

    // FOOT
    glPushMatrix();
    // Position upper leg with respect to parent body
    glTranslatef(-(-1.55*lowerLegWidth), -5.0*robotBodyLength, 0.6*lowerLegWidth);

    // build upper leg
    glPushMatrix();
    glScalef(lowerLegWidth, 0.3*lowerLegLength, lowerLegWidth);
    glutSolidCube(1.0);

    glPopMatrix();
    glPopMatrix();

    // Front Claw
    glPushMatrix();
    glTranslatef(1.55*lowerLegWidth, -5.3*robotBodyLength, 1.3*lowerLegWidth);

    glPushMatrix();
    glRotatef(90.0, 1.0, 0.0, 0.0);

    glPushMatrix();
    glScalef(clawWidth, clawLength, clawWidth);
    glutSolidCube(1.0);

    glPopMatrix();
    glPopMatrix();
    glPopMatrix();

    // Left Claw
    glPushMatrix();
    glTranslatef(2.2*lowerLegWidth, -5.3*robotBodyLength, 0.6*lowerLegWidth);

    glPushMatrix();
    glRotatef(90.0, 1.0, 0.0, 0.0);
    glPushMatrix();
    glRotatef(90.0, 0.0, 0.0, 1.0);

    glPushMatrix();
    glScalef(clawWidth, clawLength, clawWidth);
    glutSolidCube(1.0);

    glPopMatrix();
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();

    // Right Claw
    glPushMatrix();
    glTranslatef(0.9*lowerLegWidth, -5.3*robotBodyLength, 0.6*lowerLegWidth);

    glPushMatrix();
    glRotatef(90.0, 1.0, 0.0, 0.0);
    glPushMatrix();
    glRotatef(90.0, 0.0, 0.0, 1.0);

    glPushMatrix();
    glScalef(clawWidth, clawLength, clawWidth);
    glutSolidCube(1.0);

    glPopMatrix();
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();

    glPopMatrix();
    glPopMatrix();
    glPopMatrix(); // closing left leg hierarchy here
}

void Robot::drawRightFoot()
{
    glMaterialfv(GL_FRONT, GL_AMBIENT, robotLowerBody_mat_ambient);
    glMaterialfv(GL_FRONT, GL_SPECULAR, robotLowerBody_mat_specular);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, robotLowerBody_mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SHININESS, robotLowerBody_mat_shininess);
    
    glPushMatrix();
    glTranslatef(-1.5*lowerLegWidth, -4.1*robotBodyLength, lowerLegWidth);
    glRotatef(rightFootAngle, 1.0, 0.0, 0.0);
    glTranslatef(1.5*lowerLegWidth, 4.1*robotBodyLength, -lowerLegWidth);

    glPushMatrix();
    glRotatef(90.0, 0.0, 1.0, 0.0);

    glPushMatrix();
    // Position lower cylindrical join in respect to body
    glTranslatef(-1.5*lowerLegWidth, -4.1*robotBodyLength, -2.1*lowerLegWidth);

    glPushMatrix();
    // Creating cylinder object for lower body
    gluCylinder(gluNewQuadric(), 0.3*lowerLegWidth, 0.3*lowerLegWidth, 1.1*lowerLegWidth, 100, 100);

    glPopMatrix();
    glPopMatrix();

    glPushMatrix();
    // Position disk object to close lower body cylinder left side
    glTranslatef(-1.5*lowerLegWidth, -4.1*robotBodyLength, -2.1*lowerLegWidth);

    glPushMatrix();
    // Creating disk object to close lower body cylinder sides
    GLUquadricObj *rightFoot_rightDisk;
    rightFoot_rightDisk = gluNewQuadric();
    gluQuadricDrawStyle(rightFoot_rightDisk, GLU_LINE);
    gluDisk(rightFoot_rightDisk, 0.0, 0.29*lowerLegWidth, 100, 100);

    glPopMatrix();
    glPopMatrix();

    glPushMatrix();
    // Position disk object to close lower body cylinder right side
    glTranslatef(-1.5*lowerLegWidth, -4.1*robotBodyLength, -1.1*lowerLegWidth);

    glPushMatrix();
    // Creating disk object to close lower body cylinder sides
    GLUquadricObj *rightFoot_leftDisk;
    rightFoot_leftDisk = gluNewQuadric();
    gluQuadricDrawStyle(rightFoot_leftDisk, GLU_LINE);
    gluDisk(rightFoot_leftDisk, 0.0, 0.29*lowerLegWidth, 100, 100);

    glPopMatrix();
    glPopMatrix();
    glPopMatrix();

    // FOOT
    glPushMatrix();
    // Position upper leg with respect to parent body
    glTranslatef(-1.55*lowerLegWidth, -5.0*robotBodyLength, 0.6*lowerLegWidth);

    // build upper leg
    glPushMatrix();
    glScalef(lowerLegWidth, 0.3*lowerLegLength, lowerLegWidth);
    glutSolidCube(1.0);

    glPopMatrix();
    glPopMatrix();

    // Front Claw
    glPushMatrix();
    glTranslatef(-1.55*lowerLegWidth, -5.3*robotBodyLength, 1.3*lowerLegWidth);

    glPushMatrix();
    glRotatef(90.0, 1.0, 0.0, 0.0);

    glPushMatrix();
    glScalef(clawWidth, clawLength, clawWidth);
    glutSolidCube(1.0);

    glPopMatrix();
    glPopMatrix();
    glPopMatrix();

    // Right Claw
    glPushMatrix();
    glTranslatef(-2.2*lowerLegWidth, -5.3*robotBodyLength, 0.6*lowerLegWidth);

    glPushMatrix();
    glRotatef(90.0, 1.0, 0.0, 0.0);
    glPushMatrix();
    glRotatef(90.0, 0.0, 0.0, 1.0);

    glPushMatrix();
    glScalef(clawWidth, clawLength, clawWidth);
    glutSolidCube(1.0);

    glPopMatrix();
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();

    // Left Claw
    glPushMatrix();
    glTranslatef(-0.9*lowerLegWidth, -5.3*robotBodyLength, 0.6*lowerLegWidth);

    glPushMatrix();
    glRotatef(90.0, 1.0, 0.0, 0.0);
    glPushMatrix();
    glRotatef(90.0, 0.0, 0.0, 1.0);

    glPushMatrix();
    glScalef(clawWidth, clawLength, clawWidth);
    glutSolidCube(1.0);

    glPopMatrix();
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();

    glPopMatrix();
    glPopMatrix();
    glPopMatrix(); // closing right leg hierarchy here
}

//bool cannonStop = false;
//bool leftStep = false;
//bool rightStep = false;

//void Robot::animation(){
//    animateGun();
////    walkForwardAnimation();
//}

void Robot::animateGun(){
    cannonAngle += 5.0;
}

void Robot::walkForwardAnimation(){
    leftStepForwardAnimation();
    rightStepForwardAnimation();
    
    z_pos -= 0.08;
}

void Robot::walkBackwardAnimation(){
    leftStepBackwardAnimation();
    rightStepBackwardAnimation();
}

void Robot::leftStepForwardAnimation(){
    leftHipAngle -= 50.0;
    leftKneeAngle += 50.0;
}

void Robot::leftStepBackwardAnimation(){
    leftHipAngle += 50.0;
    leftKneeAngle -= 50.0;
}

void Robot::rightStepForwardAnimation(){
    rightHipAngle -= 50.0;
    rightKneeAngle += 50.0;
}

void Robot::rightStepBackwardAnimation(){
    rightHipAngle += 50.0;
    rightKneeAngle -= 50.0;
}
