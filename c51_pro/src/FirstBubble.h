#ifndef _FIRSTBUBBLE_H_
#define _FIRSTBUBBLE_H_

#include <reg52.h>
// #include <intrins.h>

typedef unsigned int u16;
typedef unsigned char u8;

#define MAX_BUBBLE_QUANTITY 8
#define LED_PORT P2
#define SMG_A_DP_PORT P0

sbit LED1 = P2 ^ 0;
sbit BEEP = P2 ^ 5;

u8 gsmg_code[17] = {
    0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07,
    0x7f, 0x6f, 0x77, 0x7c, 0x39, 0x5e, 0x79, 0x71
};


void LedStart1(void);

void delay_10us(u16 ten_us);

void spark(void);

void moveBubble(void);

void crol_cror(void);

void alertAlarm(void);

void screenOps(void);

#endif