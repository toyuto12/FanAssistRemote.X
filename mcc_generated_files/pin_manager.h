/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.77
        Device            :  PIC16F18855
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.05 and above
        MPLAB 	          :  MPLAB X 5.20	
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set IO_RA0 aliases
#define IO_RA0_TRIS                 TRISAbits.TRISA0
#define IO_RA0_LAT                  LATAbits.LATA0
#define IO_RA0_PORT                 PORTAbits.RA0
#define IO_RA0_WPU                  WPUAbits.WPUA0
#define IO_RA0_OD                   ODCONAbits.ODCA0
#define IO_RA0_ANS                  ANSELAbits.ANSA0
#define IO_RA0_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define IO_RA0_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define IO_RA0_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define IO_RA0_GetValue()           PORTAbits.RA0
#define IO_RA0_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define IO_RA0_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define IO_RA0_SetPullup()          do { WPUAbits.WPUA0 = 1; } while(0)
#define IO_RA0_ResetPullup()        do { WPUAbits.WPUA0 = 0; } while(0)
#define IO_RA0_SetPushPull()        do { ODCONAbits.ODCA0 = 0; } while(0)
#define IO_RA0_SetOpenDrain()       do { ODCONAbits.ODCA0 = 1; } while(0)
#define IO_RA0_SetAnalogMode()      do { ANSELAbits.ANSA0 = 1; } while(0)
#define IO_RA0_SetDigitalMode()     do { ANSELAbits.ANSA0 = 0; } while(0)

// get/set iDWSW aliases
#define iDWSW_TRIS                 TRISAbits.TRISA1
#define iDWSW_LAT                  LATAbits.LATA1
#define iDWSW_PORT                 PORTAbits.RA1
#define iDWSW_WPU                  WPUAbits.WPUA1
#define iDWSW_OD                   ODCONAbits.ODCA1
#define iDWSW_ANS                  ANSELAbits.ANSA1
#define iDWSW_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define iDWSW_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define iDWSW_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define iDWSW_GetValue()           PORTAbits.RA1
#define iDWSW_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define iDWSW_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define iDWSW_SetPullup()          do { WPUAbits.WPUA1 = 1; } while(0)
#define iDWSW_ResetPullup()        do { WPUAbits.WPUA1 = 0; } while(0)
#define iDWSW_SetPushPull()        do { ODCONAbits.ODCA1 = 0; } while(0)
#define iDWSW_SetOpenDrain()       do { ODCONAbits.ODCA1 = 1; } while(0)
#define iDWSW_SetAnalogMode()      do { ANSELAbits.ANSA1 = 1; } while(0)
#define iDWSW_SetDigitalMode()     do { ANSELAbits.ANSA1 = 0; } while(0)

// get/set iUPSW aliases
#define iUPSW_TRIS                 TRISAbits.TRISA2
#define iUPSW_LAT                  LATAbits.LATA2
#define iUPSW_PORT                 PORTAbits.RA2
#define iUPSW_WPU                  WPUAbits.WPUA2
#define iUPSW_OD                   ODCONAbits.ODCA2
#define iUPSW_ANS                  ANSELAbits.ANSA2
#define iUPSW_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define iUPSW_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define iUPSW_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define iUPSW_GetValue()           PORTAbits.RA2
#define iUPSW_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define iUPSW_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define iUPSW_SetPullup()          do { WPUAbits.WPUA2 = 1; } while(0)
#define iUPSW_ResetPullup()        do { WPUAbits.WPUA2 = 0; } while(0)
#define iUPSW_SetPushPull()        do { ODCONAbits.ODCA2 = 0; } while(0)
#define iUPSW_SetOpenDrain()       do { ODCONAbits.ODCA2 = 1; } while(0)
#define iUPSW_SetAnalogMode()      do { ANSELAbits.ANSA2 = 1; } while(0)
#define iUPSW_SetDigitalMode()     do { ANSELAbits.ANSA2 = 0; } while(0)

