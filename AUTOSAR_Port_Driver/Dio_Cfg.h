 /******************************************************************************
 *
 * Module: Dio
 *
 * File Name: Dio_Cfg.h
 *
 * Description: Pre-Compile Configuration Header file for TM4C123GH6PM Microcontroller - Dio Driver
 *
 * Author: Mohamed Tarek
 ******************************************************************************/

#ifndef DIO_CFG_H
#define DIO_CFG_H

/*
 * Module Version 1.0.0
 */
#define DIO_CFG_SW_MAJOR_VERSION              (1U)
#define DIO_CFG_SW_MINOR_VERSION              (0U)
#define DIO_CFG_SW_PATCH_VERSION              (0U)

/*
 * AUTOSAR Version 4.0.3
 */
#define DIO_CFG_AR_RELEASE_MAJOR_VERSION     (4U)
#define DIO_CFG_AR_RELEASE_MINOR_VERSION     (0U)
#define DIO_CFG_AR_RELEASE_PATCH_VERSION     (3U)

/* Pre-compile option for Development Error Detect */
#define DIO_DEV_ERROR_DETECT                (STD_OFF)

/* Pre-compile option for Version Info API */
#define DIO_VERSION_INFO_API                (STD_OFF)

/* Pre-compile option for presence of Dio_FlipChannel API */
#define DIO_FLIP_CHANNEL_API                (STD_ON)

/* Number of the configured Dio Channels */
#define DIO_CONFIGURED_CHANNLES              (39U)


/* DIO Configured Port ID's  */
#define DioConf_PA0_PORT_NUM                (Dio_PortType)0
#define DioConf_PA1_PORT_NUM                (Dio_PortType)0
#define DioConf_PA2_PORT_NUM                (Dio_PortType)0
#define DioConf_PA3_PORT_NUM                (Dio_PortType)0
#define DioConf_PA4_PORT_NUM                (Dio_PortType)0
#define DioConf_PA5_PORT_NUM                (Dio_PortType)0
#define DioConf_PA6_PORT_NUM                (Dio_PortType)0
#define DioConf_PA7_PORT_NUM                (Dio_PortType)0
#define DioConf_PB0_PORT_NUM                (Dio_PortType)1
#define DioConf_PB1_PORT_NUM                (Dio_PortType)1
#define DioConf_PB2_PORT_NUM                (Dio_PortType)1
#define DioConf_PB3_PORT_NUM                (Dio_PortType)1
#define DioConf_PB4_PORT_NUM                (Dio_PortType)1
#define DioConf_PB5_PORT_NUM                (Dio_PortType)1
#define DioConf_PB6_PORT_NUM                (Dio_PortType)1
#define DioConf_PB7_PORT_NUM                (Dio_PortType)1
#define DioConf_PC4_PORT_NUM                (Dio_PortType)2
#define DioConf_PC5_PORT_NUM                (Dio_PortType)2
#define DioConf_PC6_PORT_NUM                (Dio_PortType)2
#define DioConf_PC7_PORT_NUM                (Dio_PortType)2
#define DioConf_PD0_PORT_NUM                (Dio_PortType)3
#define DioConf_PD1_PORT_NUM                (Dio_PortType)3
#define DioConf_PD2_PORT_NUM                (Dio_PortType)3
#define DioConf_PD3_PORT_NUM                (Dio_PortType)3
#define DioConf_PD4_PORT_NUM                (Dio_PortType)3
#define DioConf_PD5_PORT_NUM                (Dio_PortType)3
#define DioConf_PD6_PORT_NUM                (Dio_PortType)3
#define DioConf_PD7_PORT_NUM                (Dio_PortType)3
#define DioConf_PE0_PORT_NUM                (Dio_PortType)4
#define DioConf_PE1_PORT_NUM                (Dio_PortType)4
#define DioConf_PE2_PORT_NUM                (Dio_PortType)4
#define DioConf_PE3_PORT_NUM                (Dio_PortType)4
#define DioConf_PE4_PORT_NUM                (Dio_PortType)4
#define DioConf_PE5_PORT_NUM                (Dio_PortType)4
#define DioConf_PF0_PORT_NUM                (Dio_PortType)5
#define DioConf_LED1_PORT_NUM               (Dio_PortType)5
#define DioConf_PF2_PORT_NUM                (Dio_PortType)5
#define DioConf_PF3_PORT_NUM                (Dio_PortType)5
#define DioConf_SW1_PORT_NUM                (Dio_PortType)5


