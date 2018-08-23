/*
 * usci_i2c.c
 *
 *  Created on: 11-Nov-2016
 *      Author: Dale Hewgill
 *
 *  This is an interrupt driven implementation of an I2C master for the MSP430 USCI module.
 */

#include "usci_i2c.h"

// #########################
// Defines and type definitions



// #########################
// Function Prototypes



// #########################
// Function Definitions



// #########################
// Interrupt

// For I2C RX/TX.
#pragma vector=USCIAB0TX_VECTOR
__interrupt void USCIAB0TX_ISR(void)
{
    // Ready to transmit or receive next byte.
    // Service UCBxTXIFG when buffer is empty [tx] or full [rx].
    __no_operation();
}

// For I2C state changes.
#pragma vector=USCIAB0RX_VECTOR
__interrupt void USCIAB0RX_ISR(void)
{
    // In single master mode, for UCNACKIFG only.
    __no_operation();
}
