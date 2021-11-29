/*
 * Pixel.c
 *
 *  Created on: -----
 *      Author: -----
 */

#include "Pixel.h"



//Table for pixel dots.
//                 dots[X][Y][COLOR]
volatile uint8_t dots[8][8][3]={0};



static const int RST_SLEEP = 500;
#define RST_BIT 0x01
#define BIT1 (0x01 << 1)
#define SB_BIT (0x01 << 2)
#define CLK (0x01 << 3)
#define SDA_BIT (0x01 << 4)

// Here the setup operations for the LED matrix will be performed
void setup(){


    //reseting screen at start is a MUST to operation (Set RST-pin to 1).

    // Initialize
    CONTROL = 0;
    CHANNEL = 0;

    // Toggle rst bit
    CONTROL |= RST_BIT;
    usleep(RST_SLEEP);
    CONTROL &=~ RST_BIT;
    usleep(RST_SLEEP);
    CONTROL |= RST_BIT;
    usleep(RST_SLEEP);

    // Set sda bit
    CONTROL |= SDA_BIT;

    //Write code that sets 6-bit values in register of DM163 chip. Recommended that every bit in that register is set to 1. 6-bits and 24 "bytes", so some kind of loop structure could be nice.
    //24*6 bits needs to be transmitted
    for (int i=0; i < 24; i++) {
        for (int j=0; j < 6; j++) {
            CONTROL |= SDA_BIT; // sda = 1
            CONTROL &=~ CLK; // clk = 0
            CONTROL |= CLK; // clk = 1
        }
    }

    //Final thing in this function is to set SB-bit to 1 to enable transmission to 8-bit register.
    CONTROL |= SB_BIT;
}

//Change value of one pixel at led matrix. This function is only used for changing values of dots array
void SetPixel(uint8_t x,uint8_t y, uint8_t r, uint8_t g, uint8_t b){

    //Hint: you can invert Y-axis quite easily with 7-y
    dots[x][y][0]=b;
    //Write rest of two lines of code required to make this function work properly (green and red colors to array).
    dots[x][y][1]=g;
    dots[x][y][2]=r;
}


//Put new data to led matrix. Hint: This function is supposed to send 24-bytes and parameter x is for channel x-coordinate.
void run(uint8_t x){
    //Write code that writes data to led matrix driver (8-bit data). Use values from dots array
    //Hint: use nested loops (loops inside loops)
    //Hint2: loop iterations are 8,3,8 (pixels,color,8-bitdata)

    for (int pixel=0; pixel < 8; pixel++)
    {
        for (int color=0; color < 3; color++)
        {
        	uint8_t data = dots[x][pixel][color];
            for (int bit=0; bit < 8; bit++)
            {
                if (data & 0x80)
                    CONTROL |= SDA_BIT; // sda = 1
                else
                    CONTROL &= ~SDA_BIT; // sda = 0

                CONTROL &=~ CLK; // clk = 0
                data <<= 1;
                CONTROL |= CLK; // clk = 1
            }
        }
    }
    latch();
}

//Latch signal. See colorsshield.pdf or DM163.pdf in project folder on how latching works
void latch(){
    CONTROL |= BIT1; // lat = 1
    CONTROL &=~ BIT1; // lat = 0
}

void set_channel_bit(uint8_t x) {
    CHANNEL = (0x01 << x);
}

//Set one line (channel) as active, one at a time.
void open_line(uint8_t x){
    if (x < 8) {
        set_channel_bit(x);
    }
    else {
        CHANNEL = 0;
    }
}