// get/set iTIMSW aliases
#define iTIMSW_TRIS                 TRISAbits.TRISA3
#define iTIMSW_LAT                  LATAbits.LATA3
#define iTIMSW_PORT                 PORTAbits.RA3
#define iTIMSW_WPU                  WPUAbits.WPUA3
#define iTIMSW_OD                   ODCONAbits.ODCA3
#define iTIMSW_ANS                  ANSELAbits.ANSA3
#define iTIMSW_SetHigh()            do { LATAbits.LATA3 = 1; } while(0)
#define iTIMSW_SetLow()             do { LATAbits.LATA3 = 0; } while(0)
#define iTIMSW_Toggle()             do { LATAbits.LATA3 = ~LATAbits.LATA3; } while(0)
#define iTIMSW_GetValue()           PORTAbits.RA3
#define iTIMSW_SetDigitalInput()    do { TRISAbits.TRISA3 = 1; } while(0)
#define iTIMSW_SetDigitalOutput()   do { TRISAbits.TRISA3 = 0; } while(0)
#define iTIMSW_SetPullup()          do { WPUAbits.WPUA3 = 1; } while(0)
#define iTIMSW_ResetPullup()        do { WPUAbits.WPUA3 = 0; } while(0)
#define iTIMSW_SetPushPull()        do { ODCONAbits.ODCA3 = 0; } while(0)
#define iTIMSW_SetOpenDrain()       do { ODCONAbits.ODCA3 = 1; } while(0)
#define iTIMSW_SetAnalogMode()      do { ANSELAbits.ANSA3 = 1; } while(0)
#define iTIMSW_SetDigitalMode()     do { ANSELAbits.ANSA3 = 0; } while(0)

// get/set iAUTOSW aliases
#define iAUTOSW_TRIS                 TRISAbits.TRISA4
#define iAUTOSW_LAT                  LATAbits.LATA4
#define iAUTOSW_PORT                 PORTAbits.RA4
#define iAUTOSW_WPU                  WPUAbits.WPUA4
#define iAUTOSW_OD                   ODCONAbits.ODCA4
#define iAUTOSW_ANS                  ANSELAbits.ANSA4
#define iAUTOSW_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define iAUTOSW_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define iAUTOSW_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define iAUTOSW_GetValue()           PORTAbits.RA4
#define iAUTOSW_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define iAUTOSW_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define iAUTOSW_SetPullup()          do { WPUAbits.WPUA4 = 1; } while(0)
#define iAUTOSW_ResetPullup()        do { WPUAbits.WPUA4 = 0; } while(0)
#define iAUTOSW_SetPushPull()        do { ODCONAbits.ODCA4 = 0; } while(0)
#define iAUTOSW_SetOpenDrain()       do { ODCONAbits.ODCA4 = 1; } while(0)
#define iAUTOSW_SetAnalogMode()      do { ANSELAbits.ANSA4 = 1; } while(0)
#define iAUTOSW_SetDigitalMode()     do { ANSELAbits.ANSA4 = 0; } while(0)

// get/set iPOWSW aliases
#define iPOWSW_TRIS                 TRISAbits.TRISA5
#define iPOWSW_LAT                  LATAbits.LATA5
#define iPOWSW_PORT                 PORTAbits.RA5
#define iPOWSW_WPU                  WPUAbits.WPUA5
#define iPOWSW_OD                   ODCONAbits.ODCA5
#define iPOWSW_ANS                  ANSELAbits.ANSA5
#define iPOWSW_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define iPOWSW_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define iPOWSW_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define iPOWSW_GetValue()           PORTAbits.RA5
#define iPOWSW_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define iPOWSW_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define iPOWSW_SetPullup()          do { WPUAbits.WPUA5 = 1; } while(0)
#define iPOWSW_ResetPullup()        do { WPUAbits.WPUA5 = 0; } while(0)
#define iPOWSW_SetPushPull()        do { ODCONAbits.ODCA5 = 0; } while(0)
#define iPOWSW_SetOpenDrain()       do { ODCONAbits.ODCA5 = 1; } while(0)
#define iPOWSW_SetAnalogMode()      do { ANSELAbits.ANSA5 = 1; } while(0)
#define iPOWSW_SetDigitalMode()     do { ANSELAbits.ANSA5 = 0; } while(0)

