/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.77
        Device            :  PIC16F18855
        Driver Version    :  2.00
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

#include "mcc_generated_files/mcc.h"
#include "lcd.h"

#define DLE	0x10
#define STX	0x02
#define ETX	0x03

uint8_t interval;
void isr_TMR0(void){
	interval ++;
}

void _wait( uint16_t tim ){
	while(tim){
		if( interval ){
			interval --;
			tim --;
		}
	}
}


void InitTempSensor( void ){
	
}

#define TS_WAIT_TIMER	10
uint8_t TempCountRange;
uint16_t CheckTempSensor( void ){
	static  uint16_t exTmr = 0;
	uint16_t tmr = TMR1_ReadTimer();
	 
	if((tmr!=0) && (exTmr!=tmr)){
		exTmr = tmr;
		return 0;
	}else{
		exTmr = 0;
		TMR1_WriteTimer(0);
		tmr = tmr/16;
		return tmr;
//		return tmr;
	}
}

typedef union{
	uint8_t dat;
	struct{
		uint8_t up				:1;
		uint8_t dwn				:1;
		uint8_t time			:1;
		uint8_t auto_manual		:1;
		uint8_t pow				:1;
		uint8_t nc				:3;
	};
} stInput;
	

#define CHATA	10
void TaskInput( stInput *in ){
	static uint8_t tim[] = {0,0,0,0,0};
	
	if( iUPSW_PORT ) tim[0] = 0;
	else if( tim[0] < 10 ) tim[0] ++;
	in->up = ( tim[0] == (CHATA-1) ) ?1 :0 ;
	
	if( iDWSW_PORT ) tim[1] = 0;
	else if( tim[1] < 10 ) tim[1] ++;
	in->dwn = ( tim[1] == (CHATA-1) ) ?1 :0 ;
	
	if( iTIMSW_PORT ) tim[2] = 0;
	else if( tim[2] < 10 ) tim[2] ++;
	in->time = ( tim[2] == (CHATA-1) ) ?1 :0 ;

	if( iAUTOSW_PORT ) tim[3] = 0;
	else if( tim[3] < 10 ) tim[3] ++;
	in->auto_manual = ( tim[3] == (CHATA-1) ) ?1 :0 ;

	if( iPOWSW_PORT ) tim[4] = 0;
	else if( tim[4] < 10 ) tim[4] ++;
	in->pow = ( tim[4] == (CHATA-1) ) ?1 :0 ;
}

void SendCmd4Body( uint8_t *data, uint8_t length ){
	EUSART_Write( DLE );
	EUSART_Write( STX );
	
	while( length -- ){
		if( *data == DLE ) EUSART_Write( DLE );
		EUSART_Write( *data );
		data ++;
	}
	
	EUSART_Write( DLE );
	EUSART_Write( ETX );
}

uint16_t OffTimer = 0;
uint8_t OffTimerStopEnable = 0;

uint8_t ReadOffTimerHour(void){
//	if( OffTimer ) return OffTimer;
	if( OffTimer ) return (OffTimer /60) +1;
	else return 0;
}

void WriteOffTimerHour(uint8_t hour){
//	OffTimer = hour;
	if( hour ) OffTimer = hour *60 -1;
	else OffTimer = 0;
}

void TaskOffTimer(void){
	static uint16_t ms = 0;
	
	if( ms < (100*60) ) ms ++;
	else{
		ms = 0;
		if( OffTimer == 1 ){
			OffTimerStopEnable = true;
			OffTimer = 0;
		}else if( OffTimer ) OffTimer --;
	}
}


/*
                         Main application
 */
void main(void)
{
    // initialize the device
    SYSTEM_Initialize();
	
    // When using interrupts, you need to set the Global and Peripheral Interrupt Enable bits
    // Use the following macros to:

	TMR0_SetInterruptHandler(isr_TMR0);
	
    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();
	
	oDE_RE_SetHigh();
	oALARM_SetHigh();	
	LcdInit();
	
    while (1){
		static stInput Input = {0};
		static uint8_t pageInit = true;
		static uint16_t PowLv[] = {0,2000,2300,2600,2900,3200,3500,3800};
		static uint16_t Power = 0;
		// Add your application code
		
		if( interval ){
			interval --;
			uint16_t tmp = CheckTempSensor();
			TaskInput( &Input );
			TaskOffTimer();
			
			static bool isPowerOn = true;
			if( Input.pow ){
				isPowerOn ^= 1;
				LcdClear();
				pageInit = true;
			}
			
			if( !isPowerOn ){
				Power = 0;
				OffTimerStopEnable = false;
			}else{
				static bool isManual = true;
				if( Input.auto_manual ){
					isManual ^= 1;
					LcdClear();
					pageInit = true;
				}

				if( tmp ){
					LcdWriteTemp(115,55,tmp-50);
				}
				
				//オート・マニュアル共通アイテム
				if( pageInit ){
					LcdSetLocate( 90,6 );
					LcdSendDatas( TMPHUM[0], 10 );
					LcdSetLocate( 90,7 );
					LcdSendDatas( TMPHUM[1], 10 );
				}

				static uint16_t timeKeep = 0;
				if( Input.time ){
					timeKeep = 300;
					uint8_t hour = ReadOffTimerHour();
					if( hour == 23 ) WriteOffTimerHour( 0 );
					else WriteOffTimerHour( hour +1 );
				}else{
					if( timeKeep ) timeKeep --;
				}
				
				if( OffTimerStopEnable && Input.dat ){
					OffTimerStopEnable = false;
					Input.dat = 0;
				}

				if( isManual ){
					// マニュアル表示の初期化
					if(pageInit){
						LcdSetLocate( 3,0 );
						LcdSendDatas( MANUAL[0], 44);
						LcdSetLocate( 3,2 );
						LcdSendDatas( OFFTIMER[0], 57 );
						LcdSetLocate( 3,4 );
						LcdSendDatas( AIRFLOW[0], 52 );
					}

					static uint8_t val = 0;
					if( (val<7) && Input.up ) val ++;
					if( val && Input.dwn ) val --;

					uint8_t hour = ReadOffTimerHour();
					LcdWriteHour(79,17,hour, (timeKeep) ?0 :1);
					LcdWriteAirflow(59,33,val);
					
					if( OffTimerStopEnable ) Power = 0;
					else Power = PowLv[val];
					
				}else{
					// オート表示の初期化
					if(pageInit){
						LcdSetLocate( 3,0 );
						LcdSendDatas( AUTO[0], 44 );
						LcdSetLocate( 3,2 );
						LcdSendDatas( AIRFLOW[0], 52 );
						LcdSetLocate( 3,4 );
						LcdSendDatas( TEMP[0], 72 );
						LcdSetLocate( 3,6 );
						LcdSendDatas( OFFTIMER[0], 57 );
					}
					
					static uint8_t Temp = 25;
					if( (Temp<80) && Input.up ) Temp ++;
					if( Temp && Input.dwn ) Temp --;
					
					LcdWriteYMeter(60,50,2,23);
					LcdWriteTemp(95,33,Temp);		//Tempreture
					uint8_t hour = ReadOffTimerHour();
					LcdWriteHour(76,17+32,hour, (timeKeep) ?0 :1);

					if( OffTimerStopEnable ) Power = 0;
					else Power = 3000;
				}
			}

			
			static uint8_t cnt;
			if( cnt < 50 ) cnt ++;
			else{
				cnt = 0;
//				oALARM_Toggle();

				SendCmd4Body( (uint8_t *)&Power, 2 );
			}
//			oALARM_SetLow();
			pageInit = false;
		}
	}
}
/**
 End of File
*/