/*******************************************************************************
* File Name: M2QuadDec_Cnt16.h  
* Version 3.0
*
*  Description:
*   Contains the function prototypes and constants available to the counter
*   user module.
*
*   Note:
*    None
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/
    
#if !defined(CY_COUNTER_M2QuadDec_Cnt16_H)
#define CY_COUNTER_M2QuadDec_Cnt16_H

#include "cytypes.h"
#include "cyfitter.h"
#include "CyLib.h" /* For CyEnterCriticalSection() and CyExitCriticalSection() functions */

extern uint8 M2QuadDec_Cnt16_initVar;

/* Check to see if required defines such as CY_PSOC5LP are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5LP)
    #error Component Counter_v3_0 requires cy_boot v3.0 or later
#endif /* (CY_ PSOC5LP) */

/* Error message for removed M2QuadDec_Cnt16_CounterUDB_sCTRLReg_ctrlreg through optimization */
#ifdef M2QuadDec_Cnt16_CounterUDB_sCTRLReg_ctrlreg__REMOVED
    #error Counter_v3_0 detected with a constant 0 for the enable, a \
                                constant 0 for the count or constant 1 for \
                                the reset. This will prevent the component from\
                                operating.
#endif /* M2QuadDec_Cnt16_CounterUDB_sCTRLReg_ctrlreg__REMOVED */


/**************************************
*           Parameter Defaults        
**************************************/

#define M2QuadDec_Cnt16_Resolution            16u
#define M2QuadDec_Cnt16_UsingFixedFunction    0u
#define M2QuadDec_Cnt16_ControlRegRemoved     0u
#define M2QuadDec_Cnt16_COMPARE_MODE_SOFTWARE 0u
#define M2QuadDec_Cnt16_CAPTURE_MODE_SOFTWARE 0u
#define M2QuadDec_Cnt16_RunModeUsed           0u


/***************************************
*       Type defines
***************************************/


/**************************************************************************
 * Sleep Mode API Support
 * Backup structure for Sleep Wake up operations
 *************************************************************************/
typedef struct
{
    uint8 CounterEnableState; 
    uint16 CounterUdb;         /* Current Counter Value */

    #if (!M2QuadDec_Cnt16_ControlRegRemoved)
        uint8 CounterControlRegister;               /* Counter Control Register */
    #endif /* (!M2QuadDec_Cnt16_ControlRegRemoved) */

}M2QuadDec_Cnt16_backupStruct;


/**************************************
 *  Function Prototypes
 *************************************/
void    M2QuadDec_Cnt16_Start(void) ;
void    M2QuadDec_Cnt16_Stop(void) ;
void    M2QuadDec_Cnt16_SetInterruptMode(uint8 interruptsMask) ;
uint8   M2QuadDec_Cnt16_ReadStatusRegister(void) ;
#define M2QuadDec_Cnt16_GetInterruptSource() M2QuadDec_Cnt16_ReadStatusRegister()
#if(!M2QuadDec_Cnt16_ControlRegRemoved)
    uint8   M2QuadDec_Cnt16_ReadControlRegister(void) ;
    void    M2QuadDec_Cnt16_WriteControlRegister(uint8 control) \
        ;
#endif /* (!M2QuadDec_Cnt16_ControlRegRemoved) */
#if (!(M2QuadDec_Cnt16_UsingFixedFunction && (CY_PSOC5A)))
    void    M2QuadDec_Cnt16_WriteCounter(uint16 counter) \
            ; 
#endif /* (!(M2QuadDec_Cnt16_UsingFixedFunction && (CY_PSOC5A))) */
uint16  M2QuadDec_Cnt16_ReadCounter(void) ;
uint16  M2QuadDec_Cnt16_ReadCapture(void) ;
void    M2QuadDec_Cnt16_WritePeriod(uint16 period) \
    ;
uint16  M2QuadDec_Cnt16_ReadPeriod( void ) ;
#if (!M2QuadDec_Cnt16_UsingFixedFunction)
    void    M2QuadDec_Cnt16_WriteCompare(uint16 compare) \
        ;
    uint16  M2QuadDec_Cnt16_ReadCompare( void ) \
        ;
#endif /* (!M2QuadDec_Cnt16_UsingFixedFunction) */

#if (M2QuadDec_Cnt16_COMPARE_MODE_SOFTWARE)
    void    M2QuadDec_Cnt16_SetCompareMode(uint8 compareMode) ;
#endif /* (M2QuadDec_Cnt16_COMPARE_MODE_SOFTWARE) */
#if (M2QuadDec_Cnt16_CAPTURE_MODE_SOFTWARE)
    void    M2QuadDec_Cnt16_SetCaptureMode(uint8 captureMode) ;
#endif /* (M2QuadDec_Cnt16_CAPTURE_MODE_SOFTWARE) */
void M2QuadDec_Cnt16_ClearFIFO(void)     ;
void M2QuadDec_Cnt16_Init(void)          ;
void M2QuadDec_Cnt16_Enable(void)        ;
void M2QuadDec_Cnt16_SaveConfig(void)    ;
void M2QuadDec_Cnt16_RestoreConfig(void) ;
void M2QuadDec_Cnt16_Sleep(void)         ;
void M2QuadDec_Cnt16_Wakeup(void)        ;