// get/set oALARM aliases
#define oALARM_TRIS                 TRISAbits.TRISA6
#define oALARM_LAT                  LATAbits.LATA6
#define oALARM_PORT                 PORTAbits.RA6
#define oALARM_WPU                  WPUAbits.WPUA6
#define oALARM_OD                   ODCONAbits.ODCA6
#define oALARM_ANS                  ANSELAbits.ANSA6
#define oALARM_SetHigh()            do { LATAbits.LATA6 = 1; } while(0)
#define oALARM_SetLow()             do { LATAbits.LATA6 = 0; } while(0)
#define oALARM_Toggle()             do { LATAbits.LATA6 = ~LATAbits.LATA6; } while(0)
#define oALARM_GetValue()           PORTAbits.RA6
#define oALARM_SetDigitalInput()    do { TRISAbits.TRISA6 = 1; } while(0)
#define oALARM_SetDigitalOutput()   do { TRISAbits.TRISA6 = 0; } while(0)
#define oALARM_SetPullup()          do { WPUAbits.WPUA6 = 1; } while(0)
#define oALARM_ResetPullup()        do { WPUAbits.WPUA6 = 0; } while(0)
#define oALARM_SetPushPull()        do { ODCONAbits.ODCA6 = 0; } while(0)
#define oALARM_SetOpenDrain()       do { ODCONAbits.ODCA6 = 1; } while(0)
#define oALARM_SetAnalogMode()      do { ANSELAbits.ANSA6 = 1; } while(0)
#define oALARM_SetDigitalMode()     do { ANSELAbits.ANSA6 = 0; } while(0)

// get/set RA7 procedures
#define RA7_SetHigh()            do { LATAbits.LATA7 = 1; } while(0)
#define RA7_SetLow()             do { LATAbits.LATA7 = 0; } while(0)
#define RA7_Toggle()             do { LATAbits.LATA7 = ~LATAbits.LATA7; } while(0)
#define RA7_GetValue()              PORTAbits.RA7
#define RA7_SetDigitalInput()    do { TRISAbits.TRISA7 = 1; } while(0)
#define RA7_SetDigitalOutput()   do { TRISAbits.TRISA7 = 0; } while(0)
#define RA7_SetPullup()             do { WPUAbits.WPUA7 = 1; } while(0)
#define RA7_ResetPullup()           do { WPUAbits.WPUA7 = 0; } while(0)
#define RA7_SetAnalogMode()         do { ANSELAbits.ANSA7 = 1; } while(0)
#define RA7_SetDigitalMode()        do { ANSELAbits.ANSA7 = 0; } while(0)

// get/set SDI1 aliases
#define SDI1_TRIS                 TRISBbits.TRISB0
#define SDI1_LAT                  LATBbits.LATB0
#define SDI1_PORT                 PORTBbits.RB0
#define SDI1_WPU                  WPUBbits.WPUB0
#define SDI1_OD                   ODCONBbits.ODCB0
#define SDI1_ANS                  ANSELBbits.ANSB0
#define SDI1_SetHigh()            do { LATBbits.LATB0 = 1; } while(0)
#define SDI1_SetLow()             do { LATBbits.LATB0 = 0; } while(0)
#define SDI1_Toggle()             do { LATBbits.LATB0 = ~LATBbits.LATB0; } while(0)
#define SDI1_GetValue()           PORTBbits.RB0
#define SDI1_SetDigitalInput()    do { TRISBbits.TRISB0 = 1; } while(0)
#define SDI1_SetDigitalOutput()   do { TRISBbits.TRISB0 = 0; } while(0)
#define SDI1_SetPullup()          do { WPUBbits.WPUB0 = 1; } while(0)
#define SDI1_ResetPullup()        do { WPUBbits.WPUB0 = 0; } while(0)
#define SDI1_SetPushPull()        do { ODCONBbits.ODCB0 = 0; } while(0)
#define SDI1_SetOpenDrain()       do { ODCONBbits.ODCB0 = 1; } while(0)
#define SDI1_SetAnalogMode()      do { ANSELBbits.ANSB0 = 1; } while(0)
#define SDI1_SetDigitalMode()     do { ANSELBbits.ANSB0 = 0; } while(0)

