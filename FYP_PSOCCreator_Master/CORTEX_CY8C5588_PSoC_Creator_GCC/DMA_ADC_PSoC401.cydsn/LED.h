/*******************************************************************************
* File Name: LED.h
* Version 1.0
*
* Description:
*  This file provides functions for the RGB LED control.
*
* Note:
*
********************************************************************************
* Copyright 2015, Cypress Semiconductor Corporation. All rights reserved.
* This software is owned by Cypress Semiconductor Corporation and is protected
* by and subject to worldwide patent and copyright laws and treaties.
* Therefore, you may use this software only as provided in the license agreement
* accompanying the software package from which you obtained this software.
* CYPRESS AND ITS SUPPLIERS MAKE NO WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
* WITH REGARD TO THIS SOFTWARE, INCLUDING, BUT NOT LIMITED TO, NONINFRINGEMENT,
* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*******************************************************************************/

#if !defined(CY_LED_H)
#define CY_LED_H

#include <project.h>

/*******************************************************************************
*   Configuration macros
*******************************************************************************/

/* Set this depending on your LED connection */
#define LED_ACTIVE_STATE    0
#define LED_IS_ACTIVE_HIGH  (LED_ACTIVE_STATE != 0)
#define LED_IS_ACTIVE_LOW   (LED_ACTIVE_STATE == 0)


/*******************************************************************************
* Function Name: RED_ON
********************************************************************************
*
* Summary:
*  Turns on the red color component.
*
* Parameters:
*   None
*
* Return:
*   None
*
*******************************************************************************/
#if(LED_IS_ACTIVE_LOW)
    #define RED_ON()   {RED_DR &= ~RED_MASK;}
#else
    #define RED_ON()   {RED_DR |= RED_MASK;}
#endif /* LED_IS_ACTIVE_LOW */


/*******************************************************************************
* Function Name: RED_OFF
********************************************************************************
*
* Summary:
*  Turns off the red color component.
*
* Parameters:
*   None
*
* Return:
*   None
*
*******************************************************************************/
#if(LED_IS_ACTIVE_LOW)
    #define RED_OFF()   {RED_DR |= RED_MASK;}
#else
    #define RED_OFF()   {RED_DR &= ~RED_MASK;}
#endif /* LED_IS_ACTIVE_LOW */


/*******************************************************************************
* Function Name: BLUE_ON
********************************************************************************
*
* Summary:
*  Turns on the blue color component.
*
* Parameters:
*   None
*
* Return:
*   None
*
*******************************************************************************/
#if(LED_IS_ACTIVE_LOW)
    #define BLUE_ON()   {BLUE_DR &= ~BLUE_MASK;}
#else
    #define BLUE_ON()   {BLUE_DR |= BLUE_MASK;}
#endif /* LED_IS_ACTIVE_LOW */


/*******************************************************************************
* Function Name: BLUE_OFF
********************************************************************************
*
* Summary:
*  Turns off the blue color component.
*
* Parameters:
*   None
*
* Return:
*   None
*
*******************************************************************************/
#if(LED_IS_ACTIVE_LOW)
    #define BLUE_OFF()   {BLUE_DR |= BLUE_MASK;}
#else
    #define BLUE_OFF()   {BLUE_DR &= ~BLUE_MASK;}
#endif /* LED_IS_ACTIVE_LOW */


/*******************************************************************************
* Function Name: GREEN_ON
********************************************************************************
*
* Summary:
*  Turns on the green color component.
*
* Parameters:
*   None
*
* Return:
*   None
*
*******************************************************************************/
#if(LED_IS_ACTIVE_LOW)
    #define GREEN_ON()   {GREEN_DR &= ~GREEN_MASK;}
#else
    #define GREEN_ON()   {GREEN_DR |= GREEN_MASK;}
#endif /* LED_IS_ACTIVE_LOW */


/*******************************************************************************
* Function Name: GREEN_OFF
********************************************************************************
*
* Summary:
*  Turns off the green color component.
*
* Parameters:
*   None
*
* Return:
*   None
*
*******************************************************************************/
#if(LED_IS_ACTIVE_LOW)
    #define GREEN_OFF()   {GREEN_DR |= GREEN_MASK;}
#else
    #define GREEN_OFF()   {GREEN_DR &= ~GREEN_MASK;}
#endif /* LED_IS_ACTIVE_LOW */

#endif /* CY_LED_H */


/* [] END OF FILE */