/***************************************
*   Enumerated Types and Parameters
***************************************/

/* Enumerated Type B_Counter__CompareModes, Used in Compare Mode retained for backward compatibility of tests*/
#define M2QuadDec_Cnt16__B_COUNTER__LESS_THAN 1
#define M2QuadDec_Cnt16__B_COUNTER__LESS_THAN_OR_EQUAL 2
#define M2QuadDec_Cnt16__B_COUNTER__EQUAL 0
#define M2QuadDec_Cnt16__B_COUNTER__GREATER_THAN 3
#define M2QuadDec_Cnt16__B_COUNTER__GREATER_THAN_OR_EQUAL 4
#define M2QuadDec_Cnt16__B_COUNTER__SOFTWARE 5

/* Enumerated Type Counter_CompareModes */
#define M2QuadDec_Cnt16_CMP_MODE_LT 1u
#define M2QuadDec_Cnt16_CMP_MODE_LTE 2u
#define M2QuadDec_Cnt16_CMP_MODE_EQ 0u
#define M2QuadDec_Cnt16_CMP_MODE_GT 3u
#define M2QuadDec_Cnt16_CMP_MODE_GTE 4u
#define M2QuadDec_Cnt16_CMP_MODE_SOFTWARE_CONTROLLED 5u

/* Enumerated Type B_Counter__CaptureModes, Used in Capture Mode retained for backward compatibility of tests*/
#define M2QuadDec_Cnt16__B_COUNTER__NONE 0
#define M2QuadDec_Cnt16__B_COUNTER__RISING_EDGE 1
#define M2QuadDec_Cnt16__B_COUNTER__FALLING_EDGE 2
#define M2QuadDec_Cnt16__B_COUNTER__EITHER_EDGE 3
#define M2QuadDec_Cnt16__B_COUNTER__SOFTWARE_CONTROL 4

/* Enumerated Type Counter_CompareModes */
#define M2QuadDec_Cnt16_CAP_MODE_NONE 0u
#define M2QuadDec_Cnt16_CAP_MODE_RISE 1u
#define M2QuadDec_Cnt16_CAP_MODE_FALL 2u
#define M2QuadDec_Cnt16_CAP_MODE_BOTH 3u
#define M2QuadDec_Cnt16_CAP_MODE_SOFTWARE_CONTROLLED 4u


/***************************************
 *  Initialization Values
 **************************************/
#define M2QuadDec_Cnt16_CAPTURE_MODE_CONF       0u
#define M2QuadDec_Cnt16_INIT_PERIOD_VALUE       32768u
#define M2QuadDec_Cnt16_INIT_COUNTER_VALUE      32768u
#if (M2QuadDec_Cnt16_UsingFixedFunction)
#define M2QuadDec_Cnt16_INIT_INTERRUPTS_MASK    ((uint8)((uint8)0u << M2QuadDec_Cnt16_STATUS_ZERO_INT_EN_MASK_SHIFT))
#else
#define M2QuadDec_Cnt16_INIT_COMPARE_VALUE      32768u
#define M2QuadDec_Cnt16_INIT_INTERRUPTS_MASK ((uint8)((uint8)0u << M2QuadDec_Cnt16_STATUS_ZERO_INT_EN_MASK_SHIFT) | \
        ((uint8)((uint8)0u << M2QuadDec_Cnt16_STATUS_CAPTURE_INT_EN_MASK_SHIFT)) | \
        ((uint8)((uint8)0u << M2QuadDec_Cnt16_STATUS_CMP_INT_EN_MASK_SHIFT)) | \
        ((uint8)((uint8)0u << M2QuadDec_Cnt16_STATUS_OVERFLOW_INT_EN_MASK_SHIFT)) | \
        ((uint8)((uint8)0u << M2QuadDec_Cnt16_STATUS_UNDERFLOW_INT_EN_MASK_SHIFT)))
#define M2QuadDec_Cnt16_DEFAULT_COMPARE_MODE    0u

#if( 0 != M2QuadDec_Cnt16_CAPTURE_MODE_CONF)
    #define M2QuadDec_Cnt16_DEFAULT_CAPTURE_MODE    ((uint8)((uint8)0u << M2QuadDec_Cnt16_CTRL_CAPMODE0_SHIFT))
#else    
    #define M2QuadDec_Cnt16_DEFAULT_CAPTURE_MODE    (0u )
#endif /* ( 0 != M2QuadDec_Cnt16_CAPTURE_MODE_CONF) */

#endif /* (M2QuadDec_Cnt16_UsingFixedFunction) */


/**************************************
 *  Registers
 *************************************/
