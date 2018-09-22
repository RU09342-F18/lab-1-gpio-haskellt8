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
    P4DIR |= (BIT7); // set P4 Bit 7 to out, LED P4.7

    P4OUT &= ~BIT7; // force LED P4.7 off
    P1OUT &= ~BIT0; // force LED P1.0 off

    long countTo1=SECONDS/3; // flip 3 times a second
    long counter1=0;
    long countTo2=SECONDS/4; // flip 4 times a second
    long counter2=0;
    while(1)
    {
        if (counter1++ == countTo1)
        {
            counter1=0;
            P1OUT ^= BIT0; // flip LED
        }
        if (counter2++ == countTo2)
        {
            counter2=0;
            P4OUT ^= BIT7; // flip LED
        }
    }
}
