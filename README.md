# OpenGl-top-view-Car-Racing-Game

The Game is a top view reward collecting Car Game , The Car within the Game even has the ability to drag.
Many Important Features are :

1) Car Acceleration
2) Car Decceleration
3) Steering
4) Friction (Automatic Decelaration)

# ScreenShots

![image](https://user-images.githubusercontent.com/44642485/128123678-85c15ff7-dcf6-4fad-85bb-4ab76fe3d8a0.png)

![image](https://user-images.githubusercontent.com/44642485/128123706-19bfe15d-0d8b-465e-abb4-5258802d00f8.png)

# Logic Explained

1) Car Movement is Implemented by recalculation of the vertices of the car with respect to changing acceleration and steer angle.
2) Reward are randomly assigned position coordinates every new Game.
3) Collision between Reward Coin and Car is implemented by carrying out a threshhold perimeter around the reward coin.
4) Friction is simulated by subtracting the velocity by it's fraction.
5) Car Drag is implemented by recording multiple keyboard operations using char vector and then using combinations of keys to interpret multiple car operations including drag.

# Operations to control car

KeyBoard Operations are as follow :

1) w -> accelerate 
2) s -> deccelerate
3) a -> steer left
4) d -> steer right

# Requirements to run the Game

Use OpenGL -> Either include GLUT.h framework or GL/gl.h framework in cpp





