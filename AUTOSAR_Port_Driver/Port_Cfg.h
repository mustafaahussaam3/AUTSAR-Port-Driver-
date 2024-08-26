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
    PORT_PIN_MODE_DIO   =  0,
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
#define PORT_CONFIGURED_CHANNELS            39U

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
#define PORT_PIN_INITIAL_MODE            PORT_PIN_MODE_DIO

/* Port Pin Level value from Port pin list. */
#define PORT_PIN_LEVEL_HIGH                 (STD_HIGH)
#define PORT_PIN_LEVEL_LOW                  (STD_LOW)
#define PORT_PIN_LEVEL_VALUE             PORT_PIN_LEVEL_HIGH

/* Port pin mode from mode list */
#define PORT_PIN_MODE                     PORT_PIN_MODE_DIO

/* Parameter to indicate if the mode is changeable on a port pin during runtime */
#define PORT_PIN_MODE_CHANGEABLE            (STD_OFF)

/* Channel Index in the array of structures in Port_PBcfg.c */
#define DioConf_PA0_CHANNEL_ID_INDEX         (uint8)0x00
#define DioConf_PA1_CHANNEL_ID_INDEX         (uint8)0x01
#define DioConf_PA2_CHANNEL_ID_INDEX         (uint8)0x02
#define DioConf_PA3_CHANNEL_ID_INDEX         (uint8)0x03
#define DioConf_PA4_CHANNEL_ID_INDEX         (uint8)0x04
#define DioConf_PA5_CHANNEL_ID_INDEX         (uint8)0x05
#define DioConf_PA6_CHANNEL_ID_INDEX         (uint8)0x06
#define DioConf_PA7_CHANNEL_ID_INDEX         (uint8)0x07
#define DioConf_PB0_CHANNEL_ID_INDEX         (uint8)0x08
#define DioConf_PB1_CHANNEL_ID_INDEX         (uint8)0x09
#define DioConf_PB2_CHANNEL_ID_INDEX         (uint8)0x0A
#define DioConf_PB3_CHANNEL_ID_INDEX         (uint8)0x0B
#define DioConf_PB4_CHANNEL_ID_INDEX         (uint8)0x0C
#define DioConf_PB5_CHANNEL_ID_INDEX         (uint8)0x0D
#define DioConf_PB6_CHANNEL_ID_INDEX         (uint8)0x0E
#define DioConf_PB7_CHANNEL_ID_INDEX         (uint8)0x0F
#define DioConf_PC4_CHANNEL_ID_INDEX         (uint8)0x10
#define DioConf_PC5_CHANNEL_ID_INDEX         (uint8)0x11
#define DioConf_PC6_CHANNEL_ID_INDEX         (uint8)0x12
#define DioConf_PC7_CHANNEL_ID_INDEX         (uint8)0x13
#define DioConf_PD0_CHANNEL_ID_INDEX         (uint8)0x14
#define DioConf_PD1_CHANNEL_ID_INDEX         (uint8)0x15
#define DioConf_PD2_CHANNEL_ID_INDEX         (uint8)0x16
#define DioConf_PD3_CHANNEL_ID_INDEX         (uint8)0x17
#define DioConf_PD4_CHANNEL_ID_INDEX         (uint8)0x18
#define DioConf_PD5_CHANNEL_ID_INDEX         (uint8)0x19
#define DioConf_PD6_CHANNEL_ID_INDEX         (uint8)0x1A
#define DioConf_PD7_CHANNEL_ID_INDEX         (uint8)0x1B
#define DioConf_PE0_CHANNEL_ID_INDEX         (uint8)0x1C
#define DioConf_PE1_CHANNEL_ID_INDEX         (uint8)0x1D
#define DioConf_PE2_CHANNEL_ID_INDEX         (uint8)0x1E
#define DioConf_PE3_CHANNEL_ID_INDEX         (uint8)0x1F
#define DioConf_PE4_CHANNEL_ID_INDEX         (uint8)0x20
#define DioConf_PE5_CHANNEL_ID_INDEX         (uint8)0x21
#define DioConf_PF0_CHANNEL_ID_INDEX         (uint8)0x22
#define DioConf_LED1_CHANNEL_ID_INDEX        (uint8)0x23
#define DioConf_PF2_CHANNEL_ID_INDEX         (uint8)0x24
#define DioConf_PF3_CHANNEL_ID_INDEX         (uint8)0x25
#define DioConf_SW1_CHANNEL_ID_INDEX         (uint8)0x26
uint16 PortPinId;
uint16 PortNumberOfPortPins;


#endif /* PORT_CFG_H_ */