// get/set SCK1 aliases
#define SCK1_TRIS                 TRISBbits.TRISB1
#define SCK1_LAT                  LATBbits.LATB1
#define SCK1_PORT                 PORTBbits.RB1
#define SCK1_WPU                  WPUBbits.WPUB1
#define SCK1_OD                   ODCONBbits.ODCB1
#define SCK1_ANS                  ANSELBbits.ANSB1
#define SCK1_SetHigh()            do { LATBbits.LATB1 = 1; } while(0)
#define SCK1_SetLow()             do { LATBbits.LATB1 = 0; } while(0)
#define SCK1_Toggle()             do { LATBbits.LATB1 = ~LATBbits.LATB1; } while(0)
#define SCK1_GetValue()           PORTBbits.RB1
#define SCK1_SetDigitalInput()    do { TRISBbits.TRISB1 = 1; } while(0)
#define SCK1_SetDigitalOutput()   do { TRISBbits.TRISB1 = 0; } while(0)
#define SCK1_SetPullup()          do { WPUBbits.WPUB1 = 1; } while(0)
#define SCK1_ResetPullup()        do { WPUBbits.WPUB1 = 0; } while(0)
#define SCK1_SetPushPull()        do { ODCONBbits.ODCB1 = 0; } while(0)
#define SCK1_SetOpenDrain()       do { ODCONBbits.ODCB1 = 1; } while(0)
#define SCK1_SetAnalogMode()      do { ANSELBbits.ANSB1 = 1; } while(0)
#define SCK1_SetDigitalMode()     do { ANSELBbits.ANSB1 = 0; } while(0)

// get/set SDO1 aliases
#define SDO1_TRIS                 TRISBbits.TRISB2
#define SDO1_LAT                  LATBbits.LATB2
#define SDO1_PORT                 PORTBbits.RB2
#define SDO1_WPU                  WPUBbits.WPUB2
#define SDO1_OD                   ODCONBbits.ODCB2
#define SDO1_ANS                  ANSELBbits.ANSB2
#define SDO1_SetHigh()            do { LATBbits.LATB2 = 1; } while(0)
#define SDO1_SetLow()             do { LATBbits.LATB2 = 0; } while(0)
#define SDO1_Toggle()             do { LATBbits.LATB2 = ~LATBbits.LATB2; } while(0)
#define SDO1_GetValue()           PORTBbits.RB2
#define SDO1_SetDigitalInput()    do { TRISBbits.TRISB2 = 1; } while(0)
#define SDO1_SetDigitalOutput()   do { TRISBbits.TRISB2 = 0; } while(0)
#define SDO1_SetPullup()          do { WPUBbits.WPUB2 = 1; } while(0)
#define SDO1_ResetPullup()        do { WPUBbits.WPUB2 = 0; } while(0)
#define SDO1_SetPushPull()        do { ODCONBbits.ODCB2 = 0; } while(0)
#define SDO1_SetOpenDrain()       do { ODCONBbits.ODCB2 = 1; } while(0)
#define SDO1_SetAnalogMode()      do { ANSELBbits.ANSB2 = 1; } while(0)
#define SDO1_SetDigitalMode()     do { ANSELBbits.ANSB2 = 0; } while(0)

