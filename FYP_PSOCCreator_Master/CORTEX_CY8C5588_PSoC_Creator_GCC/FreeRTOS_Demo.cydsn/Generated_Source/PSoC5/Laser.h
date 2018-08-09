/*******************************************************************************
* File Name: Laser.h  
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

#if !defined(CY_PINS_Laser_H) /* Pins Laser_H */
#define CY_PINS_Laser_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Laser_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Laser__PORT == 15 && ((Laser__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Laser_Write(uint8 value);
void    Laser_SetDriveMode(uint8 mode);
uint8   Laser_ReadDataReg(void);
uint8   Laser_Read(void);
void    Laser_SetInterruptMode(uint16 position, uint16 mode);
uint8   Laser_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Laser_SetDriveMode() function.
     *  @{
     */
        #define Laser_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Laser_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Laser_DM_RES_UP          PIN_DM_RES_UP
        #define Laser_DM_RES_DWN         PIN_DM_RES_DWN
        #define Laser_DM_OD_LO           PIN_DM_OD_LO
        #define Laser_DM_OD_HI           PIN_DM_OD_HI
        #define Laser_DM_STRONG          PIN_DM_STRONG
        #define Laser_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Laser_MASK               Laser__MASK
#define Laser_SHIFT              Laser__SHIFT
#define Laser_WIDTH              1u

/* Interrupt constants */
#if defined(Laser__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Laser_SetInterruptMode() function.
     *  @{
     */
        #define Laser_INTR_NONE      (uint16)(0x0000u)
        #define Laser_INTR_RISING    (uint16)(0x0001u)
        #define Laser_INTR_FALLING   (uint16)(0x0002u)
        #define Laser_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Laser_INTR_MASK      (0x01u) 
#endif /* (Laser__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Laser_PS                     (* (reg8 *) Laser__PS)
/* Data Register */
#define Laser_DR                     (* (reg8 *) Laser__DR)
/* Port Number */
#define Laser_PRT_NUM                (* (reg8 *) Laser__PRT) 
/* Connect to Analog Globals */                                                  
#define Laser_AG                     (* (reg8 *) Laser__AG)                       
/* Analog MUX bux enable */
#define Laser_AMUX                   (* (reg8 *) Laser__AMUX) 
/* Bidirectional Enable */                                                        
#define Laser_BIE                    (* (reg8 *) Laser__BIE)
/* Bit-mask for Aliased Register Access */
#define Laser_BIT_MASK               (* (reg8 *) Laser__BIT_MASK)
/* Bypass Enable */
#define Laser_BYP                    (* (reg8 *) Laser__BYP)
/* Port wide control signals */                                                   
#define Laser_CTL                    (* (reg8 *) Laser__CTL)
/* Drive Modes */
#define Laser_DM0                    (* (reg8 *) Laser__DM0) 
#define Laser_DM1                    (* (reg8 *) Laser__DM1)
#define Laser_DM2                    (* (reg8 *) Laser__DM2) 
/* Input Buffer Disable Override */
#define Laser_INP_DIS                (* (reg8 *) Laser__INP_DIS)
/* LCD Common or Segment Drive */
#define Laser_LCD_COM_SEG            (* (reg8 *) Laser__LCD_COM_SEG)
/* Enable Segment LCD */
#define Laser_LCD_EN                 (* (reg8 *) Laser__LCD_EN)
/* Slew Rate Control */
#define Laser_SLW                    (* (reg8 *) Laser__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Laser_PRTDSI__CAPS_SEL       (* (reg8 *) Laser__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Laser_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Laser__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Laser_PRTDSI__OE_SEL0        (* (reg8 *) Laser__PRTDSI__OE_SEL0) 
#define Laser_PRTDSI__OE_SEL1        (* (reg8 *) Laser__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Laser_PRTDSI__OUT_SEL0       (* (reg8 *) Laser__PRTDSI__OUT_SEL0) 
#define Laser_PRTDSI__OUT_SEL1       (* (reg8 *) Laser__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Laser_PRTDSI__SYNC_OUT       (* (reg8 *) Laser__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Laser__SIO_CFG)
    #define Laser_SIO_HYST_EN        (* (reg8 *) Laser__SIO_HYST_EN)
    #define Laser_SIO_REG_HIFREQ     (* (reg8 *) Laser__SIO_REG_HIFREQ)
    #define Laser_SIO_CFG            (* (reg8 *) Laser__SIO_CFG)
    #define Laser_SIO_DIFF           (* (reg8 *) Laser__SIO_DIFF)
#endif /* (Laser__SIO_CFG) */

/* Interrupt Registers */
#if defined(Laser__INTSTAT)
    #define Laser_INTSTAT            (* (reg8 *) Laser__INTSTAT)
    #define Laser_SNAP               (* (reg8 *) Laser__SNAP)
    
	#define Laser_0_INTTYPE_REG 		(* (reg8 *) Laser__0__INTTYPE)
#endif /* (Laser__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Laser_H */


/* [] END OF FILE */
