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
     uint8 channelNumber = 0;
     /* looping in the array to set each pin with its configuration */
     while (channelNumber < PORT_CONFIGURED_CHANNELS )
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


                   /* PD7 or PF0 */
                   if( ((ConfigPtr->Channels[channelNumber].port_num == 3) && (ConfigPtr->Channels[channelNumber].pin_num == 7)) || ((ConfigPtr->Channels[channelNumber].port_num == 5) && (ConfigPtr->Channels[channelNumber].pin_num == 0)) )
                   {
                       /* Unlock the GPIOCR register */
                       *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_LOCK_REG_OFFSET) = 0x4C4F434B;
                       /* Set the corresponding bit in GPIOCR register to allow changes on this pin */
                       SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_COMMIT_REG_OFFSET) , ConfigPtr->Channels[channelNumber].pin_num);
                   }
                   /* PC0 to PC3 */
                   else if( (ConfigPtr->Channels[channelNumber].port_num == 2) && (ConfigPtr->Channels[channelNumber].pin_num <= 3) )
                   {
                       /* Do Nothing ...  this is the JTAG pins */
                   }
                   else
                   {
                       /* Do Nothing ... No need to unlock the commit register for this pin */
                   }


                   /* Setup the pin mode as Alternative Function, DIO or ADC */
                   if ( ConfigPtr->Channels[channelNumber].mode == PORT_PIN_MODE_DIO)
                   {
                       /* Disable Alternative function for this pin by clear the corresponding bit in GPIOAFSEL register */
                       CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ALT_FUNC_REG_OFFSET) , ConfigPtr->Channels[channelNumber].pin_num);
                       /* Clear the corresponding bit in the GPIOAMSEL register to disable analog functionality on this pin */
                       CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) , ConfigPtr->Channels[channelNumber].pin_num);
                       /* Masking this pin to zero to either be used as GPIO or Adding the mode number in the alternative mode */
                       *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) &= ~(0x0000000F << (ConfigPtr->Channels[channelNumber].pin_num * 4));
                       /* Set the Enable pin for either GPIO or Alternative function Mode */
                       SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET) , ConfigPtr->Channels[channelNumber].pin_num);

                   }
                   else if ( ConfigPtr->Channels[channelNumber].mode == PORT_PIN_MODE_ADC)
                   {
                       /* Choosing only the MCU ADC Pins (PE0 to PE5) and (PD0 to PD3) and PB4, PB5, if the user enters a pin out of this range it will got dev erro */
                       if ( (ConfigPtr->Channels[channelNumber].port_num == 4) || ((ConfigPtr->Channels[channelNumber].port_num == 3) && (ConfigPtr->Channels[channelNumber].pin_num <=3)) ||
                               ((ConfigPtr->Channels[channelNumber].port_num == 1) && (ConfigPtr->Channels[channelNumber].pin_num == 4 )) || ((ConfigPtr->Channels[channelNumber].port_num == 1) && (ConfigPtr->Channels[channelNumber].pin_num == 5)))
                       {
                       /* Set the corresponding bit in the GPIOAMSEL register to enable analog functionality on this pin */
                       SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) , ConfigPtr->Channels[channelNumber].pin_num);
                       *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) &= ~(0x0000000F << (ConfigPtr->Channels[channelNumber].pin_num * 4));
                       /* Disable Alternative function for this pin by clear the corresponding bit in GPIOAFSEL register */
                       CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ALT_FUNC_REG_OFFSET) , ConfigPtr->Channels[channelNumber].pin_num);
                       /* Clear the Enable pin for Use ADC  */
                       CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET) , ConfigPtr->Channels[channelNumber].pin_num);
                       }
                       else
                       {
                           #if (PORT_DEV_ERROR_DETECT == STD_ON)
                           Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_INIT_SID, PORT_E_PARAM_PIN);
                           #endif
                       }
                   }
                   else
                   {
                       /* Enable Alternative function for this pin by set the corresponding bit in GPIOAFSEL register */
                       SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ALT_FUNC_REG_OFFSET) , ConfigPtr->Channels[channelNumber].pin_num);
                       /* Clear the corresponding bit in the GPIOAMSEL register to disable analog functionality on this pin */
                       CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) , ConfigPtr->Channels[channelNumber].pin_num);
                       /* Masking this pin to zero to either be used as GPIO or Adding the mode number in the alternative mode */
                       *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) &= ~(0x0000000F << (ConfigPtr->Channels[channelNumber].pin_num * 4));
                       /* Adding the mode number in the Control Register which is masked by 4 bits */
                       *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) |= (ConfigPtr->Channels[channelNumber].mode << (ConfigPtr->Channels[channelNumber].pin_num * 4));
                       /* Set the Enable pin for either GPIO or Alternative function Mode */
                       SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET) , ConfigPtr->Channels[channelNumber].pin_num);
                   }


                   if(ConfigPtr->Channels[channelNumber].direction == PORT_PIN_OUT)
                   {
                       /* Set the corresponding bit in the GPIODIR register to configure it as output pin */
                       SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIR_REG_OFFSET) , ConfigPtr->Channels[channelNumber].pin_num );
                       if(ConfigPtr->Channels[channelNumber].initial_value == STD_HIGH)
                       {
                           /* Set the corresponding bit in the GPIODATA register to provide initial value 1 */
                           SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DATA_REG_OFFSET) , ConfigPtr->Channels[channelNumber].pin_num );
                       }
                       else
                       {
                           /* Clear the corresponding bit in the GPIODATA register to provide initial value 0 */
                           CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DATA_REG_OFFSET) , ConfigPtr->Channels[channelNumber].pin_num);
                       }
                   }
                   else if(ConfigPtr->Channels[channelNumber].direction == PORT_PIN_IN)
                   {
                       /* Clear the corresponding bit in the GPIODIR register to configure it as input pin */
                       CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIR_REG_OFFSET) , ConfigPtr->Channels[channelNumber].pin_num);

                       if(ConfigPtr->Channels[channelNumber].resistor == PULL_UP)
                       {
                           /* Set the corresponding bit in the GPIOPUR register to enable the internal pull up pin */
                           SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_PULL_UP_REG_OFFSET) , ConfigPtr->Channels[channelNumber].pin_num);
                       }
                       else if(ConfigPtr->Channels[channelNumber].resistor == PULL_DOWN)
                       {
                           /* Set the corresponding bit in the GPIOPDR register to enable the internal pull down pin */
                           SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_PULL_DOWN_REG_OFFSET) , ConfigPtr->Channels[channelNumber].pin_num );
                       }
                       else
                       {
                           /* Clear the corresponding bit in the GPIOPUR register to disable the internal pull up pin */
                           CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_PULL_UP_REG_OFFSET) , ConfigPtr->Channels[channelNumber].pin_num );
                           /* Clear the corresponding bit in the GPIOPDR register to disable the internal pull down pin */
                           CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_PULL_DOWN_REG_OFFSET) , ConfigPtr->Channels[channelNumber].pin_num );
                       }
                   }
                   else
                   {
                       /* Do Nothing */
                   }


                   /* increment the Structure to the other pin configuration */
                   channelNumber++;
        }
     /* Set the pin status to initialized to be used in other functions for development error */
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
#if (PORT_SET_PIN_DIRECTION_API == STD_ON)
void Port_SetPinDirection( Port_PinType Pin, Port_PinDirectionType Direction )
{
    boolean error = FALSE;
#if (PORT_DEV_ERROR_DETECT == STD_ON)
    if (Pin > PORT_CONFIGURED_CHANNELS)
    {
        Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_SET_PIN_DIRECTION_SID, PORT_E_PARAM_PIN);
        error = TRUE;
    }
    else
    {
        /* No Action Required */
    }

    if (PORT_NOT_INITIALIZED == Port_Status)
    {
        Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_SET_PIN_DIRECTION_SID, PORT_E_UNINIT);
        error = TRUE;
    }
    else
    {
        /* No Action Required */
    }

