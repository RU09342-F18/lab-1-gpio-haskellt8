#include <msp430.h>

#define TENTHS 3200 // tenth of clock frequency

/**
 * main.c
 */
void main(void)
{
    WDTCTL = WDTPW + WDTHOLD; // stop watchdog timer

    P1DIR |= (BIT0); // set P1 Bit 0 to out, LED P1.0
    P2DIR &= ~(BIT1); // set P2 Bit 1 to in
    P2REN |= (BIT1); // enable P1 Bit 1 resistor
    P2OUT |= (BIT1); // set P2 Bit 1 resistor to pull up
    P4DIR |= (BIT7); // set P1 Bit 6 to out, LED P4.7

    while (1) // always loop
    {
        int button = P2IN & BIT1; // & P1.3 button with BIT3 to get button status
        if (button == 0) // button is 0 when P1.3 button is pressed
        {
            P4OUT &= ~BIT7; // force LED P1.6 off
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
                    P4OUT ^= BIT7; // flip LED
                }
            }
        }
    }
}
