
class Robot
{
public:
//    float leftHipAngle;
//    float leftKneeAngle;
//    float rightHipAngle;
//    float rightKneeAngle;
    
    float x_pos = 0.0;
    float y_pos = 4.5;
    float z_pos = 30.0;
    
    float health = 3;
    
    float robotBodyWidth = 10.0;
    float robotBodyLength = 2.0;
    float robotBodyDepth = 6.0;

    float headWidth = robotBodyWidth;
    float headLength = robotBodyLength*2;
    float headDepth = robotBodyDepth;

    float cannonHeight = robotBodyWidth*0.7;
    float cannonRadius = robotBodyLength / 4.0;

    float upperLegLength = robotBodyLength*2.0;
    float upperLegWidth = 0.15*robotBodyWidth;

    float lowerLegLength = upperLegLength*1.2;
    float lowerLegWidth = upperLegWidth*0.9;

    float clawWidth = 0.5*lowerLegWidth;
    float clawLength = 0.3*lowerLegLength;

    char curJoint = 'b';

    // Control angles
    float robotAngle = 0.0;
    float hipAngle = 0.0;
    
    float leftHipAngle = 0.0;
    float leftKneeAngle = 0.0;
    float leftFootAngle = 0.0;

    float rightHipAngle = 0.0;
    float rightKneeAngle = 0.0;
    float rightFootAngle = 0.0;

    float upperLegAngle = 30.0;
    float lowerLegAngle = -60.0;
    float cannonAngle = 10.0;
    
    Robot(float x_param, float hip_param);
    void drawRobot();
    void drawBody();
    void drawHead();
    void drawCannon();
    void drawLowerBody();
    void drawLeftUpperLeg();
    void drawRightUpperLeg();
    void drawLeftUpperLeg2();
    void drawRightUpperLeg2();
    void drawLeftLowerLeg();
    void drawRightLowerLeg();
    void drawLeftFoot();
    void drawRightFoot();
    void keyboard(unsigned char key, int x, int y);
    void walkForwardAnimation();
    void walkBackwardAnimation();
    void animation();
    void animateGun();
    void leftStepForwardAnimation();
    void rightStepForwardAnimation();
    void leftStepBackwardAnimation();
    void rightStepBackwardAnimation();
};
