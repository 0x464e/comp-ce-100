# COMP.CE.100 Introduction to embedded systems 
This repository contains the project work I did with my partner for my university's introduction to embedded systems course.  
The assignment was to program an alien shooter game on a LED matrix using C.  
In this project we used C to manipulate memory at specific addresses to produce desired results on the LED matrix. An extra step was to animate LEDs using only ARM assembly, the assembly code is found in the [`blinker.S` file](https://github.com/0x464e/comp-ce-100/blob/master/src/blinker.S).  
To figure how we should manipulate memory and at which addresses at which timings, we had to refer to [data sheets](https://github.com/0x464e/comp-ce-100/tree/master/datasheets/) for the processor, LED matrix, and the development board.

![image](https://i.imgur.com/OG59LHr.png)

In the game you can move your ship, which is seen in the bottom rows of the LED matrix, left and right and you can shoot at the alien which is moving left and right at the top of the screen.

## Building/Usage
Building and using this is so involved that I feel it's not worth to try to even write out instructions. Not only would you need to have the specific same hardware we had, but also all the required SDKs with same versions along with complicated linker scripts.