// get/set oCS aliases
#define oCS_TRIS                 TRISBbits.TRISB3
#define oCS_LAT                  LATBbits.LATB3
#define oCS_PORT                 PORTBbits.RB3
#define oCS_WPU                  WPUBbits.WPUB3
#define oCS_OD                   ODCONBbits.ODCB3
#define oCS_ANS                  ANSELBbits.ANSB3
#define oCS_SetHigh()            do { LATBbits.LATB3 = 1; } while(0)
#define oCS_SetLow()             do { LATBbits.LATB3 = 0; } while(0)
#define oCS_Toggle()             do { LATBbits.LATB3 = ~LATBbits.LATB3; } while(0)
#define oCS_GetValue()           PORTBbits.RB3
#define oCS_SetDigitalInput()    do { TRISBbits.TRISB3 = 1; } while(0)
#define oCS_SetDigitalOutput()   do { TRISBbits.TRISB3 = 0; } while(0)
#define oCS_SetPullup()          do { WPUBbits.WPUB3 = 1; } while(0)
#define oCS_ResetPullup()        do { WPUBbits.WPUB3 = 0; } while(0)
#define oCS_SetPushPull()        do { ODCONBbits.ODCB3 = 0; } while(0)
#define oCS_SetOpenDrain()       do { ODCONBbits.ODCB3 = 1; } while(0)
#define oCS_SetAnalogMode()      do { ANSELBbits.ANSB3 = 1; } while(0)
#define oCS_SetDigitalMode()     do { ANSELBbits.ANSB3 = 0; } while(0)

// get/set oA0 aliases
#define oA0_TRIS                 TRISBbits.TRISB4
#define oA0_LAT                  LATBbits.LATB4
#define oA0_PORT                 PORTBbits.RB4
#define oA0_WPU                  WPUBbits.WPUB4
#define oA0_OD                   ODCONBbits.ODCB4
#define oA0_ANS                  ANSELBbits.ANSB4
#define oA0_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define oA0_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define oA0_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define oA0_GetValue()           PORTBbits.RB4
#define oA0_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define oA0_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define oA0_SetPullup()          do { WPUBbits.WPUB4 = 1; } while(0)
#define oA0_ResetPullup()        do { WPUBbits.WPUB4 = 0; } while(0)
#define oA0_SetPushPull()        do { ODCONBbits.ODCB4 = 0; } while(0)
#define oA0_SetOpenDrain()       do { ODCONBbits.ODCB4 = 1; } while(0)
#define oA0_SetAnalogMode()      do { ANSELBbits.ANSB4 = 1; } while(0)
#define oA0_SetDigitalMode()     do { ANSELBbits.ANSB4 = 0; } while(0)

// get/set oRESB aliases
#define oRESB_TRIS                 TRISBbits.TRISB5
#define oRESB_LAT                  LATBbits.LATB5
#define oRESB_PORT                 PORTBbits.RB5
#define oRESB_WPU                  WPUBbits.WPUB5
#define oRESB_OD                   ODCONBbits.ODCB5
#define oRESB_ANS                  ANSELBbits.ANSB5
#define oRESB_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define oRESB_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define oRESB_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define oRESB_GetValue()           PORTBbits.RB5
#define oRESB_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define oRESB_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define oRESB_SetPullup()          do { WPUBbits.WPUB5 = 1; } while(0)
#define oRESB_ResetPullup()        do { WPUBbits.WPUB5 = 0; } while(0)
#define oRESB_SetPushPull()        do { ODCONBbits.ODCB5 = 0; } while(0)
#define oRESB_SetOpenDrain()       do { ODCONBbits.ODCB5 = 1; } while(0)
#define oRESB_SetAnalogMode()      do { ANSELBbits.ANSB5 = 1; } while(0)
#define oRESB_SetDigitalMode()     do { ANSELBbits.ANSB5 = 0; } while(0)