#endif

    if (FALSE == error)
    {
    volatile uint32 * PortGpio_Ptr = NULL_PTR; /* point to the required Port Registers base address */

                      switch(ConfigPtr->Channels[Pin].port_num)
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


      if( Port_PinDirectionType == PORT_PIN_OUT)
      {
          /* Set the corresponding bit in the GPIODIR register to configure it as output pin */
          SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIR_REG_OFFSET) , ConfigPtr->Channels[Pin].pin_num );
      }
      else if(Port_PinDirectionType == PORT_PIN_IN)
      {
          /* Clear the corresponding bit in the GPIODIR register to configure it as input pin */
          CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIR_REG_OFFSET) , ConfigPtr->Channels[Pin].pin_num);

      }
      else
      {
          /* Do Nothing */
      }
    }
    else
    {
        /* Do Nothing */
    }
}
#endif
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
    boolean error = FALSE;
#if (PORT_DEV_ERROR_DETECT == STD_ON)
    if (PORT_NOT_INITIALIZED == Port_Status)
    {
        Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_SET_PIN_DIRECTION_SID, PORT_E_UNINIT);
        error = TRUE;
    }
    else
    {
        /* No Action Required */
    }

#endif
    if (FALSE == error)
    {
        uint8 channelNumber = 0;
        while (channelNumber < PORT_CONFIGURED_CHANNELS )
             {
               const Port_ConfigType* ConfigPtr = &Port_Configuration;
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


                      /* PD7 or PF0 */
                      if( ((ConfigPtr->Channels[channelNumber].port_num == 3) && (ConfigPtr->Channels[channelNumber].pin_num == 7)) || ((ConfigPtr->Channels[channelNumber].port_num == 5) && (ConfigPtr->Channels[channelNumber].pin_num == 0)) )
                      {
                          /* Unlock the GPIOCR register */
                          *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_LOCK_REG_OFFSET) = 0x4C4F434B;
                          /* Set the corresponding bit in GPIOCR register to allow changes on this pin */
                          SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_COMMIT_REG_OFFSET) , ConfigPtr->Channels[channelNumber].pin_num);
                      }
                      /* PC0 to PC3 */
                      else if( (ConfigPtr->Channels[channelNumber].port_num == 2) && (ConfigPtr->Channels[channelNumber].pin_num <= 3) )
                      {
                          /* Do Nothing ...  this is the JTAG pins */
                      }
                      else
                      {
                          /* Do Nothing ... No need to unlock the commit register for this pin */
                      }

                      if(ConfigPtr->Channels[channelNumber].direction == PORT_PIN_OUT)
                      {
                          /* Set the corresponding bit in the GPIODIR register to configure it as output pin */
                          SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIR_REG_OFFSET) , ConfigPtr->Channels[channelNumber].pin_num );
                          if(ConfigPtr->Channels[channelNumber].initial_value == STD_HIGH)
                          {
                              /* Set the corresponding bit in the GPIODATA register to provide initial value 1 */
                              SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DATA_REG_OFFSET) , ConfigPtr->Channels[channelNumber].pin_num );
                          }
                          else
                          {
                              /* Clear the corresponding bit in the GPIODATA register to provide initial value 0 */
                              CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DATA_REG_OFFSET) , ConfigPtr->Channels[channelNumber].pin_num);
                          }
                      }
                      else if(ConfigPtr->Channels[channelNumber].direction == PORT_PIN_IN)
                      {
                          /* Clear the corresponding bit in the GPIODIR register to configure it as input pin */
                          CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIR_REG_OFFSET) , ConfigPtr->Channels[channelNumber].pin_num);

                          if(ConfigPtr->Channels[channelNumber].resistor == PULL_UP)
                          {
                              /* Set the corresponding bit in the GPIOPUR register to enable the internal pull up pin */
                              SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_PULL_UP_REG_OFFSET) , ConfigPtr->Channels[channelNumber].pin_num);
                          }
                          else if(ConfigPtr->Channels[channelNumber].resistor == PULL_DOWN)
                          {
                              /* Set the corresponding bit in the GPIOPDR register to enable the internal pull down pin */
                              SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_PULL_DOWN_REG_OFFSET) , ConfigPtr->Channels[channelNumber].pin_num );
                          }
                          else
                          {
                              /* Clear the corresponding bit in the GPIOPUR register to disable the internal pull up pin */
                              CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_PULL_UP_REG_OFFSET) , ConfigPtr->Channels[channelNumber].pin_num );
                              /* Clear the corresponding bit in the GPIOPDR register to disable the internal pull down pin */
                              CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_PULL_DOWN_REG_OFFSET) , ConfigPtr->Channels[channelNumber].pin_num );
                          }
                      }
                      else
                      {
                          /* Do Nothing */
                      }
                      /* increment the Structure to the other pin configuration */
                      channelNumber++;
               }
    }
    else
    {
        /* Do Nothing */
    }
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
#if (PORT_VERSION_INFO_API == STD_ON)
void Port_GetVersionInfo( Std_VersionInfoType* versioninfo )
{
#if (PORT_DEV_ERROR_DETECT == STD_ON)
    /* Check if input pointer is not Null pointer */
    if(NULL_PTR == versioninfo)
    {
        /* Report to DET  */
        Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_GET_VERSION_INFO_SID, PORT_E_PARAM_POINTER);
    }
    else
