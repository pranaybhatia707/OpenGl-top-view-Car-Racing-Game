//
//  drawCoin.cpp
//  ComputerGraphic
//
//  Created by Pranay Bhatia on 24/06/21.
//  Copyright © 2021 Pranay Bhatia. All rights reserved.
//

#include "header.cpp"
#include "bicycle.cpp"
#include "coins.cpp"

float MIN_DIST = 40;

void draw_coin(coins *c,Bicycle car){
    
    if (c->colided){
        return;
    }
    int x = c->x;
    int y = c->y;
    float dist = sqrt(pow((car.xc - c->x), 2) + pow((car.yc - c->y), 2));
    if (dist <= MIN_DIST){
        c->colided = true;
        points+=100;
    }
    
    int draw = !c->colided;
    
    if(draw){
        int r = 10;
        glColor3f(1.0, 1.0, 0);
        glBegin(GL_POLYGON);
        for(int i = 0;i<=360;i++){
            int xt = x+r*cos(i*pi/180);
            int yt = y+r*sin(i*pi/180);
            glVertex2f(xt,yt);
        }
        glEnd();
    }
    
    glutPostRedisplay();
}
