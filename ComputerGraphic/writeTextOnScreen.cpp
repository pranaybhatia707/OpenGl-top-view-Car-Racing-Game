//
//  writeTextOnScreen.cpp
//  ComputerGraphic
//
//  Created by Pranay Bhatia on 24/06/21.
//  Copyright © 2021 Pranay Bhatia. All rights reserved.
//

#include "header.cpp"

void drawText(){
    string s1 = "Points = "+to_string(points);
    glColor3f(1.0,0.0,0.0);
    glRasterPos2f(wind_x-140,wind_y-30);
    int len, i;
    len = s1.length();
    for (i = 0; i < len; i++) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, s1[i]);
    }
    string s2 = "Level "+to_string(level);
    glColor3f(1.0,0.0,0.0);
    glRasterPos2f(30,wind_y-30);
    len = s2.length();
    for (i = 0; i < len; i++) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, s2[i]);
    }
}

void drawGameOver(){
    string s1 = "GAME OVER BITCH";
    glColor3f(194.0/255.0, 4.0/255.0, 108.0/255.0);
    glRasterPos2f(wind_x/2-50,wind_y/2);
    int len, i;
    len = s1.length();
    for (i = 0; i < len; i++) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, s1[i]);
    }
}
