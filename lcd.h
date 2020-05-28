#ifndef LCD_H
#define	LCD_H

#include "mcc_generated_files/mcc.h"

#define LCD_SIZE_X	0x80
#define LCD_SIZE_Y	56
#define LCD_PAGE	8

typedef union{
	uint16_t all;
	struct{
		uint8_t x;
		uint8_t y;
	};
}stPoint;
typedef struct{
	stPoint size;
	uint8_t xStart;
	uint8_t xEnd;
	uint8_t *buf;
} stLCDData;

void LcdSendData( uint8_t data );
void LcdSendDatas( uint8_t *data, uint8_t length );
void LcdSetLocate( uint8_t x, uint8_t y );
void LcdWrite( uint8_t x, uint8_t y, stLCDData dat );
void LcdWriteTemp( uint8_t x, uint8_t y, uint8_t tmp );
void LcdWriteValue( uint8_t x, uint8_t y, uint8_t keta, uint16_t val, uint8_t isBlink );
void LcdWriteHour( uint8_t x, uint8_t y, uint8_t hour, uint8_t isBlink );
void LcdWriteAirflow( uint8_t x, uint8_t y, uint8_t lv );
void LcdWriteOffTimer( uint8_t lv );
void LcdWriteYMeter( uint8_t x, uint8_t size, uint8_t page, uint8_t val );
void LcdClear(void);
void LcdInit(void);

