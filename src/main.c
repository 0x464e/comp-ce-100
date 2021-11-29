/******************************************************************************
*
* Copyright (C) 2009 - 2014 Xilinx, Inc.  All rights reserved.
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
*
* Use of the Software is limited solely to applications:
* (a) running on a Xilinx device, or
* (b) that interact with a Xilinx device through a bus or interconnect.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
* XILINX  BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
* WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF
* OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*
* Except as contained in this notice, the name of the Xilinx shall not be used
* in advertising or otherwise to promote the sale, use or other dealings in
* this Software without prior written authorization from Xilinx.
*
******************************************************************************/

/*
 *
 *
 * This application configures UART 16550 to baud rate 9600.
 * PS7 UART (Zynq) is not initialized by this application, since
 * bootrom/bsp configures it to baud rate 115200
 *
 * ------------------------------------------------
 * | UART TYPE   BAUD RATE                        |
 * ------------------------------------------------
 *   uartns550   9600
 *   uartlite    Configurable only in HW design
 *   ps7_uart    115200 (configured by bootrom/bsp)
 */

// Main program for exercise

//****************************************************
//By default, every output used in this exercise is 0
//****************************************************
#include <stdio.h>
#include "platform.h"
#include "xil_printf.h"
#include "sleep.h"
#include "xgpiops.h"
#include "xttcps.h"
#include "xscugic.h"
#include "xparameters.h"
#include "Pixel.h"
#include "Interrupt_setup.h"
#include "alien.h"
#include "Bullet.h"
#include "Ship.h"

//********************************************************************
//***************TRY TO READ COMMENTS*********************************
//********************************************************************

//***Hint: Use sleep(x)  or usleep(x) if you want some delays.****
//***To call assembler code found in blinker.S, call it using: blinker();***


//Comment this if you want to disable all interrupts
#define enable_interrupts
 //Status==0x01 ->btn0, Status==0x02->btn1, Status==0x04->btn2, Status==0x08-> btn3, Status==0x10->SW0, Status==0x20 -> SW1
#define BTN0 0x01
#define BTN1 0x02
#define BTN2 0x04
#define BTN3 0x08
#define SW0  0x10
#define SW1  0x20




/***************************************************************************************
Name:
Student number:

Name:
Student number:

Name:
Student number:

Tick boxes that you have coded

Led-matrix driver        Game            Assembler
    []                    []                    []

Brief description:

*****************************************************************************************/

volatile int8_t ShipPosition = 1;

struct Alien alien = { 100, {0,1}, 1, 0};
Alien* alien_ptr = &alien;
Bullet alienbullet_global = {1, 1, {0,0}, 0, 0};
Bullet* alienbullet_ptr = &alienbullet_global;
const Bullet ship_bullet = {-1, 0, {-1,-1}, 0, 0};
Bullet ship_bullets[3] = {ship_bullet, ship_bullet, ship_bullet};
Bullet* ship_bullets_ptr = ship_bullets;
//starts with value 1000 0000
//

uint8_t LedPosition = 0;


#define LEDS  *(uint8_t*)(0x41200000)

int main()
{
    //**DO NOT REMOVE THIS****
        init_platform();
    //************************


#ifdef    enable_interrupts
        init_interrupts();
#endif


        //setup screen
        setup();



        Xil_ExceptionEnable();

        LEDS = 0b1000;


        //Try to avoid writing any code in the main loop.
        while(1){


        }


        cleanup_platform();
        return 0;
}


//Timer interrupt handler for led matrix update. Frequency is 800 Hz
void TickHandler(void *CallBackRef){
    //Don't remove this
    uint32_t StatusEvent;

    //exceptions must be disabled when updating screen
    Xil_ExceptionDisable();



    //****Write code here ****

    static uint8_t channel = 0;
    open_line(8);
    run(channel);
    open_line(channel);
    channel = (channel + 1) % 8;



    DrawShip(ShipPosition, 0, 50, 0);





    //****END OF OWN CODE*****************

    //*********clear timer interrupt status. DO NOT REMOVE********
    StatusEvent = XTtcPs_GetInterruptStatus((XTtcPs *)CallBackRef);
    XTtcPs_ClearInterruptStatus((XTtcPs *)CallBackRef, StatusEvent);
    //*************************************************************
    //enable exceptions
    Xil_ExceptionEnable();
}


//Timer interrupt for moving alien, shooting... Frequency is 10 Hz by default
void TickHandler1(void *CallBackRef){

    //Don't remove this
    uint32_t StatusEvent;

    //****Write code here ****
    open_line(8);
    blinker();
    DrawAlien(alien_ptr);

    open_line(8);
    //DrawBullet(alienbullet_ptr);

    DrawBullet(alienbullet_ptr, alien_ptr);
    for (int i=0; i < 3; i++) {
    	open_line(8);
    	DrawBullet(ship_bullets_ptr + i, NULL);
    }

    //****END OF OWN CODE*****************
    //clear timer interrupt status. DO NOT REMOVE
    StatusEvent = XTtcPs_GetInterruptStatus((XTtcPs *)CallBackRef);
    XTtcPs_ClearInterruptStatus((XTtcPs *)CallBackRef, StatusEvent);

}

//Interrupt handler for switches and buttons.
//Reading Status will tell which button or switch was used
//Bank information is useless in this exercise
void ButtonHandler(void *CallBackRef, u32 Bank, u32 Status){
    //****Write code here ****

    //Hint: Status==0x01 ->btn0, Status==0x02->btn1, Status==0x04->btn2, Status==0x08-> btn3, Status==0x10->SW0, Status==0x20 -> SW1
    static uint8_t bullet_no = 0;


    if(Status == BTN2) {
        ShipPosition = (ShipPosition + 1) % 8;
    }
    else if (Status == BTN3) {
        ShipPosition = ((ShipPosition - 1) % 8 + 8) % 8; // trick for negative modulo to work (-1 % 8 = 7)
    }
    else if (Status == BTN1) {
    	ship_bullets[bullet_no].coords.x = ShipPosition;
    	ship_bullets[bullet_no].coords.y = 6;
        bullet_no = (bullet_no + 1) % 3;
    }




    //****END OF OWN CODE*****************
}