#if (M2QuadDec_Cnt16_UsingFixedFunction)
    #define M2QuadDec_Cnt16_STATICCOUNT_LSB     (*(reg16 *) M2QuadDec_Cnt16_CounterHW__CAP0 )
    #define M2QuadDec_Cnt16_STATICCOUNT_LSB_PTR ( (reg16 *) M2QuadDec_Cnt16_CounterHW__CAP0 )
    #define M2QuadDec_Cnt16_PERIOD_LSB          (*(reg16 *) M2QuadDec_Cnt16_CounterHW__PER0 )
    #define M2QuadDec_Cnt16_PERIOD_LSB_PTR      ( (reg16 *) M2QuadDec_Cnt16_CounterHW__PER0 )
    /* MODE must be set to 1 to set the compare value */
    #define M2QuadDec_Cnt16_COMPARE_LSB         (*(reg16 *) M2QuadDec_Cnt16_CounterHW__CNT_CMP0 )
    #define M2QuadDec_Cnt16_COMPARE_LSB_PTR     ( (reg16 *) M2QuadDec_Cnt16_CounterHW__CNT_CMP0 )
    /* MODE must be set to 0 to get the count */
    #define M2QuadDec_Cnt16_COUNTER_LSB         (*(reg16 *) M2QuadDec_Cnt16_CounterHW__CNT_CMP0 )
    #define M2QuadDec_Cnt16_COUNTER_LSB_PTR     ( (reg16 *) M2QuadDec_Cnt16_CounterHW__CNT_CMP0 )
    #define M2QuadDec_Cnt16_RT1                 (*(reg8 *) M2QuadDec_Cnt16_CounterHW__RT1)
    #define M2QuadDec_Cnt16_RT1_PTR             ( (reg8 *) M2QuadDec_Cnt16_CounterHW__RT1)