#endif
    {
        /* Copy the vendor Id */
        versioninfo->vendorID = (uint16)PORT_VENDOR_ID;
        /* Copy the module Id */
        versioninfo->moduleID = (uint16)PORT_MODULE_ID;
        /* Copy Software Major Version */
        versioninfo->sw_major_version = (uint8)PORT_SW_MAJOR_VERSION;
        /* Copy Software Minor Version */
        versioninfo->sw_minor_version = (uint8)PORT_SW_MINOR_VERSION;
        /* Copy Software Patch Version */
        versioninfo->sw_patch_version = (uint8)PORT_SW_PATCH_VERSION;
    }
}
#endif
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
#if (PORT_PIN_MODE_CHANGEABLE == STD_ON)
void Port_SetPinMode( Port_PinType Pin, Port_PinModeType Mode )
{
    Port_Inital_Mode mode = Mode ;
    boolean error = FALSE;
#if (PORT_DEV_ERROR_DETECT == STD_ON)
    if (PORT_NOT_INITIALIZED == Port_Status)
    {
        Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_SET_PIN_DIRECTION_SID, PORT_E_UNINIT);
        error = TRUE;
    }
    else
    {
        /* No Action Required */
    }

#endif
    if (FALSE == error)
    {

          volatile uint32 * PortGpio_Ptr = NULL_PTR; /* point to the required Port Registers base address */

             switch(ConfigPtr->Channels[Pin].port_num)
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

         /* Setup the pin mode as Alternative Function, DIO or ADC */
       if ( mode == PORT_PIN_MODE_DIO)
       {
           /* Disable Alternative function for this pin by clear the corresponding bit in GPIOAFSEL register */
           CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ALT_FUNC_REG_OFFSET) , ConfigPtr->Channels[Pin].pin_num);
           /* Clear the corresponding bit in the GPIOAMSEL register to disable analog functionality on this pin */
           CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) , ConfigPtr->Channels[Pin].pin_num);
           /* Masking this pin to zero to either be used as GPIO or Adding the mode number in the alternative mode */
           *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) &= ~(0x0000000F << (ConfigPtr->Channels[Pin].pin_num * 4));
           /* Set the Enable pin for either GPIO or Alternative function Mode */
           SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET) , ConfigPtr->Channels[Pin].pin_num);

       }
       else if ( mode == PORT_PIN_MODE_ADC)
       {
           /* Choosing only the MCU ADC Pins (PE0 to PE5) and (PD0 to PD3) and PB4, PB5, if the user enters a pin out of this range it will got dev erro */
           if ( (ConfigPtr->Channels[Pin].port_num == 4) || ((ConfigPtr->Channels[Pin].port_num == 3) && (ConfigPtr->Channels[Pin].pin_num <=3)) ||
                   ((ConfigPtr->Channels[Pin].port_num == 1) && (ConfigPtr->Channels[Pin].pin_num == 4 )) || ((ConfigPtr->Channels[Pin].port_num == 1) && (ConfigPtr->Channels[Pin].pin_num == 5)))
           {
           /* Set the corresponding bit in the GPIOAMSEL register to enable analog functionality on this pin */
           SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) , ConfigPtr->Channels[Pin].pin_num);
           *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) &= ~(0x0000000F << (ConfigPtr->Channels[Pin].pin_num * 4));
           /* Disable Alternative function for this pin by clear the corresponding bit in GPIOAFSEL register */
           CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ALT_FUNC_REG_OFFSET) , ConfigPtr->Channels[Pin].pin_num);
           /* Clear the Enable pin for Use ADC  */
           CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET) , ConfigPtr->Channels[Pin].pin_num);
           }
           else
           {
               #if (PORT_DEV_ERROR_DETECT == STD_ON)
               Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_INIT_SID, PORT_E_PARAM_PIN);
               #endif
           }
       }
       else
       {
           /* Enable Alternative function for this pin by set the corresponding bit in GPIOAFSEL register */
           SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ALT_FUNC_REG_OFFSET) , ConfigPtr->Channels[Pin].pin_num);
           /* Clear the corresponding bit in the GPIOAMSEL register to disable analog functionality on this pin */
           CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) , ConfigPtr->Channels[Pin].pin_num);
           /* Masking this pin to zero to either be used as GPIO or Adding the mode number in the alternative mode */
           *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) &= ~(0x0000000F << (ConfigPtr->Channels[Pin].pin_num * 4));
           /* Adding the mode number in the Control Register which is masked by 4 bits */
           *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) |= (ConfigPtr->Channels[channelNumber].mode << (ConfigPtr->Channels[Pin].pin_num * 4));
           /* Set the Enable pin for either GPIO or Alternative function Mode */
           SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET) , ConfigPtr->Channels[Pin].pin_num);
       }


    else
    {
        /* Do Nothing */
    }

}
#endif
