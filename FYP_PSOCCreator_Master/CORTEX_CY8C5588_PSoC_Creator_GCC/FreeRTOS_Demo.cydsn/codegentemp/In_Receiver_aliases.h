/*******************************************************************************
* File Name: In_Receiver.h  
* Version 2.20
*
* Description:
*  This file contains the Alias definitions for Per-Pin APIs in cypins.h. 
*  Information on using these APIs can be found in the System Reference Guide.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_In_Receiver_ALIASES_H) /* Pins In_Receiver_ALIASES_H */
#define CY_PINS_In_Receiver_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
*              Constants        
***************************************/
#define In_Receiver_0			(In_Receiver__0__PC)
#define In_Receiver_0_INTR	((uint16)((uint16)0x0001u << In_Receiver__0__SHIFT))

#define In_Receiver_INTR_ALL	 ((uint16)(In_Receiver_0_INTR))

#endif /* End Pins In_Receiver_ALIASES_H */


/* [] END OF FILE */
