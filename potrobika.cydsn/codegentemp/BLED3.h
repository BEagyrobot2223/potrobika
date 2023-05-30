/*******************************************************************************
* File Name: BLED3.h  
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

#if !defined(CY_PINS_BLED3_H) /* Pins BLED3_H */
#define CY_PINS_BLED3_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "BLED3_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 BLED3__PORT == 15 && ((BLED3__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    BLED3_Write(uint8 value);
void    BLED3_SetDriveMode(uint8 mode);
uint8   BLED3_ReadDataReg(void);
uint8   BLED3_Read(void);
void    BLED3_SetInterruptMode(uint16 position, uint16 mode);
uint8   BLED3_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the BLED3_SetDriveMode() function.
     *  @{
     */
        #define BLED3_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define BLED3_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define BLED3_DM_RES_UP          PIN_DM_RES_UP
        #define BLED3_DM_RES_DWN         PIN_DM_RES_DWN
        #define BLED3_DM_OD_LO           PIN_DM_OD_LO
        #define BLED3_DM_OD_HI           PIN_DM_OD_HI
        #define BLED3_DM_STRONG          PIN_DM_STRONG
        #define BLED3_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define BLED3_MASK               BLED3__MASK
#define BLED3_SHIFT              BLED3__SHIFT
#define BLED3_WIDTH              1u

/* Interrupt constants */
#if defined(BLED3__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in BLED3_SetInterruptMode() function.
     *  @{
     */
        #define BLED3_INTR_NONE      (uint16)(0x0000u)
        #define BLED3_INTR_RISING    (uint16)(0x0001u)
        #define BLED3_INTR_FALLING   (uint16)(0x0002u)
        #define BLED3_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define BLED3_INTR_MASK      (0x01u) 
#endif /* (BLED3__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define BLED3_PS                     (* (reg8 *) BLED3__PS)
/* Data Register */
#define BLED3_DR                     (* (reg8 *) BLED3__DR)
/* Port Number */
#define BLED3_PRT_NUM                (* (reg8 *) BLED3__PRT) 
/* Connect to Analog Globals */                                                  
#define BLED3_AG                     (* (reg8 *) BLED3__AG)                       
/* Analog MUX bux enable */
#define BLED3_AMUX                   (* (reg8 *) BLED3__AMUX) 
/* Bidirectional Enable */                                                        
#define BLED3_BIE                    (* (reg8 *) BLED3__BIE)
/* Bit-mask for Aliased Register Access */
#define BLED3_BIT_MASK               (* (reg8 *) BLED3__BIT_MASK)
/* Bypass Enable */
#define BLED3_BYP                    (* (reg8 *) BLED3__BYP)
/* Port wide control signals */                                                   
#define BLED3_CTL                    (* (reg8 *) BLED3__CTL)
/* Drive Modes */
#define BLED3_DM0                    (* (reg8 *) BLED3__DM0) 
#define BLED3_DM1                    (* (reg8 *) BLED3__DM1)
#define BLED3_DM2                    (* (reg8 *) BLED3__DM2) 
/* Input Buffer Disable Override */
#define BLED3_INP_DIS                (* (reg8 *) BLED3__INP_DIS)
/* LCD Common or Segment Drive */
#define BLED3_LCD_COM_SEG            (* (reg8 *) BLED3__LCD_COM_SEG)
/* Enable Segment LCD */
#define BLED3_LCD_EN                 (* (reg8 *) BLED3__LCD_EN)
/* Slew Rate Control */
#define BLED3_SLW                    (* (reg8 *) BLED3__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define BLED3_PRTDSI__CAPS_SEL       (* (reg8 *) BLED3__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define BLED3_PRTDSI__DBL_SYNC_IN    (* (reg8 *) BLED3__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define BLED3_PRTDSI__OE_SEL0        (* (reg8 *) BLED3__PRTDSI__OE_SEL0) 
#define BLED3_PRTDSI__OE_SEL1        (* (reg8 *) BLED3__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define BLED3_PRTDSI__OUT_SEL0       (* (reg8 *) BLED3__PRTDSI__OUT_SEL0) 
#define BLED3_PRTDSI__OUT_SEL1       (* (reg8 *) BLED3__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define BLED3_PRTDSI__SYNC_OUT       (* (reg8 *) BLED3__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(BLED3__SIO_CFG)
    #define BLED3_SIO_HYST_EN        (* (reg8 *) BLED3__SIO_HYST_EN)
    #define BLED3_SIO_REG_HIFREQ     (* (reg8 *) BLED3__SIO_REG_HIFREQ)
    #define BLED3_SIO_CFG            (* (reg8 *) BLED3__SIO_CFG)
    #define BLED3_SIO_DIFF           (* (reg8 *) BLED3__SIO_DIFF)
#endif /* (BLED3__SIO_CFG) */

/* Interrupt Registers */
#if defined(BLED3__INTSTAT)
    #define BLED3_INTSTAT            (* (reg8 *) BLED3__INTSTAT)
    #define BLED3_SNAP               (* (reg8 *) BLED3__SNAP)
    
	#define BLED3_0_INTTYPE_REG 		(* (reg8 *) BLED3__0__INTTYPE)
#endif /* (BLED3__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_BLED3_H */


/* [] END OF FILE */
