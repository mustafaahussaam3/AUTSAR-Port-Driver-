/******************************************************************************
 *
 * Module: Port
 *
 * File Name: Port_PBcfg.h
 *
 * Description: Post Build Configuration for TM4C123GH6PM Microcontroller
 * - Port Driver.
 *
 * Author: Mustafa Hussam Eldin
 ******************************************************************************/

#include "Port.h"

/*
 * Module Version 1.0.0
 */
#define PORT_PBCFG_SW_MAJOR_VERSION              (1U)
#define PORT_PBCFG_SW_MINOR_VERSION              (0U)
#define PORT_PBCFG_SW_PATCH_VERSION              (0U)

/*
 * AUTOSAR Version 4.0.3
 */
#define PORT_PBCFG_AR_RELEASE_MAJOR_VERSION     (4U)
#define PORT_PBCFG_AR_RELEASE_MINOR_VERSION     (0U)
#define PORT_PBCFG_AR_RELEASE_PATCH_VERSION     (3U)

/* AUTOSAR Version checking between PORT_PBcfg.c and PORT.h files */
#if ((PORT_PBCFG_AR_RELEASE_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
 ||  (PORT_PBCFG_AR_RELEASE_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION)\
 ||  (PORT_PBCFG_AR_RELEASE_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of PBcfg.c does not match the expected version"
#endif

/* Software Version checking between PORT_PBcfg.c and PORT.h files */
#if ((PORT_PBCFG_SW_MAJOR_VERSION != PORT_SW_MAJOR_VERSION)\
 ||  (PORT_PBCFG_SW_MINOR_VERSION != PORT_SW_MINOR_VERSION)\
 ||  (PORT_PBCFG_SW_PATCH_VERSION != PORT_SW_PATCH_VERSION))
  #error "The SW version of PBcfg.c does not match the expected version"
#endif

/* PB structure used with PORT_Init API */
const Port_ConfigType Port_Configuration = {
                                             PORTA, PIN0, PORT_PIN_IN, OFF, (uint8)0
                                             PORTA, PIN1, PORT_PIN_IN, OFF, (uint8)0
                                             PORTA, PIN2, PORT_PIN_IN, OFF, (uint8)0
                                             PORTA, PIN3, PORT_PIN_IN, OFF, (uint8)0
                                             PORTA, PIN4, PORT_PIN_IN, OFF, (uint8)0
                                             PORTA, PIN5, PORT_PIN_IN, OFF, (uint8)0
                                             PORTA, PIN6, PORT_PIN_IN, OFF, (uint8)0
                                             PORTA, PIN7, PORT_PIN_IN, OFF, (uint8)0
                                             PORTB, PIN0, PORT_PIN_IN, OFF, (uint8)0
                                             PORTB, PIN1, PORT_PIN_IN, OFF, (uint8)0
                                             PORTB, PIN2, PORT_PIN_IN, OFF, (uint8)0
                                             PORTB, PIN3, PORT_PIN_IN, OFF, (uint8)0
                                             PORTB, PIN4, PORT_PIN_IN, OFF, (uint8)0
                                             PORTB, PIN5, PORT_PIN_IN, OFF, (uint8)0
                                             PORTB, PIN6, PORT_PIN_IN, OFF, (uint8)0
                                             PORTB, PIN7, PORT_PIN_IN, OFF, (uint8)0
                                             PORTC, PIN0, PORT_PIN_IN, OFF, (uint8)0  /* JTAG Pin Start*/
                                             PORTC, PIN1, PORT_PIN_IN, OFF, (uint8)0
                                             PORTC, PIN2, PORT_PIN_IN, OFF, (uint8)0
                                             PORTC, PIN3, PORT_PIN_IN, OFF, (uint8)0  /* JTAG Pin End */
                                             PORTC, PIN4, PORT_PIN_IN, OFF, (uint8)0
                                             PORTC, PIN5, PORT_PIN_IN, OFF, (uint8)0
                                             PORTC, PIN6, PORT_PIN_IN, OFF, (uint8)0
                                             PORTC, PIN7, PORT_PIN_IN, OFF, (uint8)0
                                             PORTD, PIN0, PORT_PIN_IN, OFF, (uint8)0  /* NMI PIN */
                                             PORTD, PIN1, PORT_PIN_IN, OFF, (uint8)0
                                             PORTD, PIN2, PORT_PIN_IN, OFF, (uint8)0
                                             PORTD, PIN3, PORT_PIN_IN, OFF, (uint8)0
                                             PORTD, PIN4, PORT_PIN_IN, OFF, (uint8)0
                                             PORTD, PIN5, PORT_PIN_IN, OFF, (uint8)0
                                             PORTD, PIN6, PORT_PIN_IN, OFF, (uint8)0
                                             PORTD, PIN7, PORT_PIN_IN, OFF, (uint8)0
                                             PORTF, PIN0, PORT_PIN_IN, OFF, (uint8)0
                                             PORTF, PIN1, PORT_PIN_IN, OFF, (uint8)0
                                             PORTF, PIN2, PORT_PIN_IN, OFF, (uint8)0
                                             PORTF, PIN3, PORT_PIN_IN, OFF, (uint8)0
                                             PORTF, PIN4, PORT_PIN_IN, OFF, (uint8)0
                                             PORTF, PIN5, PORT_PIN_IN, OFF, (uint8)0
                                             PORTF, PIN6, PORT_PIN_IN, OFF, (uint8)0
                                             PORTF, PIN7, PORT_PIN_IN, OFF, (uint8)0 /* NMI PIN */
                                         };

