/*******************************************************************************
* File Name: BSTOPGOMB.h  
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

#if !defined(CY_PINS_BSTOPGOMB_H) /* Pins BSTOPGOMB_H */
#define CY_PINS_BSTOPGOMB_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "BSTOPGOMB_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 BSTOPGOMB__PORT == 15 && ((BSTOPGOMB__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    BSTOPGOMB_Write(uint8 value);
void    BSTOPGOMB_SetDriveMode(uint8 mode);
uint8   BSTOPGOMB_ReadDataReg(void);
uint8   BSTOPGOMB_Read(void);
void    BSTOPGOMB_SetInterruptMode(uint16 position, uint16 mode);
uint8   BSTOPGOMB_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the BSTOPGOMB_SetDriveMode() function.
     *  @{
     */
        #define BSTOPGOMB_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define BSTOPGOMB_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define BSTOPGOMB_DM_RES_UP          PIN_DM_RES_UP
        #define BSTOPGOMB_DM_RES_DWN         PIN_DM_RES_DWN
        #define BSTOPGOMB_DM_OD_LO           PIN_DM_OD_LO
        #define BSTOPGOMB_DM_OD_HI           PIN_DM_OD_HI
        #define BSTOPGOMB_DM_STRONG          PIN_DM_STRONG
        #define BSTOPGOMB_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define BSTOPGOMB_MASK               BSTOPGOMB__MASK
#define BSTOPGOMB_SHIFT              BSTOPGOMB__SHIFT
#define BSTOPGOMB_WIDTH              1u

/* Interrupt constants */
#if defined(BSTOPGOMB__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in BSTOPGOMB_SetInterruptMode() function.
     *  @{
     */
        #define BSTOPGOMB_INTR_NONE      (uint16)(0x0000u)
        #define BSTOPGOMB_INTR_RISING    (uint16)(0x0001u)
        #define BSTOPGOMB_INTR_FALLING   (uint16)(0x0002u)
        #define BSTOPGOMB_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define BSTOPGOMB_INTR_MASK      (0x01u) 
#endif /* (BSTOPGOMB__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define BSTOPGOMB_PS                     (* (reg8 *) BSTOPGOMB__PS)
/* Data Register */
#define BSTOPGOMB_DR                     (* (reg8 *) BSTOPGOMB__DR)
/* Port Number */
#define BSTOPGOMB_PRT_NUM                (* (reg8 *) BSTOPGOMB__PRT) 
/* Connect to Analog Globals */                                                  
#define BSTOPGOMB_AG                     (* (reg8 *) BSTOPGOMB__AG)                       
/* Analog MUX bux enable */
#define BSTOPGOMB_AMUX                   (* (reg8 *) BSTOPGOMB__AMUX) 
/* Bidirectional Enable */                                                        
#define BSTOPGOMB_BIE                    (* (reg8 *) BSTOPGOMB__BIE)
/* Bit-mask for Aliased Register Access */
#define BSTOPGOMB_BIT_MASK               (* (reg8 *) BSTOPGOMB__BIT_MASK)
/* Bypass Enable */
#define BSTOPGOMB_BYP                    (* (reg8 *) BSTOPGOMB__BYP)
/* Port wide control signals */                                                   
#define BSTOPGOMB_CTL                    (* (reg8 *) BSTOPGOMB__CTL)
/* Drive Modes */
#define BSTOPGOMB_DM0                    (* (reg8 *) BSTOPGOMB__DM0) 
#define BSTOPGOMB_DM1                    (* (reg8 *) BSTOPGOMB__DM1)
#define BSTOPGOMB_DM2                    (* (reg8 *) BSTOPGOMB__DM2) 
/* Input Buffer Disable Override */
#define BSTOPGOMB_INP_DIS                (* (reg8 *) BSTOPGOMB__INP_DIS)
/* LCD Common or Segment Drive */
#define BSTOPGOMB_LCD_COM_SEG            (* (reg8 *) BSTOPGOMB__LCD_COM_SEG)
/* Enable Segment LCD */
#define BSTOPGOMB_LCD_EN                 (* (reg8 *) BSTOPGOMB__LCD_EN)
/* Slew Rate Control */
#define BSTOPGOMB_SLW                    (* (reg8 *) BSTOPGOMB__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define BSTOPGOMB_PRTDSI__CAPS_SEL       (* (reg8 *) BSTOPGOMB__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define BSTOPGOMB_PRTDSI__DBL_SYNC_IN    (* (reg8 *) BSTOPGOMB__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define BSTOPGOMB_PRTDSI__OE_SEL0        (* (reg8 *) BSTOPGOMB__PRTDSI__OE_SEL0) 
#define BSTOPGOMB_PRTDSI__OE_SEL1        (* (reg8 *) BSTOPGOMB__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define BSTOPGOMB_PRTDSI__OUT_SEL0       (* (reg8 *) BSTOPGOMB__PRTDSI__OUT_SEL0) 
#define BSTOPGOMB_PRTDSI__OUT_SEL1       (* (reg8 *) BSTOPGOMB__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define BSTOPGOMB_PRTDSI__SYNC_OUT       (* (reg8 *) BSTOPGOMB__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(BSTOPGOMB__SIO_CFG)
    #define BSTOPGOMB_SIO_HYST_EN        (* (reg8 *) BSTOPGOMB__SIO_HYST_EN)
    #define BSTOPGOMB_SIO_REG_HIFREQ     (* (reg8 *) BSTOPGOMB__SIO_REG_HIFREQ)
    #define BSTOPGOMB_SIO_CFG            (* (reg8 *) BSTOPGOMB__SIO_CFG)
    #define BSTOPGOMB_SIO_DIFF           (* (reg8 *) BSTOPGOMB__SIO_DIFF)
#endif /* (BSTOPGOMB__SIO_CFG) */

/* Interrupt Registers */
#if defined(BSTOPGOMB__INTSTAT)
    #define BSTOPGOMB_INTSTAT            (* (reg8 *) BSTOPGOMB__INTSTAT)
    #define BSTOPGOMB_SNAP               (* (reg8 *) BSTOPGOMB__SNAP)
    
	#define BSTOPGOMB_0_INTTYPE_REG 		(* (reg8 *) BSTOPGOMB__0__INTTYPE)
#endif /* (BSTOPGOMB__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_BSTOPGOMB_H */


/* [] END OF FILE */
