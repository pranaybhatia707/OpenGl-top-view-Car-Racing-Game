//
//  keyboardInput.cpp
//  ComputerGraphic
//
//  Created by Pranay Bhatia on 24/06/21.
//  Copyright © 2021 Pranay Bhatia. All rights reserved.
//

#include "header.cpp"

int keyarr[127];

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
        //case 'q':car.delta = 0; break;
            
    };
}

