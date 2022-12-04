class Laser
{
public:
    
    float x_pos = 0.0;
    float y_pos = 0.0;
    float z_pos = 0.0;
    
    float laser_height = 130.0;
    float laser_radius = 0.06;
    
    bool laser_mouseUpdated = false;

    float laserAngleX = 0.0;
    float laserAngleY = 0.0;
    
//    Laser(float x_param, float y_param, float z_param);
    void drawLaser();
    void mouseMotion(int x, int y);
};
