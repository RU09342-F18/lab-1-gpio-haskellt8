#include <msp430.h>

#define TENTHS 3200 //tenth of clock frequency

/**
 * main.c
 */
void main(void)
{
    WDTCTL = WDTPW + WDTHOLD; // Stop watchdog timer

    P1DIR |= (BIT0); //set P1 Bit 0 to out, LED P1.0
    P1DIR &= ~(BIT3); //set P1 Bit 3 to in
    P1REN |= (BIT3); //enable P1 Bit 3 resistor
    P1OUT |= (BIT3); //set P1 Bit 3 resistor to Pull Up
    P1DIR |= (BIT6); //set P1 Bit 6 to out, LED P1.6

    while (1) // always loop
    {
        int button = P1IN & BIT3; // & P1.3 button with BIT3 to get button status
        if (button == 0) // button is 0 when P1.3 button is pressed
        {
            P1OUT &= ~BIT6; // force LED P1.6 off
            long j; // declared outside of for loop to compile
            for( j = 10*TENTHS; j > 0; j-- ) // loop for a tenth of a second
            {
                if (j == 1) // first iteration of loop
                {
                    P1OUT ^= BIT0; // flip LED
                }
            }
        }
        else // button not pressed
        {
            P1OUT &= ~BIT0; // force LED P1.0 off
            long j; // declared outside of for loop to compile
            for( j = 5*TENTHS; j > 0; j-- ) // loop for a tenth of a second
            {
                if (j == 1) // first iteration of loop
                {
                    P1OUT ^= BIT6; // flip LED
                }
            }
        }
    }
}