#else
    
    #if (M2QuadDec_Cnt16_Resolution <= 8u) /* 8-bit Counter */
    
        #define M2QuadDec_Cnt16_STATICCOUNT_LSB     (*(reg8 *) \
            M2QuadDec_Cnt16_CounterUDB_sC16_counterdp_u0__F0_REG )
        #define M2QuadDec_Cnt16_STATICCOUNT_LSB_PTR ( (reg8 *) \
            M2QuadDec_Cnt16_CounterUDB_sC16_counterdp_u0__F0_REG )
        #define M2QuadDec_Cnt16_PERIOD_LSB          (*(reg8 *) \
            M2QuadDec_Cnt16_CounterUDB_sC16_counterdp_u0__D0_REG )
        #define M2QuadDec_Cnt16_PERIOD_LSB_PTR      ( (reg8 *) \
            M2QuadDec_Cnt16_CounterUDB_sC16_counterdp_u0__D0_REG )
        #define M2QuadDec_Cnt16_COMPARE_LSB         (*(reg8 *) \
            M2QuadDec_Cnt16_CounterUDB_sC16_counterdp_u0__D1_REG )
        #define M2QuadDec_Cnt16_COMPARE_LSB_PTR     ( (reg8 *) \
            M2QuadDec_Cnt16_CounterUDB_sC16_counterdp_u0__D1_REG )
        #define M2QuadDec_Cnt16_COUNTER_LSB         (*(reg8 *) \
            M2QuadDec_Cnt16_CounterUDB_sC16_counterdp_u0__A0_REG )  
        #define M2QuadDec_Cnt16_COUNTER_LSB_PTR     ( (reg8 *)\
            M2QuadDec_Cnt16_CounterUDB_sC16_counterdp_u0__A0_REG )
    
    #elif(M2QuadDec_Cnt16_Resolution <= 16u) /* 16-bit Counter */
        #if(CY_PSOC3) /* 8-bit address space */ 
            #define M2QuadDec_Cnt16_STATICCOUNT_LSB     (*(reg16 *) \
                M2QuadDec_Cnt16_CounterUDB_sC16_counterdp_u0__F0_REG )
            #define M2QuadDec_Cnt16_STATICCOUNT_LSB_PTR ( (reg16 *) \
                M2QuadDec_Cnt16_CounterUDB_sC16_counterdp_u0__F0_REG )
            #define M2QuadDec_Cnt16_PERIOD_LSB          (*(reg16 *) \
                M2QuadDec_Cnt16_CounterUDB_sC16_counterdp_u0__D0_REG )
            #define M2QuadDec_Cnt16_PERIOD_LSB_PTR      ( (reg16 *) \
                M2QuadDec_Cnt16_CounterUDB_sC16_counterdp_u0__D0_REG )
            #define M2QuadDec_Cnt16_COMPARE_LSB         (*(reg16 *) \
                M2QuadDec_Cnt16_CounterUDB_sC16_counterdp_u0__D1_REG )
            #define M2QuadDec_Cnt16_COMPARE_LSB_PTR     ( (reg16 *) \
                M2QuadDec_Cnt16_CounterUDB_sC16_counterdp_u0__D1_REG )
            #define M2QuadDec_Cnt16_COUNTER_LSB         (*(reg16 *) \
                M2QuadDec_Cnt16_CounterUDB_sC16_counterdp_u0__A0_REG )  
            #define M2QuadDec_Cnt16_COUNTER_LSB_PTR     ( (reg16 *)\
                M2QuadDec_Cnt16_CounterUDB_sC16_counterdp_u0__A0_REG )
        #else /* 16-bit address space */
            #define M2QuadDec_Cnt16_STATICCOUNT_LSB     (*(reg16 *) \
                M2QuadDec_Cnt16_CounterUDB_sC16_counterdp_u0__16BIT_F0_REG )
            #define M2QuadDec_Cnt16_STATICCOUNT_LSB_PTR ( (reg16 *) \
                M2QuadDec_Cnt16_CounterUDB_sC16_counterdp_u0__16BIT_F0_REG )
            #define M2QuadDec_Cnt16_PERIOD_LSB          (*(reg16 *) \
                M2QuadDec_Cnt16_CounterUDB_sC16_counterdp_u0__16BIT_D0_REG )
            #define M2QuadDec_Cnt16_PERIOD_LSB_PTR      ( (reg16 *) \
                M2QuadDec_Cnt16_CounterUDB_sC16_counterdp_u0__16BIT_D0_REG )
            #define M2QuadDec_Cnt16_COMPARE_LSB         (*(reg16 *) \
                M2QuadDec_Cnt16_CounterUDB_sC16_counterdp_u0__16BIT_D1_REG )
            #define M2QuadDec_Cnt16_COMPARE_LSB_PTR     ( (reg16 *) \
                M2QuadDec_Cnt16_CounterUDB_sC16_counterdp_u0__16BIT_D1_REG )
            #define M2QuadDec_Cnt16_COUNTER_LSB         (*(reg16 *) \
                M2QuadDec_Cnt16_CounterUDB_sC16_counterdp_u0__16BIT_A0_REG )  
            #define M2QuadDec_Cnt16_COUNTER_LSB_PTR     ( (reg16 *)\
                M2QuadDec_Cnt16_CounterUDB_sC16_counterdp_u0__16BIT_A0_REG )
        #endif /* CY_PSOC3 */   
    #elif(M2QuadDec_Cnt16_Resolution <= 24u) /* 24-bit Counter */
        
        #define M2QuadDec_Cnt16_STATICCOUNT_LSB     (*(reg32 *) \
            M2QuadDec_Cnt16_CounterUDB_sC16_counterdp_u0__F0_REG )
        #define M2QuadDec_Cnt16_STATICCOUNT_LSB_PTR ( (reg32 *) \
            M2QuadDec_Cnt16_CounterUDB_sC16_counterdp_u0__F0_REG )
        #define M2QuadDec_Cnt16_PERIOD_LSB          (*(reg32 *) \
            M2QuadDec_Cnt16_CounterUDB_sC16_counterdp_u0__D0_REG )
        #define M2QuadDec_Cnt16_PERIOD_LSB_PTR      ( (reg32 *) \
            M2QuadDec_Cnt16_CounterUDB_sC16_counterdp_u0__D0_REG )
        #define M2QuadDec_Cnt16_COMPARE_LSB         (*(reg32 *) \
            M2QuadDec_Cnt16_CounterUDB_sC16_counterdp_u0__D1_REG )
        #define M2QuadDec_Cnt16_COMPARE_LSB_PTR     ( (reg32 *) \
            M2QuadDec_Cnt16_CounterUDB_sC16_counterdp_u0__D1_REG )
        #define M2QuadDec_Cnt16_COUNTER_LSB         (*(reg32 *) \
            M2QuadDec_Cnt16_CounterUDB_sC16_counterdp_u0__A0_REG )  
        #define M2QuadDec_Cnt16_COUNTER_LSB_PTR     ( (reg32 *)\
            M2QuadDec_Cnt16_CounterUDB_sC16_counterdp_u0__A0_REG )
    
    #else /* 32-bit Counter */
        #if(CY_PSOC3 || CY_PSOC5) /* 8-bit address space */
            #define M2QuadDec_Cnt16_STATICCOUNT_LSB     (*(reg32 *) \
                M2QuadDec_Cnt16_CounterUDB_sC16_counterdp_u0__F0_REG )
            #define M2QuadDec_Cnt16_STATICCOUNT_LSB_PTR ( (reg32 *) \
                M2QuadDec_Cnt16_CounterUDB_sC16_counterdp_u0__F0_REG )
            #define M2QuadDec_Cnt16_PERIOD_LSB          (*(reg32 *) \
                M2QuadDec_Cnt16_CounterUDB_sC16_counterdp_u0__D0_REG )
            #define M2QuadDec_Cnt16_PERIOD_LSB_PTR      ( (reg32 *) \
                M2QuadDec_Cnt16_CounterUDB_sC16_counterdp_u0__D0_REG )
            #define M2QuadDec_Cnt16_COMPARE_LSB         (*(reg32 *) \
                M2QuadDec_Cnt16_CounterUDB_sC16_counterdp_u0__D1_REG )
            #define M2QuadDec_Cnt16_COMPARE_LSB_PTR     ( (reg32 *) \
                M2QuadDec_Cnt16_CounterUDB_sC16_counterdp_u0__D1_REG )
            #define M2QuadDec_Cnt16_COUNTER_LSB         (*(reg32 *) \
                M2QuadDec_Cnt16_CounterUDB_sC16_counterdp_u0__A0_REG )  
            #define M2QuadDec_Cnt16_COUNTER_LSB_PTR     ( (reg32 *)\
                M2QuadDec_Cnt16_CounterUDB_sC16_counterdp_u0__A0_REG )
        #else /* 32-bit address space */
            #define M2QuadDec_Cnt16_STATICCOUNT_LSB     (*(reg32 *) \
                M2QuadDec_Cnt16_CounterUDB_sC16_counterdp_u0__32BIT_F0_REG )
            #define M2QuadDec_Cnt16_STATICCOUNT_LSB_PTR ( (reg32 *) \
                M2QuadDec_Cnt16_CounterUDB_sC16_counterdp_u0__32BIT_F0_REG )
            #define M2QuadDec_Cnt16_PERIOD_LSB          (*(reg32 *) \
                M2QuadDec_Cnt16_CounterUDB_sC16_counterdp_u0__32BIT_D0_REG )
            #define M2QuadDec_Cnt16_PERIOD_LSB_PTR      ( (reg32 *) \
                M2QuadDec_Cnt16_CounterUDB_sC16_counterdp_u0__32BIT_D0_REG )
            #define M2QuadDec_Cnt16_COMPARE_LSB         (*(reg32 *) \
                M2QuadDec_Cnt16_CounterUDB_sC16_counterdp_u0__32BIT_D1_REG )
            #define M2QuadDec_Cnt16_COMPARE_LSB_PTR     ( (reg32 *) \
                M2QuadDec_Cnt16_CounterUDB_sC16_counterdp_u0__32BIT_D1_REG )
            #define M2QuadDec_Cnt16_COUNTER_LSB         (*(reg32 *) \
                M2QuadDec_Cnt16_CounterUDB_sC16_counterdp_u0__32BIT_A0_REG )  
            #define M2QuadDec_Cnt16_COUNTER_LSB_PTR     ( (reg32 *)\
                M2QuadDec_Cnt16_CounterUDB_sC16_counterdp_u0__32BIT_A0_REG )
        #endif /* CY_PSOC3 || CY_PSOC5 */   
    #endif

	#define M2QuadDec_Cnt16_COUNTER_LSB_PTR_8BIT     ( (reg8 *)\
                M2QuadDec_Cnt16_CounterUDB_sC16_counterdp_u0__A0_REG )
				
    #define M2QuadDec_Cnt16_AUX_CONTROLDP0 \
        (*(reg8 *) M2QuadDec_Cnt16_CounterUDB_sC16_counterdp_u0__DP_AUX_CTL_REG)
    
    #define M2QuadDec_Cnt16_AUX_CONTROLDP0_PTR \
        ( (reg8 *) M2QuadDec_Cnt16_CounterUDB_sC16_counterdp_u0__DP_AUX_CTL_REG)
    
    #if (M2QuadDec_Cnt16_Resolution == 16 || M2QuadDec_Cnt16_Resolution == 24 || M2QuadDec_Cnt16_Resolution == 32)
       #define M2QuadDec_Cnt16_AUX_CONTROLDP1 \
           (*(reg8 *) M2QuadDec_Cnt16_CounterUDB_sC16_counterdp_u1__DP_AUX_CTL_REG)
       #define M2QuadDec_Cnt16_AUX_CONTROLDP1_PTR \
           ( (reg8 *) M2QuadDec_Cnt16_CounterUDB_sC16_counterdp_u1__DP_AUX_CTL_REG)
    #endif /* (M2QuadDec_Cnt16_Resolution == 16 || M2QuadDec_Cnt16_Resolution == 24 || M2QuadDec_Cnt16_Resolution == 32) */
    
    #if (M2QuadDec_Cnt16_Resolution == 24 || M2QuadDec_Cnt16_Resolution == 32)
       #define M2QuadDec_Cnt16_AUX_CONTROLDP2 \
           (*(reg8 *) M2QuadDec_Cnt16_CounterUDB_sC16_counterdp_u2__DP_AUX_CTL_REG)
       #define M2QuadDec_Cnt16_AUX_CONTROLDP2_PTR \
           ( (reg8 *) M2QuadDec_Cnt16_CounterUDB_sC16_counterdp_u2__DP_AUX_CTL_REG)
    #endif /* (M2QuadDec_Cnt16_Resolution == 24 || M2QuadDec_Cnt16_Resolution == 32) */
    
    #if (M2QuadDec_Cnt16_Resolution == 32)
       #define M2QuadDec_Cnt16_AUX_CONTROLDP3 \
           (*(reg8 *) M2QuadDec_Cnt16_CounterUDB_sC16_counterdp_u3__DP_AUX_CTL_REG)
       #define M2QuadDec_Cnt16_AUX_CONTROLDP3_PTR \
           ( (reg8 *) M2QuadDec_Cnt16_CounterUDB_sC16_counterdp_u3__DP_AUX_CTL_REG)
    #endif /* (M2QuadDec_Cnt16_Resolution == 32) */

