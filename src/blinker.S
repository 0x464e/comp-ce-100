


.global blinker


blinker:
    push  {r11}
    add   r11, sp, #0

    ldrb  r3, =LedPosition  //load LedPosition address
    ldr   r2, [r3]          //load LedPosition value
    cmp   r2, #2            //value less than 3?
    bhi   lsl               //branch to shift left branch if not
    ldr   r3, =0x41200000   //otherwise continue here, load LEDS address
    ldr   r2, [r3]            //load LEDS value
    lsr   r2, r2, #1        //shift value right by one
    str   r2, [r3]          //store shifted value to LEDS
    b     inc               //branch to increment branch

lsl:
    ldr   r3, =0x41200000   //load LEDS address
    ldr   r2, [r3]          //load LEDS value
    lsl   r2, r2, #1        //shift value left by one
    str   r2, [r3]          //store shifted value to LEDS
    b     inc               //branch to increment branch

inc:
    ldrb  r3, =LedPosition  //load LedPosition address
    ldr   r2, [r3]          //load LedPosition value
    add   r2, r2, #1        //increment value by one
    str   r2, [r3]          //store incremented value
    cmp   r2, #6            //check if value is 6
    bne   end               //if not, branch to the function ending
    mov   r2, #0            //if value was 6, set it back to 0
    str   r2, [r3]          //store the changed value to LedPosition
    b     end               //branch to the function ending

end:
    add   sp, r11, #0
    pop   {r11}
    bx    lr

