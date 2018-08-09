/*
 * FreeRTOS Kernel V10.0.1
 * Copyright (C) 2017 Amazon.com, Inc. or its affiliates.  All Rights Reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * http://www.FreeRTOS.org
 * http://aws.amazon.com/freertos
 *
 * 1 tab == 4 spaces!
 */

/* This is the master file !!!!!!  */




/* Standard includes */
#include <device.h>
#include <stdio.h>
#include <stdint.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
 

/* FreeRTOS includes */
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"
#include "serial.h"

/* My headers */
#include "movement.h"

/* The time between cycles of the 'check' functionality (defined within the
tick hook. */
#define mainCHECK_DELAY						( ( TickType_t ) 5000 / portTICK_PERIOD_MS )
#define mainCOM_LED							( 3 )

/* The number of nano seconds between each processor clock. */
#define mainNS_PER_CLOCK ( ( unsigned long ) ( ( 1.0 / ( double ) configCPU_CLOCK_HZ ) * 1000000000.0 ) )

/* Task priorities. */
#define mainSENDER_PRIORITY       			( tskIDLE_PRIORITY )
#define mainRECEIVER_PRIORITY        		( tskIDLE_PRIORITY )

#define comRX_BLOCK_TIME			( ( TickType_t ) 0xffff )


void PID_initialise( void *p );
void receive_data( void *p );
void DMA_config();
static void prvHardwareSetup( void );


static xComPortHandle pxPort = NULL;
xSemaphoreHandle gatekeeper = 0;
xQueueHandle queue_handle = NULL;


/* global variables */
signed char rx_receive;
unsigned char buffer[64];


wheel_data left_wheel;
wheel_data right_wheel;
PID_data k;

int isMaster = 1;           // use 1 if it is the master, 0 if it is the slave.


// START OF FUNCTIONS
int main( void ) {
	const signed char * run[64];
    if (isMaster){
    /* This is the for loop for the master system */
        
        
        
    }
    if (~isMaster){
    /* This is the for loop for the slave system */
        
    prvHardwareSetup(); 
    DMA_config();
    sprintf((char *) run, "\n=== Master ===\n\n");
    vSerialPutString(pxPort, (const signed char *) run, 64);
    
    sprintf((char *) run, "\n=== NEW RUN ===\n\n");
    vSerialPutString(pxPort, (const signed char *) run, 64);
    
    gatekeeper = xSemaphoreCreateMutex();
    
    xTaskCreate( PID_initialise, (const char*) "initialise the PID", 1024, NULL, 2, NULL );
    xTaskCreate( receive_data, (const char*) "waiting for a serial bus to come in", 1024, NULL, 1, NULL );
    
	vTaskStartScheduler();
    
    }

	for( ;; );  // You won't actually reach this for loop.
}
void DMA_config(){
    ADC_DelSig_1_Start();
    ADC_DelSig_1_StartConvert();
    Filter_1_Start();
    Opamp_1_Start();
    PGA_1_Start();
    PGA_2_Start();  
    /* Defines for DMA_1 */
    #define DMA_1_BYTES_PER_BURST 1
    #define DMA_1_REQUEST_PER_BURST 1
    #define DMA_1_SRC_BASE (CYDEV_PERIPH_BASE)
    #define DMA_1_DST_BASE (CYDEV_PERIPH_BASE)

    /* Variable declarations for DMA_1 */
    /* Move these variable declarations to the top of the function */
    uint8 DMA_1_Chan;
    uint8 DMA_1_TD[1];

    /* DMA Configuration for DMA_1 */
    DMA_1_Chan = DMA_1_DmaInitialize(DMA_1_BYTES_PER_BURST, DMA_1_REQUEST_PER_BURST, 
        HI16(DMA_1_SRC_BASE), HI16(DMA_1_DST_BASE));
    DMA_1_TD[0] = CyDmaTdAllocate();
    CyDmaTdSetConfiguration(DMA_1_TD[0], 8, CY_DMA_DISABLE_TD, 0);
    CyDmaTdSetAddress(DMA_1_TD[0], LO16((uint32)ADC_DelSig_1_DEC_SAMP_PTR), LO16((uint32)Filter_1_STAGEA_PTR));
    CyDmaChSetInitialTd(DMA_1_Chan, DMA_1_TD[0]);
    CyDmaChEnable(DMA_1_Chan, 1);
    const signed char * local_write[64];
    sprintf((char *) local_write, "In DMA CONFIG  ");
    vSerialPutString(pxPort, (const signed char *) local_write, 64);
}

