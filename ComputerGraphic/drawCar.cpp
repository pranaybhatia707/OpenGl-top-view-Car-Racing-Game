//
//  drawCar.cpp
//  ComputerGraphic
//
//  Created by Pranay Bhatia on 24/06/21.
//  Copyright © 2021 Pranay Bhatia. All rights reserved.
//

#include "header.cpp"


int l = 60,b = 30; // length and breadth of car ..

void draw_car(int x , int y, float Phi,float d){
    
    glColor3f(1.0, 0, 0);
    Phi +=  pi/2;
    //car boundary
    glBegin(GL_POLYGON);
    glVertex2f(x-10*sin(Phi), y+10*cos(Phi));
    glVertex2f(x-l*sin(Phi), y+l*cos(Phi));
    glVertex2f(x-l*sin(Phi)+b*cos(Phi), y+l*cos(Phi)+b*sin(Phi));
    glVertex2f(x+b*cos(Phi)-10*sin(Phi), y+b*sin(Phi)+10*cos(Phi));
    glVertex2f(x+(b-10)*cos(Phi), y+(b-10)*sin(Phi));
    glVertex2f(x+10*cos(Phi), y+10*sin(Phi));
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(x+13*cos(Phi), y+13*sin(Phi));
    glVertex2f(x+17*cos(Phi), y+17*sin(Phi));
    glVertex2f(x+13*cos(Phi)-l*sin(Phi), y+13*sin(Phi)+l*cos(Phi));
    glVertex2f(x+17*cos(Phi)-l*sin(Phi), y+17*sin(Phi)+l*cos(Phi));
    glEnd();
    // back wheel 1
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(x-(l-10)*sin(Phi), y+(l-10)*cos(Phi));
    glVertex2f(x-(l-23)*sin(Phi), y+(l-23)*cos(Phi));
    glVertex2f(x-(l-23)*sin(Phi)-8*cos(Phi), y+(l-23)*cos(Phi)-8*sin(Phi));
    glVertex2f(x-(l-10)*sin(Phi)-8*cos(Phi), y+(l-10)*cos(Phi)-8*sin(Phi));
    glEnd();
    // back wheel 2
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(x-(l-10)*sin(Phi)+b*cos(Phi), y+(l-10)*cos(Phi)+b*sin(Phi));
    glVertex2f(x-(l-23)*sin(Phi)+b*cos(Phi), y+(l-23)*cos(Phi)+b*sin(Phi));
    glVertex2f(x-(l-23)*sin(Phi)+(8+b)*cos(Phi), y+(l-23)*cos(Phi)+(8+b)*sin(Phi));
    glVertex2f(x-(l-10)*sin(Phi)+(8+b)*cos(Phi), y+(l-10)*cos(Phi)+(8+b)*sin(Phi));
    glEnd();
    // front wheel 1
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(x-(23)*sin(Phi+d), y+(23)*cos(Phi+d));
    glVertex2f(x-(10)*sin(Phi+d), y+(10)*cos(Phi+d));
    glVertex2f(x-(10)*sin(Phi+d)-8*cos(Phi+d), y+(10)*cos(Phi+d)-8*sin(Phi+d));
    glVertex2f(x-(23)*sin(Phi+d)-8*cos(Phi+d), y+(23)*cos(Phi+d)-8*sin(Phi+d));
    glEnd();
    // back wheel 2
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(x-(23)*sin(Phi+d)+b*cos(Phi+d), y+(23)*cos(Phi+d)+b*sin(Phi+d));
    glVertex2f(x-(10)*sin(Phi+d)+b*cos(Phi+d), y+(10)*cos(Phi+d)+b*sin(Phi+d));
    glVertex2f(x-(10)*sin(Phi+d)+(8+b)*cos(Phi+d), y+(10)*cos(Phi+d)+(8+b)*sin(Phi+d));
    glVertex2f(x-(23)*sin(Phi+d)+(8+b)*cos(Phi+d), y+(23)*cos(Phi+d)+(8+b)*sin(Phi+d));
    glEnd();
}
