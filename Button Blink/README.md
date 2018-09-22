# Button Blink
This program was interfaced with the microcontroller, to make a LED flash when a button is pressed, and a different LED flash when the button is released.

## Supported Microprocessors
* MSP430G2553
* MSP430F5529

## Specifications
The processor has a 32kHz clock cycle.  The define macro defines 'TENTHS' as 3200.  This was done in oreder to be used to the LED to flash at multiples of 0.1 seconds.  Rather than putting in a single empty for loop to delay, I used 2 for loops one for each LED.  The for loops are in if else checks for the button pressed.  This way, it is easy to change the flash rate for either LED, without changing both of the rates.
