 /******************************************************************************
 *
 * Module: Port
 *
 * File Name: Port.c
 *
 * Description: Source file for TM4C123GH6PM Microcontroller - Port Driver.
 *
 *  Author: Mohamed Tarek
 *  Edited By : Mustafa Hussam Eldin
 ******************************************************************************/

#include "Port.h"
#include "tm4c123gh6pm_registers.h"

#if (PORT_DEV_ERROR_DETECT == STD_ON)

#include "Det.h"
/* AUTOSAR Version checking between Det and PORT Modules */
#if ((DET_AR_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
 || (DET_AR_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION)\
 || (DET_AR_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Det.h does not match the expected version"
#endif

#endif

STATIC uint8 Port_Status = PORT_NOT_INITIALIZED;

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
void Port_Init( const Port_ConfigType* ConfigPtr )
{
#if (PORT_DEV_ERROR_DETECT == STD_ON)
    /* check if the input configuration pointer is not a NULL_PTR */
    if (NULL_PTR == ConfigPtr)
    {
        Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_INIT_SID,
                        PORT_E_PARAM_CONFIG);
    }
    else
#endif
  {
     uint8 configSize = sizeof(Port_Configuration)/ sizeof(Port_ConfigChannel);
     uint8 channelNumber;
     while (channelNumber < configSize )
      {
        volatile uint32 * PortGpio_Ptr = NULL_PTR; /* point to the required Port Registers base address */

        switch(ConfigPtr->Channels[channelNumber].port_num)
        {
            case  0: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTA_BASE_ADDRESS; /* PORTA Base Address */
                     break;
            case  1: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTB_BASE_ADDRESS; /* PORTB Base Address */
                     break;
            case  2: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTC_BASE_ADDRESS; /* PORTC Base Address */
                     break;
            case  3: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTD_BASE_ADDRESS; /* PORTD Base Address */
                     break;
            case  4: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTE_BASE_ADDRESS; /* PORTE Base Address */
                     break;
            case  5: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTF_BASE_ADDRESS; /* PORTF Base Address */
                     break;
        }

        if( ((ConfigPtr->Channels[channelNumber].port_num == 3) && (ConfigPtr->Channels[channelNumber].pin_num == 7)) || ((ConfigPtr->Channels[channelNumber].port_num == 5) && (ConfigPtr->Channels[channelNumber].pin_num == 0)) ) /* PD7 or PF0 */
        {
            *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_LOCK_REG_OFFSET) = 0x4C4F434B;                     /* Unlock the GPIOCR register */
            SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_COMMIT_REG_OFFSET) , ConfigPtr->Channels[channelNumber].pin_num);  /* Set the corresponding bit in GPIOCR register to allow changes on this pin */
        }
        else if( (ConfigPtr->Channels[channelNumber].port_num == 2) && (ConfigPtr->Channels[channelNumber].pin_num <= 3) ) /* PC0 to PC3 */
        {
            /* Do Nothing ...  this is the JTAG pins */
        }
        else
        {
            /* Do Nothing ... No need to unlock the commit register for this pin */
        }

        if(ConfigPtr->Channels[channelNumber].direction == PORT_PIN_OUT)
        {
            SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIR_REG_OFFSET) , ConfigPtr->Channels[channelNumber].pin_num );               /* Set the corresponding bit in the GPIODIR register to configure it as output pin */

            if(ConfigPtr->Channels[channelNumber].initial_value == STD_HIGH)
            {
                SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DATA_REG_OFFSET) , ConfigPtr->Channels[channelNumber].pin_num );          /* Set the corresponding bit in the GPIODATA register to provide initial value 1 */
            }
            else
            {
                CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DATA_REG_OFFSET) , ConfigPtr->Channels[channelNumber].pin_num);        /* Clear the corresponding bit in the GPIODATA register to provide initial value 0 */
            }
        }
        else if(ConfigPtr->Channels[channelNumber].direction == PORT_PIN_IN)
        {
            CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIR_REG_OFFSET) , ConfigPtr->Channels[channelNumber].pin_num);             /* Clear the corresponding bit in the GPIODIR register to configure it as input pin */

            if(ConfigPtr->Channels[channelNumber].resistor == PULL_UP)
            {
                SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_PULL_UP_REG_OFFSET) , ConfigPtr->Channels[channelNumber].pin_num);       /* Set the corresponding bit in the GPIOPUR register to enable the internal pull up pin */
            }
            else if(ConfigPtr->Channels[channelNumber].resistor == PULL_DOWN)
            {
                SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_PULL_DOWN_REG_OFFSET) , ConfigPtr->Channels[channelNumber].pin_num );     /* Set the corresponding bit in the GPIOPDR register to enable the internal pull down pin */
            }
            else
            {
                CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_PULL_UP_REG_OFFSET) , ConfigPtr->Channels[channelNumber].pin_num );     /* Clear the corresponding bit in the GPIOPUR register to disable the internal pull up pin */
                CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_PULL_DOWN_REG_OFFSET) , ConfigPtr->Channels[channelNumber].pin_num );   /* Clear the corresponding bit in the GPIOPDR register to disable the internal pull down pin */
            }
        }
        else
        {
            /* Do Nothing */
        }

        /* Setup the pin mode as GPIO */
        CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) , ConfigPtr->Channels[channelNumber].pin_num);      /* Clear the corresponding bit in the GPIOAMSEL register to disable analog functionality on this pin */
        CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ALT_FUNC_REG_OFFSET) , ConfigPtr->Channels[channelNumber].pin_num);             /* Disable Alternative function for this pin by clear the corresponding bit in GPIOAFSEL register */
        *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) &= ~(0x0000000F << (ConfigPtr->Channels[channelNumber].pin_num * 4));     /* Clear the PMCx bits for this pin */
        SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET) , ConfigPtr->Channels[channelNumber].pin_num);         /* Set the corresponding bit in the GPIODEN register to enable digital functionality on this pin */
        channelNumber++;
    }
     Port_Status = PORT_INITIALIZED ;
  }
}
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
void Port_SetPinDirection( Port_PinType Pin, Port_PinDirectionType Direction )
{

}

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
void Port_RefreshPortDirection( void )
{

}

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
void Port_GetVersionInfo( Std_VersionInfoType* versioninfo )
{

}

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
void Port_SetPinMode( Port_PinType Pin, Port_PinModeType Mode )
{

}

