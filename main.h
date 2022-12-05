// Function prototypes
void init3DSurfaceWindow();
void display3D();
void reshape3D(int w, int h);

void handleMouse(int x, int y);
//void mouseButtonHandler3D(int button, int state, int x, int y);
//void mouseScrollWheelHandler3D(int button, int dir, int xMouse, int yMouse);
//void mouseMotionHandler3D(int xMouse, int yMouse);
//void keyboardHandler3D(unsigned char key, int x, int y);

void drawGround();
void animationHandler(int param);
void laserAnimation(int param);
void forwardStepHandler(int param);
void stepHandler(int param);
void backwardStepHandler(int param);
void keyboard(unsigned char key, int x, int y);

