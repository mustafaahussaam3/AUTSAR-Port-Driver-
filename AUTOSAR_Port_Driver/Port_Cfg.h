/******************************************************************************
 *
 * Module: Port
 *
 * File Name: Port_Cfg.h
 *
 * Description: Pre Build Configuration for TM4C123GH6PM Microcontroller
 * - Port Driver.
 *
 * Author: Mustafa Hussam Eldin
 ******************************************************************************/

#ifndef PORT_CFG_H_
#define PORT_CFG_H_

/*
 * Module Version 1.0.0
 */
#define PORT_CFG_SW_MAJOR_VERSION              (1U)
#define PORT_CFG_SW_MINOR_VERSION              (0U)
#define PORT_CFG_SW_PATCH_VERSION              (0U)

/*
 * AUTOSAR Version 4.0.3
 */
#define PORT_CFG_AR_RELEASE_MAJOR_VERSION     (4U)
#define PORT_CFG_AR_RELEASE_MINOR_VERSION     (0U)
#define PORT_CFG_AR_RELEASE_PATCH_VERSION     (3U)

typedef enum {
    PORT_PIN_MODE_DIO   =  0,  PORT_PIN_MODE_ADC = 0,
    PORT_PIN_MODE_UART  =  1,  PORT_PIN_MODE_SSI1  = 1,
    PORT_PIN_MODE_SSI   =  2,  PORT_PIN_MODE_UART1C= 2,
    PORT_PIN_MODE_I2C   =  3,  PORT_PIN_MODE_CAN0  = 3,
    PORT_PIN_MODE_M0PWM =  4,
    PORT_PIN_MODE_M1PWM =  5,
    PORT_PIN_MODE_CAN1  =  8,
    PORT_PIN_MODE_CAN01 =  8,
    PORT_PIN_MODE_NMI   =  8,
}Port_Inital_Mode;

/* Number of Configured Channel in Port */
#define PORT_CONFIGURED_CHANNELS             (39U)

/* Pre-compile option for Set Pin Direction API */
#define PORT_SET_PIN_DIRECTION_API          (STD_OFF)

/* Pre-compile option for Version Info API */
#define PORT_VERSION_INFO_API               (STD_ON)

/* Pre-compile option for Development Error Detect */
#define PORT_DEV_ERROR_DETECT               (STD_ON)

/* Pre-compile  switch to enable / disable the use of the function Port_SetPinMode(). */
#define PORT_SET_PIN_MODE_API               (STD_OFF)

/* Pre-compile to The initial direction of the pin (IN or OUT) */
#define PORT_PIN_DIRECTION                 PORT_PIN_IN

/* Parameter to indicate if the direction is changeable on a port pin during runtime */
#define PORT_PIN_DIRECTION_CHANGEABLE       (STD_OFF)

/* Port pin mode from mode list for use with Port_Init() function */
#define PORT_PIN_INITIAL_MODE           PORT_PIN_MODE_DIO

/* Port Pin Level value from Port pin list. */
#define PORT_PIN_LEVEL_HIGH                 (STD_HIGH)
#define PORT_PIN_LEVEL_LOW                  (STD_LOW)
#define PORT_PIN_LEVEL_VALUE             PORT_PIN_LEVEL_HIGH

/* Port pin mode from mode list */
#define PORT_PIN_MODE

/* Parameter to indicate if the mode is changeable on a port pin during runtime */
#define PORT_PIN_MODE_CHANGEABLE            (STD_OFF)

uint16 PortPinId;
uint16 PortNumberOfPortPins;


#endif /* PORT_CFG_H_ */
