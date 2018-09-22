# Simple Blink
This program was built in order to make an LED flash, at a certian rate, with a 50% duty cycle. This is a good program to get familar with the c programming syntax, as well as getting familiar with a microcontroller.

## Supported Microprocessors
* MSP430G2553
* MSP430F5529

## Specifications
The processor has a 32kHz clock cycle.  The define macro defines 'SECONDS' as 32000.  This value is uesd in a for loop to loop for 32000 times.  This delays the program, allowing to simulate a sleep operation.  Putting this before line of code that flips the status of an LED should make the LED flip one time every second, assuming that the processor executes one operation every 1/32000 seconds.
