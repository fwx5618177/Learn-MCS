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

// 控制直流电机控制管脚
sbit DC_Motor = P1 ^ 0;
#define DC_MOTOR_RUN_TIME 5000

// 控制电机管脚
sbit IN1_A = P1 ^ 0;
sbit IN1_B = P1 ^ 1;
sbit IN1_C = P1 ^ 2;
sbit IN1_D = P1 ^ 3;

// 独立按键控制管脚
sbit KEY_1 = P3 ^ 1;
sbit KEY_2 = P3 ^ 0;
sbit KEY_3 = P3 ^ 2;
sbit KEY_4 = P3 ^ 3;

// 按键按下的键值
#define KEY1_PRESS 1
#define KEY2_PRESS 2
#define KEY3_PRESS 3
#define KEY4_PRESS 4
#define KEY1_UNPRESS 0

// 电机速度
#define STEP_MAXSPEED 1
#define STEP_MINSPEED 5

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

void machineTrigger(void);

void stepMachine(void);

#endif