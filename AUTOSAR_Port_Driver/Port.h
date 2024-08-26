 /******************************************************************************
 *
 * Module: Port
 *
 * File Name: Port.h
 *
 * Description: Header file for TM4C123GH6PM Microcontroller - Port Driver.
 *
 * Author : Mustafa Hussam Eldin
 ******************************************************************************/

#ifndef PORT_H
#define PORT_H

#define PORT_VENDOR_ID    (1000U)

/* PORT Module Id */
#define PORT_MODULE_ID    (121U)

/* PORT Instance Id */
#define PORT_INSTANCE_ID  (0U)

/*
 * Module Version 1.0.0
 */
#define PORT_SW_MAJOR_VERSION           (1U)
#define PORT_SW_MINOR_VERSION           (0U)
#define PORT_SW_PATCH_VERSION           (0U)

/*
 * AUTOSAR Version 4.0.3
 */
#define PORT_AR_RELEASE_MAJOR_VERSION   (4U)
#define PORT_AR_RELEASE_MINOR_VERSION   (0U)
#define PORT_AR_RELEASE_PATCH_VERSION   (3U)

/*
 * Macros for PORT Status
 */
#define PORT_INITIALIZED                (1U)
#define PORT_NOT_INITIALIZED            (0U)

/* Standard AUTOSAR types */
#include "Std_Types.h"

