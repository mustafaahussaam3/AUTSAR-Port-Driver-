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

typdef enum {
    PORT_PIN_MODE_ADC, PORT_PIN_MODE_CAN,
    PORT_PIN_MODE_DIO, PORT_PIN_MODE_DIO_GPT,
    PORT_PIN_MODE_DIO_WDG, PORT_PIN_MODE_FLEXRAY,
    PORT_PIN_MODE_ICU, PORT_PIN_MODE_LIN,
    PORT_PIN_MODE_MEM, PORT_PIN_MODE_PWM,
    PORT_PIN_MODE_SPI
}Port_Inital_Mode;

/* Pre-compile option for Set Pin Direction API */
#define PORT_SET_PIN_DIRECTION_API          (STD_ON)

/* Pre-compile option for Version Info API */
#define PORT_VERSION_INFO_API               (STD_ON)

/* Pre-compile option for Development Error Detect */
#define PORT_DEV_ERROR_DETECT               (STD_ON)

/* Pre-compile  switch to enable / disable the use of the function Port_SetPinMode(). */
#define PORT_SET_PIN_MODE_API               (STD_ON)

/* Pre-compile to The initial direction of the pin (IN or OUT) */
#define PORT_PIN_DIRECTION                 PORT_PIN_IN

/* Parameter to indicate if the direction is changeable on a port pin during runtime */
#define PORT_PIN_DIRECTION_CHANGEABLE       (STD_OFF)

/* Port pin mode from mode list for use with Port_Init() function */
#define PORT_PIN_INITIAL_MODE       (Port_Inital_Mode)PORT_PIN_MODE_DIO

/* Port Pin Level value from Port pin list. */
#define PORT_PIN_LEVEL_HIGH                 (STD_HIGH)
#define PORT_PIN_LEVEL_LOW                  (STD_LOW)
#define PORT_PIN_LEVEL_VALUE             PORT_PIN_LEVEL_HIGH

/* Port pin mode from mode list */
#define PORT_PIN_MODE               (Port_Inital_Mode)PORT_PIN_MODE_DIO

/* Parameter to indicate if the mode is changeable on a port pin during runtime */
#define PORT_PIN_MODE_CHANGEABLE            (STD_OFF)

uint16 PortPinId;
uint16 PortNumberOfPortPins;


#endif /* PORT_CFG_H_ */
