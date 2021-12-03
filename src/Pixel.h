#ifndef PIXEL_H_
#define PIXEL_H_

#include "platform.h"
#include "xil_printf.h"
#include "sleep.h"
#include "xgpiops.h"
#include "xttcps.h"
#include "xscugic.h"
#include "xparameters.h"

#define CONTROL  *(uint8_t*)(0x41220008)
#define CHANNEL  *(uint8_t*)(0x41220000)


void setup();
void SetPixel(uint8_t x,uint8_t y, uint8_t r, uint8_t g, uint8_t b);
void run(uint8_t x);
void latch();
void set_channel_bit(uint8_t x);
void open_line(uint8_t x);

#endif /* PIXEL_H_ */
