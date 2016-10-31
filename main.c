#include <msp430.h> 

// #########################
// Function Definitions

// The _system_pre_init() function will run before the global variables are initialized.
// It's a good place to stop the watchdog and set the system freq, etc...
// Just don't do anything that requires global variables yet!
// The 'return 1' is necessary to init globals on function exit.
int _system_pre_init(void)
{
    WDTCTL = WDTPW | WDTHOLD;		// Stop watchdog timer

    DCOCTL = 0;
    BCSCTL1 = CALBC1_16MHZ;
    DCOCTL = CALDCO_16MHZ;			// Set clock to 16MHz
	BCSCTL3 |= XCAP_3;				// 12.5 pF for LaunchPad crystal
	//BCSCTL2 |= DIVS_3;				// SMCLK = MCLK/8

	return 1;
}
/*
 * main.c
 */
int main(void) {
	
	return 0;
}