/* AUTOSAR checking between Std Types and PORT Modules */
#if ((STD_TYPES_AR_RELEASE_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
 ||  (STD_TYPES_AR_RELEASE_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION)\
 ||  (STD_TYPES_AR_RELEASE_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Std_Types.h does not match the expected version"
#endif

#include "Port_Cfg.h"
/* AUTOSAR Version checking between PORT_Cfg.h and PORT.h files */
#if ((PORT_CFG_AR_RELEASE_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
 ||  (PORT_CFG_AR_RELEASE_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION)\
 ||  (PORT_CFG_AR_RELEASE_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of PORT_Cfg.h does not match the expected version"
#endif

/* Software Version checking between PORT_Cfg.h and PORT.h files */
#if ((PORT_CFG_SW_MAJOR_VERSION != PORT_SW_MAJOR_VERSION)\
 ||  (PORT_CFG_SW_MINOR_VERSION != PORT_SW_MINOR_VERSION)\
 ||  (PORT_CFG_SW_PATCH_VERSION != PORT_SW_PATCH_VERSION))
  #error "The SW version of PORT_Cfg.h does not match the expected version"
#endif

/* Non AUTOSAR files */
#include "Common_Macros.h"
/******************************************************************************
 *                      API Service Id Macros                                 *
 ******************************************************************************/
/* Service ID for Port setup gpio pin */
#define PORT_INIT_SID                   (uint8)0x00

/* Service ID for Port Set Pin Direction */
#define PORT_SET_PIN_DIRECTION_SID      (uint8)0x01

/* Service ID for Refresh Port Direction */
#define PORT_REFRESH_PORT_DIRECTION_SID (uint8)0x02

/* Service ID for Get Version Info */
#define PORT_GET_VERSION_INFO_SID       (uint8)0x03

/* Service ID for Port Set Pin Mode */
#define PORT_SET_PIN_MODE_SID           (uint8)0x04
/*******************************************************************************
 *                      DET Error Codes                                        *
 *******************************************************************************/
/* Det code to report invalid Port Pin ID requested */
#define PORT_E_PARAM_PIN                (uint8)0x0A

/* Port Pin not configured as changeable */
#define PORT_E_DIRECTION_UNCHANGEABLE   (uint8)0x0B

/* API Port_Init service called with wrong parameter. */
#define PORT_E_PARAM_CONFIG             (uint8)0x0C

/* API Port_SetPinMode service called when mode is unchangeable */
#define PORT_E_PARAM_INVALID_MODE       (uint8)0x0D
#define PORT_E_MODE_UNCHANGEABLE        (uint8)0x0E

/* API service called without module initialization */
#define PORT_E_UNINIT                   (uint8)0x0F

/* APIs called with a Null Pointer */
#define PORT_E_PARAM_POINTER            (uint8)0x10



/*******************************************************************************
 *                              Module Definitions                             *
 *******************************************************************************/

/* GPIO Registers base addresses */
#define GPIO_PORTA_BASE_ADDRESS           0x40004000
#define GPIO_PORTB_BASE_ADDRESS           0x40005000
#define GPIO_PORTC_BASE_ADDRESS           0x40006000
#define GPIO_PORTD_BASE_ADDRESS           0x40007000
#define GPIO_PORTE_BASE_ADDRESS           0x40024000
#define GPIO_PORTF_BASE_ADDRESS           0x40025000

/* GPIO Registers offset addresses */
#define PORT_DATA_REG_OFFSET              0x3FC
#define PORT_DIR_REG_OFFSET               0x400
#define PORT_ALT_FUNC_REG_OFFSET          0x420
#define PORT_PULL_UP_REG_OFFSET           0x510
#define PORT_PULL_DOWN_REG_OFFSET         0x514
#define PORT_DIGITAL_ENABLE_REG_OFFSET    0x51C
#define PORT_LOCK_REG_OFFSET              0x520
#define PORT_COMMIT_REG_OFFSET            0x524
#define PORT_ANALOG_MODE_SEL_REG_OFFSET   0x528
#define PORT_CTL_REG_OFFSET               0x52C

#define PORTA                             (0U)
#define PORTB                             (1U)
#define PORTC                             (2U)
#define PORTD                             (3U)
#define PORTE                             (4U)
#define PORTF                             (5U)

#define PIN0                              (0U)
#define PIN1                              (1U)
#define PIN2                              (2U)
#define PIN3                              (3U)
#define PIN4                              (4U)
#define PIN5                              (5U)
#define PIN6                              (6U)
#define PIN7                              (7U)


/*******************************************************************************
 *                              Module Data Types                              *
 *******************************************************************************/

/*Data type for the symbolic name of a port pin.  */
typedef uint8 Port_PinType;

/* Different port pin modes.
 * PORT212: The type Port_PinModeType shall be used with the
 * function call Port_SetPinMode
 *
 */
typedef uint8 Port_PinModeType;

/* Description: Enum to hold PIN direction */
typedef enum
{
     PORT_PIN_IN,PORT_PIN_OUT
}Port_PinDirectionType;

/* Description: Enum to hold internal resistor type for PIN */
typedef enum
{
    OFF,PULL_UP,PULL_DOWN
}Port_InternalResistor;

/* Description: Structure to configure each individual PIN:
 *	1. the PORT Which the pin belongs to. 0, 1, 2, 3, 4 or 5
 *	2. the number of the pin in the PORT.
 *  3. the direction of pin --> INPUT or OUTPUT
 *  4. the internal resistor --> Disable, Pull up or Pull down
 *
 *  is Hardware Dependent Structure
 */
typedef struct
{
     uint8 port_num;
     uint8 pin_num;
     Port_PinDirectionType direction;
     Port_InternalResistor resistor;
     uint8 initial_value;
     Port_Inital_Mode mode;
}Port_ConfigChannel;

typedef struct 
{
  Port_ConfigChannel Channels[PORT_CONFIGURED_CHANNELS];
}Port_ConfigType;


/*******************************************************************************
 *                      Function Prototypes                                    *
 *******************************************************************************/

/************************************************************************************
* Service Name: Port_Init
* Servivce ID[hex]: 0x00
* Sync/Async: Synchronous
* Reentrancy: Non Reentrant
* Parameters (in): ConfigPtr - Pointer to post-build configuration data
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Initializes the Port Driver module.
************************************************************************************/
void Port_Init( const Port_ConfigType* ConfigPtr );

/************************************************************************************
* Service Name: Port_SetPinDirection
* Servivce ID[hex]: 0x01
* Sync/Async: Synchronous
* Reentrancy: reentrant, it shall be configured with same pin number but different port
* Parameters (in): Pin (Port Pin ID number) - Direction (Port Pin Direction_
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: value: Sets the port pin direction during run time
************************************************************************************/
void Port_SetPinDirection( Port_PinType Pin, Port_PinDirectionType Direction );

/************************************************************************************
* Service Name: Port_SetPinDirection
* Servivce ID[hex]: 0x02
* Sync/Async: Synchronous
* Reentrancy: Non Reentrant
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: value: Refreshes port direction.
************************************************************************************/
void Port_RefreshPortDirection( void );

/************************************************************************************
* Service Name: Port_GetVersionInfo
* Servivce ID[hex]: 0x03
* Sync/Async: Synchronous
* Reentrancy: Non Reentrant
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): versioninfo - Pointer to where to store the version information of this module.
* Return value: None
* Description: value: Returns the version information of this module.
************************************************************************************/
void Port_GetVersionInfo( Std_VersionInfoType* versioninfo );

/************************************************************************************
* Service Name: Port_SetPinMode
* Servivce ID[hex]: 0x04
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): Pin - Port Pin ID number
*                  Mode - New Port Pin mode to be set on port pin.
* Parameters (inout): None
* Parameters (out):   None
* Return value: None
* Description: value: Sets the port pin mode during run time
************************************************************************************/
void Port_SetPinMode( Port_PinType Pin, Port_PinModeType Mode );

/*******************************************************************************
 *                       External Variables                                    *
 *******************************************************************************/
/* Extern PB structures to be used by Port and other modules */
extern const Port_ConfigType Port_Configuration;

#endif /* PORT_H */
