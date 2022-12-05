class Laser
{
public:
    
    float x_pos = 0.0;
    float y_pos = 0.0;
    float z_pos = 28.0;
    
    float laser_height = 100.0;
    float laser_radius = 0.06;
    
    void drawLaser();
    void mouseMotion(int x, int y);
    void checkCollision(float robot_x, float robot_y, float robot_z);
};