/* DIO Configured Channel ID's */
#define DioConf_PA0_CHANNEL_NUM             (Dio_ChannelType)0
#define DioConf_PA1_CHANNEL_NUM             (Dio_ChannelType)1
#define DioConf_PA2_CHANNEL_NUM             (Dio_ChannelType)2
#define DioConf_PA3_CHANNEL_NUM             (Dio_ChannelType)3
#define DioConf_PA4_CHANNEL_NUM             (Dio_ChannelType)4
#define DioConf_PA5_CHANNEL_NUM             (Dio_ChannelType)5
#define DioConf_PA6_CHANNEL_NUM             (Dio_ChannelType)6
#define DioConf_PA7_CHANNEL_NUM             (Dio_ChannelType)7
#define DioConf_PB0_CHANNEL_NUM             (Dio_ChannelType)0
#define DioConf_PB1_CHANNEL_NUM             (Dio_ChannelType)1
#define DioConf_PB2_CHANNEL_NUM             (Dio_ChannelType)2
#define DioConf_PB3_CHANNEL_NUM             (Dio_ChannelType)3
#define DioConf_PB4_CHANNEL_NUM             (Dio_ChannelType)4
#define DioConf_PB5_CHANNEL_NUM             (Dio_ChannelType)5
#define DioConf_PB6_CHANNEL_NUM             (Dio_ChannelType)6
#define DioConf_PB7_CHANNEL_NUM             (Dio_ChannelType)7
#define DioConf_PC4_CHANNEL_NUM             (Dio_ChannelType)4
#define DioConf_PC5_CHANNEL_NUM             (Dio_ChannelType)5
#define DioConf_PC6_CHANNEL_NUM             (Dio_ChannelType)6
#define DioConf_PC7_CHANNEL_NUM             (Dio_ChannelType)7
#define DioConf_PD0_CHANNEL_NUM             (Dio_ChannelType)0
#define DioConf_PD1_CHANNEL_NUM             (Dio_ChannelType)1
#define DioConf_PD2_CHANNEL_NUM             (Dio_ChannelType)2
#define DioConf_PD3_CHANNEL_NUM             (Dio_ChannelType)3
#define DioConf_PD4_CHANNEL_NUM             (Dio_ChannelType)4
#define DioConf_PD5_CHANNEL_NUM             (Dio_ChannelType)5
#define DioConf_PD6_CHANNEL_NUM             (Dio_ChannelType)6
#define DioConf_PD7_CHANNEL_NUM             (Dio_ChannelType)7
#define DioConf_PE0_CHANNEL_NUM             (Dio_ChannelType)0
#define DioConf_PE1_CHANNEL_NUM             (Dio_ChannelType)1
#define DioConf_PE2_CHANNEL_NUM             (Dio_ChannelType)2
#define DioConf_PE3_CHANNEL_NUM             (Dio_ChannelType)3
#define DioConf_PE4_CHANNEL_NUM             (Dio_ChannelType)4
#define DioConf_PE5_CHANNEL_NUM             (Dio_ChannelType)5
#define DioConf_PF0_CHANNEL_NUM             (Dio_ChannelType)0
#define DioConf_LED1_CHANNEL_NUM            (Dio_ChannelType)1
#define DioConf_PF2_CHANNEL_NUM             (Dio_ChannelType)2
#define DioConf_PF3_CHANNEL_NUM             (Dio_ChannelType)3
#define DioConf_SW1_CHANNEL_NUM             (Dio_ChannelType)4

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

#endif /* DIO_CFG_H */