void receive_data( void *p ) {
    
    p = NULL;
    
    const signed char * local_write[64];
    int i = 0;
    int go = 0;
    signed char type = 0;
    char temp[10];
    while(1) {
        if (pdTRUE == xSerialGetChar(pxPort, &rx_receive, comRX_BLOCK_TIME)) {
            type = rx_receive;
            if(xSemaphoreTake(gatekeeper, 50000)) {
                if(type=='1'){
                    for(i=0;i<8;i++){
                        xSerialGetChar(pxPort, &rx_receive, comRX_BLOCK_TIME);
                        buffer[i] = rx_receive;
                    }
                    sprintf((char *) local_write, "buffer read as %s\n", buffer);
                    vSerialPutString(pxPort, (const signed char *) local_write, 64);
                    update_inc( &left_wheel, &right_wheel, buffer);
                    sprintf((char *) local_write, "left inc: %i\nright inc: %i\n", left_wheel.inc, right_wheel.inc);
                    vSerialPutString(pxPort, (const signed char *) local_write, 64);
                }
                if(type=='2'){
                    CySoftwareReset();
                }  
                if (type=='3'){
                    for(i=0;i<8;i++){
                        xSerialGetChar(pxPort, &rx_receive, comRX_BLOCK_TIME);
                        buffer[i] = rx_receive;
                    }
                    sprintf((char *) local_write, "buffer read as %s\n", buffer);
                    vSerialPutString(pxPort, (const signed char *) local_write, 64);
                    update_k( &k, buffer);
                    snprintf((char *) local_write,64, "Kp Value: %f", k.Kp);
                    
                    vSerialPutString(pxPort, (const signed char *) local_write, 64);
                    
                }
                for (i=0; i<65; i++) {
                    buffer[i] = ' ';
                }
                go = 0;
                i = 0;
                type=0;                   
                xSemaphoreGive(gatekeeper);
            }
        }
    }
}

void PID_initialise( void *p ) {
    
    p = NULL;
        
    initialise_wheel_data(&left_wheel);
    initialise_wheel_data(&right_wheel);
    
    k.Kp = 40;
    k.Ki = 0;
    k.Kd = 20;
    
    signed char *local_write[64];  
    
    while(1) {
    	if(xSemaphoreTake(gatekeeper, 50000)) {              // wait until semaphore is free:
            mov_update_error(&left_wheel, &right_wheel);    // update error values
                sprintf((char *) local_write, "left wheel inc: %li\n", left_wheel.cur_dest);
                //vSerialPutString(pxPort, (signed char *) local_write, 64);
            mov_get_PID(&left_wheel, &right_wheel, &k);     // calculate wheel voltage from errors using PID
            
            mov_Adj_Volt(&left_wheel, &right_wheel);        // adjust the voltage of the wheels
            sprintf((char *) local_write, "Filter Read: %u\n", Filter_1_Read8(Filter_1_CHANNEL_A));
            vSerialPutString(pxPort, (signed char *) local_write, 64);
			xSemaphoreGive(gatekeeper);                     // give the semaphore back
    	}
        vTaskDelay(10);                                     // wait 10ms before going again
    }
}

void prvHardwareSetup( void ) {
    
    /* Port layer functions that need to be copied into the vector table. */
    extern void xPortPendSVHandler( void );
    extern void xPortSysTickHandler( void );
    extern void vPortSVCHandler( void );
    extern cyisraddress CyRamVectors[];

	/* Install the OS Interrupt Handlers. */
	CyRamVectors[ 11 ] = ( cyisraddress ) vPortSVCHandler;
	CyRamVectors[ 14 ] = ( cyisraddress ) xPortPendSVHandler;
	CyRamVectors[ 15 ] = ( cyisraddress ) xPortSysTickHandler;

	/* Start-up the shared peripherals. */
    PWM_M1_Start();
    PWM_M2_Start();
    M1Clock_Start();
    MClock_Start();
    
    M1QuadDec_Start();
    M1QuadDec_Enable();
    M1QuadDec_SetCounter(0);
    
    M2QuadDec_Start();
    M2QuadDec_Enable();
    M2QuadDec_SetCounter(0);

	UART_1_Start();                         // Start the UART
    xSerialPortInitMinimal( 57600, 64 );    // Set the serial baud rate and buffer size in bytes
    
    Timer_1_Start();

    /* Start up the master peripherals. */
    if (isMaster){
         Laser_Write(1);// turn on the laser
    }
    
    /* Start up the slave peripherals. */
    if (~isMaster){
    }
}


// DON'T TOUCH THESE (PART OF FREERTOS)
void vApplicationStackOverflowHook( TaskHandle_t pxTask, char *pcTaskName ) {
	/* The stack space has been execeeded for a task, considering allocating more. */
	taskDISABLE_INTERRUPTS();
	for( ;; );
}
void vApplicationMallocFailedHook( void ) {
	/* The heap space has been execeeded. */
	taskDISABLE_INTERRUPTS();
	for( ;; );
}
