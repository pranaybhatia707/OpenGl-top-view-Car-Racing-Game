//
//  coins.cpp
//  ComputerGraphic
//
//  Created by Pranay Bhatia on 24/06/21.
//  Copyright © 2021 Pranay Bhatia. All rights reserved.
//

#include "header.cpp"

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

