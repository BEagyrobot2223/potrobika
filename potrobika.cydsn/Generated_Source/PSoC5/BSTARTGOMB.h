/*******************************************************************************
* File Name: BSTARTGOMB.h  
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

#if !defined(CY_PINS_BSTARTGOMB_H) /* Pins BSTARTGOMB_H */
#define CY_PINS_BSTARTGOMB_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "BSTARTGOMB_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 BSTARTGOMB__PORT == 15 && ((BSTARTGOMB__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    BSTARTGOMB_Write(uint8 value);
void    BSTARTGOMB_SetDriveMode(uint8 mode);
uint8   BSTARTGOMB_ReadDataReg(void);
uint8   BSTARTGOMB_Read(void);
void    BSTARTGOMB_SetInterruptMode(uint16 position, uint16 mode);
uint8   BSTARTGOMB_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the BSTARTGOMB_SetDriveMode() function.
     *  @{
     */
        #define BSTARTGOMB_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define BSTARTGOMB_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define BSTARTGOMB_DM_RES_UP          PIN_DM_RES_UP
        #define BSTARTGOMB_DM_RES_DWN         PIN_DM_RES_DWN
        #define BSTARTGOMB_DM_OD_LO           PIN_DM_OD_LO
        #define BSTARTGOMB_DM_OD_HI           PIN_DM_OD_HI
        #define BSTARTGOMB_DM_STRONG          PIN_DM_STRONG
        #define BSTARTGOMB_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define BSTARTGOMB_MASK               BSTARTGOMB__MASK
#define BSTARTGOMB_SHIFT              BSTARTGOMB__SHIFT
#define BSTARTGOMB_WIDTH              1u

/* Interrupt constants */
#if defined(BSTARTGOMB__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in BSTARTGOMB_SetInterruptMode() function.
     *  @{
     */
        #define BSTARTGOMB_INTR_NONE      (uint16)(0x0000u)
        #define BSTARTGOMB_INTR_RISING    (uint16)(0x0001u)
        #define BSTARTGOMB_INTR_FALLING   (uint16)(0x0002u)
        #define BSTARTGOMB_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define BSTARTGOMB_INTR_MASK      (0x01u) 
#endif /* (BSTARTGOMB__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define BSTARTGOMB_PS                     (* (reg8 *) BSTARTGOMB__PS)
/* Data Register */
#define BSTARTGOMB_DR                     (* (reg8 *) BSTARTGOMB__DR)
/* Port Number */
#define BSTARTGOMB_PRT_NUM                (* (reg8 *) BSTARTGOMB__PRT) 
/* Connect to Analog Globals */                                                  
#define BSTARTGOMB_AG                     (* (reg8 *) BSTARTGOMB__AG)                       
/* Analog MUX bux enable */
#define BSTARTGOMB_AMUX                   (* (reg8 *) BSTARTGOMB__AMUX) 
/* Bidirectional Enable */                                                        
#define BSTARTGOMB_BIE                    (* (reg8 *) BSTARTGOMB__BIE)
/* Bit-mask for Aliased Register Access */
#define BSTARTGOMB_BIT_MASK               (* (reg8 *) BSTARTGOMB__BIT_MASK)
/* Bypass Enable */
#define BSTARTGOMB_BYP                    (* (reg8 *) BSTARTGOMB__BYP)
/* Port wide control signals */                                                   
#define BSTARTGOMB_CTL                    (* (reg8 *) BSTARTGOMB__CTL)
/* Drive Modes */
#define BSTARTGOMB_DM0                    (* (reg8 *) BSTARTGOMB__DM0) 
#define BSTARTGOMB_DM1                    (* (reg8 *) BSTARTGOMB__DM1)
#define BSTARTGOMB_DM2                    (* (reg8 *) BSTARTGOMB__DM2) 
/* Input Buffer Disable Override */
#define BSTARTGOMB_INP_DIS                (* (reg8 *) BSTARTGOMB__INP_DIS)
/* LCD Common or Segment Drive */
#define BSTARTGOMB_LCD_COM_SEG            (* (reg8 *) BSTARTGOMB__LCD_COM_SEG)
/* Enable Segment LCD */
#define BSTARTGOMB_LCD_EN                 (* (reg8 *) BSTARTGOMB__LCD_EN)
/* Slew Rate Control */
#define BSTARTGOMB_SLW                    (* (reg8 *) BSTARTGOMB__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define BSTARTGOMB_PRTDSI__CAPS_SEL       (* (reg8 *) BSTARTGOMB__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define BSTARTGOMB_PRTDSI__DBL_SYNC_IN    (* (reg8 *) BSTARTGOMB__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define BSTARTGOMB_PRTDSI__OE_SEL0        (* (reg8 *) BSTARTGOMB__PRTDSI__OE_SEL0) 
#define BSTARTGOMB_PRTDSI__OE_SEL1        (* (reg8 *) BSTARTGOMB__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define BSTARTGOMB_PRTDSI__OUT_SEL0       (* (reg8 *) BSTARTGOMB__PRTDSI__OUT_SEL0) 
#define BSTARTGOMB_PRTDSI__OUT_SEL1       (* (reg8 *) BSTARTGOMB__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define BSTARTGOMB_PRTDSI__SYNC_OUT       (* (reg8 *) BSTARTGOMB__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(BSTARTGOMB__SIO_CFG)
    #define BSTARTGOMB_SIO_HYST_EN        (* (reg8 *) BSTARTGOMB__SIO_HYST_EN)
    #define BSTARTGOMB_SIO_REG_HIFREQ     (* (reg8 *) BSTARTGOMB__SIO_REG_HIFREQ)
    #define BSTARTGOMB_SIO_CFG            (* (reg8 *) BSTARTGOMB__SIO_CFG)
    #define BSTARTGOMB_SIO_DIFF           (* (reg8 *) BSTARTGOMB__SIO_DIFF)
#endif /* (BSTARTGOMB__SIO_CFG) */

/* Interrupt Registers */
#if defined(BSTARTGOMB__INTSTAT)
    #define BSTARTGOMB_INTSTAT            (* (reg8 *) BSTARTGOMB__INTSTAT)
    #define BSTARTGOMB_SNAP               (* (reg8 *) BSTARTGOMB__SNAP)
    
	#define BSTARTGOMB_0_INTTYPE_REG 		(* (reg8 *) BSTARTGOMB__0__INTTYPE)
#endif /* (BSTARTGOMB__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_BSTARTGOMB_H */


/* [] END OF FILE */
