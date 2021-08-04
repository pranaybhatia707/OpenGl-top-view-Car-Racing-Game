#include <GL/glut.h>
#include <math.h>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <unistd.h>
#include <string>

using namespace std;
#define pi 3.14

//int x_c = 250,y_c = 250;
//float Angle = 30;
float Phi;
//int v = 12; // velocity ..
int l = 60,b = 30; // length and breadth of car ..
//int acc = 6; // acceleration ..
//int max_vel = 42; // maximum velocity ..

int wind_x = 1000;
int wind_y = 1000; // window size ...
float MIN_DIST = 40;

float D_STEER = 0.002; // Angle turned in 1 steer ..
float D_A = 3.75;  // acceleration ..
float dt=0.2;

int points = 0;
int level = 2;
bool GAME_OVER = false;

int keyarr[127];

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
        
        delta = min(max(-0.02f, delta), 0.02f); // maximum steerig ..
        v = min(max(0.0f, v), 80.0f); // maximum velocity ..
        
        if ((xc > 1000) or (xc < 0)){
            GAME_OVER = true;
        }
        
        if ((yc > 1000) or (yc < 0)){
            GAME_OVER = true;
        }
    }
}car;

void draw_car(int x , int y, bool r){
    if(r){
        glColor3f(1.0, 0, 0);
    }
    else{
        glColor3f(0, 0, 1.0);
    }
    Phi = car.theta + pi/2;
    float d = car.delta;
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

// No. of coins , I want to use will be 12 - 2*level
class coins{
public:
    int x;
    int y;
    bool colided = false;
    
    coins(){
        x = rand()%(wind_x-10);
        y = rand()%(wind_y-10);
    }
    void recoins(){
        x = rand()%(wind_x-10);
        y = rand()%(wind_y-10);
    }
};

void draw_coin(coins *c){

    if (c->colided){
        return;
    }
    int x = c->x;
    int y = c->y;
    float dist = sqrt(pow((car.xc - c->x), 2) + pow((car.yc- c->y), 2));
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

coins c[10];

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

int t = 0;
void display1() {
    glClear(GL_COLOR_BUFFER_BIT);
    if (not GAME_OVER){
        for(int i = 0;i < 12-2*level;i++){
            draw_coin(c+i);
        }
        draw_car(car.xc, car.yc, true);
        
        drawText(); 
    }
    else{
        drawGameOver();
    }
    glutPostRedisplay();
    glFlush();
}

void keyup(unsigned char Key, int x, int y)
{
    switch(Key)
    {
        case 'w': keyarr[int('w')] = 0; break;
        case 'a': keyarr[int('a')] = 0; break;
        case 's': keyarr[int('s')] = 0; break;
        case 'd': keyarr[int('d')] = 0; break;
    };
}

void MyKeyboardFunc(unsigned char Key, int x, int y){
    
    switch(Key)
    {
        case 'w':keyarr[int('w')] = 1; break;
        case 'a':keyarr[int('a')] = 1; break;
        case 's':keyarr[int('s')] = 1; break;
        case 'd':keyarr[int('d')] = 1; break;
        case 'q':car.delta = 0; break;
            
    };
}

void myinit() {
    glClearColor(38.0/255.0, 140.0/255.0, 171.0/255.0, 1.0);
    //glColor3f(1.0, 0.0, 0.0);
    glPointSize(5.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 999.0, 0.0, 999.0);
    
}

void idle()
{
    float a = 0;
    float d_steer = 0;
    bool pressed = false;
    if (keyarr[int('w')])
        a = D_A; pressed = true;
    if (keyarr[int('a')])
        d_steer = D_STEER; pressed = true;
    if (keyarr[int('s')])
        a = -D_A; pressed = true;
    if (keyarr[int('d')])
        d_steer = -D_STEER; pressed = true;
    car.step(a, d_steer);
    
    glClear(GL_COLOR_BUFFER_BIT);
    for(int i = 0;i < 12-2*level;i++){
        draw_coin(c+i);
    }
    if (not GAME_OVER){
        for(int i = 0;i < 12-2*level;i++){
            draw_coin(c+i);
        }
        draw_car(car.xc, car.yc, true);     
        drawText(); 
    }
    else{
        drawGameOver();
    }
    glutPostRedisplay();
    glFlush();
    usleep(20000);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(wind_x, wind_y);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Crazy Car Game");
    glutDisplayFunc(display1);
    glutIdleFunc(idle);
    glutKeyboardUpFunc(keyup);
    glutKeyboardFunc(MyKeyboardFunc);
   
    myinit();
    glutMainLoop();
}
