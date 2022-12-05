class Laser
{
public:
    
    // variables
    float x_pos = 0.0;
    float y_pos = 0.0;
    float z_pos = 28.0;
    
    float laser_height = 100.0;
    float laser_radius = 0.06;
    
    //functions
    Laser(float x_param, float y_param, float z_param, float radius, float height);
    void drawLaser();
    void drawRobotLaser(int robot_id);
    void mouseMotion(int x, int y);
    void checkCollision(float robot_x, float robot_y, float robot_z);
    void moveLaserForward();
    void reposition(float x_param, float y_param, float z_param);
};