#endif  /* (M2QuadDec_Cnt16_UsingFixedFunction) */

#if (M2QuadDec_Cnt16_UsingFixedFunction)
    #define M2QuadDec_Cnt16_STATUS         (*(reg8 *) M2QuadDec_Cnt16_CounterHW__SR0 )
    /* In Fixed Function Block Status and Mask are the same register */
    #define M2QuadDec_Cnt16_STATUS_MASK             (*(reg8 *) M2QuadDec_Cnt16_CounterHW__SR0 )
    #define M2QuadDec_Cnt16_STATUS_MASK_PTR         ( (reg8 *) M2QuadDec_Cnt16_CounterHW__SR0 )
    #define M2QuadDec_Cnt16_CONTROL                 (*(reg8 *) M2QuadDec_Cnt16_CounterHW__CFG0)
    #define M2QuadDec_Cnt16_CONTROL_PTR             ( (reg8 *) M2QuadDec_Cnt16_CounterHW__CFG0)
    #define M2QuadDec_Cnt16_CONTROL2                (*(reg8 *) M2QuadDec_Cnt16_CounterHW__CFG1)
    #define M2QuadDec_Cnt16_CONTROL2_PTR            ( (reg8 *) M2QuadDec_Cnt16_CounterHW__CFG1)
    #if (CY_PSOC3 || CY_PSOC5LP)
        #define M2QuadDec_Cnt16_CONTROL3       (*(reg8 *) M2QuadDec_Cnt16_CounterHW__CFG2)
        #define M2QuadDec_Cnt16_CONTROL3_PTR   ( (reg8 *) M2QuadDec_Cnt16_CounterHW__CFG2)
    #endif /* (CY_PSOC3 || CY_PSOC5LP) */
    #define M2QuadDec_Cnt16_GLOBAL_ENABLE           (*(reg8 *) M2QuadDec_Cnt16_CounterHW__PM_ACT_CFG)
    #define M2QuadDec_Cnt16_GLOBAL_ENABLE_PTR       ( (reg8 *) M2QuadDec_Cnt16_CounterHW__PM_ACT_CFG)
    #define M2QuadDec_Cnt16_GLOBAL_STBY_ENABLE      (*(reg8 *) M2QuadDec_Cnt16_CounterHW__PM_STBY_CFG)
    #define M2QuadDec_Cnt16_GLOBAL_STBY_ENABLE_PTR  ( (reg8 *) M2QuadDec_Cnt16_CounterHW__PM_STBY_CFG)
    

    /********************************
    *    Constants
    ********************************/

    /* Fixed Function Block Chosen */
    #define M2QuadDec_Cnt16_BLOCK_EN_MASK          M2QuadDec_Cnt16_CounterHW__PM_ACT_MSK
    #define M2QuadDec_Cnt16_BLOCK_STBY_EN_MASK     M2QuadDec_Cnt16_CounterHW__PM_STBY_MSK 
    
    /* Control Register Bit Locations */    
    /* As defined in Register Map, part of TMRX_CFG0 register */
    #define M2QuadDec_Cnt16_CTRL_ENABLE_SHIFT      0x00u
    #define M2QuadDec_Cnt16_ONESHOT_SHIFT          0x02u
    /* Control Register Bit Masks */
    #define M2QuadDec_Cnt16_CTRL_ENABLE            ((uint8)((uint8)0x01u << M2QuadDec_Cnt16_CTRL_ENABLE_SHIFT))         
    #define M2QuadDec_Cnt16_ONESHOT                ((uint8)((uint8)0x01u << M2QuadDec_Cnt16_ONESHOT_SHIFT))

    /* Control2 Register Bit Masks */
    /* Set the mask for run mode */
    #if (CY_PSOC5A)
        /* Use CFG1 Mode bits to set run mode */
        #define M2QuadDec_Cnt16_CTRL_MODE_SHIFT        0x01u    
        #define M2QuadDec_Cnt16_CTRL_MODE_MASK         ((uint8)((uint8)0x07u << M2QuadDec_Cnt16_CTRL_MODE_SHIFT))
    #endif /* (CY_PSOC5A) */
    #if (CY_PSOC3 || CY_PSOC5LP)
        /* Use CFG2 Mode bits to set run mode */
        #define M2QuadDec_Cnt16_CTRL_MODE_SHIFT        0x00u    
        #define M2QuadDec_Cnt16_CTRL_MODE_MASK         ((uint8)((uint8)0x03u << M2QuadDec_Cnt16_CTRL_MODE_SHIFT))
    #endif /* (CY_PSOC3 || CY_PSOC5LP) */
    /* Set the mask for interrupt (raw/status register) */
    #define M2QuadDec_Cnt16_CTRL2_IRQ_SEL_SHIFT     0x00u
    #define M2QuadDec_Cnt16_CTRL2_IRQ_SEL          ((uint8)((uint8)0x01u << M2QuadDec_Cnt16_CTRL2_IRQ_SEL_SHIFT))     
    
    /* Status Register Bit Locations */
    #define M2QuadDec_Cnt16_STATUS_ZERO_SHIFT      0x07u  /* As defined in Register Map, part of TMRX_SR0 register */ 

    /* Status Register Interrupt Enable Bit Locations */
    #define M2QuadDec_Cnt16_STATUS_ZERO_INT_EN_MASK_SHIFT      (M2QuadDec_Cnt16_STATUS_ZERO_SHIFT - 0x04u)

    /* Status Register Bit Masks */                           
    #define M2QuadDec_Cnt16_STATUS_ZERO            ((uint8)((uint8)0x01u << M2QuadDec_Cnt16_STATUS_ZERO_SHIFT))

    /* Status Register Interrupt Bit Masks*/
    #define M2QuadDec_Cnt16_STATUS_ZERO_INT_EN_MASK       ((uint8)((uint8)M2QuadDec_Cnt16_STATUS_ZERO >> 0x04u))
    
    /*RT1 Synch Constants: Applicable for PSoC3 and PSoC5LP */
    #define M2QuadDec_Cnt16_RT1_SHIFT            0x04u
    #define M2QuadDec_Cnt16_RT1_MASK             ((uint8)((uint8)0x03u << M2QuadDec_Cnt16_RT1_SHIFT))  /* Sync TC and CMP bit masks */
    #define M2QuadDec_Cnt16_SYNC                 ((uint8)((uint8)0x03u << M2QuadDec_Cnt16_RT1_SHIFT))
    #define M2QuadDec_Cnt16_SYNCDSI_SHIFT        0x00u
    #define M2QuadDec_Cnt16_SYNCDSI_MASK         ((uint8)((uint8)0x0Fu << M2QuadDec_Cnt16_SYNCDSI_SHIFT)) /* Sync all DSI inputs */
    #define M2QuadDec_Cnt16_SYNCDSI_EN           ((uint8)((uint8)0x0Fu << M2QuadDec_Cnt16_SYNCDSI_SHIFT)) /* Sync all DSI inputs */
    
