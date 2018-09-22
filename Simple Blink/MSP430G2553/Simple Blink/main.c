#include <msp430.h>

#define SECONDS 32000 // tenth of clock frequency

/**
 * main.c
 */
void main(void)
{
    WDTCTL = WDTPW + WDTHOLD; // stop watchdog timer

    P1DIR |= (BIT0); // set P1 Bit 0 to out, LED P1.0
    P1OUT &= ~BIT0; // force LED P1.0 off
    while (1) // always loop
    {
        long j; // declared outside of for loop to compile
        for( j = SECONDS; j > 0; j-- ) // loop for a tenth of a second
        {
            //Do nothing
        }
        P1OUT ^= BIT0; // flip LED
    }
}
