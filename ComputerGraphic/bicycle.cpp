//
//  bicycle.cpp
//  ComputerGraphic
//
//  Created by Pranay Bhatia on 24/06/21.
//  Copyright © 2021 Pranay Bhatia. All rights reserved.
//

#include "header.cpp"

float dt=0.2;

class Bicycle
{
public:
    float xc = 50;
    float yc = 50;
    float v = 0;
    float theta = 0;
    float delta = 0;
    float beta = 0;
    
    float L = 2.56;
    float lr = L / 2;
    
    void reset()
    {
        xc = 0; // centre of mass
        yc = 0; // centre of mass
        theta = 0; // angle of car with x - axis
        delta = 0; // steer angle ..
        beta = 0;
    }
    
    void step(float a, float d_delta)
    {
        float dx = v*cos(theta) * dt;
        float dy = v*sin(theta) * dt;
        xc = xc + dx;
        yc = yc + dy;
        theta = theta + v*cos(beta)*tan(delta)/L * dt;
        beta = atan(lr*delta/L);
        v += a*dt - v / 100;
        delta += d_delta;
        
        delta = min(max(-0.3f, delta), 0.3f); // maximum steerig ..
        v = min(max(0.0f, v), 80.0f); // maximum velocity ..
        
        if ((xc > 1000) or (xc < 0)){
            GAME_OVER = true;
        }
        
        if ((yc > 1000) or (yc < 0)){
            GAME_OVER = true;
        }
    }
};
