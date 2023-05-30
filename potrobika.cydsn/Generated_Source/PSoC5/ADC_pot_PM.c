/*******************************************************************************
* File Name: ADC_pot_PM.c
* Version 3.10
*
* Description:
*  This file provides Sleep/WakeUp APIs functionality.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "ADC_pot.h"


/***************************************
* Local data allocation
***************************************/

static ADC_pot_BACKUP_STRUCT  ADC_pot_backup =
{
    ADC_pot_DISABLED
};


/*******************************************************************************
* Function Name: ADC_pot_SaveConfig
********************************************************************************
*
* Summary:
*  Saves the current user configuration.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void ADC_pot_SaveConfig(void)
{
    /* All configuration registers are marked as [reset_all_retention] */
}


/*******************************************************************************
* Function Name: ADC_pot_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void ADC_pot_RestoreConfig(void)
{
    /* All congiguration registers are marked as [reset_all_retention] */
}


/*******************************************************************************
* Function Name: ADC_pot_Sleep
********************************************************************************
*
* Summary:
*  This is the preferred routine to prepare the component for sleep.
*  The ADC_pot_Sleep() routine saves the current component state,
*  then it calls the ADC_Stop() function.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  ADC_pot_backup - The structure field 'enableState' is modified
*  depending on the enable state of the block before entering to sleep mode.
*
*******************************************************************************/
void ADC_pot_Sleep(void)
{
    if((ADC_pot_PWRMGR_SAR_REG  & ADC_pot_ACT_PWR_SAR_EN) != 0u)
    {
        if((ADC_pot_SAR_CSR0_REG & ADC_pot_SAR_SOF_START_CONV) != 0u)
        {
            ADC_pot_backup.enableState = ADC_pot_ENABLED | ADC_pot_STARTED;
        }
        else
        {
            ADC_pot_backup.enableState = ADC_pot_ENABLED;
        }
        ADC_pot_Stop();
    }
    else
    {
        ADC_pot_backup.enableState = ADC_pot_DISABLED;
    }
}


/*******************************************************************************
* Function Name: ADC_pot_Wakeup
********************************************************************************
*
* Summary:
*  This is the preferred routine to restore the component to the state when
*  ADC_pot_Sleep() was called. If the component was enabled before the
*  ADC_pot_Sleep() function was called, the
*  ADC_pot_Wakeup() function also re-enables the component.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  ADC_pot_backup - The structure field 'enableState' is used to
*  restore the enable state of block after wakeup from sleep mode.
*
*******************************************************************************/
void ADC_pot_Wakeup(void)
{
    if(ADC_pot_backup.enableState != ADC_pot_DISABLED)
    {
        ADC_pot_Enable();
        #if(ADC_pot_DEFAULT_CONV_MODE != ADC_pot__HARDWARE_TRIGGER)
            if((ADC_pot_backup.enableState & ADC_pot_STARTED) != 0u)
            {
                ADC_pot_StartConvert();
            }
        #endif /* End ADC_pot_DEFAULT_CONV_MODE != ADC_pot__HARDWARE_TRIGGER */
    }
}


/* [] END OF FILE */
