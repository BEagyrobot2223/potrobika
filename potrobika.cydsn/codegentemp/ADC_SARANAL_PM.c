/*******************************************************************************
* File Name: ADC_SARANAL_PM.c
* Version 2.10
*
* Description:
*  This file contains the setup, control and status commands to support
*  component operations in low power mode.
*
* Note:
*
********************************************************************************
* Copyright 2012-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "ADC_SARANAL.h"
#include "ADC_SARANAL_SAR.h"
#if(ADC_SARANAL_CLOCK_SOURCE == ADC_SARANAL_CLOCK_INTERNAL)
    #include "ADC_SARANAL_IntClock.h"
#endif   /* ADC_SARANAL_CLOCK_SOURCE == ADC_SARANAL_CLOCK_INTERNAL */


/*******************************************************************************
* Function Name: ADC_SARANAL_Sleep
********************************************************************************
*
* Summary:
*  Stops the ADC operation and saves the configuration registers and component
*  enable state. Should be called just prior to entering sleep
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Side Effects:
*  None.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void ADC_SARANAL_Sleep(void)
{
    ADC_SARANAL_SAR_Stop();
    ADC_SARANAL_SAR_Sleep();
    ADC_SARANAL_Disable();

    #if(ADC_SARANAL_CLOCK_SOURCE == ADC_SARANAL_CLOCK_INTERNAL)
        ADC_SARANAL_IntClock_Stop();
    #endif   /* ADC_SARANAL_CLOCK_SOURCE == ADC_SARANAL_CLOCK_INTERNAL */
}


/*******************************************************************************
* Function Name: ADC_SARANAL_Wakeup
********************************************************************************
*
* Summary:
*  Restores the component enable state and configuration registers. This should
*  be called just after awaking from sleep mode
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Side Effects:
*  None.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void ADC_SARANAL_Wakeup(void)
{
    ADC_SARANAL_SAR_Wakeup();
    ADC_SARANAL_SAR_Enable();

    #if(ADC_SARANAL_CLOCK_SOURCE == ADC_SARANAL_CLOCK_INTERNAL)
        ADC_SARANAL_IntClock_Start();
    #endif   /* ADC_SARANAL_CLOCK_SOURCE == ADC_SARANAL_CLOCK_INTERNAL */

    /* The block is ready to use 10 us after the SAR enable signal is set high. */
    CyDelayUs(10u);
    
    ADC_SARANAL_Enable();

    #if(ADC_SARANAL_SAMPLE_MODE == ADC_SARANAL_SAMPLE_MODE_FREE_RUNNING)
        ADC_SARANAL_SAR_StartConvert();
    #endif /* (ADC_SARANAL_SAMPLE_MODE == ADC_SARANAL_SAMPLE_MODE_FREE_RUNNING) */

    (void) CY_GET_REG8(ADC_SARANAL_STATUS_PTR);
}


/*******************************************************************************
* Function Name: ADC_SARANAL_SaveConfig
********************************************************************************
*
* Summary:
*  Save the current configuration of ADC non-retention registers
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Side Effects:
*  None.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void ADC_SARANAL_SaveConfig(void)
{

}


/*******************************************************************************
* Function Name: ADC_SARANAL_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the configuration of ADC non-retention registers
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Side Effects:
*  None.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void ADC_SARANAL_RestoreConfig(void)
{

}


/* [] END OF FILE */
