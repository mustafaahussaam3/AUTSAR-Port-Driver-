 /******************************************************************************
 *
 * Module: Dio
 *
 * File Name: Dio_PBcfg.c
 *
 * Description: Post Build Configuration Source file for TM4C123GH6PM Microcontroller - Dio Driver
 *
 * Author: Mohamed Tarek
 ******************************************************************************/

#include "Dio.h"

/*
 * Module Version 1.0.0
 */
#define DIO_PBCFG_SW_MAJOR_VERSION              (1U)
#define DIO_PBCFG_SW_MINOR_VERSION              (0U)
#define DIO_PBCFG_SW_PATCH_VERSION              (0U)

/*
 * AUTOSAR Version 4.0.3
 */
#define DIO_PBCFG_AR_RELEASE_MAJOR_VERSION     (4U)
#define DIO_PBCFG_AR_RELEASE_MINOR_VERSION     (0U)
#define DIO_PBCFG_AR_RELEASE_PATCH_VERSION     (3U)

/* AUTOSAR Version checking between Dio_PBcfg.c and Dio.h files */
#if ((DIO_PBCFG_AR_RELEASE_MAJOR_VERSION != DIO_AR_RELEASE_MAJOR_VERSION)\
 ||  (DIO_PBCFG_AR_RELEASE_MINOR_VERSION != DIO_AR_RELEASE_MINOR_VERSION)\
 ||  (DIO_PBCFG_AR_RELEASE_PATCH_VERSION != DIO_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of PBcfg.c does not match the expected version"
#endif

/* Software Version checking between Dio_PBcfg.c and Dio.h files */
#if ((DIO_PBCFG_SW_MAJOR_VERSION != DIO_SW_MAJOR_VERSION)\
 ||  (DIO_PBCFG_SW_MINOR_VERSION != DIO_SW_MINOR_VERSION)\
 ||  (DIO_PBCFG_SW_PATCH_VERSION != DIO_SW_PATCH_VERSION))
  #error "The SW version of PBcfg.c does not match the expected version"
#endif

/* PB structure used with Dio_Init API */
const Dio_ConfigType Dio_Configuration = {
                                             DioConf_PA0_PORT_NUM, DioConf_PA0_CHANNEL_NUM,
                                             DioConf_PA1_PORT_NUM, DioConf_PA1_CHANNEL_NUM,
                                             DioConf_PA2_PORT_NUM, DioConf_PA2_CHANNEL_NUM,
                                             DioConf_PA3_PORT_NUM, DioConf_PA3_CHANNEL_NUM,
                                             DioConf_PA4_PORT_NUM, DioConf_PA4_CHANNEL_NUM,
                                             DioConf_PA5_PORT_NUM, DioConf_PA5_CHANNEL_NUM,
                                             DioConf_PA6_PORT_NUM, DioConf_PA6_CHANNEL_NUM,
                                             DioConf_PA7_PORT_NUM, DioConf_PA7_CHANNEL_NUM,
                                             DioConf_PB0_PORT_NUM, DioConf_PB0_CHANNEL_NUM,
                                             DioConf_PB1_PORT_NUM, DioConf_PB1_CHANNEL_NUM,
                                             DioConf_PB2_PORT_NUM, DioConf_PB2_CHANNEL_NUM,
                                             DioConf_PB3_PORT_NUM, DioConf_PB3_CHANNEL_NUM,
                                             DioConf_PB4_PORT_NUM, DioConf_PB4_CHANNEL_NUM,
                                             DioConf_PB5_PORT_NUM, DioConf_PB5_CHANNEL_NUM,
                                             DioConf_PB6_PORT_NUM, DioConf_PB6_CHANNEL_NUM,
                                             DioConf_PB7_PORT_NUM, DioConf_PB7_CHANNEL_NUM,
                                             DioConf_PC4_PORT_NUM, DioConf_PC4_CHANNEL_NUM,
                                             DioConf_PC5_PORT_NUM, DioConf_PC5_CHANNEL_NUM,
                                             DioConf_PC6_PORT_NUM, DioConf_PC6_CHANNEL_NUM,
                                             DioConf_PC7_PORT_NUM, DioConf_PC7_CHANNEL_NUM,
                                             DioConf_PD0_PORT_NUM, DioConf_PD0_CHANNEL_NUM,
                                             DioConf_PD1_PORT_NUM, DioConf_PD1_CHANNEL_NUM,
                                             DioConf_PD2_PORT_NUM, DioConf_PD2_CHANNEL_NUM,
                                             DioConf_PD3_PORT_NUM, DioConf_PD3_CHANNEL_NUM,
                                             DioConf_PD4_PORT_NUM, DioConf_PD4_CHANNEL_NUM,
                                             DioConf_PD5_PORT_NUM, DioConf_PD5_CHANNEL_NUM,
                                             DioConf_PD6_PORT_NUM, DioConf_PD6_CHANNEL_NUM,
                                             DioConf_PD7_PORT_NUM, DioConf_PD7_CHANNEL_NUM,
                                             DioConf_PE0_PORT_NUM, DioConf_PE0_CHANNEL_NUM,
                                             DioConf_PE1_PORT_NUM, DioConf_PE1_CHANNEL_NUM,
                                             DioConf_PE2_PORT_NUM, DioConf_PE2_CHANNEL_NUM,
                                             DioConf_PE3_PORT_NUM, DioConf_PE3_CHANNEL_NUM,
                                             DioConf_PE4_PORT_NUM, DioConf_PE4_CHANNEL_NUM,
                                             DioConf_PE5_PORT_NUM, DioConf_PE5_CHANNEL_NUM,
                                             DioConf_PF0_PORT_NUM, DioConf_PF0_CHANNEL_NUM,
                                             DioConf_LED1_PORT_NUM,DioConf_LED1_CHANNEL_NUM,
                                             DioConf_PF2_PORT_NUM, DioConf_PF2_CHANNEL_NUM,
                                             DioConf_PF3_PORT_NUM, DioConf_PF3_CHANNEL_NUM,
				                             DioConf_SW1_PORT_NUM, DioConf_SW1_CHANNEL_NUM
				                         };