// get/set IO_RB6 aliases
#define IO_RB6_TRIS                 TRISBbits.TRISB6
#define IO_RB6_LAT                  LATBbits.LATB6
#define IO_RB6_PORT                 PORTBbits.RB6
#define IO_RB6_WPU                  WPUBbits.WPUB6
#define IO_RB6_OD                   ODCONBbits.ODCB6
#define IO_RB6_ANS                  ANSELBbits.ANSB6
#define IO_RB6_SetHigh()            do { LATBbits.LATB6 = 1; } while(0)
#define IO_RB6_SetLow()             do { LATBbits.LATB6 = 0; } while(0)
#define IO_RB6_Toggle()             do { LATBbits.LATB6 = ~LATBbits.LATB6; } while(0)
#define IO_RB6_GetValue()           PORTBbits.RB6
#define IO_RB6_SetDigitalInput()    do { TRISBbits.TRISB6 = 1; } while(0)
#define IO_RB6_SetDigitalOutput()   do { TRISBbits.TRISB6 = 0; } while(0)
#define IO_RB6_SetPullup()          do { WPUBbits.WPUB6 = 1; } while(0)
#define IO_RB6_ResetPullup()        do { WPUBbits.WPUB6 = 0; } while(0)
#define IO_RB6_SetPushPull()        do { ODCONBbits.ODCB6 = 0; } while(0)
#define IO_RB6_SetOpenDrain()       do { ODCONBbits.ODCB6 = 1; } while(0)
#define IO_RB6_SetAnalogMode()      do { ANSELBbits.ANSB6 = 1; } while(0)
#define IO_RB6_SetDigitalMode()     do { ANSELBbits.ANSB6 = 0; } while(0)

// get/set IO_RB7 aliases
#define IO_RB7_TRIS                 TRISBbits.TRISB7
#define IO_RB7_LAT                  LATBbits.LATB7
#define IO_RB7_PORT                 PORTBbits.RB7
#define IO_RB7_WPU                  WPUBbits.WPUB7
#define IO_RB7_OD                   ODCONBbits.ODCB7
#define IO_RB7_ANS                  ANSELBbits.ANSB7
#define IO_RB7_SetHigh()            do { LATBbits.LATB7 = 1; } while(0)
#define IO_RB7_SetLow()             do { LATBbits.LATB7 = 0; } while(0)
#define IO_RB7_Toggle()             do { LATBbits.LATB7 = ~LATBbits.LATB7; } while(0)
#define IO_RB7_GetValue()           PORTBbits.RB7
#define IO_RB7_SetDigitalInput()    do { TRISBbits.TRISB7 = 1; } while(0)
#define IO_RB7_SetDigitalOutput()   do { TRISBbits.TRISB7 = 0; } while(0)
#define IO_RB7_SetPullup()          do { WPUBbits.WPUB7 = 1; } while(0)
#define IO_RB7_ResetPullup()        do { WPUBbits.WPUB7 = 0; } while(0)
#define IO_RB7_SetPushPull()        do { ODCONBbits.ODCB7 = 0; } while(0)
#define IO_RB7_SetOpenDrain()       do { ODCONBbits.ODCB7 = 1; } while(0)
#define IO_RB7_SetAnalogMode()      do { ANSELBbits.ANSB7 = 1; } while(0)
#define IO_RB7_SetDigitalMode()     do { ANSELBbits.ANSB7 = 0; } while(0)

