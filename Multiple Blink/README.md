# Multiple Blink
This program was interfaced with the microcontroller, to make 2 LED's flash at different, independent rates.

## Supported Microprocessors
* MSP430G2553
* MSP430F5529

## Specifications
The processor has a 32kHz clock cycle.  The define macro defines 'SECONDS' as 32000.  This value is uesd to get increments of the clock rate, in order to make the LED's flash at some ratio of the clock.  This makes it easier to make the LED's flash at a visible rate.  Since the LED's are flashing at a different frequency, it is easier to use a counter to delay the flipping of states of the LED rather than using a for loop for a delay.  Seperate counters and seperate counter limits make flipping of LED's independant of each other.
