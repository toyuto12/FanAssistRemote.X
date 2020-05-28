#define LCD_C
#include "lcd.h"

void _wait( uint16_t tim );

#define DISPLAY			0xAE
#define SET_PAGE_ADR	0xB0
#define SET_COL_ADRH	0x10
#define SET_COL_ADRL	0x00
#define SET_BIAS		0xA2
#define ADC_SELECT		0xA0
#define CMN_SELECT		0xC0
#define LCD_RESET		0xE2
#define SET_DISP_STARTLINE	0x40
#define POW_CONTROL		0x28
#define SET_V0VOLT		0x20

void LcdSendCmd( uint8_t cmd ){
	while( SPI1_IsBufferFull() );
	oCS_SetLow();
	oA0_SetLow();		// Low = CMD
	
	SPI1_Exchange8bit( cmd );
	
	oCS_SetHigh();
}

void LcdSendData( uint8_t data ){
	while( SPI1_IsBufferFull() );
	oCS_SetLow();
	oA0_SetHigh();		// High = DATA
	
	SPI1_Exchange8bit( data );
	
	oCS_SetHigh();
}

void LcdSendDatas( uint8_t *data, uint8_t length ){
	while( SPI1_IsBufferFull() );
	oCS_SetLow();
	oA0_SetHigh();		// High = DATA
	
	while( length-- ){
		SPI1_Exchange8bit( *data );
		data ++;
	}
	
	oCS_SetHigh();
}

void LcdSetColumn( uint8_t x ){
	LcdSendCmd( SET_COL_ADRH | (x>>4));
	LcdSendCmd( SET_COL_ADRL | (x&0x0F));
}

void LcdSetLocate( uint8_t x, uint8_t y ){
	LcdSetColumn( x );
	LcdSendCmd( SET_PAGE_ADR | (y&0x0F) );
}

void LcdWriteFill( uint8_t x, uint8_t y, stLCDData dat ){
	uint8_t page=y>>3;						// BasePageAddress算出
	uint8_t col=x;							// BaseColumnAddress算出
	uint8_t yShift=y&0x07;					// 元データからのシフト数算出
	uint8_t pSize=(dat.size.y-1 +yShift)>>3;	// 必要Page数算出
	uint8_t fSize = dat.xEnd-dat.xStart;	// 必要Column数算出
	uint8_t *pDat = &dat.buf[dat.xStart];	// BaseDataAddress取得

	if( !yShift ){							// データシフト無い場合
		for( int i=0; i<=pSize; i++ ){
			LcdSendCmd( SET_PAGE_ADR | (page&0x0F) );
			LcdSetColumn( col );
			for( int j=0; j<fSize; j++ ) LcdSendData( 0x00 );
			page ++;
		}
	}else{									// データシフトある場合
		for( int i=0; i<=pSize; i++ ){
			LcdSendCmd( SET_PAGE_ADR | (page&0x0F) );
			LcdSetColumn( col );
			for( int j=0; j<fSize; j++ ) LcdSendData( 0x00 );
			page ++;
		}
	}
}

void LcdWrite( uint8_t x, uint8_t y, stLCDData dat ){
	uint8_t page=y>>3;						// BasePageAddress算出
	uint8_t col=x;							// BaseColumnAddress算出
	uint8_t yShift=y&0x07;					// 元データからのシフト数算出
	uint8_t pSize=(dat.size.y-1 +yShift)>>3;	// 必要Page数算出
	uint8_t fSize = dat.xEnd-dat.xStart;	// 必要Column数算出
	uint8_t *pDat = &dat.buf[dat.xStart];	// BaseDataAddress取得

	if( !yShift ){							// データシフト無い場合
		for( int i=0; i<=pSize; i++ ){
			LcdSendCmd( SET_PAGE_ADR | (page&0x0F) );
			LcdSetColumn( col );
			LcdSendDatas( pDat, fSize );
			pDat += dat.size.x;
			page ++;
		}
	}else{									// データシフトある場合
		uint16_t tmp;
		for( int i=0; i<=pSize; i++ ){
			LcdSendCmd( SET_PAGE_ADR | (page&0x0F) );
			LcdSetColumn( col );
			for( int j=0; j<fSize; j++ ){
				if( i==0 ){
					tmp = *pDat;
					tmp <<= yShift;
				}else if( i==pSize ){
					tmp = (uint16_t)*(pDat-dat.size.x);
					tmp >>= (8-yShift);
				}else{
					tmp = (uint16_t)*pDat<<8 | *(pDat-dat.size.x);
					tmp >>= (8-yShift);
				}
				LcdSendData( (uint8_t)tmp );
				pDat ++;
			}
			page ++;
			pDat += (dat.size.x -fSize);
		}
	}
}

void LcdWriteValue( uint8_t x, uint8_t y, uint8_t keta, uint16_t val, uint8_t isBlink ){
	stLCDData dat = {0};
	uint8_t valNo,i=0;
	bool isZero = false;		// 0表示を禁止
	static uint8_t blink=0;
	
	blink ++;
	if( blink & 0x40 ) isBlink = false;
	
	dat.buf = PARAM;	dat.size.x = 64;	dat.size.y = 7;
	while(keta--){
		x -= 7;
		valNo = val%10;
		dat.xStart = valNo*5;
		dat.xEnd = dat.xStart +5;
		if( !isBlink && (val || isZero)){
			LcdWrite( x, y, dat );
			val /= 10;
		}else{
			LcdWriteFill( x, y, dat );
		}
		isZero = false;
	};
}