// get/set oSEN aliases
#define oSEN_TRIS                 TRISCbits.TRISC2
#define oSEN_LAT                  LATCbits.LATC2
#define oSEN_PORT                 PORTCbits.RC2
#define oSEN_WPU                  WPUCbits.WPUC2
#define oSEN_OD                   ODCONCbits.ODCC2
#define oSEN_ANS                  ANSELCbits.ANSC2
#define oSEN_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define oSEN_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define oSEN_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define oSEN_GetValue()           PORTCbits.RC2
#define oSEN_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define oSEN_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define oSEN_SetPullup()          do { WPUCbits.WPUC2 = 1; } while(0)
#define oSEN_ResetPullup()        do { WPUCbits.WPUC2 = 0; } while(0)
#define oSEN_SetPushPull()        do { ODCONCbits.ODCC2 = 0; } while(0)
#define oSEN_SetOpenDrain()       do { ODCONCbits.ODCC2 = 1; } while(0)
#define oSEN_SetAnalogMode()      do { ANSELCbits.ANSC2 = 1; } while(0)
#define oSEN_SetDigitalMode()     do { ANSELCbits.ANSC2 = 0; } while(0)

// get/set IO_RC3 aliases
#define IO_RC3_TRIS                 TRISCbits.TRISC3
#define IO_RC3_LAT                  LATCbits.LATC3
#define IO_RC3_PORT                 PORTCbits.RC3
#define IO_RC3_WPU                  WPUCbits.WPUC3
#define IO_RC3_OD                   ODCONCbits.ODCC3
#define IO_RC3_ANS                  ANSELCbits.ANSC3
#define IO_RC3_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define IO_RC3_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define IO_RC3_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define IO_RC3_GetValue()           PORTCbits.RC3
#define IO_RC3_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define IO_RC3_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define IO_RC3_SetPullup()          do { WPUCbits.WPUC3 = 1; } while(0)
#define IO_RC3_ResetPullup()        do { WPUCbits.WPUC3 = 0; } while(0)
#define IO_RC3_SetPushPull()        do { ODCONCbits.ODCC3 = 0; } while(0)
#define IO_RC3_SetOpenDrain()       do { ODCONCbits.ODCC3 = 1; } while(0)
#define IO_RC3_SetAnalogMode()      do { ANSELCbits.ANSC3 = 1; } while(0)
#define IO_RC3_SetDigitalMode()     do { ANSELCbits.ANSC3 = 0; } while(0)

// get/set oDE_RE aliases
#define oDE_RE_TRIS                 TRISCbits.TRISC5
#define oDE_RE_LAT                  LATCbits.LATC5
#define oDE_RE_PORT                 PORTCbits.RC5
#define oDE_RE_WPU                  WPUCbits.WPUC5
#define oDE_RE_OD                   ODCONCbits.ODCC5
#define oDE_RE_ANS                  ANSELCbits.ANSC5
#define oDE_RE_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define oDE_RE_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define oDE_RE_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define oDE_RE_GetValue()           PORTCbits.RC5
#define oDE_RE_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define oDE_RE_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define oDE_RE_SetPullup()          do { WPUCbits.WPUC5 = 1; } while(0)
#define oDE_RE_ResetPullup()        do { WPUCbits.WPUC5 = 0; } while(0)
#define oDE_RE_SetPushPull()        do { ODCONCbits.ODCC5 = 0; } while(0)
#define oDE_RE_SetOpenDrain()       do { ODCONCbits.ODCC5 = 1; } while(0)
#define oDE_RE_SetAnalogMode()      do { ANSELCbits.ANSC5 = 1; } while(0)
#define oDE_RE_SetDigitalMode()     do { ANSELCbits.ANSC5 = 0; } while(0)

// get/set RC6 procedures
#define RC6_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define RC6_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define RC6_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define RC6_GetValue()              PORTCbits.RC6
#define RC6_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define RC6_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)
#define RC6_SetPullup()             do { WPUCbits.WPUC6 = 1; } while(0)
#define RC6_ResetPullup()           do { WPUCbits.WPUC6 = 0; } while(0)
#define RC6_SetAnalogMode()         do { ANSELCbits.ANSC6 = 1; } while(0)
#define RC6_SetDigitalMode()        do { ANSELCbits.ANSC6 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/