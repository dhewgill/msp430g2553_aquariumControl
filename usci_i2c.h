#ifndef MSP430_USCI_I2C_H_
#define MSP430_USCI_I2C_H_

#include <msp430.h>
#include <stdint.h>
#include <stddef.h>

//Definitions for error codes.
#define USCI_I2C_NO_ACK_ON_ADDRESS	0x01	// The slave did not acknowledge  the address
#define USCI_I2C_NO_ACK_ON_DATA		0x02	// The slave did not acknowledge  all data
#define USCI_I2C_MISSING_START_CON	0x03	// Generated Start Condition not detected on bus
#define USCI_I2C_MISSING_STOP_CON	0x04	// Generated Stop Condition not detected on bus
#define USCI_I2C_UE_DATA_COL		0x05	// Unexpected Data Collision (arbitration)
#define USCI_I2C_UE_STOP_CON		0x06	// Unexpected Stop Condition
#define USCI_I2C_UE_START_CON		0x07	// Unexpected Start Condition
#define USCI_I2C_NO_DATA			0x08	// Transmission buffer is empty
#define USCI_I2C_DATA_OUT_OF_BOUND	0x09	// Transmission buffer is outside SRAM space
#define USCI_I2C_BAD_MEM_READ		0x0A	// Error during external memory read

#define USCI_I2C_EVENT_SIG			0x80
#define USCI_BUSY					0x40

//Type definitions
typedef enum
{
	USCI_I2C_ERR_NONE				= 0x00,
	USCI_I2C_ERR_NO_ACK_ON_ADDRESS	= 0x01,	// The slave did not acknowledge  the address
	USCI_I2C_ERR_NO_ACK_ON_DATA		= 0x02,	// The slave did not acknowledge  all data
	USCI_I2C_ERR_MISSING_START_CON	= 0x03,	// Generated Start Condition not detected on bus
	USCI_I2C_ERR_MISSING_STOP_CON	= 0x04,	// Generated Stop Condition not detected on bus
	USCI_I2C_ERR_UE_DATA_COL		= 0x05,	// Unexpected Data Collision (arbitration)
	USCI_I2C_ERR_UE_STOP_CON		= 0x06,	// Unexpected Stop Condition
	USCI_I2C_ERR_UE_START_CON		= 0x07,	// Unexpected Start Condition
	USCI_I2C_ERR_NO_DATA			= 0x08,	// Transmission buffer is empty
	USCI_I2C_ERR_DATA_OUT_OF_BOUND	= 0x09,	// Transmission buffer is outside SRAM space
	USCI_I2C_ERR_BAD_MEM_READ		= 0x0a,	// Error during external memory read
	USCI_I2C_ERR_MASK				= 0x0f	// Mask to retrieve the errors from the union.
} enum_usci_i2c_errors_t;

typedef enum
{
	I2C_T_IDLE				= 0,
	I2C_T_TX_STOP			= 1,
	I2C_T_RX_STOP			= 2,
	I2C_T_TX_WAIT			= 3,	// Transmit n bytes then hand control to main thread without issuing stop.
	I2C_T_RX_WAIT			= 4,	// Receive n bytes then hand control to main thread without issuing stop.
	I2C_T_TX_RESTART		= 5,
	I2C_T_RX_RESTART		= 6
	//I2C_T_RX_RNDM			= 8		// Random read; implies tx_restart followed by rx_stop.
} enum_i2c_transact_type_t;

typedef enum
{
	I2C_S_START					= 0,
	I2C_S_TX_BYTE				= 2,
	I2C_S_RX_BYTE				= 4,
	I2C_S_PREP_ACK_NACK_ADDR	= 6,
	I2C_S_PREP_ACK_NACK			= 8,
	I2C_S_ACK_NACK_ADDR			= 10,
	I2C_S_ACK_NACK				= 12,
	I2C_S_PREP_STOP				= 14,
	I2C_S_STOP					= 16
} enum_i2c_state_t;

typedef enum
{
    I2C_S_TX_IDLE               = 0,
    I2C_S_TX_ADDR               = 2,
    I2C_S_TX_BYTE               = 4
} enum_i2c_tx_state_t;

typedef struct _i2c_transaction_t i2c_transaction_t;

typedef void* (*i2c_callback_fnptr_t)( i2c_transaction_t *, void * );

struct _i2c_transaction_t
{
	volatile uint8_t					address;
	volatile uint8_t					numBytes;			// uint8_t is ok as long as numBytes < 63 for LCD transfers.
	volatile enum_i2c_transact_type_t	transactType;
	i2c_callback_fnptr_t				callbackFn;
	volatile uint8_t					*buf;
};

typedef union _usci_i2c_sys_info_t
{
	enum_usci_i2c_errors_t	error;
	uint8_t					flags;
} usci_i2c_sys_info_t;


#endif /* MSP430_USCI_I2C_H_ */
