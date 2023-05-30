/*******************************************************************************
* File Name: IR_FLA.h  
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

#if !defined(CY_PINS_IR_FLA_H) /* Pins IR_FLA_H */
#define CY_PINS_IR_FLA_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "IR_FLA_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 IR_FLA__PORT == 15 && ((IR_FLA__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    IR_FLA_Write(uint8 value);
void    IR_FLA_SetDriveMode(uint8 mode);
uint8   IR_FLA_ReadDataReg(void);
uint8   IR_FLA_Read(void);
void    IR_FLA_SetInterruptMode(uint16 position, uint16 mode);
uint8   IR_FLA_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the IR_FLA_SetDriveMode() function.
     *  @{
     */
        #define IR_FLA_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define IR_FLA_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define IR_FLA_DM_RES_UP          PIN_DM_RES_UP
        #define IR_FLA_DM_RES_DWN         PIN_DM_RES_DWN
        #define IR_FLA_DM_OD_LO           PIN_DM_OD_LO
        #define IR_FLA_DM_OD_HI           PIN_DM_OD_HI
        #define IR_FLA_DM_STRONG          PIN_DM_STRONG
        #define IR_FLA_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define IR_FLA_MASK               IR_FLA__MASK
#define IR_FLA_SHIFT              IR_FLA__SHIFT
#define IR_FLA_WIDTH              1u

/* Interrupt constants */
#if defined(IR_FLA__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in IR_FLA_SetInterruptMode() function.
     *  @{
     */
        #define IR_FLA_INTR_NONE      (uint16)(0x0000u)
        #define IR_FLA_INTR_RISING    (uint16)(0x0001u)
        #define IR_FLA_INTR_FALLING   (uint16)(0x0002u)
        #define IR_FLA_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define IR_FLA_INTR_MASK      (0x01u) 
#endif /* (IR_FLA__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define IR_FLA_PS                     (* (reg8 *) IR_FLA__PS)
/* Data Register */
#define IR_FLA_DR                     (* (reg8 *) IR_FLA__DR)
/* Port Number */
#define IR_FLA_PRT_NUM                (* (reg8 *) IR_FLA__PRT) 
/* Connect to Analog Globals */                                                  
#define IR_FLA_AG                     (* (reg8 *) IR_FLA__AG)                       
/* Analog MUX bux enable */
#define IR_FLA_AMUX                   (* (reg8 *) IR_FLA__AMUX) 
/* Bidirectional Enable */                                                        
#define IR_FLA_BIE                    (* (reg8 *) IR_FLA__BIE)
/* Bit-mask for Aliased Register Access */
#define IR_FLA_BIT_MASK               (* (reg8 *) IR_FLA__BIT_MASK)
/* Bypass Enable */
#define IR_FLA_BYP                    (* (reg8 *) IR_FLA__BYP)
/* Port wide control signals */                                                   
#define IR_FLA_CTL                    (* (reg8 *) IR_FLA__CTL)
/* Drive Modes */
#define IR_FLA_DM0                    (* (reg8 *) IR_FLA__DM0) 
#define IR_FLA_DM1                    (* (reg8 *) IR_FLA__DM1)
#define IR_FLA_DM2                    (* (reg8 *) IR_FLA__DM2) 
/* Input Buffer Disable Override */
#define IR_FLA_INP_DIS                (* (reg8 *) IR_FLA__INP_DIS)
/* LCD Common or Segment Drive */
#define IR_FLA_LCD_COM_SEG            (* (reg8 *) IR_FLA__LCD_COM_SEG)
/* Enable Segment LCD */
#define IR_FLA_LCD_EN                 (* (reg8 *) IR_FLA__LCD_EN)
/* Slew Rate Control */
#define IR_FLA_SLW                    (* (reg8 *) IR_FLA__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define IR_FLA_PRTDSI__CAPS_SEL       (* (reg8 *) IR_FLA__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define IR_FLA_PRTDSI__DBL_SYNC_IN    (* (reg8 *) IR_FLA__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define IR_FLA_PRTDSI__OE_SEL0        (* (reg8 *) IR_FLA__PRTDSI__OE_SEL0) 
#define IR_FLA_PRTDSI__OE_SEL1        (* (reg8 *) IR_FLA__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define IR_FLA_PRTDSI__OUT_SEL0       (* (reg8 *) IR_FLA__PRTDSI__OUT_SEL0) 
#define IR_FLA_PRTDSI__OUT_SEL1       (* (reg8 *) IR_FLA__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define IR_FLA_PRTDSI__SYNC_OUT       (* (reg8 *) IR_FLA__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(IR_FLA__SIO_CFG)
    #define IR_FLA_SIO_HYST_EN        (* (reg8 *) IR_FLA__SIO_HYST_EN)
    #define IR_FLA_SIO_REG_HIFREQ     (* (reg8 *) IR_FLA__SIO_REG_HIFREQ)
    #define IR_FLA_SIO_CFG            (* (reg8 *) IR_FLA__SIO_CFG)
    #define IR_FLA_SIO_DIFF           (* (reg8 *) IR_FLA__SIO_DIFF)
#endif /* (IR_FLA__SIO_CFG) */

/* Interrupt Registers */
#if defined(IR_FLA__INTSTAT)
    #define IR_FLA_INTSTAT            (* (reg8 *) IR_FLA__INTSTAT)
    #define IR_FLA_SNAP               (* (reg8 *) IR_FLA__SNAP)
    
	#define IR_FLA_0_INTTYPE_REG 		(* (reg8 *) IR_FLA__0__INTTYPE)
#endif /* (IR_FLA__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_IR_FLA_H */


/* [] END OF FILE */