void LcdWriteOffTimer( uint8_t lv ){
	stLCDData ldat;
	ldat.size.x=40;	ldat.size.y=24;
	
	ldat.xStart=0;	ldat.xEnd=6;
	ldat.buf = (lv) ?TIMER_ON :TIMER_OFF ;
	LcdWrite(59,24,ldat);

	ldat.xStart=6;	ldat.xEnd=13;
	ldat.buf = (lv>1) ?TIMER_ON :TIMER_OFF ;
	LcdWrite(65,24,ldat);

	ldat.xStart=13;	ldat.xEnd=21;
	ldat.buf = (lv>2) ?TIMER_ON :TIMER_OFF ;
	LcdWrite(72,24,ldat);

	ldat.xStart=21;	ldat.xEnd=30;
	ldat.buf = (lv>3) ?TIMER_ON :TIMER_OFF ;
	LcdWrite(80,24,ldat);

	ldat.xStart=30;	ldat.xEnd=39;
	ldat.buf = (lv>4) ?TIMER_ON :TIMER_OFF ;
	LcdWrite(89,24,ldat);
}

void LcdWriteYMeter( uint8_t x, uint8_t size, uint8_t page, uint8_t val ){
	size -= 2;
	LcdSetLocate( x,page );
	LcdSendData( 0xFF );
	uint8_t i;
	for( i=0 ; i<size; i++ ){
		LcdSendData( (i<val) ?0xFF :0x81 );
	}
	LcdSendData( 0xFF );
}

void LcdWriteAirflow( uint8_t x, uint8_t y, uint8_t lv ){
	stLCDData ldat;
	ldat.size.x=11;	ldat.size.y=7;
	
	ldat.xStart=0;	ldat.xEnd=6;
	ldat.buf = (lv) ?LV1_2_ON :LV1_2_OFF ;
	LcdWrite(x,y,ldat);
	
	ldat.xStart=6;	ldat.xEnd=11;
	ldat.buf = (lv>1) ?LV1_2_ON :LV1_2_OFF ;
	LcdWrite(x+6,y,ldat);
	
	ldat.size.x=29;	ldat.size.y=16;

	ldat.xStart=0;	ldat.xEnd=6;
	ldat.buf = (lv>2) ?LV3_7_ON :LV3_7_OFF ;
	LcdWrite(x+12,y-9,ldat);
	
	ldat.xStart=6;	ldat.xEnd=12;
	ldat.buf = (lv>3) ?LV3_7_ON :LV3_7_OFF ;
	LcdWrite(x+18,y-9,ldat);

	ldat.xStart=12;	ldat.xEnd=18;
	ldat.buf = (lv>4) ?LV3_7_ON :LV3_7_OFF ;
	LcdWrite(x+24,y-9,ldat);

	ldat.xStart=18;	ldat.xEnd=24;
	ldat.buf = (lv>5) ?LV3_7_ON :LV3_7_OFF ;
	LcdWrite(x+30,y-9,ldat);

	ldat.xStart=24;	ldat.xEnd=29;
	ldat.buf = (lv>6) ?LV3_7_ON :LV3_7_OFF ;
	LcdWrite(x+36,y-9,ldat);
}

void LcdWriteHour( uint8_t x, uint8_t y, uint8_t hour, uint8_t isBlink ){
	LcdWriteValue(x,y,2,hour, isBlink);
	stLCDData ldat;
	ldat.size.x=8;	ldat.size.y=7;
	ldat.xStart=0,ldat.xEnd=8;
	if( hour ) ldat.buf = HOUR;
	else ldat.buf = HOUR_OFF;
	LcdWrite(x+1,y,ldat);
}

void LcdWriteTemp( uint8_t x, uint8_t y, uint8_t tmp ){
	LcdWriteValue(x,y,2,tmp, false);
	stLCDData ldat;
	ldat.size.x=64;	ldat.size.y=7;
	ldat.xStart=55,ldat.xEnd=64;
	ldat.buf = PARAM;
	LcdWrite(x+1,y,ldat);
}

void LcdClear(void){
	uint8_t page,col;
	for( page=0; page<LCD_PAGE; page++ ){
		LcdSetLocate( 0, page );
		for( col=0; col<(LCD_SIZE_X); col++ )	LcdSendData( 0x00 );
	}
}

void LcdInit(void){
	oRESB_SetLow();
	_wait(50);
	oRESB_SetHigh();
	_wait(1);

	LcdSendCmd( SET_DISP_STARTLINE | 0 );		// 0x40
	
	LcdSendCmd( SET_BIAS | 0 );					// 0xA2
	LcdSendCmd( ADC_SELECT | 0 );				// 0xA0
	LcdSendCmd( CMN_SELECT | 0x08 );			// 0xC8

	LcdSendCmd( SET_V0VOLT | 0x07 );			// 0x27
	// Eletronic VR Mode Set
	LcdSendCmd( 0x81 );		LcdSendCmd( 0x2F );
	// Booster Ratio Set
	LcdSendCmd( 0xF8 );		LcdSendCmd( 0x01 );

	LcdSendCmd( POW_CONTROL | 0x07 );			// 0x2F

	LcdClear();
	
	LcdSendCmd( DISPLAY | 1 );

}


