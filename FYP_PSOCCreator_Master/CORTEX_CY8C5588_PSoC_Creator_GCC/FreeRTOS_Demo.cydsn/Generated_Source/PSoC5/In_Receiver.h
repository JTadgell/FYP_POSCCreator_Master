/*******************************************************************************
* File Name: In_Receiver.h  
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

#if !defined(CY_PINS_In_Receiver_H) /* Pins In_Receiver_H */
#define CY_PINS_In_Receiver_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "In_Receiver_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 In_Receiver__PORT == 15 && ((In_Receiver__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    In_Receiver_Write(uint8 value);
void    In_Receiver_SetDriveMode(uint8 mode);
uint8   In_Receiver_ReadDataReg(void);
uint8   In_Receiver_Read(void);
void    In_Receiver_SetInterruptMode(uint16 position, uint16 mode);
uint8   In_Receiver_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the In_Receiver_SetDriveMode() function.
     *  @{
     */
        #define In_Receiver_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define In_Receiver_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define In_Receiver_DM_RES_UP          PIN_DM_RES_UP
        #define In_Receiver_DM_RES_DWN         PIN_DM_RES_DWN
        #define In_Receiver_DM_OD_LO           PIN_DM_OD_LO
        #define In_Receiver_DM_OD_HI           PIN_DM_OD_HI
        #define In_Receiver_DM_STRONG          PIN_DM_STRONG
        #define In_Receiver_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define In_Receiver_MASK               In_Receiver__MASK
#define In_Receiver_SHIFT              In_Receiver__SHIFT
#define In_Receiver_WIDTH              1u

/* Interrupt constants */
#if defined(In_Receiver__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in In_Receiver_SetInterruptMode() function.
     *  @{
     */
        #define In_Receiver_INTR_NONE      (uint16)(0x0000u)
        #define In_Receiver_INTR_RISING    (uint16)(0x0001u)
        #define In_Receiver_INTR_FALLING   (uint16)(0x0002u)
        #define In_Receiver_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define In_Receiver_INTR_MASK      (0x01u) 
#endif /* (In_Receiver__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define In_Receiver_PS                     (* (reg8 *) In_Receiver__PS)
/* Data Register */
#define In_Receiver_DR                     (* (reg8 *) In_Receiver__DR)
/* Port Number */
#define In_Receiver_PRT_NUM                (* (reg8 *) In_Receiver__PRT) 
/* Connect to Analog Globals */                                                  
#define In_Receiver_AG                     (* (reg8 *) In_Receiver__AG)                       
/* Analog MUX bux enable */
#define In_Receiver_AMUX                   (* (reg8 *) In_Receiver__AMUX) 
/* Bidirectional Enable */                                                        
#define In_Receiver_BIE                    (* (reg8 *) In_Receiver__BIE)
/* Bit-mask for Aliased Register Access */
#define In_Receiver_BIT_MASK               (* (reg8 *) In_Receiver__BIT_MASK)
/* Bypass Enable */
#define In_Receiver_BYP                    (* (reg8 *) In_Receiver__BYP)
/* Port wide control signals */                                                   
#define In_Receiver_CTL                    (* (reg8 *) In_Receiver__CTL)
/* Drive Modes */
#define In_Receiver_DM0                    (* (reg8 *) In_Receiver__DM0) 
#define In_Receiver_DM1                    (* (reg8 *) In_Receiver__DM1)
#define In_Receiver_DM2                    (* (reg8 *) In_Receiver__DM2) 
/* Input Buffer Disable Override */
#define In_Receiver_INP_DIS                (* (reg8 *) In_Receiver__INP_DIS)
/* LCD Common or Segment Drive */
#define In_Receiver_LCD_COM_SEG            (* (reg8 *) In_Receiver__LCD_COM_SEG)
/* Enable Segment LCD */
#define In_Receiver_LCD_EN                 (* (reg8 *) In_Receiver__LCD_EN)
/* Slew Rate Control */
#define In_Receiver_SLW                    (* (reg8 *) In_Receiver__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define In_Receiver_PRTDSI__CAPS_SEL       (* (reg8 *) In_Receiver__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define In_Receiver_PRTDSI__DBL_SYNC_IN    (* (reg8 *) In_Receiver__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define In_Receiver_PRTDSI__OE_SEL0        (* (reg8 *) In_Receiver__PRTDSI__OE_SEL0) 
#define In_Receiver_PRTDSI__OE_SEL1        (* (reg8 *) In_Receiver__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define In_Receiver_PRTDSI__OUT_SEL0       (* (reg8 *) In_Receiver__PRTDSI__OUT_SEL0) 
#define In_Receiver_PRTDSI__OUT_SEL1       (* (reg8 *) In_Receiver__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define In_Receiver_PRTDSI__SYNC_OUT       (* (reg8 *) In_Receiver__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(In_Receiver__SIO_CFG)
    #define In_Receiver_SIO_HYST_EN        (* (reg8 *) In_Receiver__SIO_HYST_EN)
    #define In_Receiver_SIO_REG_HIFREQ     (* (reg8 *) In_Receiver__SIO_REG_HIFREQ)
    #define In_Receiver_SIO_CFG            (* (reg8 *) In_Receiver__SIO_CFG)
    #define In_Receiver_SIO_DIFF           (* (reg8 *) In_Receiver__SIO_DIFF)
#endif /* (In_Receiver__SIO_CFG) */

/* Interrupt Registers */
#if defined(In_Receiver__INTSTAT)
    #define In_Receiver_INTSTAT            (* (reg8 *) In_Receiver__INTSTAT)
    #define In_Receiver_SNAP               (* (reg8 *) In_Receiver__SNAP)
    
	#define In_Receiver_0_INTTYPE_REG 		(* (reg8 *) In_Receiver__0__INTTYPE)
#endif /* (In_Receiver__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_In_Receiver_H */


/* [] END OF FILE */
