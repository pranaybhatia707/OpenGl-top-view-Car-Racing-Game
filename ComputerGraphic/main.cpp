#include "header.cpp"  // file for defining all the headers ..

int points = 0;
int level = 1;
bool GAME_OVER = false;

int wind_x = 1000;
int wind_y = 1000; // window size ...

#include "drawCar.cpp"  // file for drawing cars ..
#include "drawCoin.cpp" // file for drawing coins ..
#include "writeTextOnScreen.cpp" // file for writing text on screen ..
#include "keyboardInput.cpp" // Details regarding keyboard input function ..

float D_STEER = 0.002; // Angle turned in 1 steer ..
float D_A = 3.75;  // acceleration ..

Bicycle car;

coins c[10];

void display1() {
    glClear(GL_COLOR_BUFFER_BIT);
    if (not GAME_OVER){
        for(int i = 0;i < 12-2*level;i++){
            draw_coin(c+i,car);
        }
        draw_car(car.xc, car.yc, car.theta,car.delta);
        drawText();
    }
    else{
        drawGameOver();
    }
    glutPostRedisplay();
    glFlush();
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
        draw_coin(c+i,car);
    }
    if (not GAME_OVER){
        for(int i = 0;i < 12-2*level;i++){
            draw_coin(c+i,car);
        }
        draw_car(car.xc, car.yc, car.theta,car.delta);
        drawText();
    }
    else{
        drawGameOver();
    }
    glutPostRedisplay();
    glFlush();
    usleep(20000);
}

void myinit() {
    glClearColor(38.0/255.0, 140.0/255.0, 171.0/255.0, 1.0);
    //glColor3f(1.0, 0.0, 0.0);
    glPointSize(5.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 999.0, 0.0, 999.0);
    
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
