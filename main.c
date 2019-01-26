#include <msp430.h> 

// ############################
// Defines and type definitions

typedef struct menu_item_2line
{
    const uint8_t*          line_1_static;
    const uint8_t*          line_2_static;
    const uint8_t           l1_cursor_pos;
    const uint8_t           l2_cursor_pos;
    struct menu_item_2line* next_menu;
} menu_item_2line_t;

// ############################
// Function Definitions



/* **************************************************************************************
 * The _system_pre_init() function will run before the global variables are initialized.
 * It's a good place to stop the watchdog and set the system freq, etc...
 * Just don't do anything that requires global variables yet!
 * The 'return 1' is necessary to init globals on function exit.
************************************************************************************** */
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
int main(void)
{
	// Inits.

    for (;;)
    {
        // Why were we woken up?

        // If woken up because of continuation of I2C event:
            // Continue I2C event [follow callback, etc...].

        // If woken up for some system event:
            // Set the system flag(s).

        // If the I2C peripheral [USCI] is not busy:
            // Service any system flags that require USCI [in priority sequence].

        // Service any system flags that don't require shared resources.

        // Go to sleep if we can.
    }

	return 0;
}


/*
 * State machine for UI updates.
 *
 */
