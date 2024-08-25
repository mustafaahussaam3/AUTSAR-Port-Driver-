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

/* PB structure used with PORT_Init API Excluding JTAG Pin From Configurations*/
const Port_ConfigType Port_Configuration = {
                                             PORTA, PIN0, PORT_PIN_IN, OFF, STD_IDLE, PORT_PIN_INITIAL_MODE,  /* 0 PA0 */ /*  U0Rx */
                                             PORTA, PIN1, PORT_PIN_IN, OFF, STD_IDLE, PORT_PIN_INITIAL_MODE,  /* 1 PA1 */ /*  U0Tx */
                                             PORTA, PIN2, PORT_PIN_IN, OFF, STD_IDLE, PORT_PIN_INITIAL_MODE,  /* 2 PA2 */
                                             PORTA, PIN3, PORT_PIN_IN, OFF, STD_IDLE, PORT_PIN_INITIAL_MODE,  /* 3 PA3 */
                                             PORTA, PIN4, PORT_PIN_IN, OFF, STD_IDLE, PORT_PIN_INITIAL_MODE,  /* 4 PA4 */
                                             PORTA, PIN5, PORT_PIN_IN, OFF, STD_IDLE, PORT_PIN_INITIAL_MODE,  /* 5 PA5 */
                                             PORTA, PIN6, PORT_PIN_IN, OFF, STD_IDLE, PORT_PIN_INITIAL_MODE,  /* 6 PA6 */
                                             PORTA, PIN7, PORT_PIN_IN, OFF, STD_IDLE, PORT_PIN_INITIAL_MODE,  /* 7 PA7 */

                                             PORTB, PIN0, PORT_PIN_IN, OFF, STD_IDLE, PORT_PIN_INITIAL_MODE,  /* 8 PB0 */ /*  U1Rx */
                                             PORTB, PIN1, PORT_PIN_IN, OFF, STD_IDLE, PORT_PIN_INITIAL_MODE,  /* 9 PB1 */ /*  U1Tx */
                                             PORTB, PIN2, PORT_PIN_IN, OFF, STD_IDLE, PORT_PIN_INITIAL_MODE,  /*10 PB2 */
                                             PORTB, PIN3, PORT_PIN_IN, OFF, STD_IDLE, PORT_PIN_INITIAL_MODE,  /*11 PB3 */
                                             PORTB, PIN4, PORT_PIN_IN, OFF, STD_IDLE, PORT_PIN_INITIAL_MODE,  /*12 PB4 */
                                             PORTB, PIN5, PORT_PIN_IN, OFF, STD_IDLE, PORT_PIN_INITIAL_MODE,  /*13 PB5 */
                                             PORTB, PIN6, PORT_PIN_IN, OFF, STD_IDLE, PORT_PIN_INITIAL_MODE,  /*14 PB6 */
                                             PORTB, PIN7, PORT_PIN_IN, OFF, STD_IDLE, PORT_PIN_INITIAL_MODE,  /*15 PB7 */

                                             PORTC, PIN4, PORT_PIN_IN, OFF, STD_IDLE, PORT_PIN_INITIAL_MODE,  /*16 PC4 */ /*  U4Rx */ /* U1Rx */
                                             PORTC, PIN5, PORT_PIN_IN, OFF, STD_IDLE, PORT_PIN_INITIAL_MODE,  /*17 PC5 */ /*  U4Tx */ /* U1Tx */
                                             PORTC, PIN6, PORT_PIN_IN, OFF, STD_IDLE, PORT_PIN_INITIAL_MODE,  /*18 PC6 */ /*  U3Rx */
                                             PORTC, PIN7, PORT_PIN_IN, OFF, STD_IDLE, PORT_PIN_INITIAL_MODE,  /*19 PC7 */ /*  U3Tx */

                                             PORTD, PIN0, PORT_PIN_IN, OFF, STD_IDLE, PORT_PIN_INITIAL_MODE,  /*20 PD0 */
                                             PORTD, PIN1, PORT_PIN_IN, OFF, STD_IDLE, PORT_PIN_INITIAL_MODE,  /*21 PD1 */
                                             PORTD, PIN2, PORT_PIN_IN, OFF, STD_IDLE, PORT_PIN_INITIAL_MODE,  /*22 PD2 */
                                             PORTD, PIN3, PORT_PIN_IN, OFF, STD_IDLE, PORT_PIN_INITIAL_MODE,  /*23 PD3 */
                                             PORTD, PIN4, PORT_PIN_IN, OFF, STD_IDLE, PORT_PIN_INITIAL_MODE,  /*24 PD4 */
                                             PORTD, PIN5, PORT_PIN_IN, OFF, STD_IDLE, PORT_PIN_INITIAL_MODE,  /*25 PD5 */
                                             PORTD, PIN6, PORT_PIN_IN, OFF, STD_IDLE, PORT_PIN_INITIAL_MODE,  /*26 PD6 */
                                             PORTD, PIN7, PORT_PIN_IN, OFF, STD_IDLE, PORT_PIN_INITIAL_MODE,  /*27 PD7 */ /*  NMI PIN */

                                             PORTE, PIN0, PORT_PIN_IN, OFF, STD_IDLE, PORT_PIN_INITIAL_MODE,  /*28 PE0 */
                                             PORTE, PIN1, PORT_PIN_IN, OFF, STD_IDLE, PORT_PIN_INITIAL_MODE,  /*29 PE1 */
                                             PORTE, PIN2, PORT_PIN_IN, OFF, STD_IDLE, PORT_PIN_INITIAL_MODE,  /*30 PE2 */
                                             PORTE, PIN3, PORT_PIN_IN, OFF, STD_IDLE, PORT_PIN_INITIAL_MODE,  /*31 PE3 */
                                             PORTE, PIN4, PORT_PIN_IN, OFF, STD_IDLE, PORT_PIN_INITIAL_MODE,  /*32 PE4 */
                                             PORTE, PIN5, PORT_PIN_IN, OFF, STD_IDLE, PORT_PIN_INITIAL_MODE,  /*33 PE5 */

                                             PORTF, PIN0, PORT_PIN_IN, OFF, STD_IDLE, PORT_PIN_INITIAL_MODE,  /*34 PF0 */ /*  NMI PIN */
                                             PORTF, PIN1,PORT_PIN_OUT, OFF, STD_IDLE, PORT_PIN_INITIAL_MODE,  /*35 PF1 */     /* Internal Led */
                                             PORTF, PIN2, PORT_PIN_IN, OFF, STD_IDLE, PORT_PIN_INITIAL_MODE,  /*36 PF2 */
                                             PORTF, PIN3, PORT_PIN_IN, OFF, STD_IDLE, PORT_PIN_INITIAL_MODE,  /*37 PF3 */
                                             PORTF, PIN4, PORT_PIN_IN, PULL_UP, STD_HIGH, PORT_PIN_INITIAL_MODE   /*38 PF4 */ /* Internal Switch */
                                         };

