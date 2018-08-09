/*******************************************************************************
* File Name: main.c
*
* Version:   1.0
*
* Description:
*  This example project demonstrates reading data from the ADC and writing it
*  to a RAM register. The EOC of the ADC triggers the DMA to transfer the ADC
*  result to a variable.
*  
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
#include <project.h>
#include "LED.h"

/* ADC conversion result ranges */
#define RANGE0              0u
#define RANGE1              1u
#define RANGE2              2u
#define RANGE3              3u

/* Refresh rate of LED in milliseconds. */
#define	USER_LED_REFRESH    25u

/* Position of bits in ADC result determines ADC result range. */
#define SAMPLE_RANGE_POS    9u
 

/*******************************************************************************
*   Function Prototypes
*******************************************************************************/
static void SetLedColor(void);


/*******************************************************************************
*   Global Variables
*******************************************************************************/

/* ADC measurement status and result */
int16   adcSample = 0;

/* User refresh rate */
uint8 userRefresh = USER_LED_REFRESH - 1u;


/*******************************************************************************
* Function Name: main
********************************************************************************
*
* Summary:
*  Starts all the components. Switches colors of RGB LED corresponding to the
*  ADC conversion results.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
int main()
{
    /* Initialize ADC. Conversion is not enabled yet. */
    ADC_Start();

    /* Configure DMA source and destination locations to transfer from
    * ADC data register to memory variable.
    */
    DMA_Start((void *)ADC_SAR_CHAN0_RESULT_PTR, (void *)&adcSample);

    /* Start ADC conversion. */
    ADC_StartConvert();

    for(;;)
    {
        /* Check the DMA interrupt register to determine if a new sample was
        * transferred from ADC to the RAM variable. The DMA channel is configured
        * to generate IRQ on completion of a transfer. This project uses a single
        * DMA channel, hence there is no need to determine which DMA channel 
        * caused the interrupt.
        */
        if(0u != CyDmaGetInterruptSourceMasked())
        {
            /* Once asserted, interrupt remains high (active) until cleared. */
            CyDmaClearInterruptSource(DMA_CHANNEL_MASK);

            /* This is called at a 1 millisecond rate because the ADC sample
            * rate is 1000 SPS and therefore the DMA performs a transfer
            * every millisecond.
            */
            if(0 != userRefresh)
            {
                --userRefresh;
            }
            else
            /* This is only called at user refresh rate. */
            {   
                /* Saturate ADC result to positive numbers. */
                if(adcSample < 0)
                {
                    adcSample = 0;
                }
                /* Update LED color. */
                userRefresh = USER_LED_REFRESH - 1u;
                SetLedColor();
            }
        }
        
    }
}


/*******************************************************************************
* Function Name: SetLedColor
********************************************************************************
*
* Summary:
*  Sets RGB LED color corresponding to the range of the ADC result value.
*  
* Theory:
*  When the negative input to the SAR ADC is connected to VSS, the effective
*  conversion resolution for single ended channels is one bit less than
*  selected in the customizer. In this example the customizer setting is 12 bits.
*  That results in the effective resolution of 11 bits or the ADC data will be
*  between 0..7FF, which is further divided into 4 ranges. Each range is
*  represented with a RGB LED color on Pioneer DVK kit as follows:
*   RANGE 0: 000..1FF - BLUE
*   RANGE 1: 200..3FF - GREEN
*   RANGE 2: 400..5FF - RED
*   RANGE 3: 600..7FF - YELLOW
*
* Parameters:
*   None
*
* Return:
*   None
*
*******************************************************************************/
void SetLedColor(void)
{
    /* Turn RGB LED off. */
    RED_OFF();
    BLUE_OFF();
    GREEN_OFF();
    
    /* Turn on color components correspondingly to ADC data range.
    * Shift adcSample to right to use MSB to determine range.
    */
    switch(adcSample >> SAMPLE_RANGE_POS)
    {
        /* Blue */
        case RANGE0:
            BLUE_ON();
            break;
        
        /* Green */
        case RANGE1:
            GREEN_ON();
            break;

        /* Red */
        case RANGE2:
            RED_ON();
            break;

        /* Yellow */
        case RANGE3:
            RED_ON();
            GREEN_ON();
            break;

        default:
            break;
    }
}


/* [] END OF FILE */