#else /* !M2QuadDec_Cnt16_UsingFixedFunction */
    #define M2QuadDec_Cnt16_STATUS               (* (reg8 *) M2QuadDec_Cnt16_CounterUDB_sSTSReg_stsreg__STATUS_REG )
    #define M2QuadDec_Cnt16_STATUS_PTR           (  (reg8 *) M2QuadDec_Cnt16_CounterUDB_sSTSReg_stsreg__STATUS_REG )
    #define M2QuadDec_Cnt16_STATUS_MASK          (* (reg8 *) M2QuadDec_Cnt16_CounterUDB_sSTSReg_stsreg__MASK_REG )
    #define M2QuadDec_Cnt16_STATUS_MASK_PTR      (  (reg8 *) M2QuadDec_Cnt16_CounterUDB_sSTSReg_stsreg__MASK_REG )
    #define M2QuadDec_Cnt16_STATUS_AUX_CTRL      (*(reg8 *) M2QuadDec_Cnt16_CounterUDB_sSTSReg_stsreg__STATUS_AUX_CTL_REG)
    #define M2QuadDec_Cnt16_STATUS_AUX_CTRL_PTR  ( (reg8 *) M2QuadDec_Cnt16_CounterUDB_sSTSReg_stsreg__STATUS_AUX_CTL_REG)
    #define M2QuadDec_Cnt16_CONTROL              (* (reg8 *) M2QuadDec_Cnt16_CounterUDB_sCTRLReg_ctrlreg__CONTROL_REG )
    #define M2QuadDec_Cnt16_CONTROL_PTR          (  (reg8 *) M2QuadDec_Cnt16_CounterUDB_sCTRLReg_ctrlreg__CONTROL_REG )


    /********************************
    *    Constants
    ********************************/
    /* Control Register Bit Locations */
    #define M2QuadDec_Cnt16_CTRL_CAPMODE0_SHIFT    0x03u       /* As defined by Verilog Implementation */
    #define M2QuadDec_Cnt16_CTRL_RESET_SHIFT       0x06u       /* As defined by Verilog Implementation */
    #define M2QuadDec_Cnt16_CTRL_ENABLE_SHIFT      0x07u       /* As defined by Verilog Implementation */
    /* Control Register Bit Masks */
    #define M2QuadDec_Cnt16_CTRL_CMPMODE_MASK      0x07u 
    #define M2QuadDec_Cnt16_CTRL_CAPMODE_MASK      0x03u  
    #define M2QuadDec_Cnt16_CTRL_RESET             ((uint8)((uint8)0x01u << M2QuadDec_Cnt16_CTRL_RESET_SHIFT))  
    #define M2QuadDec_Cnt16_CTRL_ENABLE            ((uint8)((uint8)0x01u << M2QuadDec_Cnt16_CTRL_ENABLE_SHIFT)) 

    /* Status Register Bit Locations */
    #define M2QuadDec_Cnt16_STATUS_CMP_SHIFT       0x00u       /* As defined by Verilog Implementation */
    #define M2QuadDec_Cnt16_STATUS_ZERO_SHIFT      0x01u       /* As defined by Verilog Implementation */
    #define M2QuadDec_Cnt16_STATUS_OVERFLOW_SHIFT  0x02u       /* As defined by Verilog Implementation */
    #define M2QuadDec_Cnt16_STATUS_UNDERFLOW_SHIFT 0x03u       /* As defined by Verilog Implementation */
    #define M2QuadDec_Cnt16_STATUS_CAPTURE_SHIFT   0x04u       /* As defined by Verilog Implementation */
    #define M2QuadDec_Cnt16_STATUS_FIFOFULL_SHIFT  0x05u       /* As defined by Verilog Implementation */
    #define M2QuadDec_Cnt16_STATUS_FIFONEMP_SHIFT  0x06u       /* As defined by Verilog Implementation */
    /* Status Register Interrupt Enable Bit Locations - UDB Status Interrupt Mask match Status Bit Locations*/
    #define M2QuadDec_Cnt16_STATUS_CMP_INT_EN_MASK_SHIFT       M2QuadDec_Cnt16_STATUS_CMP_SHIFT       
    #define M2QuadDec_Cnt16_STATUS_ZERO_INT_EN_MASK_SHIFT      M2QuadDec_Cnt16_STATUS_ZERO_SHIFT      
    #define M2QuadDec_Cnt16_STATUS_OVERFLOW_INT_EN_MASK_SHIFT  M2QuadDec_Cnt16_STATUS_OVERFLOW_SHIFT  
    #define M2QuadDec_Cnt16_STATUS_UNDERFLOW_INT_EN_MASK_SHIFT M2QuadDec_Cnt16_STATUS_UNDERFLOW_SHIFT 
    #define M2QuadDec_Cnt16_STATUS_CAPTURE_INT_EN_MASK_SHIFT   M2QuadDec_Cnt16_STATUS_CAPTURE_SHIFT   
    #define M2QuadDec_Cnt16_STATUS_FIFOFULL_INT_EN_MASK_SHIFT  M2QuadDec_Cnt16_STATUS_FIFOFULL_SHIFT  
    #define M2QuadDec_Cnt16_STATUS_FIFONEMP_INT_EN_MASK_SHIFT  M2QuadDec_Cnt16_STATUS_FIFONEMP_SHIFT  
    /* Status Register Bit Masks */                
    #define M2QuadDec_Cnt16_STATUS_CMP             ((uint8)((uint8)0x01u << M2QuadDec_Cnt16_STATUS_CMP_SHIFT))  
    #define M2QuadDec_Cnt16_STATUS_ZERO            ((uint8)((uint8)0x01u << M2QuadDec_Cnt16_STATUS_ZERO_SHIFT)) 
    #define M2QuadDec_Cnt16_STATUS_OVERFLOW        ((uint8)((uint8)0x01u << M2QuadDec_Cnt16_STATUS_OVERFLOW_SHIFT)) 
    #define M2QuadDec_Cnt16_STATUS_UNDERFLOW       ((uint8)((uint8)0x01u << M2QuadDec_Cnt16_STATUS_UNDERFLOW_SHIFT)) 
    #define M2QuadDec_Cnt16_STATUS_CAPTURE         ((uint8)((uint8)0x01u << M2QuadDec_Cnt16_STATUS_CAPTURE_SHIFT)) 
    #define M2QuadDec_Cnt16_STATUS_FIFOFULL        ((uint8)((uint8)0x01u << M2QuadDec_Cnt16_STATUS_FIFOFULL_SHIFT))
    #define M2QuadDec_Cnt16_STATUS_FIFONEMP        ((uint8)((uint8)0x01u << M2QuadDec_Cnt16_STATUS_FIFONEMP_SHIFT))
    /* Status Register Interrupt Bit Masks  - UDB Status Interrupt Mask match Status Bit Locations */
    #define M2QuadDec_Cnt16_STATUS_CMP_INT_EN_MASK            M2QuadDec_Cnt16_STATUS_CMP                    
    #define M2QuadDec_Cnt16_STATUS_ZERO_INT_EN_MASK           M2QuadDec_Cnt16_STATUS_ZERO            
    #define M2QuadDec_Cnt16_STATUS_OVERFLOW_INT_EN_MASK       M2QuadDec_Cnt16_STATUS_OVERFLOW        
    #define M2QuadDec_Cnt16_STATUS_UNDERFLOW_INT_EN_MASK      M2QuadDec_Cnt16_STATUS_UNDERFLOW       
    #define M2QuadDec_Cnt16_STATUS_CAPTURE_INT_EN_MASK        M2QuadDec_Cnt16_STATUS_CAPTURE         
    #define M2QuadDec_Cnt16_STATUS_FIFOFULL_INT_EN_MASK       M2QuadDec_Cnt16_STATUS_FIFOFULL        
    #define M2QuadDec_Cnt16_STATUS_FIFONEMP_INT_EN_MASK       M2QuadDec_Cnt16_STATUS_FIFONEMP         
    

    /* StatusI Interrupt Enable bit Location in the Auxilliary Control Register */
    #define M2QuadDec_Cnt16_STATUS_ACTL_INT_EN     0x10u /* As defined for the ACTL Register */
    
    /* Datapath Auxillary Control Register definitions */
    #define M2QuadDec_Cnt16_AUX_CTRL_FIFO0_CLR         0x01u   /* As defined by Register map */
    #define M2QuadDec_Cnt16_AUX_CTRL_FIFO1_CLR         0x02u   /* As defined by Register map */
    #define M2QuadDec_Cnt16_AUX_CTRL_FIFO0_LVL         0x04u   /* As defined by Register map */
    #define M2QuadDec_Cnt16_AUX_CTRL_FIFO1_LVL         0x08u   /* As defined by Register map */
    #define M2QuadDec_Cnt16_STATUS_ACTL_INT_EN_MASK    0x10u   /* As defined for the ACTL Register */
    
#endif /* M2QuadDec_Cnt16_UsingFixedFunction */

#endif  /* CY_COUNTER_M2QuadDec_Cnt16_H */


/* [] END OF FILE */

