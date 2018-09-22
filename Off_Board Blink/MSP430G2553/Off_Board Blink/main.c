#include <msp430.h>

#define SECONDS 32000 // clock frequency
#define SECONDS 32000 // clock frequency

/**
 * main.c
 */
void main(void)
{
    WDTCTL = WDTPW + WDTHOLD; // stop watchdog timer

    P1DIR |= (BIT0); // set P1 Bit 0 to out, LED P1.0
    P1DIR |= (BIT6); // set P1 Bit 6 to out, LED P1.6

    P1OUT &= ~BIT6; // force LED P1.6 off
    P1OUT &= ~BIT0; // force LED P1.0 off

    const long countTo1=SECONDS/3;
    long counter1=0;
    const long countTo2=SECONDS/4;
    long counter2=0;
    while(1) // loop second
    {
        if (counter1++ > countTo1) // first iteration of loop
        {
            counter1=0;
            P1OUT ^= BIT6; // flip LED
        }
        if (counter2++ > countTo2) // first iteration of loop
        {
            counter2=0;
            P1OUT ^= BIT0; // flip LED
        }
    }
}