const uint8_t AUTO[1][44] = {
	{0xC0,0x30,0x2C,0x23,0x2C,0x30,0xC0, 0 ,0x7F,0x80,0x80,0x80,0x80,0x7F, 0 ,0x01,0x01,0xFF,0x01,0x01, 0 ,0x7E,0x81,0x81,0x81,0x81,0x7E, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
};

const uint8_t MANUAL[1][44] = {
	{0xFF,0x03,0x3C,0xC0,0xC0,0x3C,0x03,0xFF, 0 ,0xC0,0x30,0x2C,0x23,0x2C,0x30,0xC0, 0 ,0xFF,0x03,0x0C,0x30,0xC0,0xFF, 0 ,0x7F,0x80,0x80,0x80,0x80,0x7F, 0 ,0xC0,0x30,0x2C,0x23,0x2C,0x30,0xC0, 0 ,0xFF,0x80,0x80,0x80, 0 }
};

// LV1_2_OFF.bmp Output (PixelSize=(11,7)
const uint8_t LV1_2_OFF[1][11] = {
	{0x78,0x4C,0x44,0x44,0x7C,0x00,0x7C,0x42,0x41,0x41,0x7F},
};

// LV1_2_ON.bmp Output (PixelSize=(11,7)
const uint8_t LV1_2_ON[1][11] = {
	{0x78,0x7C,0x7C,0x7C,0x7C,0x00,0x7C,0x7E,0x7F,0x7F,0x7F},
};

// LV3_7_OFF.bmp Output (PixelSize=(29,16)
const uint8_t LV3_7_OFF[2][29] = {
	{0x00,0x00,0x80,0x80,0x80,0x00,0x80,0x40,0x20,0x20,0xE0,0x00,0xE0,0x10,0x08,0x08,0xF8,0x00,0xF8,0x04,0x02,0x02,0xFE,0x00,0xFE,0x01,0x01,0x01,0xFF},
	{0xFE,0x81,0x80,0x80,0xFF,0x00,0xFF,0x80,0x80,0x80,0xFF,0x00,0xFF,0x80,0x80,0x80,0xFF,0x00,0xFF,0x80,0x80,0x80,0xFF,0x00,0xFF,0x80,0x80,0x80,0x7F},
};

// LV3_7_ON.bmp Output (PixelSize=(29,16)
const uint8_t LV3_7_ON[2][29] = {
	{0x00,0x00,0x80,0x80,0x80,0x00,0x80,0xC0,0xE0,0xE0,0xE0,0x00,0xE0,0xF0,0xF8,0xF8,0xF8,0x00,0xF8,0xFC,0xFE,0xFE,0xFE,0x00,0xFE,0xFF,0xFF,0xFF,0xFF},
	{0xFE,0xFF,0xFF,0xFF,0xFF,0x00,0xFF,0xFF,0xFF,0xFF,0xFF,0x00,0xFF,0xFF,0xFF,0xFF,0xFF,0x00,0xFF,0xFF,0xFF,0xFF,0xFF,0x00,0xFF,0xFF,0xFF,0xFF,0x7F},
};

// PARAM.bmp Output (PixelSize=(64,7)
const uint8_t PARAM[1][64] = {
	{0x00,0x3E,0x41,0x41,0x3E,0x00,0x00,0x02,0x7F,0x00,0x00,0x62,0x51,0x49,0x46,0x00,0x22,0x49,0x49,0x36,0x30,0x2C,0x23,0x7F,0x20,0x00,0x27,0x45,0x45,0x39,0x00,0x3E,0x49,0x49,0x32,0x00,0x01,0x71,0x0D,0x03,0x00,0x36,0x49,0x49,0x36,0x00,0x26,0x49,0x49,0x3E,0x47,0x37,0x08,0x76,0x71,0x02,0x05,0x02,0x3E,0x41,0x41,0x41,0x41,0x22},
};

const uint8_t HOUR[1][8] = {
	{0, 0xFF,0x08,0x08,0x08,0x08,0xFF, 0}
};

const uint8_t HOUR_OFF[1][8] = {
	{0, 0,0,0,0,0,0, 0}
};

// TIMER_OFF.bmp Output (PixelSize=(40,24)
const uint8_t TIMER_OFF[3][40] = {
	{0xF0,0x10,0x10,0x10,0xF0,0x00,0xF0,0x10,0x10,0x10,0x10,0xF0,0x00,0xF0,0x10,0x10,0x10,0x10,0x10,0xF0,0x00,0xF0,0x10,0x10,0x10,0x10,0x10,0x10,0xF0,0x00,0xF0,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0xF0},
	{0xFF,0x00,0x00,0x00,0xFF,0x00,0xFF,0x00,0x00,0x00,0x00,0xFF,0x00,0xFF,0x00,0x00,0x00,0x00,0x00,0xFF,0x00,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0x00,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF},
	{0x07,0x84,0x04,0x04,0x07,0x80,0x87,0x84,0x04,0x04,0x04,0x07,0x00,0x07,0x04,0x04,0x04,0x04,0x04,0x07,0x00,0x07,0x04,0x04,0x04,0x04,0x04,0x04,0x07,0x00,0x07,0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x07},
};

// TIMER_ON.bmp Output (PixelSize=(40,24)
const uint8_t TIMER_ON[3][40] = {
	{0xF0,0xF0,0xF0,0xF0,0xF0,0x00,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0x00,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0x00,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0x00,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0},
	{0xFF,0xFF,0xFF,0xFF,0xFF,0x00,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x00,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x00,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x00,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF},
	{0x07,0x87,0x07,0x07,0x07,0x80,0x87,0x87,0x07,0x07,0x07,0x07,0x00,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x00,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x00,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07},
};

// TMPHUM.bmp Output (PixelSize=(22,16)
const uint8_t TMPHUM[2][22] = {
	{0x00,0x00,0xFE,0xC1,0xC1,0xC1,0xFE,0x92,0x92,0x92,0x00,0xC0,0x20,0x10,0x0C,0x03,0x0C,0x10,0x20,0xD5,0x15,0x15},
	{0x10,0x3C,0x4F,0xBF,0xFF,0xFF,0x7F,0x3C,0x10,0x00,0x1F,0x20,0x5E,0x5E,0xBE,0xBE,0xBE,0x5E,0x5E,0x20,0x1F,0x00},
};

const uint8_t AIRFLOW[1][52] = {
	{ 0xC0,0x30,0x2C,0x23,0x2C,0x30,0xC0, 0 ,0xFF,0x00,0x00, 0 ,0xFF,0x11,0x11,0x31,0xCE, 0,0,0,0,0 ,0xFF,0x09,0x09,0x09, 0,0 ,0xFF,0x80,0x80,0x80, 0 ,0x7E,0x81,0x81,0x81,0x81,0x7E, 0 ,0x03,0x3C,0xC0,0x30,0x0C,0x03,0x0C,0x30,0xC0,0x3C,0x03, 0 }
};

const uint8_t OFFTIMER[1][57] = {
	{0x7E,0x81,0x81,0x81,0x81,0x7E, 0,0 ,0xFF,0x09,0x09,0x09, 0,0 ,0xFF,0x09,0x09,0x09, 0,0,0,0 ,0x01,0x01,0xFF,0x01,0x01, 0,0 ,0xFF, 0,0,0 ,0xFF,0x03,0x3C,0xC0,0xC0,0x3C,0x03,0xFF, 0,0 ,0xFF,0x89,0x89,0x89, 0,0 ,0xFF,0x11,0x11,0x31,0xCE, 0,0 ,0x84, 0 }
};

const uint8_t TEMP[1][72] = {
	{0x01,0x01,0xFF,0x01,0x01, 0
	,0x78,0x94,0x94,0x94,0x98, 0,0 
	,0xFC,0x08,0x04,0x04,0xF8,0x04,0x04,0xF8, 0,0 
	,0xFF,0x11,0x11,0x11,0x0E, 0,0 
	,0x78,0x94,0x94,0x94,0x98, 0,0 
	,0xFC,0x04,0x04, 0 
	,0x64,0x94,0x94,0x94,0xF8, 0 
	,0x04,0x7E,0x84,0x84, 0 
	,0x7C,0x80,0x80,0x40,0xFC, 0,0
	,0xFC,0x04,0x04, 0 
	,0x78,0x94,0x94,0x94,0x98, 0,0
	,0x84, 0}
};


#ifdef LCD_C

#else

#endif // LCD_C
#endif	/* LCD_H */

