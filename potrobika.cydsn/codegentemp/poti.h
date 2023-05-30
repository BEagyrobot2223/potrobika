/*******************************************************************************
* File Name: poti.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_poti_H) /* Pins poti_H */
#define CY_PINS_poti_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "poti_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 poti__PORT == 15 && ((poti__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    poti_Write(uint8 value);
void    poti_SetDriveMode(uint8 mode);
uint8   poti_ReadDataReg(void);
uint8   poti_Read(void);
void    poti_SetInterruptMode(uint16 position, uint16 mode);
uint8   poti_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the poti_SetDriveMode() function.
     *  @{
     */
        #define poti_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define poti_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define poti_DM_RES_UP          PIN_DM_RES_UP
        #define poti_DM_RES_DWN         PIN_DM_RES_DWN
        #define poti_DM_OD_LO           PIN_DM_OD_LO
        #define poti_DM_OD_HI           PIN_DM_OD_HI
        #define poti_DM_STRONG          PIN_DM_STRONG
        #define poti_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define poti_MASK               poti__MASK
#define poti_SHIFT              poti__SHIFT
#define poti_WIDTH              1u

/* Interrupt constants */
#if defined(poti__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in poti_SetInterruptMode() function.
     *  @{
     */
        #define poti_INTR_NONE      (uint16)(0x0000u)
        #define poti_INTR_RISING    (uint16)(0x0001u)
        #define poti_INTR_FALLING   (uint16)(0x0002u)
        #define poti_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define poti_INTR_MASK      (0x01u) 
#endif /* (poti__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define poti_PS                     (* (reg8 *) poti__PS)
/* Data Register */
#define poti_DR                     (* (reg8 *) poti__DR)
/* Port Number */
#define poti_PRT_NUM                (* (reg8 *) poti__PRT) 
/* Connect to Analog Globals */                                                  
#define poti_AG                     (* (reg8 *) poti__AG)                       
/* Analog MUX bux enable */
#define poti_AMUX                   (* (reg8 *) poti__AMUX) 
/* Bidirectional Enable */                                                        
#define poti_BIE                    (* (reg8 *) poti__BIE)
/* Bit-mask for Aliased Register Access */
#define poti_BIT_MASK               (* (reg8 *) poti__BIT_MASK)
/* Bypass Enable */
#define poti_BYP                    (* (reg8 *) poti__BYP)
/* Port wide control signals */                                                   
#define poti_CTL                    (* (reg8 *) poti__CTL)
/* Drive Modes */
#define poti_DM0                    (* (reg8 *) poti__DM0) 
#define poti_DM1                    (* (reg8 *) poti__DM1)
#define poti_DM2                    (* (reg8 *) poti__DM2) 
/* Input Buffer Disable Override */
#define poti_INP_DIS                (* (reg8 *) poti__INP_DIS)
/* LCD Common or Segment Drive */
#define poti_LCD_COM_SEG            (* (reg8 *) poti__LCD_COM_SEG)
/* Enable Segment LCD */
#define poti_LCD_EN                 (* (reg8 *) poti__LCD_EN)
/* Slew Rate Control */
#define poti_SLW                    (* (reg8 *) poti__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define poti_PRTDSI__CAPS_SEL       (* (reg8 *) poti__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define poti_PRTDSI__DBL_SYNC_IN    (* (reg8 *) poti__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define poti_PRTDSI__OE_SEL0        (* (reg8 *) poti__PRTDSI__OE_SEL0) 
#define poti_PRTDSI__OE_SEL1        (* (reg8 *) poti__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define poti_PRTDSI__OUT_SEL0       (* (reg8 *) poti__PRTDSI__OUT_SEL0) 
#define poti_PRTDSI__OUT_SEL1       (* (reg8 *) poti__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define poti_PRTDSI__SYNC_OUT       (* (reg8 *) poti__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(poti__SIO_CFG)
    #define poti_SIO_HYST_EN        (* (reg8 *) poti__SIO_HYST_EN)
    #define poti_SIO_REG_HIFREQ     (* (reg8 *) poti__SIO_REG_HIFREQ)
    #define poti_SIO_CFG            (* (reg8 *) poti__SIO_CFG)
    #define poti_SIO_DIFF           (* (reg8 *) poti__SIO_DIFF)
#endif /* (poti__SIO_CFG) */

/* Interrupt Registers */
#if defined(poti__INTSTAT)
    #define poti_INTSTAT            (* (reg8 *) poti__INTSTAT)
    #define poti_SNAP               (* (reg8 *) poti__SNAP)
    
	#define poti_0_INTTYPE_REG 		(* (reg8 *) poti__0__INTTYPE)
#endif /* (poti__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_poti_H */


/* [] END OF FILE */
